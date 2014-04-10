#ifndef BLAD_ROZMIARU_H
#define BLAD_ROZMIARU_H

#include "blad.h"

/*!
Klasa bledu rozmiaru. Wywolywana w momencie mnozenia lub dodawania macierzy o zlych rozmiarach, mnozenia wektora przez nieodpowiednia macierz lub dodawania roznych rozmiarem wektorow. Rowniez w przypadku liczenia sladu macierzy niekwadratowej.
*/
class BladRozmiaru : public Blad{
private:
	char* komunikat;
public:
	BladRozmiaru(){
		const char*format="Jeden z podanych rozmiarow wektora lub macierzy uniemozliwia wykonanie zadanego dzialania!";
		komunikat=new char[strlen(format)-1];
		sprintf(komunikat,format);
	}	
	const char* opis()const{
		return komunikat;
	}	
	~BladRozmiaru(){
		delete[]komunikat;
	}
};

#endif
