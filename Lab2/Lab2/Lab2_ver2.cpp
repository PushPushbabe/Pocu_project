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
		while (1) //���� : int���� �о���� �ʹ�.
		{	
			
			//���� : �ٸ� �ڷ����� ������ ��� ��Ʈ�� �����Ͱ� �����. fail bit�� set�ȴ�.
			//���� : ��ü������ ��Ʈ���� ������� �ʾ� fail bit�� in�� ������ �Է� ������ �ݺ��ȴ�.
			// �ذ�� : ignore�� ��Ʈ�����ۿ� �ִ� ���� �����.
			// ���� : fail�� ����Ų ������Ʈ�� ����� �ʹ�. �������� ������ ' ' �� '\n' �ΰ����̴�.
			
			
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