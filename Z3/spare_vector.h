/*!
\mainpage Biblioteka operacji na macierzach i wektorach rzadkich.
<b>Biblioteka umozliwia wykonywanie operacji na nastepujacych obiektach:</b>\n
:: wektor pelny\n
:: wektor rzadki\n
:: macierz pelna\n
:: macierz rzadka A (wiersze macierzy sa wektorami rzadkimi)\n
:: macierz rzadka B (kolumny macierzy sa wektorami rzadkimi)\n
:: macierz rzadka C (elementy niezerowe sa w liscie)\n\n

<b>Zdefiniowane operacje</b>:\n
:: dodawanie wektorow\n
:: dodawanie macierzy\n
:: mnozenie macierzy\n
:: mnozenie macierzy przez wektor\n
:: liczenie sladu macierzy\n
:: transpozycja macierzy\n
:: wprowadzanie i wyprowadzanie obiektu do pliku\n
\author Piotr Jastrzebski 2I1
*/

#ifndef SPARE_VECTOR_H
#define SPARE_VECTOR_H

#include <list>
#include <iostream>
#include <fstream>
#include "normal_vector.h"
#include "blad_otwarcia_pliku.h"
#include "blad_rozmiaru.h"
#define N 20

using namespace std;

class normal_matrix;
class c_spare_matrix;

/*!Klasa pomocnicza wektora rzadkiego. Najmniejsza skladowa wektora.
Przechowuje inormacje o pojedynczym elemencie wektora jako para wartosc-pozycja.
*/
struct le2{
	double val;/*!< Wartosc.*/
	int pos;/*!< Pozycja.\warning Elementy wektora numerowane sa od 0 do N-1, gdzie rozmiar wektora rowny jest N.*/
};

/*!
Klasa wektora rzadkiego.
Definiuje element skladowy wektora jako pare wartosc-pozycja.
Obejmuje dodawanie wektorow tego samego lub roznego typu. Umozliwia odczyt i zapis wektora do pliku, jak rowniez wypisanie na ekran.
*/
class spare_vector{
private:
	list<struct le2> element;
	friend class normal_vector;
	int max;
public:

/*!
Dodawanie dwoch wektorow rzadkich.
Wynikiem jest wektor rzadki.
*/
	spare_vector operator+(const spare_vector &v2) const;
	
	
/*!
Dodawanie dwoch wektorow: rzadkiego i normalnego.
Wynikiem jest wektor pelny.
*/
	friend normal_vector operator+(const normal_vector &v1, const spare_vector &v2);
	
	
/*!
Dodawanie dwoch wektorow: normalnego i rzadkiego.
Wynikiem jest wektor pelny.
*/
	friend normal_vector operator+(const spare_vector &v1, const normal_vector &v2);

	
/*!
Odczyt z pliku wektora rzadkiego.
Maksymalny rozmiar nazwy wraz z rozszerzeniem - 20 znakow.\n\n
Struktura pliku:\n\n
<tt>rozmiar_wektora\n
pozycja_elementu_1 wartosc_elementu_1\n
pozycja_elementu_2 wartosc_elementu_2\n
...\n
pozycja_elementu_x wartosc_elementu_x\n
</tt>
\warning Elementy wektora numerowane sa od 0 do N-1, gdzie rozmiar wektora rowny jest N. 
*/
	friend void load_sv(spare_vector &v1, char name[N]);
	
	
/*!
Zapis do pliku wektora rzadkiego.
Maksymalny rozmiar nazwy wraz z rozszerzeniem - 20 znakow.
Struktura pliku:\n\n
<tt>rozmiar_wektora\n
pozycja_elementu_1 wartosc_elementu_1\n
pozycja_elementu_2 wartosc_elementu_2\n
...\n
pozycja_elementu_x wartosc_elementu_x\n
</tt>
\warning Elementy wektora numerowane sa od 0 do N-1, gdzie rozmiar wektora rowny jest N. 
*/
	friend void save_sv(const spare_vector &v1, char name[N]);

	
/*!
Wyprowadzenie obiektu typu wektor rzadki na ekran w postaci przyjaznej uzytkownikowi.\n
Efekt dzialania: <tt>0 0 0 1 0 0 2 0 0 0</tt>
*/
	friend ostream& operator<< (std::ostream& ekran, const spare_vector &v1);


/*!
Mnozenie wektora rzadkiego i macierzy pelnej.
Wynikiem jest wektor pelny.
*/
	friend normal_vector operator*(const spare_vector &v, const normal_matrix &m);


/*!
Mnozenie wektora rzadkiego i macierzy rzadkiej typu C.
Wynikiem jest wektor pelny.
*/	
	friend normal_vector operator*(const spare_vector &v, const c_spare_matrix &m); 
};

#endif
