#include <iostream>
#include "fourier.h"

int main(void){
	double tab_a[NMAX]={1,70,25,79,59,63,65,6,46,82}, tab_b[NMAX]={28,62,92,96,43,28,37,92,5,3}, t=2.5, c=3;
	int ile=10;
	fourier numer1(tab_a, tab_b, c, t, ile);
	fourier kopia_numer1(numer1);
	fourier numer2;
	cin >> numer2;
	
	cout << "NUMER1" << endl << numer1 << endl;
	cout << "NUMER2" << endl << numer2 << endl;
	cout << "KOPIA_NUMER1" << endl << kopia_numer1 << endl;
	cout << "SUMA: NUMER1 + NUMER2" << endl << numer1+numer2 << endl;
	cout << "ROZNICA: NUMER1 - NUMER2" << endl << numer1-numer2 << endl;
	cout << "ILOCZYN_P" << endl << numer1*7 << endl;
	cout << "ILOCZYN_L" << endl << -7*numer1 << endl;
	cout << "Funkcja numer1 dla x=3,5: " << numer1.funkcja(3.5) << endl;
	cout << "a3 z numer1: " << numer1[3].a << endl << "b3 z numer1: " << numer1[3].b << endl;
	return 0;
}
