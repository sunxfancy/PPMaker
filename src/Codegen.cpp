#include "Codegen.h"
#include "BNF.h"
#include <string>
#include "BNFParser.h"
const char* Codegen::begin =
    "#include <vector>\n"
    "extern \"C\" {\n"
    "extern const void* __ppp_script(int __bnf_num, const std::vector<void*>& __args) {\n"
    "\tswitch(__bnf_num) {\n";

const char* Codegen::end =
    "\tdefault: return nullptr;\n"
    "\t}\n"
    "}\n"
    "}\n";


Codegen::Codegen(BNFParser* parser, vector<BNF*>& bnflist) : bnfs(bnflist) {
    this->parser = parser;
}

void Codegen::addScript(int x, const std::string& script, BNF* bnf) {
    data += "case ";
    data += to_string(x);
    data += ":{\n";
    int p = 0;
    for (State* s : bnf->getBNFdata()) {
        if (s->state_var != NULL) {
            string type = parser->getType(s->state_class);
            if (type == "") type = "char";
            data += "const ";
            data += type;
            data += "* ";
            data += s->state_var;
            data += " = (";
            data += "const ";
            data += type;
            data += "*)(__args[";
            data += to_string(p);
            data += "]);\n";
        }
        p++;
    }
    data += script;
    data += "\nreturn nullptr;\n}\n";
}

void Codegen::addAll() {
    data += parser->getInclude();
    data += begin;
    for (BNF* p : bnfs) {
        if (p->getScript() == nullptr)
            addScript(p->getID(), "", p);
        else
            addScript(p->getID(), p->getScript(), p);
    }
    data += end;
}
