#pragma once
#include <iostream>
#include "base.h"

template <typename T>
class Adder : public Base<T> {

public:

	//Constructor
	Adder();

	
	 //Destructor
	virtual ~Adder();

	 //Calculate the sum with given data
	 //@return result of the sum
	void calculate(stack<T>& calcStack, ifstream &file);
};


template <typename T>
class Subtractor : public Base<T> {

public:

	Subtractor();

	virtual ~Subtractor();
	
	void calculate(stack<T>& calcStack, ifstream &file);
};


template <typename T>
class Multiplier : public Base<T> {

public:

	Multiplier();

	virtual ~Multiplier();

	void calculate(stack<T>& calcStack, ifstream &file);
};


template <typename T>
class Divider : public Base<T> {
public:

	Divider();

	virtual ~Divider();

	void calculate(stack<T>& calcStack, ifstream &file);
};


template <typename T>
class SquareRoot : public Base<T> {
public:

	SquareRoot();

	virtual ~SquareRoot();

	void calculate(stack<T>& calcStack, ifstream &file);
};


template <typename T>
class Pop : public Base<T> {
public:

	Pop();

	virtual ~Pop();

	void calculate(stack<T>& calcStack, ifstream &file);
};


template <typename T>
class Print : public Base<T> {
public:

	Print();

	virtual ~Print();

	void calculate(stack<T>& calcStack, ifstream &file);
};


template <typename T>
class Push : public Base<T> {
public:

	Push();

	virtual ~Push();

	void calculate(stack<T>& calcStack, ifstream &file);
};


template <typename T>
class Define : public Base<T> {
public:

	Define();

	virtual ~Define();

	void calculate(stack<T>& calcStack, ifstream &file);
};


template <typename T>
class Comment : public Base<T> {
public:

	Comment();

	virtual ~Comment();

	void calculate(stack<T>& calcStack, ifstream &file);
};