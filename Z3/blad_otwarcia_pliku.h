#ifndef BLAD_OTWARCIA_PLIKU_H
#define BLAD_OTWARCIA_PLIKU_H

#include "blad.h"

/*!
Klasa bledu otwarcia pliku. Wywolywana w momencie wystapienia bledu przy probie tworzenia lub otwierania istniejacego juz pliku.
*/
class BladOtwarciaPliku : public Blad{
private:
	char* komunikat;
public:
	BladOtwarciaPliku(const char*nazwa){
		const char*format="Blad otwarcia pliku %s";
		komunikat=new char[strlen(format)+strlen(nazwa)-1];
		sprintf(komunikat,format,nazwa);
	}
	const char* opis()const{
		return komunikat;
	}
	~BladOtwarciaPliku(){
		delete[]komunikat;
	}
};

#endif
