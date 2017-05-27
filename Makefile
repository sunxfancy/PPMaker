all:
	-mkdir build
	-cd build && conan install .. --build=missing && cmake .. && make

maker:
	-cd build && make maker

run:
	-./bin/maker ./Config/lex.cfg ./Config/parser.cfg
	-cd Config/ && make

run-json:
	-./bin/maker ./JSONConfig/lex.cfg ./JSONConfig/parser.cfg


.PHONY: all maker run
