#pragma 
#include <iostream>
#include <stack>
#include <map>

using namespace std;

template <typename T>
class Base {
public:

	
	 //Constructor
	Base() {};

	 //Destructor
	virtual ~Base() {};

	
	 //Select one math operation by giving the math operation name
	 //@return a point to a selected operation
	static Base *select_operation(string operation_name);

	
	 //Caclulate the input data
	 //@return result of calculation
	virtual void calculate(stack<T>& calcStack, ifstream &file);
};