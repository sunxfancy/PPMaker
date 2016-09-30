#ifndef CODEGEN_H
#define CODEGEN_H

#include <string>
#include <vector>
using namespace std;
class BNF;
class BNFParser;

class Codegen {
public:
    Codegen(BNFParser* parser, vector<BNF*>& bnflist);
    void addAll();
    void addScript(int x, const std::string& script, BNF* bnf);
    const std::string& getOutput() const {
        return data;
    }
private:
    BNFParser* parser;
    std::string data;
    vector<BNF*>& bnfs;
    static const char* begin;
    static const char* end;
};



#endif /* end of include guard: CODEGEN_H */
