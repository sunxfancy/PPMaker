/*
* @Author: sxf
* @Date:   2014-12-31 18:41:35
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-22 14:32:08
*/

#include "BNF.h"
#include <iostream>
using namespace std;

void BNF::print_bnf(int point) const {
    auto& fout = cerr;
    fout << this->root->id << " : " << this->root->state_class;
    fout << " => ";
    int k = 0;
    for (auto p = BNFdata.begin(); p!= BNFdata.end();++p)
    {
        if (point == k) fout << ". ";
        ++k;
        State* s = *p;
        if (s->state_type == constant)
            fout << s->state_const;
        else
            fout << s->state_class;
        fout << " ";
    }
    if (point == k) fout << ". ";
    fout << endl;
}

void BNF::print_bnf() const {
    print_bnf(-1);
}

string BNF::get_graphviz_bnf(int point) const {
    string ans;
    ans += this->root->state_class;
    ans += " =&gt; ";
    int k = 0;
    for (auto p = BNFdata.begin(); p!= BNFdata.end();++p)
    {
        if (point == k) ans += "&bull; ";
        ++k;
        State* s = *p;
        if (s->state_type == constant)
            ans += s->state_const;
        else
            ans += s->state_class;
        ans += " ";
    }
    if (point == k) ans += "&bull; ";
    return ans;
}


int BNF::temp_size;
vector<BNF*> BNF::bnfs;

vector<BNF*> BNF::BuildAllBNF(State* root,VMap& vmap)
{
    BNF::bnfs.clear();
    BNF::temp_size = 0;
    State* p = root->children;
    while (p != NULL){
        BuildFromNode(p,vmap);
        p = p->brother;
    }
    vmap.constMax = vmap.constSize;
    // 最后遍历BNF列表，将Vn插入
    int idnum = 0;
    for (auto i = bnfs.begin(); i != bnfs.end(); ++i) {
        BNF* b = *i;
        b->setID(idnum++);
        vmap.InsertVn(b->getRoot()->state_class);// 插入Vn表中
    }
    return BNF::bnfs;
}

void BNF::BuildFromNode(State* node, VMap& vmap)
{
    State* p = node->children;
    while (p != NULL){
    if (!node->isList) {
	    BNF* bnf = new BNF();
	    bnf->root = node; // 根节点设置为要归约的部分
	    vector<State*>& vec = bnf->BNFdata;
	    State* q = p->children;
	    while (q != NULL){
            if (p->isList) {
                if ((q->state_type != temporality) && (q->state_type != script)) {
                    if (q->state_type != epsilon) {
                        vec.push_back(q);
                        if (q->state_type == constant) {
                            vmap.InsertConst(q->state_const); // 统计Constant的符号表
                        }
                    }
                } else {
                    if (q->state_type == script) {
                        if (q->brother == NULL)
                            bnf->bnf_script = q->script;
                        else {
                            ++temp_size;
                            char* classname = new char[10];
                            sprintf(classname,"temp%d",temp_size);
                            q->state_class = classname;
                            vec.push_back(q);

                            BNF* newbnf = new BNF();
                            newbnf->root = q;
                            State* newstate = new State();
                            newstate->state_type = epsilon;
                            bnf->BNFdata.push_back(newstate);
                            newbnf->bnf_script = q->script;
                            BNF::bnfs.push_back(newbnf);
                        }
                    } else {
                        ++temp_size;
                        char* classname = new char[10];
                        sprintf(classname,"temp%d",temp_size);
                        q->state_class = classname;
                        vec.push_back(q);
                        BuildFromNode(q,vmap);
                    }
                }
            }
            q = q->brother;
	    }
	    BNF::bnfs.push_back(bnf);
	}
	p = p->brother;
    }

}
