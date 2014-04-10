#Piotr Jastrzêbski 2I1

CXX=g++
CXXFLAGS=-Wall -g -pedantic

zad2: program.o 
	$(CXX) $(CXXFLAGS) $^ -o $@
	
program.o: program.cpp fourier.h fourier2.h
	$(CXX) $(CXXFLAGS) program.cpp -c -o $@

.PHONY:
	clean

clean:
	rm -f *.o zad2

