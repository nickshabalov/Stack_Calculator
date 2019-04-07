#include "operations.h"
#include <stack>
#include <cmath>
#include <limits>
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include<sstream>
#include <map>
#include <regex>

using namespace std;

static map <string, double> define;
static  map <string, Base<double>* > command_map;
inline bool isNumber(string token)
{
	return regex_match(token, regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")));
}

//make factory
template <typename T>
Base<T>* Base<T>::select_operation(string operation_name) {
	
	//check map for commad
	//if is => use it
	//else make new, add it to map
	if (command_map.find(operation_name) != command_map.end())
	{
		return command_map[operation_name];
	}
	else
	{
		Base* _new;
		// select one operation
		//remake it to switch
		if (operation_name.compare("*") == 0) {
			_new = new Multiplier<T>;
			command_map.insert(pair<string, Base*>("*", _new));
			return  _new;
		}
		else if (operation_name.compare("/") == 0) {
			_new = new Divider<T>;
			command_map.insert(pair<string, Base*>("/", _new));
			return  _new;
		}
		else if (operation_name.compare("+") == 0) {
			_new = new Adder<T>;
			command_map.insert(pair<string, Base*>("+", _new));
			return  _new;
		}
		else if (operation_name.compare("-") == 0) {
			_new = new Subtractor<T>;
			command_map.insert(pair<string, Base*>("-", _new));
			return  _new;
		}
		else if (operation_name.compare("sqrt") == 0) {
			_new = new SquareRoot<T>;
			command_map.insert(pair<string, Base*>("sqrt", _new));
			return  _new;
		}
		else if (operation_name.compare("push") == 0) {
			_new = new Push<T>;
			command_map.insert(pair<string, Base*>("push", _new));
			return  _new;
		}
		else if (operation_name.compare("pop") == 0) {
			_new = new Pop<T>;
			command_map.insert(pair<string, Base*>("pop", _new));
			return  _new;
		}
		else if (operation_name.compare("print") == 0) {
			_new = new Print<T>;
			command_map.insert(pair<string, Base*>("print", _new));
			return  _new;
		}
		else if (operation_name.compare("define") == 0) {
			_new = new Define<T>;
			command_map.insert(pair<string, Base*>("define", _new));
			return  _new;
		}
		else if (operation_name.compare("#") == 0) {
			_new = new Comment<T>;
			command_map.insert(pair<string, Base*>("#", _new));
			return  _new;
		}
		else {
			throw "Invalid operation: use either!";
		}
	}
}

template<typename T>
void Base<T>::calculate(stack<T>& calcStack, ifstream &file)
{
}



template <typename T>
Multiplier<T>::Multiplier() {};

template <typename T>
Multiplier<T>:: ~Multiplier() {};

template <typename T>
void Multiplier<T>::calculate(stack<T>& calcStack, ifstream &file)
{
	
	if (calcStack.size() < 2)
	{
		throw "No enough argument values for calculation!";
	}
	double lVal, rVal, result;

	rVal = calcStack.top();
	calcStack.pop();

	lVal = calcStack.top();
	calcStack.pop();

		// check possibility of overflow for further multiply
		if (abs(lVal * rVal) > DBL_MAX)
		{
			throw "These numbers are too big for multiplication!";
		}
		else {
			result = lVal * rVal;
		}
		calcStack.push(result);
	
}



template <typename T>
Divider<T>::Divider() {};

template <typename T>
Divider<T>:: ~Divider() {};

template <typename T>
void Divider<T>::calculate(stack<T>& calcStack, ifstream &file)
{

	if (calcStack.size() < 2)
	{
		throw "No enough argument values for calculation!";
	}

	double lVal, rVal, result;

	rVal = calcStack.top();
	calcStack.pop();

	lVal = calcStack.top();
	calcStack.pop();

	if (rVal == 0) 
	{
		throw "There is a ZERO denominator!";
	}
	else
	{
		result = lVal / rVal;
	}
	calcStack.push(result);

}



template <typename T>
Adder<T>::Adder() {};

template <typename T>
Adder<T>:: ~Adder() {};

template <typename T>
void Adder<T>::calculate(stack<T>& calcStack, ifstream &file)
{

	if (calcStack.size() < 2)
	{
		throw "No enough argument values for calculation!";
	}

	double lVal, rVal, result;

	rVal = calcStack.top();
	calcStack.pop();

	lVal = calcStack.top();
	calcStack.pop();

	if (abs(lVal + rVal) > DBL_MAX)
	{
		throw "These numbers are too big for multiplication!";
	}

	result = lVal + rVal;
	calcStack.push(result);
	
}



template <typename T>
Subtractor<T>::Subtractor() {};

template <typename T>
Subtractor<T>:: ~Subtractor() {};

template <typename T>
void Subtractor<T>::calculate(stack<T>& calcStack, ifstream &file)
{

	if (calcStack.size() < 2)
	{
		throw "No enough argument values for calculation!";
	}

	double lVal, rVal, result;

	rVal = calcStack.top();
	calcStack.pop();

	lVal = calcStack.top();
	calcStack.pop();

	if (abs(lVal - rVal) > DBL_MAX)
	{
		throw "These numbers are too big for multiplication!";
	}

	result = lVal - rVal;
	calcStack.push(result);	
}



template <typename T>
SquareRoot<T>::SquareRoot() {};

template <typename T>
SquareRoot<T>:: ~SquareRoot() {};

template <typename T>
void SquareRoot<T>::calculate(stack<T>& calcStack, ifstream &file)
{

	if (calcStack.empty())
	{
		throw "This an empty input!";
	}

	double rVal, result;

	rVal = calcStack.top();
	calcStack.pop();

	if (rVal < 0)
	{
		throw "There is a negative expression!";
	}

	result = sqrt(rVal);
	calcStack.push(result);
}



template <typename T>
Pop<T>::Pop() {};

template <typename T>
Pop<T>:: ~Pop() {};

template <typename T>
void Pop<T>::calculate(stack<T>& calcStack, ifstream &file)
{
	if (calcStack.empty())
	{
		throw "There is an empty list!";
	}
	calcStack.pop();
}
	


template <typename T>
Print<T>::Print() {};

template <typename T>
Print<T>:: ~Print() {};

template <typename T>
void Print<T>::calculate(stack<T>& calcStack, ifstream &file)
{
	if (calcStack.empty())
	{
		throw "There is an empty list!";
	}
	cout << ">>" << calcStack.top() << endl;
}



template <typename T>
Push<T>::Push() {};

template <typename T>
Push<T>:: ~Push() {};

template <typename T>
void Push<T>::calculate(stack<T>& calcStack, ifstream &file)
{
	string put = "";
	double nam;
	if (file.is_open())
	{
		file >> put;
	}
	else
	{
		cin >> put;
	}
	if (define.find(put) != define.end()/*isDefine(put, calcStack)*/)
	{
		for (auto it = define.begin(); it != define.end(); ++it)
		{
			if (put == (*it).first)
			{
				calcStack.push((*it).second);
			}
		}
	}
	else
	{
		if (isNumber(put))
		{
			istringstream(put) >> nam;
			calcStack.push(nam);
		}
		else
		{
			throw "Can`t push this argument: try numbers";
		}
	}
}



template <typename T>
Define<T>::Define() {};

template <typename T>
Define<T>:: ~Define() {};

template <typename T>
void Define<T>::calculate(stack<T>& calcStack, ifstream &file)
{

	string arg = "", value = "";
	if (file.is_open())
	{
		file >> arg >> value;
	}
	else
	{
		cin >> arg >> value;
	}
	if (isNumber(value) && (!isNumber(arg)))
	{
		double nam;
		istringstream(value) >> nam;
		define.insert(pair<string, double>(arg, nam));
	}
	else
	{
		throw "Can`t push this argument: try 'define argument value'!";
	}
}



template <typename T>
Comment<T>::Comment() {};

template <typename T>
Comment<T>:: ~Comment() {};

template <typename T>
void Comment<T>::calculate(stack<T>& calcStack, ifstream &file)
{
	string flood;
	if (file.is_open())
	{
		getline(file, flood);
	}
	else
	{
		getline(cin, flood);
	}
}