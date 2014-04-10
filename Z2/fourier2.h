#include <cmath>
#include <complex>
#include <iostream>
#include <assert.h>

/*
TODO:
*/

template <class TYP>
class fourier2{
private:
	TYP *tab_a, *tab_b, c, t;
	int ile;
	struct para{
		TYP a,b;
	};
public:
	fourier2(); 
	fourier2(const fourier2 &x);
	fourier2(TYP itab_a[], TYP itab_b[], int iile, TYP ic, TYP it); 
	~fourier2();
	TYP funkcja(TYP x); /*oblicza rozwiniecie szeregu dla zadanego x*/
	struct para operator[](int x); /*zwraca pare wsp (a,b) dla danego x*/
	TYP operator()(TYP x); /*operator zwraca pare wsp (a,b) dla danego x*/
	fourier2& operator=(const fourier2<TYP> &x);
	
	friend fourier2 operator+(const fourier2<TYP> &x, const fourier2<TYP> &y){ /*fourier2+fourier2->fourier2*/
		assert(x.t==y.t);
		fourier2<TYP> suma;
		if(x.ile==0 && y.ile==0){
			suma.tab_a=NULL;
			suma.tab_b=NULL;
		}
		else{
			int i=0, ile_min=0, ile_max=0;
			if(x.ile>=y.ile){
				ile_min=y.ile;
				ile_max=x.ile;
			}
			else{
				ile_min=x.ile;
				ile_max=y.ile;
			}
			suma.ile=ile_max;
			suma.tab_a = new TYP[suma.ile];
			suma.tab_b = new TYP[suma.ile];
			for(i=0;i<ile_min;i++){suma.tab_a[i]=x.tab_a[i]+y.tab_a[i]; suma.tab_b[i]=x.tab_b[i]+y.tab_b[i];}
			for(i=ile_min;i<x.ile;i++) {suma.tab_a[i]=x.tab_a[i]; suma.tab_b[i]=x.tab_b[i];}
			for(i=ile_min;i<y.ile;i++) {suma.tab_a[i]=y.tab_a[i]; suma.tab_b[i]=y.tab_b[i];}
		}
		suma.c=x.c+y.c;
		suma.t=x.t;
		return suma;
	}
	
	friend fourier2 operator-(const fourier2<TYP> &x, const fourier2<TYP> &y){ /*fourier2-fourier2->fourier2*/ 
		assert(x.t==y.t);
		fourier2<TYP> roznica;
		if(x.ile==0 && y.ile==0){
			roznica.tab_a=NULL;
			roznica.tab_b=NULL;
		}
		else{
			int i=0, ile_min=0, ile_max=0;
			if(x.ile>=y.ile){
				ile_min=y.ile;
				ile_max=x.ile;
			}
			else{
				ile_min=x.ile;
				ile_max=y.ile;
			}
			roznica.ile=ile_max;
			roznica.tab_a = new TYP[roznica.ile];
			roznica.tab_b = new TYP[roznica.ile];
			for(i=0;i<ile_min;i++){roznica.tab_a[i]=x.tab_a[i]-y.tab_a[i]; roznica.tab_b[i]=x.tab_b[i]-y.tab_b[i];}
			for(i=ile_min;i<x.ile;i++) {roznica.tab_a[i]=x.tab_a[i]; roznica.tab_b[i]=x.tab_b[i];}
			for(i=ile_min;i<y.ile;i++) {roznica.tab_a[i]=-y.tab_a[i]; roznica.tab_b[i]=-y.tab_b[i];}
		}
		roznica.c=x.c-y.c;
		roznica.t=x.t;
		return roznica;
	}
	 
	friend fourier2 operator*(const fourier2<TYP> &x, double y){ /*fourier2*double->fourier2*/	
		int i=0;
		fourier2<TYP> iloczyn;
		iloczyn.ile=x.ile;
		
		if(x.ile!=0){
			iloczyn.tab_a = new TYP[iloczyn.ile];
			iloczyn.tab_b = new TYP[iloczyn.ile];
			for(i=0; i<iloczyn.ile;i++){
				iloczyn.tab_a[i]=y*(x.tab_a[i]);
				iloczyn.tab_b[i]=y*(x.tab_b[i]);
			}
		}
		else{
			iloczyn.tab_a=NULL;
			iloczyn.tab_b=NULL;
		}
		
		iloczyn.c=y*x.c;
		iloczyn.t=x.t;
		return iloczyn;
	}
		
