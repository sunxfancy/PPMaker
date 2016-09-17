/*
* @Author: sxf
* @Date:   2015-01-02 16:29:28
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-22 10:26:23
*/

#ifndef PARSER_H
#define PARSER_H

class LexInterface;

/**
 * @brief 核心的语法分析器接口
 * @details 这是语法分析器的接口, 语法分析器会从词法分析器中获取token\n
 *          同时会在适当的时候调用元脚本解析器执行语义动作
 */
class Parser {
public:
    /**
     * @brief 构建解析器
     */
    virtual void BuildParser() = 0;

    /**
     * @brief 先AddBNF，再构建解析器
     *
     * @param  BNF配置文件路径
     */
    virtual void BuildParser(const char*) = 0;

    /**
     * @brief 将EBNF的描述文件传入，用来构建LR语法解析器
     *
     * @param  BNF配置文件路径
     */
    virtual void AddBNF(const char*) = 0;

    /**
     * @brief 设置词法分析器
     *
     * @param  Lex接口的词法分析器
     */
    virtual void setLex(LexInterface*) = 0;

    /**
     * @brief 设置非终结符的个数 set the Base Vt size of Lex
     *
     * @param size 非终结符个数
     */
    virtual void setBaseVtSize(int size) = 0;


    /**
     * @brief 构建特点的LALR解析器
     * @return 该解析器对象
     */
    static Parser* NewLRParser();
};

#endif // PARSER_H
