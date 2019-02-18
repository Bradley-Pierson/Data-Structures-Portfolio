#include "Vector.h"

Vector::Vector(int len){
		length = len;
		values = new double[length];
		
		for(int i = 0; i < length; i++){
			values[i] = 0;
		}
}


Vector::Vector(const Vector & v)=defualt;

Vector::~Vector(){
	delete [] values;
}

double & Vector::at(int idx){
	values[idx];
}

int Vector::getLength(){
	return length;
}