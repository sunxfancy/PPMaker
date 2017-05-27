#include "LR_parser.h"
#include "BNFParser.h"
#include "LALRTable.h"
#include "Grammer_Node.h"
#include <cereal/archives/json.hpp>
#include "LexInterface.h"
#include "Codegen.h"
#include <fstream>

LR_parser::LR_parser()
{

}

LR_parser::~LR_parser()
{

}


void LR_parser::ExtendBNF()
{
    mainbnf = new BNF();
    State* s = new State();
    s->state_class = "S'";
    s->state_type = statement;
    s->id = vmap.InsertVn("S'");
    mainbnf->setRoot(s);
    mainbnf->setID(-1);
    mainbnf->addBNFdata(bnflist[0]->getRoot());
}

void LR_parser::MakeID()
{
    for (auto p = bnflist.begin(); p != bnflist.end(); ++p) {
        BNF* bnf = *p;
        State* s = bnf->getRoot();
        s->id = vmap.getVn(s->state_class);
        const vector<State*>& vec = bnf->getBNFdata();
        for (auto q = vec.begin(); q != vec.end(); ++q) {
            s = *q;
            if (s->state_type == constant)
            s->id = vmap.getConst(s->state_const);
            else if (s->state_type == temporality || s->state_type == statement )
            s->id = vmap.getVn(s->state_class);
            else if (s->state_type == epsilon )
            s->id = 0;
            else if (s->state_type == terminal )
            s->id = vmap.getVt(s->state_class);
        }
    }
}

void print_ItemCollection(vector<ItemCollection*> vec) {
    for (auto p = vec.begin(); p != vec.end(); ++p) {
        ItemCollection* items = *p;
        printf("I%d:", items->getID());
        items->printSet();
    }
}


static const char begin_state[] = "style = \"filled, bold\" penwidth = 5 fillcolor = \"white\" fontname = \"Courier New\" shape = \"Mrecord\" ";
static const char end_state[] = "style = \"filled\" penwidth = 1 fillcolor = \"black\" fontname = \"Courier New\" shape = \"Mrecord\" ";
static const char normal_state[] = "style = \"filled\" penwidth = 1 fillcolor = \"white\" fontname = \"Courier New\" shape = \"Mrecord\" ";

void LR_parser::print_graphviz_ItemCollection(vector<ItemCollection*> vec, ostream& os) {
    printf("print graphviz\n");
    os << "digraph g {" << endl
       << "graph [fontsize=30 labelloc=\"t\" label=\"\" splines=true overlap=false rankdir = \"LR\"];" << endl
       << "ratio = auto;" << endl;
    os.flush();
    // 依次打印全部状态集
    for (auto p = vec.begin(); p != vec.end(); ++p) {
        ItemCollection* items = *p;
        os << '\"' << "state" << items->getID() << '\"';
        os << " [" << endl;
        if (items->getID() == 0)
            os << begin_state << endl;
        else
            os << normal_state << endl;
        items->print_graphviz_Set(os);
        os << "];" << endl;
    }

    // 依次打印goto跳转
    for (auto p = vec.begin(); p != vec.end(); ++p) {
        ItemCollection* items = *p;
        for (int i = 0; i< vmap.constSize; ++i) {
            ItemCollection* gotoitems = items->GOTO(i);
            int gotoid = -1;
            if (gotoitems != NULL) {
                gotoid = gotoitems->getID();
            }
            if (gotoid != -1) {
                os << "state" << items->getID() << " -> " << "state" << gotoid
                   << "[ penwidth = 1 fontsize = 28 fontcolor = \"black\" label = \""
                   << vmap.find(i)
                   << "\" ];" << endl;
            }
        }
    }
    os << "}" << endl;
}

