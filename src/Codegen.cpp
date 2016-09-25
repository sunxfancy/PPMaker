#include "Codegen.h"
#include <string>

const char* Codegen::begin =
    "void* __ppp_script(int x) {\n"
    "\tswitch(x) {\n";

const char* Codegen::end =
    "\tdefault: return 0;\n"
    "\t}\n"
    "}\n";


Codegen::Codegen() {
    data += begin;
}

void Codegen::addScript(int x, const std::string& script) {
    data += "case ";
    data += x;
    data += ":";
    data += script;
}
