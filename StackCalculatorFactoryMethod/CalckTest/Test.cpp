#include"pch.h"
#include"../StackCalculatorFactoryMethod/operations.cpp"

using namespace std;

TEST(Test_Calculation, Adder)
{
	stack<double> calcStack;
	string input;
	ifstream fin;
	fin.open("t.txt");
	calcStack.push(2);
	calcStack.push(3);

	Base<double>* f = Base<double>::select_operation("+");
	f->calculate(calcStack, fin);

	EXPECT_EQ(calcStack.top(), 5);
	ASSERT_ANY_THROW(f->calculate(calcStack, fin));
	calcStack.pop();
	ASSERT_ANY_THROW(f->calculate(calcStack, fin));
}

TEST(Test_Calculation, Subtractor)
{
	stack<double> calcStack;
	string input;
	ifstream fin;
	fin.open("t.txt");
	calcStack.push(3);
	calcStack.push(2);

	Base<double>* f = Base<double>::select_operation("-");
	f->calculate(calcStack, fin);

	EXPECT_EQ(calcStack.top(), 1);
	ASSERT_ANY_THROW(f->calculate(calcStack, fin));
	calcStack.pop();
	ASSERT_ANY_THROW(f->calculate(calcStack, fin));
}

TEST(Test_Calculation, Multiplier)
{
	stack<double> calcStack;
	string input;
	ifstream fin;
	fin.open("t.txt");
	calcStack.push(3);
	calcStack.push(2);

	Base<double>* f = Base<double>::select_operation("*");
	f->calculate(calcStack, fin);

	EXPECT_EQ(calcStack.top(), 6);
	ASSERT_ANY_THROW(f->calculate(calcStack, fin));
	calcStack.pop();
	ASSERT_ANY_THROW(f->calculate(calcStack, fin));
}

TEST(Test_Calculation, Divider)
{
	stack<double> calcStack;
	string input;
	ifstream fin;
	fin.open("t.txt");
	calcStack.push(9);
	calcStack.push(3);

	Base<double>* f = Base<double>::select_operation("/");
	f->calculate(calcStack, fin);

	EXPECT_EQ(calcStack.top(), 3);
	ASSERT_ANY_THROW(f->calculate(calcStack, fin));
	calcStack.pop();
	ASSERT_ANY_THROW(f->calculate(calcStack, fin));
}

TEST(Test_Calculation, SquareRoot)
{
	stack<double> calcStack;
	string input;
	ifstream fin;
	fin.open("t.txt");
	calcStack.push(9);
	
	Base<double>* f = Base<double>::select_operation("sqrt");
	f->calculate(calcStack, fin);

	EXPECT_EQ(calcStack.top(), 3);
	calcStack.pop();
	ASSERT_ANY_THROW(f->calculate(calcStack, fin));
}

TEST(Test_Calculation, Pop)
{
	stack<double> calcStack;
	string input;
	ifstream fin;
	fin.open("t.txt");
	calcStack.push(1);
	calcStack.push(2);

	Base<double>* f = Base<double>::select_operation("pop");
	f->calculate(calcStack, fin);

	EXPECT_EQ(calcStack.top(), 1);
	
}

TEST(Test_Calculation, Push)
{
	stack<double> calcStack;
	ofstream file("test.txt", ios::out | ios::trunc);
	file << "push 4" << endl;
	file.close();
	ifstream fin("test.txt");
	string str;
	while (!fin.eof())
	{
		str = "";
		fin >> str;


		try
		{
			Base<double>* f = Base<double>::select_operation(str);
			f->calculate(calcStack, fin);
		}
		catch (const char *msg)
		{
			cerr << msg << std::endl;
		}

	}
	fin.close();
	EXPECT_EQ(calcStack.top(), 4);
}
TEST(Test_Calculation, Define)
{
	stack<double> calcStack;
	ofstream file("test.txt", ios::out | ios::trunc);
	file << "define a 5" << endl;
	file << "push a" << endl;
	file.close();
	ifstream fin("test.txt");
	string str;
	while (!fin.eof())
	{
		str = "";
		fin >> str;


		try
		{
			Base<double>* f = Base<double>::select_operation(str);
			f->calculate(calcStack, fin);
		}
		catch (const char *msg)
		{
			cerr << msg << std::endl;
		}

	}
	fin.close();
	EXPECT_EQ(calcStack.top(), 5);
}
TEST(Test_Calculation, Comment)
{
	stack<double> calcStack;
	ofstream file("test.txt", ios::out | ios::trunc);
	file << "push 6" << endl;
	file << "# push 7" << endl;
	file.close();
	ifstream fin("test.txt");
	string str;
	while (!fin.eof())
	{
		str = "";
		fin >> str;


		try
		{
			Base<double>* f = Base<double>::select_operation(str);
			f->calculate(calcStack, fin);
		}
		catch (const char *msg)
		{
			cerr << msg << std::endl;
		}

	}
	fin.close();
	EXPECT_EQ(calcStack.top(), 6);
}