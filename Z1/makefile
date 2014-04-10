#Piotr Jastrzêbski 2I1

CXX=g++
CXXFLAGS=-Wall -ansi -pedantic


zad1: program.o fourier.o
	$(CXX) $(CXXFLAGS) $^ -o $@; 
	
program.o: program.cpp fourier.h
	$(CXX) $(CXXFLAGS) program.cpp -c -o $@

fourier.o: fourier.cpp fourier.h
	$(CXX) $(CXXFLAGS) fourier.cpp -c -o $@

.PHONY:
	all clean

clean:
	rm -f *.o zad1

