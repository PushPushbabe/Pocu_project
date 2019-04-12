#include <iostream>
#include <istream>
#include <fstream> //Header providing file stream classes

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int eof;
	int fail;
	int bad;

	std::fstream fin;
	fin.open("test.txt");
	
	int hours;
	cin >> hours;
	cout << "Today I studied for " << hours << " hours. " << endl;

	float price;
	cin >> price;
	cout << "The price of this green tea is $ " << price << " . " << endl;

	int number;
	cin >> number;
	eof = cin.eof();
	fail = cin.fail();
	bad = cin.bad();
	cout << "eofbit : " << eof << endl;
	cout << "failbit : " << fail << endl;
	cout << "badbit : " << bad << endl;
	cout << "number : " << number<<endl;


	fin >> number;
	eof = fin.eof();
	fail = fin.fail();
	bad = fin.bad();
	cout << "eofbit : " << eof << endl;
	cout << "failbit : " << fail << endl;
	cout << "badbit : " << bad << endl;
	cout << "number : " << number<<endl;



	return 0;
}