	friend fourier2 operator*(double x, const fourier2<TYP> &y){ /*double*fourier2->fourier2*/
		int i=0;
		fourier2<TYP> iloczyn;
		iloczyn.ile=y.ile;
		
		if(y.ile!=0){
			iloczyn.tab_a = new TYP[iloczyn.ile];
			iloczyn.tab_b = new TYP[iloczyn.ile];
			for(i=0; i<iloczyn.ile;i++){
				iloczyn.tab_a[i]=x*(y.tab_a[i]);
				iloczyn.tab_b[i]=x*(y.tab_b[i]);
			}
		}
		else{
			iloczyn.tab_a=NULL;
			iloczyn.tab_b=NULL;
		}
		
		iloczyn.c=x*y.c;
		iloczyn.t=y.t;
		return iloczyn;
	}	
		
	friend std::ostream& operator<< (std::ostream& ekran, const fourier2<TYP> &x){ /*wyprowadza strukture fourier2 na ekran */
		assert(x.ile!=0);
		int i=0;
		ekran << "Wartosci a: "; for(i=0;i<x.ile;i++){ekran << x.tab_a[i] << " ";} ekran << std::endl;
		ekran << "Wartosci b: "; for(i=0;i<x.ile;i++){ekran << x.tab_b[i] << " ";} ekran << std::endl;
		ekran << "Wartosc c: "; ekran << x.c; ekran << std::endl;
		ekran << "Wartosc t: "; ekran << x.t; ekran << std::endl;
		return ekran;
	}	
	
	friend std::istream& operator>>(std::istream& klawiatura, fourier2<TYP> &x){ /*wprowadza do struktury ze strumienia*/
		if(x.ile!=0){
			delete[] x.tab_a;
			delete[] x.tab_b;
			x.tab_a=NULL;
			x.tab_b=NULL;
			x.ile=0;
			x.c=0;
			x.t=0;
		}
		int i=0;
		std::cout << "Podaj ilosc elementow: ";
		klawiatura >> x.ile;
		assert(x.ile!=0);
		x.tab_a = new TYP[x.ile];
		x.tab_b = new TYP[x.ile];
		for(i=0;i<x.ile;i++){
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



template <class TYP> 
fourier2<TYP>::fourier2(){
	tab_a=NULL;
	tab_b=NULL;
	ile=0;
	c=0;
	t=0;
}

template <class TYP> 
fourier2<TYP>::fourier2(const fourier2<TYP> &x){
	int i=0;
	ile=x.ile;
	if(x.ile!=0){
		tab_a = new TYP[ile];
		tab_b = new TYP[ile];
		for(i=0; i<ile;i++){
			tab_a[i]=x.tab_a[i];
			tab_b[i]=x.tab_b[i];
		}
	}
	else{
		tab_a=NULL;
		tab_b=NULL;
	}
	t=x.t;
	c=x.c;
}

template <class TYP> 
fourier2<TYP>::fourier2(TYP itab_a[], TYP itab_b[], int iile, TYP ic, TYP it){
	ile=iile;
	if(iile==0){
		tab_a=NULL;
		tab_b=NULL;
	}
	else{
		int i=0;
		tab_a = new TYP[ile];
		tab_b = new TYP[ile];
		for(i=0;i<ile;i++){
			tab_a[i]=itab_a[i];
			tab_b[i]=itab_b[i];
		}
	}
	c=ic;
	t=ic;
}

template <class TYP> 
fourier2<TYP>::~fourier2(){
	delete[] tab_a;
	delete[] tab_b;
	tab_a=NULL;
	tab_b=NULL;
	ile=0;
	c=0;
	t=0;
}

template <class TYP> 
TYP fourier2<TYP>::funkcja(TYP x){
	assert(t!=0.0);
	int i=0;
	TYP wynik=c;
	for(i=0;i<ile;i++)
		wynik+=tab_a[i]*sin(2*M_PI*x/t)+tab_b[i]*cos(2*M_PI*x/t);
	return wynik;
}

template <class TYP> 
struct fourier2<TYP>::para fourier2<TYP>::operator[](int x){ 
	assert(x<=ile);
	para wynik;
	wynik.a=tab_a[x-1];
	wynik.b=tab_b[x-1];
	return wynik;
}

template <class TYP> 
TYP fourier2<TYP>::operator()(TYP x){ 
	return funkcja(x);
}

template <class TYP> 
fourier2<TYP>& fourier2<TYP>::operator=(const fourier2<TYP> &x){
	if(this != &x){
		delete[] tab_a;
		delete[] tab_b;
		tab_a=NULL;
		tab_b=NULL;
		ile=0;
		c=0;
		t=0;
		int i=0;
		ile=x.ile;
		if(x.ile!=0){
			tab_a = new TYP[ile];
			tab_b = new TYP[ile];
			for(i=0; i<ile;i++){
				tab_a[i]=x.tab_a[i];
				tab_b[i]=x.tab_b[i];
			}
		}
		else{
			tab_a=NULL;
			tab_b=NULL;
		}
	t=x.t;
	c=x.c;
	}
	return *this;
}
