#Piotr Jastrzêbski 2I1

CXX=g++
CXXFLAGS=-Wall -pedantic

zad3: main.o spare_vector.o normal_vector.o c_spare_matrix.o normal_matrix.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	
main.o: main.cpp spare_vector.h normal_vector.h normal_matrix.h c_spare_matrix.h blad_otwarcia_pliku.h blad_rozmiaru.h
	$(CXX) $(CXXFLAGS) -c -o $@ main.cpp
	
spare_vector.o: spare_vector.cpp spare_vector.h normal_vector.h blad_otwarcia_pliku.h blad_rozmiaru.h
	$(CXX) $(CXXFLAGS) -c -o $@ spare_vector.cpp
	
normal_vector.o: normal_vector.cpp normal_vector.h spare_vector.h normal_matrix.h blad_otwarcia_pliku.h blad_rozmiaru.h
	$(CXX) $(CXXFLAGS) -c -o $@ normal_vector.cpp 

normal_matrix.o: normal_matrix.cpp normal_matrix.h c_spare_matrix.h blad_otwarcia_pliku.h blad_rozmiaru.h blad_trace.h
	$(CXX) $(CXXFLAGS) -c -o $@ normal_matrix.cpp

c_spare_matrix.o: c_spare_matrix.cpp c_spare_matrix.h blad_otwarcia_pliku.h blad_rozmiaru.h blad_trace.h
	$(CXX) $(CXXFLAGS) -c -o $@ c_spare_matrix.cpp
	
.PHONY:
	clean all

all:	zad3

clean:
#	rm -f *.o zad3 core
	del *.o zad3.exe

