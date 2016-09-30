all:
	-mkdir build
	-cd build && cmake .. && make

maker:
	-cd build && make maker

run:
	-./bin/maker ./Config/lex.cfg ./Config/parser.cfg

.PHONY: all maker run
