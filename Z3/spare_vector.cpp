#include "spare_vector.h"

spare_vector spare_vector::operator+(const spare_vector &v2) const{
	if(v2.max!=max)
		throw BladRozmiaru();
	spare_vector v3;
	struct le2 tmp;
	list<struct le2>::const_iterator i1=element.begin(), i2=v2.element.begin();
	v3.max=v2.max;
	while(i1!=element.end() && i2!=v2.element.end()){
		if((*i1).pos==(*i2).pos){
			tmp.val=(((*i1).val)+((*i2).val));
			tmp.pos=(*i1).pos;
			v3.element.push_back(tmp);
			i1++;
			i2++;
		}
		else 	if((*i1).pos<(*i2).pos){
				tmp.val=(*i1).val;
				tmp.pos=(*i1).pos;
				v3.element.push_back(tmp);
				i1++;
			}
			else{
				tmp.val=(*i2).val;
				tmp.pos=(*i2).pos;
				v3.element.push_back(tmp);
				i2++;
			}
	}
	return v3;
}

void load_sv(spare_vector &v1, char name[N]){
	ifstream file(name);
	if(!file)
		throw BladOtwarciaPliku(name);
	v1.element.clear();
	struct le2 tmp;
	file >> v1.max;
	while(!file.eof()){
		file >> tmp.pos >> tmp.val;
		v1.element.push_back(tmp);
	}
	file.close();
}

void save_sv(const spare_vector &v1, char name[N]){
	ofstream file(name);
	if(!file)
		throw BladOtwarciaPliku(name);
	list<struct le2>::const_iterator i=v1.element.begin();
	file << v1.max;
	while(i!=v1.element.end()){
		file << endl << (*i).pos << " " << (*i).val;
		i++;
	}
	file.close();
}

ostream& operator<< (ostream& ekran, const spare_vector &v1){
	int i=0;
	list<struct le2>::const_iterator it=v1.element.begin();
	while(i<v1.max){
		if(i>=(*it).pos){
			ekran << (*it).val << " ";
			it++;
			i++;
		}	
		else{
			ekran << "0 ";
			i++;
		}
	}
	return ekran;
}
