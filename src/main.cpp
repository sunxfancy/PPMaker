/*
* @Author: sxf
* @Date:   2015-04-14 14:38:22
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-10 20:29:59
*/

#include <stdio.h>
#include <iostream>
#include "help_message.h"
#include <fstream>
#include "Parser.h"
#include "Lex.h"
#include <unistd.h>
#include "Grammer_Node.h"


#define maxpath 1000
using namespace std;


int main(int argc,const char *argv[])
{
	char buffer[maxpath]; int flen;
    getcwd(buffer, sizeof(buffer));

	if (argc <= 2) printf(help_message);
	else {
        Lex* lex = new Lex();
        lex->ReadConfig(argv[1]);
        lex->Init();

	    Parser* parser = Parser::NewLRParser();
		parser->setLex(lex);
	    parser->BuildParser(argv[2]);
	}
	return 0;
}
