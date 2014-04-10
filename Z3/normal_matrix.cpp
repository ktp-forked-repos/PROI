#include "normal_matrix.h"

normal_matrix normal_matrix::operator+(const normal_matrix &m1) const{
	if(r.size()!=m1.r.size() || r.front().val.size()!=m1.r.front().val.size())
		throw BladRozmiaru();
	normal_matrix result;
	vector<class normal_vector>::const_iterator i0=r.begin(), i1=m1.r.begin();
	while(i0!=r.end()){
		result.r.push_back((*i0)+(*i1));
		i0++; i1++;
	}
	return result;
}
	
normal_matrix operator+(const normal_matrix &m1, const c_spare_matrix &m2){
	if((int)m1.r.size()!=m2.rmax || (int)m1.r.front().val.size()!=m2.cmax)
		throw BladRozmiaru();
	normal_matrix result;
	list<struct le>::const_iterator i=m2.element.begin();
	result=m1;
	while(i!=m2.element.end()){
		result.r[(*i).r].val[(*i).c]+=(*i).val;
		i++;
	}
	return result;
}

normal_matrix operator+(const c_spare_matrix &m1, const normal_matrix &m2){
	if((int)m2.r.size()!=m1.rmax || (int)m2.r.front().val.size()!=m1.cmax)
		throw BladRozmiaru();
	normal_matrix result;
	list<struct le>::const_iterator i=m1.element.begin();
	result=m2;
	while(i!=m1.element.end()){
		result.r[(*i).r].val[(*i).c]+=(*i).val;
		i++;
	}
	return result;
}

normal_matrix normal_matrix::operator*(const normal_matrix &m2) const{
	if(r.front().val.size()!=m2.r.size())
		throw BladRozmiaru();	
	normal_matrix result;
	normal_vector nv;
	double tmp=0.0;
	int r1=0, c2=0, w=0, rmax1=(int)r.size(), cmax2=(int)m2.r.front().val.size(), wmax=(int)m2.r.size();
	for(r1=0;r1<rmax1;r1++){
		for(c2=0;c2<cmax2;c2++){
			for(w=0;w<wmax;w++){
				tmp+=r[r1].val[w]*m2.r[w].val[c2];
			}
			nv.val.push_back(tmp);
			tmp=0;
		}
	result.r.push_back(nv);
	nv.val.clear();
	c2=0;
	}
	return result;
}

normal_matrix operator*(const normal_matrix &m1, const c_spare_matrix &m2){
	if((int)m1.r.front().val.size()!=m2.rmax)
		throw BladRozmiaru();
	normal_matrix result;
	normal_vector nv;
	list<struct le>::const_iterator il=m2.element.begin();
	int i=0, cmax2=m2.cmax, rmax1=(int)m1.r.size();
	for(i=0;i<cmax2;i++)
		nv.val.push_back(0);
	for(i=0;i<rmax1;i++)
		result.r.push_back(nv);
	while(il!=m2.element.end()){
		for(i=0;i<rmax1;i++){
			result.r[i].val[(*il).c]+=(*il).val*(m1.r[i].val[(*il).r]);
		}
	
	il++;
	}
	return result;
}

normal_matrix operator*(const c_spare_matrix &m1, const normal_matrix &m2){
	if(m1.cmax!=(int)m2.r.size())
		throw BladRozmiaru();
	normal_matrix result;
	normal_vector nv;
	list<struct le>::const_iterator il=m1.element.begin();
	int i=0, rmax1=m1.rmax, cmax2=(int)m2.r.front().val.size();
	for(i=0;i<cmax2;i++)
		nv.val.push_back(0);
	for(i=0;i<rmax1;i++)
		result.r.push_back(nv);
	while(il!=m1.element.end()){
		for(i=0;i<cmax2;i++){
			result.r[(*il).r].val[i]+=(*il).val*(m2.r[(*il).c].val[i]);
		}
		il++;
	}
	return result;
}

double trace_nm(const normal_matrix &m1){
	if(m1.r.front().val.size()!=m1.r.size())
		throw BladTrace(m1.r.front().val.size(), m1.r.size());	
	double result=0.0;
	int i=0,max=(int)m1.r.size();
	for(i=0; i<max;i++)
		result+=m1.r[i].val[i];
	return result;
}

void transpose_nm(normal_matrix &m1){
	normal_matrix tmp;
	normal_vector nv;
	int i=0, j=0, rmax=(int)m1.r.size(), cmax=(int)m1.r.front().val.size();
	for(i=0;i<rmax;i++)
		nv.val.push_back(0);
	for(i=0;i<cmax;i++)
		tmp.r.push_back(nv);
	for(i=0;i<rmax;i++)
		for(j=0;j<cmax;j++)
			tmp.r[j].val[i]=m1.r[i].val[j];
	m1=tmp;
}

void load_nm(normal_matrix &m1, char name[N]){
	ifstream file(name);
	if(!file)
		throw BladOtwarciaPliku(name);
	m1.r.clear();
	vector<class normal_vector>::iterator i1=m1.r.begin();
	normal_vector nv;
	string s;
	double tmp=0.0;
	while(!file.eof()){
		getline(file, s);
		istringstream ss(s);
		nv.val.clear();
		while(ss>>tmp){
			nv.val.push_back(tmp);
		}
		m1.r.push_back(nv);
	}
	file.close();
}

void save_nm(const normal_matrix &m1, char name[N]){
	ofstream file(name);
	if(!file)
		throw BladOtwarciaPliku(name);
	vector<class normal_vector>::const_iterator i1=m1.r.begin();
	while(i1!=m1.r.end()){
		vector<double>::const_iterator i2=(*i1).val.begin();
		while(i2!=(*i1).val.end()){
			file << (*i2);
			i2++;
			if(i2!=(*i1).val.end())
				file << " ";
		}
		i1++;
		if(i1!=m1.r.end())
			file << endl;
	}
	file.close();
}

ostream& operator<< (ostream& ekran, const normal_matrix &m1){
	vector<class normal_vector>::const_iterator i=m1.r.begin();
	while(i!=m1.r.end()){
		ekran << (*i) << endl;
		i++;
	}
	return ekran;
}
