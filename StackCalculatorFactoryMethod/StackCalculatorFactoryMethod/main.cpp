#include <iostream>
#include <stack>
#include <string>
#include "operations.cpp"

using namespace std;

int main()
{

	cout << "welcome to calculator" << endl;
	stack<double> calcStack;
	string input;
	while (true)
	{
		//display promt
		cout << ">>";

		//get input
		cin >> input;

		//check for file
		ifstream fin;
		fin.open(input);

		if (fin.is_open())
		{
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
		}
		else if(!fin.is_open())
		{
			try
			{
				Base<double>* f = Base<double>::select_operation(input);
				f->calculate(calcStack, fin);
			}
			catch (const char *msg)
			{
				cerr << msg << std::endl;
			}


			


		}
		//check for quit
		else if (input == "q") 
		{
			return 0;
		}

		//invalid output
		else
		{
			cout << "Invalid input: try another!" << endl;
		}
	}
	system("pause");
}