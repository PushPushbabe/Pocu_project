#include <iomanip>
#include <iostream>
#include "Lab2.h"


using std::cin;
using std::cout;
using std::endl;

namespace lab2_ver2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int num_int = 0;		

		out << std::setfill(' ') << std::setw(11) << std::right << "oct";	//처음 포맷
		out << std::setfill(' ') << std::setw(11) << std::right << "dec";
		out << std::setfill(' ') << std::setw(10) << std::right << "hex" << endl;;
		out << std::setfill('-') << std::setw(12) << ' ';
		out << std::setfill('-') << std::setw(11) << ' ';
		out << std::setfill('-') << std::setw(10) << ' '<< endl;


		while (!in.eof()) //목적 : int값을 읽어오고 싶다.
		{										
			in >> num_int;

			if(in.fail() & !in.eof()) //비정상 입력지점
			{				
				in.clear();		//ignore - clear순서로 가는 경우 무한 반복이 된다. ignore가 failbit 상태에선 동작을 안하기 때문이다.
				in.ignore(LLONG_MAX, ' ');  //ignore가 동작을 안하면 fail 상태 반복
			}								//ignore의 값을 1로 바꿔서 abc123형태도 출력을 하게 할 순 있다.
			else if (in.eof() & in.fail()) //종료지점
				break;
			else  //정상 출력지점
			{
				if (num_int > 0)
				{
					out << std::setfill(' ') << std::setw(11) << std::right << std::oct << num_int;
					out << std::setfill(' ') << std::setw(11) << std::right << std::dec << num_int;
					out << std::setfill(' ') << std::setw(10) << std::right << std::hex << num_int << endl;
				}				
			}
		}
		in.clear();	//파일 초기화 부분
		in.seekg(0, std::ios::beg);
		return;
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		double num_float;
		double max = LLONG_MIN;

		while (!in.eof())
		{
			in >> num_float;
			
			if (in.fail() & !in.eof()) //비정상 입력지점
			{
				in.clear();		//ignore - clear순서로 가는 경우 무한 반복이 된다. ignore가 failbit 상태에선 동작을 안하기 때문이다.
				in.ignore(LLONG_MAX, ' ');  //ignore가 동작을 안하면 fail 상태 반복
			}
			else if (in.eof() & in.fail()) //종료지점
				break;
			else  //정상 출력지점
			{
				if (num_float > max)
					max = num_float;
				if (num_float > 0)
				{
					out.precision(3);
					out << std::setfill(' ') << std::setw(5) << '+' << std::right << std::noshowpos<< std::fixed << std::setw(14) << num_float << endl;
				}
				else
				{
					out.precision(3);
					out << std::setfill(' ') << std::setw(5) << '-' << std::right << std::fixed << std::setw(14) << abs(num_float) << endl;
				}
			}			

		}//end while
		if (max > 0)
		{
			out.precision(3);
			out << std::setfill(' ') << std::left<<std::setw(4) << "max" << '+' << std::right << std::noshowpos << std::fixed << std::setw(14) << max << endl;
		}
		else
		{
			out.precision(3);
			out << std::setfill(' ') << std::left << std::setw(4) << "max" << '-' << std::right << std::fixed << std::setw(14) << abs(max) << endl;
		}

		in.clear();	//파일 초기화 부분
		in.seekg(0, std::ios::beg);
		return;

	}

}

using namespace lab2_ver2;


int main(void)
{
	
	PrintIntegers(cin, cout);	
	cout << "\n";
	PrintMaxFloat(cin, cout);
	

return 0;
}

//in.ignore(4);
			/*if (in.eof())
			{
				out << "eof Set" << endl;
			}
			else
				out << "eof Not Set" << endl;

			if (!in.fail())
			{
				out << num << std::endl;
			}
			else if (in.fail())
			{

				in.ignore(LLONG_MAX,' ');
				in.clear();

				out << "failbit Set" << std::endl;

			}*/