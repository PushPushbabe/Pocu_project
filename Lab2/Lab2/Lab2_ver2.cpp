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

		out << std::setfill(' ') << std::setw(11) << std::right << "oct";	//ó�� ����
		out << std::setfill(' ') << std::setw(11) << std::right << "dec";
		out << std::setfill(' ') << std::setw(10) << std::right << "hex" << endl;;
		out << std::setfill('-') << std::setw(12) << ' ';
		out << std::setfill('-') << std::setw(11) << ' ';
		out << std::setfill('-') << std::setw(10) << ' '<< endl;


		while (!in.eof()) //���� : int���� �о���� �ʹ�.
		{										
			in >> num_int;

			if(in.fail() & !in.eof()) //������ �Է�����
			{				
				in.clear();		//ignore - clear������ ���� ��� ���� �ݺ��� �ȴ�. ignore�� failbit ���¿��� ������ ���ϱ� �����̴�.
				in.ignore(LLONG_MAX, ' ');  //ignore�� ������ ���ϸ� fail ���� �ݺ�
			}								//ignore�� ���� 1�� �ٲ㼭 abc123���µ� ����� �ϰ� �� �� �ִ�.
			else if (in.eof() & in.fail()) //��������
				break;
			else  //���� �������
			{
				if (num_int > 0)
				{
					out << std::setfill(' ') << std::setw(11) << std::right << std::oct << num_int;
					out << std::setfill(' ') << std::setw(11) << std::right << std::dec << num_int;
					out << std::setfill(' ') << std::setw(10) << std::right << std::hex << num_int << endl;
				}				
			}
		}
		in.clear();	//���� �ʱ�ȭ �κ�
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
			
			if (in.fail() & !in.eof()) //������ �Է�����
			{
				in.clear();		//ignore - clear������ ���� ��� ���� �ݺ��� �ȴ�. ignore�� failbit ���¿��� ������ ���ϱ� �����̴�.
				in.ignore(LLONG_MAX, ' ');  //ignore�� ������ ���ϸ� fail ���� �ݺ�
			}
			else if (in.eof() & in.fail()) //��������
				break;
			else  //���� �������
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

		in.clear();	//���� �ʱ�ȭ �κ�
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