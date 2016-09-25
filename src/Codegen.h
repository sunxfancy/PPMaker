#ifndef CODEGEN_H
#define CODEGEN_H

#include <string>

class Codegen {
public:
    Codegen();
    void addScript(int x, const std::string& script);
    const std::string& getOutput() const {
        return data;
    }
private:
    std::string data;
    static const char* begin;
    static const char* end;
};



#endif /* end of include guard: CODEGEN_H */
