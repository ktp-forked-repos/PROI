#ifndef NORMAL_VECTOR_H
#define NORMAL_VECTOR_H

#include <vector>
#include <iostream>
#include <fstream>
#include "spare_vector.h"
#include "normal_matrix.h"
#include "blad_otwarcia_pliku.h"
#include "blad_rozmiaru.h"
#define N 20

using namespace std;

class normal_matrix;
class c_spare_matrix;

/*!
Klasa wektora pelnego.
Definiuje element skladowy wektora jako wektor tablicowy wartosci.
Obejmuje dodawanie wektorow tego samego lub roznego typu. Umozliwia odczyt i zapis wektora do pliku, jak rowniez wypisanie na ekran.
*/
class normal_vector{
private:
	vector<double> val;
	friend class spare_vector;
	friend class normal_matrix;
	
public:
/*!
Dodawanie dwoch wektorow pelnych.
Wynikiem jest wektor pelny.
*/
	normal_vector operator+(const normal_vector &v2) const;
	
	
/*!
Dodawanie dwoch wektorow: normalnego i rzadkiego.
Wynikiem jest wektor pelny.
*/
	friend normal_vector operator+(const normal_vector &v1, const spare_vector &v2);
	
	
/*!
Dodawanie dwoch wektorow: rzadkiego i normalnego.
Wynikiem jest wektor pelny.
*/
	friend normal_vector operator+(const spare_vector &v1, const normal_vector &v2);

	
/*!
Mnozenie wektora pelnego i macierzy pelnej.
Wynikiem jest wektor pelny.
*/
	friend normal_vector operator*(const normal_vector &v, const normal_matrix &m);

	
/*!
Mnozenie wektora pelnego i macierzy rzadkiej typu C.
Wynikiem jest wektor pelny.
*/
	friend normal_vector operator*(const normal_vector &v, const c_spare_matrix &m);

	
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

	
/*!
Odczyt z pliku wektora pelnego.
Maksymalny rozmiar nazwy wraz z rozszerzeniem - 20 znakow.\n\n
Struktura pliku:\n\n
<tt>wartosc_0\n wartosc_1\n wartosc_2\n ...\n wartosc_x\n</tt>
*/	
	friend void load_nv(normal_vector &v1, char name[N]);
	
	
/*!
Zapis do pliku wektora pelnego.
Maksymalny rozmiar nazwy wraz z rozszerzeniem - 20 znakow.\n\n
Struktura pliku:\n\n
<tt>wartosc_0\n wartosc_1\n wartosc_2\n ...\n wartosc_x\n</tt>
*/
	friend void save_nv(const normal_vector &v1, char name[N]);

	
/*!
Wyprowadzenie obiektu typu wektor rzadki na ekran w postaci przyjaznej uzytkownikowi.\n
Efekt dzialania: <tt>0 0 0 1 0 0 2 0 0 0</tt>
*/
	friend ostream& operator<< (ostream& ekran, const normal_vector &v1);


/*!
Transpozycja macierzy pelnej.
*/	
	friend void transpose_nm(normal_matrix &m1);
	
	
/*!
Odczyt z pliku macierzy pelnej.
Maksymalny rozmiar nazwy wraz z rozszerzeniem - 20 znakow.\n\n
Struktura pliku:\n\n
<tt>wartosc_00 wartosc_01 wartosc_02 ... wartosc_0x\n
wartosc_10 wartosc_11 wartosc_12 ... wartosc_1x\n
...\n
wartosc_x0 wartosc_x1 wartosc_x2 ... wartosc_xx\n
</tt>
*/
	friend void load_nm(normal_matrix &m1, char name[N]);
	
	
/*!
Zapis do pliku macierzy pelnej.
Maksymalny rozmiar nazwy wraz z rozszerzeniem - 20 znakow.\n\n
Struktura pliku:\n\n
<tt>wartosc_00 wartosc_01 wartosc_02 ... wartosc_0x\n
wartosc_10 wartosc_11 wartosc_12 ... wartosc_1x\n
...\n
wartosc_x0 wartosc_x1 wartosc_x2 ... wartosc_xx\n
</tt>
*/
	friend void save_nm(const normal_matrix &m1, char name[N]);
	
	
/*!
Liczenie sladu macierzy pelnej.
Wynikiem jest liczba typu double.
*/
	friend double trace_nm(const normal_matrix &m1);
	
	
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
