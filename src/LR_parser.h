/*
* @Author: sxf
* @Date:   2015-01-01 19:40:28
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-22 10:25:57
*/

#ifndef LR_PARSER_H
#define LR_PARSER_H

#include "Parser.h"
#include "BNF.h"
#include "LRTable.h"
#include <vector>
#include <map>
#include <string>
#include "VMap.h"
#include "Grammer_Node.h"
using namespace std;

class BNFParser;

class LR_parser : public Parser
{
public:
  // constructors
    LR_parser();
    ~LR_parser();

    // 构建解析器
    virtual void BuildParser();

    // 先AddBNF，再构建解析器
    virtual void BuildParser(const char*);

    // 将EBNF的描述文件传入，用来构建LR语法解析器
    virtual void AddBNF(const char*);

    // 设置词法分析器
    virtual void setLex(LexInterface*);

    virtual void setBaseVtSize(int size) {
        vmap.constSize = size;
    }

private:
    LexInterface* lex;

    vector<BNF*> bnflist;

    BNF* mainbnf; // 增广文法中的根元素

    VMap vmap;

    // LR分析表
    LRTable* table;

    // BNF解析器
    BNFParser* bnfparser;

    // 配置文件路径
    std::string cfg_filepath;

    // 扩展 BNF，增加根元素
    void ExtendBNF();
    // 给每一个state加上id
    void MakeID();

    void print_GOTO(vector<ItemCollection*> vec);

    void print_graphviz_ItemCollection(vector<ItemCollection*> vec, ostream& os);

    // 串行化
    void save_log();

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar)
    {
        // serialize things by passing them to the archive
        for (BNF* p : bnflist) {
            ar(*p);
        }
    }
};

#endif // LR_PARSER_H
