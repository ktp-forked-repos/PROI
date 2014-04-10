#define NMAX 50

using namespace std;

class fourier{
	double tab_a[NMAX], tab_b[NMAX], c, t;
	int ile;
	struct para{double a,b;};
public:
	fourier(double tablica_a[NMAX], double tablica_b[NMAX], double zmienna_c, double zmienna_t, int zmienna_ile); 
	fourier(); 
	fourier(const fourier &x); 
	double funkcja(double x); /*oblicza rozwiniecie szeregu dla zadanego x*/
	struct para operator[](int x); /*zwraca pare wsp (a,b) dla danego x*/
	
	friend fourier operator+(const fourier &x, const fourier &y); /*fourier+fourier->fourier*/
	friend fourier operator-(const fourier &x, const fourier &y); /*fourier-fourier->fourier*/
	friend fourier operator*(const fourier &x, double y); /*fourier*double->fourier*/
	friend fourier operator*(double x, const fourier &y); /*double*fourier->fourier*/
	friend ostream& operator<<(ostream& ekran, const fourier& x); /*wyprowadza strukture fourier na ekran */
	friend istream& operator>>(istream& klawiatura, fourier& x); /*wprowadza do struktury ze strumienia*/
};
