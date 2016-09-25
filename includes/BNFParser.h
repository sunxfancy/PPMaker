/*
* @Author: sxf
* @Date:   2015-04-17 10:05:26
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-14 19:03:59
*/


#ifndef BNF_PARSER_H
#define BNF_PARSER_H

#include "State.h"
#include "VMap.h"
#include <map>

using namespace std;

/**
 * @brief BNF解析器类, 负责解析BNF的定义文件
 */
class BNFParser {

public:

	State* Analysis(const char* filename);

	void NowLeft();
	void NowRight();
	void AddToken(const char* token);
	void MakePrecedence(VMap& vmap);
	int getPrecedence(int id);
	bool getAssociativity(int id);

	// For type
	void NowType(const char* token);
	void AddType(const char* token);

	// For include
	void DefineInclude(const char* include);

	// for debug
	void printTree();

private:
	State* state_root;

	// 优先级表，从0开始，为最小有限，数字越大，优先级越高
	std::map<string, int> precedence_map;

	// 结合性表，true为左结合，false为右结合
	std::map<string, bool> associativity_map;

	std::map<int, int> id_precedence_map;
	std::map<int, bool> id_associativity_map;

	int now_precedence;
	bool now_associativity;

	string now_type;
	std::map<string, string> type_map;
	// for debug
	void printNode(State* s,int d);
};


#endif // BNF_PARSER_H
