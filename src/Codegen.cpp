#include "Codegen.h"
#include "BNF.h"
#include <string>
#include "BNFParser.h"
const char* Codegen::begin =
    "void* __ppp_script(int x) {\n"
    "\tswitch(x) {\n";

const char* Codegen::end =
    "\tdefault: return 0;\n"
    "\t}\n"
    "}\n";


Codegen::Codegen(BNFParser* parser, vector<BNF*>& bnflist) : bnfs(bnflist) {
    data += begin;
    this->parser = parser;
}

void Codegen::addScript(int x, const std::string& script, BNF* bnf) {
    data += "case ";
    data += x;
    data += ":{\n";
    int p = 0;
    for (State* s : bnf->getBNFdata()) {
        if (s->state_var != NULL) {
            string type = parser->getType(s->state_class);
            data += type;
            data += "* ";
            data += s->state_var;
            data += " = (";
            data += type;
            data += ")getArgs(";
            data += p;
            data += ");\n";
        }
    }
    data += script;
    data += "\nreturn nullptr;\n}\n";
}

void Codegen::addAll() {
    for (BNF* p : bnfs) {
        addScript(p->getID(), p->getScript(), p);
    }
}
