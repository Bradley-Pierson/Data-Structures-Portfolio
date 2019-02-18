#include <initializer list>
#include <iostream>

using std::cout
using std::endl;
using std::initializer_list;
using std::ostream;

class Vector{
	public:
		Vector(int);
		Vector(const Vector&); //copy constructor
		~Vector(); //destructor
		int getLength();
	private:
		int length;
		double* values;
}