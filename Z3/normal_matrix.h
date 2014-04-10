#ifndef NORMAL_MATRIX_H
#define NORMAL_MATRIX_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "normal_vector.h"
#include "c_spare_matrix.h"
#include "blad_otwarcia_pliku.h"
#include "blad_rozmiaru.h"
#include "blad_trace.h"
#define N 20

using namespace std;

/*!
Klasa macierzy pelnej.
Definiuje element skladowy macierzy jako wektor wektorow pelnych.
Obejmuje dodawanie macierzy tego samego typu. Narazie nieumozliwia odczytu i zapisu macierzy do pliku, jak rowniez wypisanie na ekran. Wykonuje transpozycje macierzy, ale nie liczy jej sladu.
*/
class normal_matrix{
private:
	vector<class normal_vector> r;

public:
/*!
Dodawanie dwoch macierzy pelnych.
Wynikiem jest macierz pelna.
*/
	normal_matrix operator+(const normal_matrix &m1) const;
	
	
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
	
	
/*!
Mnozenie dwoch macierzy pelnych.
Wynikiem jest macierz pelna.
*/
	normal_matrix operator*(const normal_matrix &m2) const;
	
	
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
Liczenie sladu macierzy pelnej.
Wynikiem jest liczba typu double.
*/
	friend double trace_nm(const normal_matrix &m1);
	
	
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
Wyprowadzenie obiektu typu macierz pelna na ekran w postaci przyjaznej uzytkownikowi.\n
Efekt dzialania:\n
<tt>0 0 0\n
1 0 0\n
2 0 0</tt>
*/
	friend ostream& operator<< (ostream& ekran, const normal_matrix &m1);
	

/*!
Mnozenie wektora pelnego i macierzy pelnej.
Wynikiem jest wektor pelny.
*/
	friend normal_vector operator*(const normal_vector &v, const normal_matrix &m);
	

/*!
Mnozenie wektora rzadkiego i macierzy pelnej.
Wynikiem jest wektor pelny.
*/
	friend normal_vector operator*(const spare_vector &v, const normal_matrix &m);
};

#endif
