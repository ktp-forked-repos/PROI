#include <cmath>
#include <iostream>
#include <assert.h>
#include "fourier.h"

using namespace std;

fourier::fourier(double tablica_a[NMAX], double tablica_b[NMAX], double zmienna_c, double zmienna_t, int zmienna_ile){ 
	int i=0;
	for(i=0;i<zmienna_ile;i++){
		tab_a[i]=tablica_a[i];
		tab_b[i]=tablica_b[i];
	}
	c=zmienna_c;
	t=zmienna_t;
	ile=zmienna_ile;	
}

fourier::fourier(){ 
	int i=0;
	for(i=0;i<NMAX;i++){
		tab_a[i]=0.0;
		tab_b[i]=0.0;
	}
	c=0.0;
	t=0.0;
	ile=0;
}

fourier::fourier(const fourier &x){ 
	int i=0;
	for(i=0;i<x.ile;i++){
		tab_a[i]=x.tab_a[i];
		tab_b[i]=x.tab_b[i];
	}
	t=x.t;
	c=x.c;
	ile=x.ile;
}

fourier operator+(const fourier &x, const fourier &y){ /*fourier+fourier->fourier*/
	fourier suma;
	assert(x.t==y.t);
	int i=0, ile_min=0, ile_max=0;
	if(x.ile>=y.ile){
		ile_min=y.ile;
		ile_max=x.ile;
	}
	else{
		ile_min=x.ile;
		ile_max=y.ile;
	}
	
	for(i=0;i<ile_min;i++){
		suma.tab_a[i]=x.tab_a[i]+y.tab_a[i];
		suma.tab_b[i]=x.tab_b[i]+y.tab_b[i];
	}
	
	for(i=ile_min;i<x.ile;i++) {suma.tab_a[i]=x.tab_a[i]; suma.tab_b[i]=x.tab_b[i];}
	for(i=ile_min;i<y.ile;i++) {suma.tab_a[i]=y.tab_a[i]; suma.tab_b[i]=y.tab_b[i];}
	
	suma.c=x.c+y.c;
	suma.t=x.t;
	suma.ile=ile_max;
	return suma;
}

fourier operator-(const fourier &x, const fourier &y){ /*fourier-fourier->fourier*/
	fourier roznica;
	assert(x.t==y.t);
	int i=0, ile_min=0, ile_max=0;
	if(x.ile>=y.ile){
		ile_min=y.ile;
		ile_max=x.ile;
	}
	else{
		ile_min=x.ile;
		ile_max=y.ile;
	}
	
	for(i=0;i<ile_min;i++){
		roznica.tab_a[i]=x.tab_a[i]-y.tab_a[i];
		roznica.tab_b[i]=x.tab_b[i]-y.tab_b[i];
	}
	
	for(i=ile_min;i<x.ile;i++) {roznica.tab_a[i]=x.tab_a[i]; roznica.tab_b[i]=x.tab_b[i];}
	for(i=ile_min;i<y.ile;i++) {roznica.tab_a[i]=-y.tab_a[i]; roznica.tab_b[i]=-y.tab_b[i];}
		
	roznica.c=x.c-y.c;
	roznica.t=x.t;
	roznica.ile=ile_max;
	return roznica;
}

fourier operator*(const fourier &x, double y){ /*fourier*double->fourier*/
	fourier iloczyn;
	int i=0;
	for(i=0;i<x.ile;i++){
		iloczyn.tab_a[i]=y*x.tab_a[i];
		iloczyn.tab_b[i]=y*x.tab_b[i];
	}
	iloczyn.c=y*x.c;
	iloczyn.t=x.t;
	iloczyn.ile=x.ile;
	return iloczyn;
}

fourier operator*(double x, const fourier &y){ /*double*fourier->fourier*/
	fourier iloczyn;
	int i=0;
	for(i=0;i<y.ile;i++){
		iloczyn.tab_a[i]=x*y.tab_a[i];
		iloczyn.tab_b[i]=x*y.tab_b[i];
	}
	iloczyn.c=x*y.c;
	iloczyn.t=y.t;
	iloczyn.ile=y.ile;
	return iloczyn;
}

fourier::para fourier::operator[](int x){ /*zwraca pare wsp. dla zadanego iteratora*/
	para wynik;
	assert(x<=ile);
	wynik.a=tab_a[x-1];
	wynik.b=tab_b[x-1];
	return wynik;
}

ostream& operator<<(ostream& ekran, const fourier &x){ /*wypisuje fouriera << */
	int i=0;
	ekran << "Wartosci a: "; for(i=0;i<x.ile;i++) ekran << x.tab_a[i] << " "; ekran << endl;
	ekran << "Wartosci b: "; for(i=0;i<x.ile;i++) ekran << x.tab_b[i] << " "; ekran << endl;
	ekran << "Wartosc c: "; ekran << x.c; ekran << endl;
	ekran << "Wartosc t: "; ekran << x.t; ekran << endl;
	return ekran;
}

istream& operator>>(istream& klawiatura, fourier &x){ /*czyta fouriera >>*/
	cout << "Podaj ilosc wspolczynnikow: ";
	cin >> x.ile;
	assert(x.ile>0);
	int i=0;
	for(i=0;i<x.ile;i++){
		cout << "Podaj pare (a b) wspolczynnikow z indeksem " << i+1 << ": ";
		klawiatura >> x.tab_a[i] >> x.tab_b[i];
	}
	cout << "Podaj wartosc wspolczynnika c: ";
	klawiatura >> x.c;
	cout << "Podaj wartosc okresu t: ";
	klawiatura >> x.t;
	return klawiatura;
}

double fourier::funkcja(double x){ /* funkcja liczy wartosc rozwiniecia dla zadanego x*/
	int i=0;
	double wynik=c;
	for(i=0;i<ile;i++) wynik+=tab_a[i]*sin(2*M_PI*x/t)+tab_b[i]*cos(2*M_PI*x/t);
	return wynik;
}
