#include "Lab2.h"
#include <string>

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		const int repeat_count = 5;  //��ü ���ڿ� ���� Ƚ��, �ʿ信 ���� ���� ����
		const int zero = 0;

		std::string str[repeat_count];  //�Է½�Ʈ�� �޴� ����
		std::string int_extract_str[repeat_count];  //���� ����� ����
		int print_int[repeat_count];	//���� �Է�
		int minus_count = 0;
		int Ascii_0 = 48;
		int Ascii_9 = 57;		
		int i = 0, j = 0;
		char * end;

		for (i = zero; i < repeat_count;i++) {  //stdin���� �Է� �ޱ�
			in >> str[i];		
		}		
		
		for (i = zero;i < repeat_count; i++)
		{
			for (j = NULL;j < str[i].size(); j++)  //�Է¹��� 5�� ���ڿ��� ���ڸ� ���� str.at(int) = ���ڿ����� int��ġ�� ���� char�� ������
			{
				if(Ascii_0 <= str[i].at(j) && str[i].at(j) <= Ascii_9)
				int_extract_str[i] += str[i].at(j);
			}
		}

		j = 0;

		for (i = zero;i < repeat_count;i++)        //���� Ascii�� ������ ���ڿ��� NULL���� �ƴϸ� ��¿� int������ �־��ֱ�
		{
			if (int_extract_str[i].size() != NULL)   
			{				
				try {
					print_int[j] = std::stoi(int_extract_str[i]); //str- int parse �Լ� std::stoi(str)
				}
				catch (const std::exception& expn)
				{
					out << "Out of range error, Set 0 \n";
					print_int[j] = 0;					
				}
				catch (...)
				{
					out << ": Unkown error\n";
				}
				j++;
			}
			else {
				minus_count++;
			}
		}

		
		out.fill('.');		//��� ���˺κ�
		out.width(12);	out <<"oct";
		out.width(11);	out << "dec";
		out.width(9);	out << "hex"<<std::endl;
		out.fill('-');
		out.width(13);	out << ".";
		out.width(11);	out << ".";
		out.width(8);	out << "-"<< std::endl;
		
		for (i = zero;i < repeat_count - minus_count ;i++) {	//��� ������ �ִ� ��ŭ �ݺ�
			out.fill('.');
			out.width(12);	out << std::oct << print_int[i];	//8���� 10���� 16���� ��� std::oct, std::dec, std::hex
			out.width(11);	out << std::dec << print_int[i];
			out.width(9);	out << std::hex << print_int[i] << std::endl;
		}
		return;
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		const int repeat_count = 5;  //��ü ���ڿ� ���� Ƚ��, �ʿ信 ���� ���� ����
		const int zero = 0;
		const int format = 1000;

		std::string str[repeat_count]; //�Է½�Ʈ�� �޴� ����
		std::string int_extract_str[repeat_count]; //���� ����� ����
		int print_int[repeat_count];  //�Ǽ��� ������
		int print_int2[repeat_count]; //�Ǽ��� �Ҽ��� * �Ҽ���°���
		int * ptr1 = NULL; //�ִ밪�� ������
		int * ptr2 = NULL; //�ִ밪�� ������2
		double print_float[repeat_count];
		int minus_count = 0;
		int Ascii_0 = 48;
		int Ascii_9 = 57;
		int i = 0, j = 0;
		

		for (i = zero; i < repeat_count;i++) {  //stdin���� �Է� �ޱ�
			in >> str[i];
		}

		for (i = zero;i < repeat_count; i++)
		{
			for (j = NULL;j < str[i].size(); j++)  //�Է¹��� 5�� ���ڿ��� ���ڸ� ���� str.at(int) = ���ڿ����� ����,��ȣ,�� ���� char�� ������
			{
				if (Ascii_0 <= str[i].at(j) && str[i].at(j) <= Ascii_9)
					int_extract_str[i] += str[i].at(j);
				else if (str[i].at(j) == '-' || str[i].at(j) == '.')   
					int_extract_str[i] += str[i].at(j);
				else
				{
					continue;
				}
			}
		}
		
		j = 0;

		for (i = zero;i < repeat_count;i++)        //���� Ascii�� ������ ���ڿ��� NULL���� �ƴϸ� ��¿� int������ �־��ֱ�
		{
			if (int_extract_str[i].size() != NULL)
			{
				try {
					print_int[j] = std::stoi(int_extract_str[i]); //������
					print_float[j] = std::stof(int_extract_str[i]) - std::stoi(int_extract_str[i]); //�Ǽ���
				}
				catch (const std::exception& expn)
				{
					out << "Out of range error, Set 0 \n";
					print_int[j] = 0;
					print_float[j] = 0;
				}
				catch (...)
				{
					out << ": Unkown error\n";
				}
				
				//out << "std::stoi(int_extract_str[i]) : " << std::stoi(int_extract_str[i]) << std::endl;
				//out << "std::stof(int_extract_str[i]) : " << std::stof(int_extract_str[i]) << std::endl;
				//out <<"print_float[j]" <<print_float[j]<<std::endl;
				if (print_float[j] < 0.0001 && print_float[j] >= 0)  //�Ǽ��� �ݿø� ���� ó��
					print_float[j] = 0;
				print_int2[j] = print_float[j] * format; //�Ǽ��θ� ����ڸ��� ��ŭ ������, ��½� ������ ���
				j++;
			}
			else {
				minus_count++;
			}
		}

		for (i = zero; i < repeat_count - 1; i++)  //�ִ밪 ������
		{
			ptr1 = &print_int[0];
			ptr2 = &print_int2[0];

			if ( *ptr1 + *ptr2 < print_int[i+1] + print_int2[i+1] )
			{
				ptr1 = &print_int[i + 1];
				ptr2 = &print_int2[i + 1];
			}else
			{
				continue;
				//�ִ밪 ����Ŵ ����
			}
		}
				

		for (i = zero;i < repeat_count - minus_count;i++) {	//��� ���˺κ�
			if (print_float[i] < 0) {
				out.fill('.');
				out.width(6);	out << '-';
				out.width(10);  out << abs(print_int[i]);
				out << '.';
				out.fill('0');
				out.width(3);   out << abs(print_int2[i]) << std::endl;
			}
			else{
				out.fill('.');
				out.width(6);	out << '+';
				out.width(10);  out << print_int[i];
				out << '.';
				out.fill('0');
				out.width(3);   out << print_int2[i] << std::endl;
			}
		}

		if (*ptr1 < 0) //�ִ밪 ���
		{	
			out << "max:.-";
			out.fill(','); 
			out.width(10);  out << abs(*ptr1);
			out << '.';
			out.fill('0');
			out.width(3);   out << abs(*ptr2) << std::endl;
		}
		else
		{
			out << "max:.+";
			out.fill('.');
			out.width(10);  out << *ptr1;
			out << '.';
			out.fill('0');
			out.width(3);   out << *ptr2 << std::endl;
		}


		return;

	}


}

using namespace lab2;


//
//int main()
//{
//
//	//PrintIntegers(std::cin, std::cout);
//	PrintMaxFloat(std::cin, std::cout);
//
//
//
//	return 0;
//
//
//
//}
//

//������ ������ in �ۿ��� ����� �ϴ� ����, ���� ���ۿ� ���� ������ �� ���� �о���� ����� �Է��� ���� ����		
			//out << "���� �������� ��ġ�� " << in.tellg() << std::endl;



			/*
			if (in.fail())
			{
				out << "����ó�� ���� ����" << std::endl;
				count_string = 0;
				in.clear();
				in.ignore(256, '\n');
				out << "����ó�� ���� �������� ��ġ�� " << in.tellg() << std::endl;
				out << "count_string�� ���� " << count_string<<std::endl;
				out << "in.fail()��? " <<in.fail() << std::endl;


				j--;
			}			*/


			//for (i = 0;i < 5;i++)
					//	num[i] = atoi(cstr[i]);

