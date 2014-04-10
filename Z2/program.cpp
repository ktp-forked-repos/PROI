#include <iostream>
#include <complex>
#include "fourier.h"
#include "fourier2.h"

using namespace std;

int main(void){
	double tab_a[5]={1,70,25,79,59}, tab_b[5]={28,37,92,5,3}, t=2.5, c=3;
	
	/**/
	fourier<double,5> numer1(tab_a, tab_b, c, t);
	fourier<double,5> kopia_numer1(numer1);
	fourier<double,5> numer2;
	cin >> numer2;
	cout << "NUMER1" << endl << numer1 << endl;
	cout << "NUMER2" << endl << numer2 << endl;
	cout << "KOPIA_NUMER1" << endl << kopia_numer1 << endl;
	cout << "SUMA: NUMER1 + NUMER2" << endl << numer1+numer2 << endl;
	cout << "ROZNICA: NUMER1 - NUMER2" << endl << numer1-numer2 << endl;
	cout << "ILOCZYN_P" << endl << numer1*7 << endl;
	cout << "ILOCZYN_L" << endl << -7*numer1 << endl;
	cout << "Funkcja numer1 dla x=3,5 /funkcja/: " << numer1.funkcja(3.5) << endl;
	cout << "Funkcja numer1 dla x=3,5 /operator/: " << numer1(3.5) << endl;
	cout << "a3 z numer1: " << numer1[3].a << endl << "b3 z numer1: " << numer1[3].b << endl;
	/**/
	
	/**/
	fourier2<double> numer02(tab_a, tab_b, 5, c, t);
	cout << numer02;
	fourier2<double> numer12=numer02;
	cin >> numer12;
	cout << numer12;
	fourier2<double> kopia_numer12(numer12);
	fourier2<double> numer22;
	cin >> numer22;
	cout << numer22;
	cout << "NUMER1" << endl << numer12 << endl;
	cout << "NUMER2" << endl << numer22 << endl;
	cout << "KOPIA_NUMER1" << endl << kopia_numer12 << endl;
	cout << "SUMA: NUMER1 + NUMER2" << endl << numer12+numer22 << endl;
	cout << "ROZNICA: NUMER1 - NUMER2" << endl << numer12-numer22 << endl;
	cout << "ILOCZYN_P" << endl << numer12*7 << endl;
	cout << "ILOCZYN_L" << endl << -7*numer12 << endl;
	cout << "Funkcja numer12 dla x=3,5 /funkcja/: " << numer12.funkcja(3.5) << endl;
	cout << "Funkcja numer12 dla x=3,5 /operator/: " << numer12(3.5) << endl;
	cout << "a3 z numer12: " << numer12[3].a << endl << "b3 z numer12: " << numer12[3].b << endl;
	/**/
	
	/**/
	complex<double> complex_tab_a[4]={complex<double>(1.2,3.0), complex<double>(1,2), complex<double>(0,0.2), complex<double>(1,3.2)};
	complex<double>	complex_tab_b[4]={1.2, complex<double>(3.2,4.5), complex<double>(100,0.3), complex<double>(0.2,1.3)};
	complex<double> complex_c=complex<double>(2.3,1.3);
	complex<double>	complex_t=2.3;
	fourier2<complex<double> > numer03(complex_tab_a, complex_tab_b, 4, complex_c, complex_t);
	cout << numer03;
	fourier2<complex<double> > numer13;
	cin >> numer13;
	cout << numer13;
	fourier2<complex<double> > kopia_numer13(numer13);
	fourier2<complex<double> > numer23;
	cin >> numer23;
	cout << numer23;
	cout << "NUMER1" << endl << numer13 << endl;
	cout << "NUMER2" << endl << numer23 << endl;
	cout << "KOPIA_NUMER1" << endl << kopia_numer13 << endl;
	cout << "SUMA: NUMER1 + NUMER2" << endl << numer13+numer23 << endl;
	cout << "ROZNICA: NUMER1 - NUMER2" << endl << numer13-numer23 << endl;
	cout << "ILOCZYN_P" << endl << numer13*7 << endl;
	cout << "ILOCZYN_L" << endl << -7*numer13 << endl;
	cout << "Funkcja numer13 dla x=3,5 /funkcja/: " << numer13.funkcja(3.5) << endl;
	cout << "Funkcja numer13 dla x=3,5 /operator/: " << numer13(3.5) << endl;
	cout << "a3 z numer13: " << numer13[3].a << endl << "b3 z numer12: " << numer13[3].b << endl;
	/**/
		
	return 0;
}
