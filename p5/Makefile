CXXFLAGS= -ansi -Wall -Werror -pedantic

all: huffman.o p5.o
	g++-4.9 huffman.o p5.o -o p5
huffman.o: HuffmanTree.cpp
	g++-4.9 $(CXXFLAGS) -c HuffmanTree.cpp -o huffman.o
p5.o: p5.cpp
	g++-4.9 $(CXXFLAGS) -c p5.cpp -o p5.o
default:
	all

clean:
	rm -f *.o
	rm -f p5
