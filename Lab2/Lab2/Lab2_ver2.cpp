#include <iostream>
#include "Lab2.h"

using std::cin;
using std::cout;

namespace lab2_ver2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int num = 0;
		int eofbit;
		int failbit;
		int i;
		while (1) //목적 : int값을 읽어오고 싶다.
		{	
			
			//문제 : 다른 자료형이 들어오는 경우 스트림 포인터가 멈춘다. fail bit가 set된다.
			//문제 : 자체적으로 스트림이 비워지지 않아 fail bit와 in의 데이터 입력 멈춤이 반복된다.
			// 해결법 : ignore로 스트림버퍼에 있는 값을 지운다.
			// 조건 : fail을 일으킨 문제비트만 지우고 싶다. 마지막의 조건은 ' ' 나 '\n' 두가지이다.
			
			
			in >> num;
			
			if (in.fail())
			{
				in.ignore(256, ' ');
				in.clear();
				//out << "set clear"<<std::endl;
				//continue;
			}

			out << num<< std::endl;
		}




	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{

	}

}

using namespace lab2_ver2;


int main(void)
{
	PrintIntegers(cin, cout);



 

return 0;
}