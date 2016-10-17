all: parser.so

parser.cfg.o : parser.cfg.cpp
	clang++ -std=c++11 -fPIC -IModel $< -o $@

func.o : func.c
	clang -fPIC $< -o $@

parser.so : parser.cfg.o lex.cfg.lexsave parser.cfg.lrsave
	clang++ parser.cfg.o func.o -Wl,--format=binary -Wl,lex.cfg.lexsave -Wl,parser.cfg.lrsave -Wl,--format=default -shared -o parser.so
