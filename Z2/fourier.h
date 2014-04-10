#include <cmath>
#include <complex>
#include <iostream>
#include <assert.h>

/*
TODO:
- dodwanie 2 obiektow o roznej liczbie wsp a i b
*/

template <class TYP, int NMAX>
class fourier{
private:
	TYP tab_a[NMAX], tab_b[NMAX], c, t;
	struct para{
		TYP a,b;
	};
public:
	fourier(); 
	fourier(const fourier &x); 
	fourier(TYP tablica_a[NMAX], TYP tablica_b[NMAX], TYP zmienna_c, TYP zmienna_t); 
	TYP funkcja(TYP x); /*oblicza rozwiniecie szeregu dla zadanego x*/	
	struct para operator[](int x); /*zwraca pare wsp (a,b) dla danego x*/
	TYP operator()(TYP x); /*operator zwraca pare wsp (a,b) dla danego x*/
	
	friend fourier operator+(const fourier<TYP, NMAX> &x, const fourier<TYP, NMAX> &y){ /*fourier+fourier->fourier*/
		assert(x.t==y.t);
		fourier<TYP, NMAX> suma;
		int i=0;
		for(i=0;i<NMAX;i++){
			suma.tab_a[i]=x.tab_a[i]+y.tab_a[i];
			suma.tab_b[i]=x.tab_b[i]+y.tab_b[i];
		}
		suma.c=x.c+y.c;
		suma.t=x.t;
		return suma;
	}
	
	friend fourier operator-(const fourier<TYP, NMAX> &x, const fourier<TYP, NMAX> &y){ /*fourier-fourier->fourier*/ 
		assert(x.t==y.t);
		fourier<TYP, NMAX> roznica;
		int i=0;
		for(i=0; i<NMAX;i++){
			roznica.tab_a[i]=x.tab_a[i]-y.tab_a[i];
			roznica.tab_b[i]=x.tab_b[i]-y.tab_b[i];
		}
		roznica.c=x.c-y.c;
		roznica.t=x.t;
		return roznica;
	}
	 
	friend fourier operator*(const fourier<TYP, NMAX> &x, double y){ /*fourier*double->fourier*/	
		fourier<TYP, NMAX> iloczyn;
		int i=0;
		for(i=0;i<NMAX;i++){
			iloczyn.tab_a[i]=y*x.tab_a[i];
			iloczyn.tab_b[i]=y*x.tab_b[i];
		}
		iloczyn.c=y*x.c;
		iloczyn.t=x.t;
		return iloczyn;
	}
		
	friend fourier operator*(double x, const fourier<TYP, NMAX> &y){ /*double*fourier->fourier*/
		fourier<TYP, NMAX> iloczyn;
		int i=0;
		for(i=0;i<NMAX;i++){
			iloczyn.tab_a[i]=x*y.tab_a[i];
			iloczyn.tab_b[i]=x*y.tab_b[i];
		}
		iloczyn.c=x*y.c;
		iloczyn.t=y.t;
		return iloczyn;
	}	
		
	friend std::ostream& operator<< (std::ostream& ekran, const fourier<TYP, NMAX> &x){ /*wyprowadza strukture fourier na ekran */
		int i=0;
		ekran << "Wartosci a: "; for(i=0;i<NMAX;i++) ekran << x.tab_a[i] << " "; ekran << std::endl;
		ekran << "Wartosci b: "; for(i=0;i<NMAX;i++) ekran << x.tab_b[i] << " "; ekran << std::endl;
		ekran << "Wartosc c: "; ekran << x.c; ekran << std::endl;
		ekran << "Wartosc t: "; ekran << x.t; ekran << std::endl;
		return ekran;
	}	
	
	friend std::istream& operator>>(std::istream& klawiatura, fourier<TYP, NMAX> &x){ /*wprowadza do struktury ze strumienia*/
		int i=0;
		for(i=0;i<NMAX;i++){
			std::cout << "Podaj pare (a b) wspolczynnikow z indeksem " << i+1 << ": ";
			klawiatura >> x.tab_a[i] >> x.tab_b[i];
		}
		std::cout << "Podaj wartosc wspolczynnika c: ";
		klawiatura >> x.c;
		std::cout << "Podaj wartosc okresu t: ";
		klawiatura >> x.t;
		return klawiatura;
	}
};



template <class TYP, int NMAX> 
fourier<TYP, NMAX>::fourier(){ 
	int i=0;
	for(i=0;i<NMAX;i++){
		tab_a[i]=0;
		tab_b[i]=0;
	}
	c=0;
	t=0;
}

template <class TYP, int NMAX> 
fourier<TYP, NMAX>::fourier(const fourier<TYP, NMAX> &x){ 
	int i=0;
	for(i=0;i<NMAX;i++){
		tab_a[i]=x.tab_a[i];
		tab_b[i]=x.tab_b[i];
	}
	t=x.t;
	c=x.c;
}

template <class TYP, int NMAX>
fourier<TYP, NMAX>::fourier(TYP tablica_a[NMAX], TYP tablica_b[NMAX], TYP zmienna_c, TYP zmienna_t){ 
	int i=0;
	for(i=0;i<NMAX;i++){
		tab_a[i]=tablica_a[i];
		tab_b[i]=tablica_b[i];
	}
	c=zmienna_c;
	t=zmienna_t;
}

template <class TYP, int NMAX> 
TYP fourier<TYP, NMAX>::funkcja(TYP x){ 
	assert(t!=0.0);
	int i=0;
	TYP wynik=c;
	for(i=0;i<NMAX;i++)
		wynik+=tab_a[i]*sin(2*M_PI*x/t)+tab_b[i]*cos(2*M_PI*x/t);
	return wynik;
}

template <class TYP, int NMAX> 
struct fourier<TYP, NMAX>::para fourier<TYP, NMAX>::operator[](int x){ 
	assert(x<=NMAX);
	para wynik;
	wynik.a=tab_a[x-1];
	wynik.b=tab_b[x-1];
	return wynik;
}

template <class TYP, int NMAX> 
TYP fourier<TYP, NMAX>::operator()(TYP x){ 
	return funkcja(x);
}