void LR_parser::print_GOTO(vector<ItemCollection*> vec) {
    printf("======= GOTO =======\n");
    for (int i = 0; i< vmap.constSize; ++i) {
        printf("\t%d",i);
    }
    printf("\n");
    for (auto p = vec.begin(); p != vec.end(); ++p) {
        ItemCollection* items = *p;
        printf("I%d:",items->getID());
        for (int i = 0; i< vmap.constSize; ++i) {
            ItemCollection* gotoitems = items->GOTO(i);
            int gotoid = -1;
            if (gotoitems != NULL) {
                gotoid = gotoitems->getID();
            }
            printf("\t%d",gotoid);
        }
        printf("\n");
    }

    printf("======= Spread =======\n");
    for (auto p = vec.begin(); p != vec.end(); ++p) {
        ItemCollection* items = *p;
        items->printSpread();
        printf("\n");
    }
}

void LR_parser::BuildParser()
{
    string save_filepath = cfg_filepath + ".lrsave";

    printf("Create LR0\n");
    // 创建LR0项集族
    vector<ItemCollection*> vec = ItemCollection::MakeLR0Items(&vmap, mainbnf, bnflist);
    // printf("======== print LR0 Collection ========\n");
    // print_ItemCollection(vec);
    // 构建LALR项集族
    ItemCollection::MakeLALRItems(vec,bnflist);
    // printf("======== print LR1 Collection ========\n");
    // print_ItemCollection(vec);
    // print_GOTO(vec);
    // printf("test: \t %d %d %d\n",vmap.constMax+1,vec.size(),vmap.constSize);

    // 打印graphviz图

    LALRTable* lalr_table = new LALRTable(vmap.constMax+1, vec.size(), vmap.constSize, bnfparser);
    printf("Size: %d\n", bnflist.size());


    lalr_table->bnf_from.resize(bnflist.size());
    for (auto* bnf : bnflist) {
        lalr_table->bnf_size.push_back(bnf->getBNFdata().size());
        lalr_table->bnf_Vn.push_back(bnf->getRoot()->id);

        std::vector<int> temp;
        for (auto* i : bnf->getBNFdata()) {
            temp.push_back(i->id);
            lalr_table->bnf_from[i->id].push_back(bnf->getRoot()->id);
        }
        lalr_table->bnfs.push_back(temp);
    }



    lalr_table->vmap = &vmap;
    lalr_table->BuildTable(vec);
    lalr_table->Save(save_filepath.c_str());
    lalr_table->printTable();
    table = (LRTable*) lalr_table;
}

void LR_parser::BuildParser(const char* filename) {
    AddBNF(filename);
    BuildParser();

    // add codegen
    Codegen gen(bnfparser, bnflist);
    gen.addAll();
    ofstream out(string(filename) + ".cpp");
    out << gen.getOutput();
    out.flush();
    out.close();
}


void LR_parser::AddBNF(const char* filename) {
    cfg_filepath = filename;
    // ask the ID name from the lex
    int size = lex->getRuleSize();
    vmap.constSize = size-1;
    for (int i = 1; i< size; ++i) {
        vmap.InsertVt(lex->getRule(i), i);
    }
    bnfparser = new BNFParser();
    State* root = bnfparser->Analysis(filename);
    if (root == NULL) {
        printf("Error State\n");
        delete bnfparser;
        return;
    }
    // bnfparser->printTree();
    bnflist = BNF::BuildAllBNF(root,vmap);
    bnfparser->MakePrecedence(vmap);
    ExtendBNF();
    MakeID(); // for each state, make a ID for it
}

void LR_parser::setLex(LexInterface* _lex)
{
    lex = _lex;
}


void LR_parser::save_log() {
    // {
	//     cereal::JSONOutputArchive oarchive(DebugMsg::parser_save());
	//     oarchive(
	// 		cereal::make_nvp("table", *((LALRTable*)table)),
	// 		cereal::make_nvp("vmap", vmap),
	// 		cereal::make_nvp("bnf", *this),
    //         cereal::make_nvp("core", core)
	//  	);
    // } // 通过让oarchive提前析构，为文件输出流添加结尾
	// DebugMsg::parser_save_close(); // 一定要确保JSONOutput输出完后再close
}
