#include "normal_vector.h"

normal_vector normal_vector::operator+(const normal_vector &v2) const{
	if(val.size()!=v2.val.size())
		throw BladRozmiaru();
	normal_vector v3;
	vector<double>::const_iterator i1=val.begin(), i2=v2.val.begin();
	while(i1!=val.end()){
		v3.val.push_back((*i1)+(*i2));
		i1++; i2++;
	}
	return v3;
}

normal_vector operator+(const normal_vector &v1, const spare_vector &v2){
	if((int)v1.val.size()!=v2.max)
		throw BladRozmiaru();
	normal_vector v3=v1;
	if(v2.element.back().pos>(int)v3.val.size())
		v3.val.resize(v2.element.back().pos,0);
	list<struct le2>::const_iterator i=v2.element.begin();
	while(i!=v2.element.end()){
		v3.val[(*i).pos]+=(*i).val;
		i++;
	}	
	return v3;
}

normal_vector operator+(const spare_vector &v1, const normal_vector &v2){
	if((int)v2.val.size()!=v1.max)
		throw BladRozmiaru();
	normal_vector v3=v2;
	if(v1.element.back().pos>(int)v3.val.size())
		v3.val.resize(v1.element.back().pos,0);
	list<struct le2>::const_iterator i=v1.element.begin();
	while(i!=v1.element.end()){
		v3.val[(*i).pos]+=(*i).val;
		i++;
	}	
	return v3;
}

normal_vector operator*(const normal_vector &v, const normal_matrix &m){
	if((int)v.val.size()!=(int)m.r.size())
		throw BladRozmiaru();
	normal_vector result;
	double tmp=0.0;
	int c2=0, w=0, cmax2=(int)m.r.front().val.size(), wmax=(int)m.r.size();
	for(c2=0;c2<cmax2;c2++){
		for(w=0;w<wmax;w++){
			tmp+=v.val[w]*(m.r[w].val[c2]);
		}
		result.val.push_back(tmp);
		tmp=0;
	}
	return result;
}

normal_vector operator*(const normal_vector &v, const c_spare_matrix &m){
	if((int)v.val.size()!=m.rmax)
		throw BladRozmiaru();
	normal_vector result;
	list<struct le>::const_iterator it=m.element.begin();
	int i=0, cmax=m.cmax;
	for(i=0;i<cmax;i++)
		result.val.push_back(0);
	while(it!=m.element.end()){
		result.val[(*it).c]+=(*it).val*(v.val[(*it).r]);
		it++;
	}
	return result;
}

normal_vector operator*(const spare_vector &v, const normal_matrix &m){
	if(v.max!=(int)m.r.size())
		throw BladRozmiaru();
	normal_vector result;
	list<struct le2>::const_iterator it=v.element.begin();
	int i=0, cmax=(int)m.r.front().val.size();
	for(i=0;i<cmax;i++)
		result.val.push_back(0);
	while(it!=v.element.end()){
		for(i=0;i<cmax;i++){
			result.val[i]+=(*it).val*(m.r[(*it).pos].val[i]);
		}
	it++;}
	return result;
}

normal_vector operator*(const spare_vector &v, const c_spare_matrix &m){
	if(v.max!=m.rmax)
		throw BladRozmiaru();
	normal_vector result;
	list<struct le2>::const_iterator it=v.element.begin();
	list<struct le>::const_iterator it2=m.element.begin();
	int i=0, cmax=m.cmax;
	for(i=0;i<cmax;i++)
		result.val.push_back(0);
	while(it!=v.element.end()){
		it2=m.element.begin();
		while(it2!=m.element.end()){
			if((*it).pos==(*it2).r)
				result.val[(*it2).c]+=(*it).val*(*it2).val;
			it2++;
		}
		it++;
	}
	return result;
} 

void load_nv(normal_vector &v1, char name[N]){
	ifstream file(name);
	if(!file)
		throw BladOtwarciaPliku(name);
	double a=0.0;
	v1.val.clear();
	while(!file.eof()){
		file >> a;
		v1.val.push_back(a);
	}
	file.close();
}

void save_nv(const normal_vector &v1, char name[N]){
	ofstream file(name);
	if(!file)
		throw BladOtwarciaPliku(name);
	vector<double>::const_iterator iv=v1.val.begin();
	while(iv!=v1.val.end()){
		file << (*iv);
		iv++;
		if(iv!=v1.val.end())
			file << " ";
	}
	file.close();
}

ostream& operator<< (ostream& ekran, const normal_vector &v1){
	vector<double>::const_iterator iv=v1.val.begin();
	while(iv!=v1.val.end()){
		ekran << (*iv) << " ";
		iv++;
	}
	return ekran;
}
