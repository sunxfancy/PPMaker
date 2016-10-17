#include "Codegen.h"
#include "BNF.h"
#include <string>
#include "BNFParser.h"
const char* Codegen::begin =
    "void* __ppp_script(int x) {\n"
    "\tswitch(x) {\n";

const char* Codegen::end =
    "\tdefault: return nullptr;\n"
    "\t}\n"
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
            data += type;
            data += "* ";
            data += s->state_var;
            data += " = (";
            data += type;
            data += "*)getArgs(";
            data += to_string(p);
            data += ");\n";
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
