all:
	-mkdir build
	-cd build && cmake .. && make

maker:
	-cd build && make maker

.PHONY: all maker
