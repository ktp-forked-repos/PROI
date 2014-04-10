#ifndef C_SPARE_MATRIX_H
#define C_SPARE_MATRIX_H

#include <list>
#include <iostream>
#include <fstream>
#include "blad_otwarcia_pliku.h"
#include "blad_rozmiaru.h"
#include "blad_trace.h"
#define N 20

class spare_vector;

using namespace std;

/*!Klasa pomocnicza macierzy rzadkiej typu C.
Przechowuje inormacje o pojedynczym elemencie macierzy jako trzy wartosci: wartosc-rzad-kolumna.
*/
struct le{
	double val;/*!< Wartosc.*/
	int r; /*!< Rzad - wspolrzedna komorki w macierzy. \warning Rzedy macierzy numerowane sa od 0 do N-1, gdzie N jest iloscia wierszy. */
	int c; /*!< Kolumna - wspolrzedna komorki w macierzy.\warning Kolumny macierzy numerowane sa od 0 do N-1, gdzie N jest iloscia kolumn.*/
};

/*!
Klasa macierzy rzadkiej typu C.
Definiuje element skladowy macierzy jako trzy wartosci: wartosc-rzad-kolumna.
Obejmuje dodawanie macierzy tego samego typu. Umozliwia odczyt i zapis macierzy do pliku, jak rowniez wypisanie na ekran. Wykonuje transpozycje macierzy, jak rowniez liczy jej slad. Elementy skladowe macierzy przechowywane sa w liscie dwukierunkowej.
*/
class c_spare_matrix{
private:
	list<struct le> element;
	int rmax, cmax;
	friend class normal_matrix;
	friend class normal_vector;
public:
/*!
Dodawanie dwoch macierzy rzadkich typu C.
Wynikiem jest macierz rzadka.
*/
	c_spare_matrix operator+(const c_spare_matrix &m1) const;
	
	
/*!
Mnozenie dwoch macierzy rzadkich typu C.
Wynikiem jest macierz rzadka.
*/
	c_spare_matrix operator*(const c_spare_matrix &m1) const;
	
	
/*!
Liczenie sladu macierzy rzadkiej typu C.
Wynikiem jest liczba typu double.
*/
	friend double trace_c_sm(const c_spare_matrix &m1);
	
	
/*!
Transpozycja macierzy rzadkiej typu C.
*/
	friend void transpose_c_sm(c_spare_matrix &m1);
	
	
/*!
Zapis do pliku macierzy rzadkiej typu C.
Maksymalny rozmiar nazwy wraz z rozszerzeniem - 20 znakow.\n\n
Struktura pliku:\n\n
<tt>ilosc_rzedow_macierzy ilosc_kolumn_macierzy\n
numer_rzedu_1 numer_kolumny_1 wartos_komorki_1\n
numer_rzedu_2 numer_kolumny_2 wartos_komorki_2\n
...\n
numer_rzedu_x numer_kolumny_x wartos_komorki_x\n
</tt>
\warning Rzedy i kolumny macierzy numerowane sa od 0 do N-1, gdzie N jest iloscia wierszy lub kolumn. 
*/
	friend void load_c_sm(c_spare_matrix &m1, char name[N]);
	
	
/*!
Odczyt z pliku macierzy rzadkiej typu C.
Maksymalny rozmiar nazwy wraz z rozszerzeniem - 20 znakow.\n\n
Struktura pliku:\n\n
<tt>ilosc_rzedow_macierzy ilosc_kolumn_macierzy\n
numer_rzedu_1 numer_kolumny_1 wartos_komorki_1\n
numer_rzedu_2 numer_kolumny_2 wartos_komorki_2\n
...\n
numer_rzedu_x numer_kolumny_x wartos_komorki_x\n
</tt>
\warning Rzedy i kolumny macierzy numerowane sa od 0 do N-1, gdzie N jest iloscia wierszy lub kolumn. 
*/	
	friend void save_c_sm(const c_spare_matrix &m1, char name[N]);

	
/*!
Wyprowadzenie obiektu typu macierz rzadka typu C na ekran w postaci przyjaznej uzytkownikowi.\n
Efekt dzialania:\n
<tt>0 0 0\n
1 0 0\n
2 0 0</tt>
*/
	friend ostream& operator<< (ostream& ekran, const c_spare_matrix &m1);
	
	
/*!
Mnozenie macierzy pelnej i macierzy rzadkiej typu C.
Wynikiem jest macierz pelna.
*/	
	friend normal_matrix operator*(const normal_matrix &m1, const c_spare_matrix &m2);
	
	
/*!
Mnozenie macierzy macierzy rzadkiej typu C i pelnej.
Wynikiem jest macierz pelna.
*/
	friend normal_matrix operator*(const c_spare_matrix &m1, const normal_matrix &m2);
	

/*!
Mnozenie wektora pelnego i macierzy rzadkiej typu C.
Wynikiem jest wektor pelny.
*/
	friend normal_vector operator*(const normal_vector &v, const c_spare_matrix &m);
	

/*!
Mnozenie wektora rzadkiego i macierzy rzadkiej typu C.
Wynikiem jest wektor pelny.
*/	
	friend normal_vector operator*(const spare_vector &v, const c_spare_matrix &m);
	

/*!
Dodawanie macierzy pelnej i rzadkiej.
Wynikiem jest macierz pelna.
*/	
	friend normal_matrix operator+(const normal_matrix &m1, const c_spare_matrix &m2);

	
/*!
Dodawanie macierzy rzadkiej i pelnej.
Wynikiem jest macierz pelna.
*/
	friend normal_matrix operator+(const c_spare_matrix &m1, const normal_matrix &m2);
};

#endif
