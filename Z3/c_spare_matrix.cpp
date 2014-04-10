#include "c_spare_matrix.h"

c_spare_matrix c_spare_matrix::operator+(const c_spare_matrix &m1) const{
	if(rmax!=m1.rmax || cmax!=m1.cmax)
		throw BladRozmiaru();
	c_spare_matrix result;
	struct le tmp;
	list<struct le>::const_iterator i1=m1.element.begin(), i2=element.begin();
	result.cmax=m1.cmax;
	result.rmax=m1.rmax;
	while(i1!=m1.element.end() && i2!=element.end()){
		if((*i1).r==(*i2).r){
			if((*i1).c==(*i2).c){
				tmp.c=(*i1).c;
				tmp.r=(*i1).r;
				tmp.val=(*i1).val+(*i2).val;
				result.element.push_back(tmp);
				i1++;
				i2++;
			}
		else	if((*i1).r<(*i2).r){
				tmp.c=(*i1).c;
				tmp.r=(*i1).r;
				tmp.val=(*i1).val;
				result.element.push_back(tmp);
				i1++;
			}
			else{
				tmp.c=(*i2).c;
				tmp.r=(*i2).r;
				tmp.val=(*i2).val;
				result.element.push_back(tmp);
				i2++;
			}
		}
	}
	return result;
}

c_spare_matrix c_spare_matrix::operator*(const c_spare_matrix &m1) const{
	if(cmax!=m1.rmax)
		throw BladRozmiaru();
	c_spare_matrix result;
	struct le tmp;
	int ir=0, ic=0;
	result.cmax=m1.cmax;
	result.rmax=rmax;
	list<struct le>::const_iterator i0=element.begin(), i1=m1.element.begin();
	ir=(*i0).r;
	ic=(*i1).c;
	while(1){
	if((*i0).r!=ir || i0==element.end()){
		if(tmp.val!=0)
			result.element.push_back(tmp);
		tmp.val=0;
		i1=m1.element.begin();
		ic++;
		if(ic>=result.cmax) {ic=0; ir++;}
		if(ir>=result.rmax) return result;
		if(i0==element.end()){
			i0=element.begin();
			while((*i0).r!=ir) i0++;
		}
		else{
			if(ic!=0) i0=element.begin();
		}
	}
	else{
		i1=m1.element.begin();
		while(i1!=m1.element.end()){
			if((*i0).c==(*i1).r && (*i0).r==ir && (*i1).c==ic){
				tmp.r=(*i0).r;
				tmp.c=(*i1).c;
				tmp.val+=((*i0).val)*((*i1).val);
			}
		i1++;
		}
	i0++;
	}
	}
}

double trace_c_sm(const c_spare_matrix &m1){
	if(m1.rmax!=m1.cmax)
		throw BladTrace(m1.rmax,m1.cmax);
	double result=0.0;
	list<struct le>::const_iterator ti=m1.element.begin();
	while(ti!=m1.element.end()){
		if((*ti).r==(*ti).c)
			result+=(*ti).val;
		ti++;
	}
	return result;
}

void transpose_c_sm(c_spare_matrix &m1){
	struct le oho;
	int i=0,j=0, tmp;
	double **tab = new double*[m1.cmax];
	for (i=0; i<m1.cmax; i++)
		tab[i] = new double[m1.rmax];
	for(i=0;i<m1.rmax;i++)
		for(j=0;j<m1.cmax;j++)
			tab[j][i]=0;
	list<struct le>::iterator ii=m1.element.begin();
	while(ii!=m1.element.end()){
		tab[(*ii).c][(*ii).r]=(*ii).val;
		ii++;
	}
	m1.element.clear();
	for(j=0;j<m1.cmax;j++)
		for(i=0;i<m1.rmax;i++)
			if(tab[j][i]!=0.0){
				oho.val=tab[j][i];
				oho.r=j;
				oho.c=i;
				m1.element.push_back(oho);
			}
	tmp=m1.rmax;
	m1.rmax=m1.cmax;
	m1.cmax=tmp;
	
	for (i=0;i<m1.cmax;i++)
		delete[] tab[i];
	delete[] tab;
}

void load_c_sm(c_spare_matrix &m1, char name[N]){
	ifstream file(name);
	if(!file)
		throw BladOtwarciaPliku(name);
	m1.element.clear();
	struct le tmp;
	file >> m1.rmax >> m1.cmax;
	while(!file.eof()){
		file >> tmp.r >> tmp.c >> tmp. val;
		m1.element.push_back(tmp);
	}
	file.close();
}

void save_c_sm(const c_spare_matrix &m1, char name[N]){
	ofstream file(name);
	if(!file)
		throw BladOtwarciaPliku(name);
	list<struct le>::const_iterator iel=m1.element.begin();
	file << m1.rmax << " " << m1.cmax;
	while(iel!=m1.element.end()){
		file << endl << (*iel).r << " " << (*iel).c << " " << (*iel).val;
		iel++;
	}
	file.close();
}

ostream& operator<< (ostream& ekran, const c_spare_matrix &m1){
	list<struct le>::const_iterator dk=m1.element.begin();
	int i=0,j=0;
	for(i=0;i<m1.rmax;i++){
		for(j=0;j<m1.cmax;j++){
			if(i==(*dk).r && j==(*dk).c){
				ekran << (*dk).val << " ";
				dk++;
			}
			else
				ekran << "0 ";
		}
		ekran << "\n";
		
	}
	return ekran;
}
