#ifndef BLAD_H
#define BLAD_H
/*!
Klasa bazowa obslugi bledow.
*/
class Blad{
public:
	virtual const char* opis()const=0;
	virtual ~Blad(){
	}
};

#endif
