all: libparser.so

parser.cfg.o : parser.cfg.cpp
	clang++ -std=c++11 -fPIC -IModel -c $< -o $@

func.o : func.c
	clang -std=c11 -fPIC -c $< -o $@

libparser.so : parser.cfg.o func.o lex.cfg.lexsave parser.cfg.lrsave
	clang++ parser.cfg.o func.o -Wl,--format=binary -Wl,lex.cfg.lexsave -Wl,parser.cfg.lrsave -Wl,--format=default -shared -o libparser.so

clean:
	-rm -rf parser.cfg.o func.o parser.so
.PHONY: clean
