#ifndef BLAD_TRACE_H
#define BLAD_TRACE_H

#include "blad.h"

/*!
Klasa bledu rozmiaru przy liczeniu sladu macierzy. Wywolywana w momencie liczenia sladu macierzy niekwadratowej.
*/
class BladTrace : public Blad{
private:
	char* komunikat;
public:
	BladTrace(int r, int c){
		const char*format="Nie mozna obliczyc sladu macierzy niekwadratowej %dx%d";
		komunikat=new char[strlen(format)-1];
		sprintf(komunikat,format,r,c);
	}	
	const char* opis()const{
		return komunikat;
	}	
	~BladTrace(){
		delete[]komunikat;
	}
};

#endif
