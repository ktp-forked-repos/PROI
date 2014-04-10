#include <iostream>
#include "normal_matrix.h"
#include "spare_vector.h"
#include "normal_vector.h"
// #include "a_spare_matrix.h"
// #include "b_spare_matrix.h"
#include "c_spare_matrix.h"


using namespace std;

int main(void){

try{
	//deklaracja obiektow
	spare_vector sv1, sv2;
	normal_vector nv1, nv2;
	normal_matrix nm1, nm2;
	c_spare_matrix cm1, cm2;
	
	//wczytanie z pliku
	load_sv(sv1, "ex/sv1.txt");
	load_sv(sv2, "ex/sv2.txt");
	load_nv(nv1, "ex/nv1.txt");
	load_nm(nm1, "ex/nm1.txt");
	load_c_sm(cm1, "ex/cm1.txt");	
	
	//dodawanie wektorow
	cout << "sv " << sv1 << endl;
	cout << "nv " << nv1 << endl;
	cout << "sv1+sv1 " << sv1+sv1 << endl;
	cout << "sv1+nv1 " << sv1+nv1 << endl;
	cout << "nv1+sv1 " << nv1+sv1 << endl;
	cout << "nv1+nv1 " << nv1+nv1 << endl << endl;
	
	//iloczyn macierzy
	cout << "nm" << endl << nm1 << endl;
	cout << "cm" << endl << cm1 << endl;
	cout << "nm*nm" << endl << nm1*nm1 << endl;
	cout << "nm*cm" << endl << nm1*cm1 << endl;
	cout << "cm*nm" << endl << cm1*nm1 << endl;
	cout << "cm*cm" << endl << cm1*cm1 << endl;
	
	//zapis do pliku
	save_sv(sv1, "ex/sv1.txt");
	save_nv(nv1, "ex/nv1.txt");
	save_nm(nm1, "ex/nm1.txt");
	save_c_sm(cm1, "ex/cm1.txt");
	
	//slad macierzy
	cout << "slad nm1 " << trace_nm(nm1) << endl;
	cout << "slad cm1 " << trace_c_sm(cm1) << endl << endl;
	
	//mnozenie wektor-macierz
	load_nv(nv2, "ex/nv2.txt");
	cout << "sv*nm " << sv2*nm1<< endl;
	cout << "nv*nm " << nv2*nm1 << endl;
	cout << "sv*cm " << sv2*cm1 << endl;
	cout << "nv*cm " << nv2*cm1 << endl << endl;
	
	//dodawanie macierzy
	cout << "nm+nm" << endl << nm1+nm1 << endl;
	cout << "nm+cm" << endl << nm1+cm1 << endl;
	cout << "cm+nm" << endl << cm1+nm1 << endl;
	cout << "cm+cm" << endl << cm1+cm1 << endl;

	
	//transpozycja macierzy
	transpose_nm(nm1);
	transpose_c_sm(cm1);
	cout << "transpozycja nm" << endl << nm1 << endl; 
	cout << "transpozycja cm" << endl << cm1 << endl;
	
	return 0;
}
catch(Blad& exc){
	cerr << "Wyjatek: "<< exc.opis() << endl;
}
	return 1;
}
