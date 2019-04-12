#include "Lab2.h"
#include <string>

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		const int repeat_count = 5;  //전체 문자열 받을 횟수, 필요에 따라서 변경 가능
		const int zero = 0;

		std::string str[repeat_count];  //입력스트림 받는 버퍼
		std::string int_extract_str[repeat_count];  //숫자 추출용 버퍼
		int print_int[repeat_count];	//정수 입력
		int minus_count = 0;
		int Ascii_0 = 48;
		int Ascii_9 = 57;		
		int i = 0, j = 0;
		char * end;

		for (i = zero; i < repeat_count;i++) {  //stdin에서 입력 받기
			in >> str[i];		
		}		
		
		for (i = zero;i < repeat_count; i++)
		{
			for (j = NULL;j < str[i].size(); j++)  //입력받은 5개 문자열중 숫자만 추출 str.at(int) = 문자열에서 int위치의 값을 char로 가져옴
			{
				if(Ascii_0 <= str[i].at(j) && str[i].at(j) <= Ascii_9)
				int_extract_str[i] += str[i].at(j);
			}
		}

		j = 0;

		for (i = zero;i < repeat_count;i++)        //숫자 Ascii값 추출한 문자열이 NULL값이 아니면 출력용 int변수에 넣어주기
		{
			if (int_extract_str[i].size() != NULL)   
			{				
				try {
					print_int[j] = std::stoi(int_extract_str[i]); //str- int parse 함수 std::stoi(str)
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

		
		out.fill('.');		//출력 포맷부분
		out.width(12);	out <<"oct";
		out.width(11);	out << "dec";
		out.width(9);	out << "hex"<<std::endl;
		out.fill('-');
		out.width(13);	out << ".";
		out.width(11);	out << ".";
		out.width(8);	out << "-"<< std::endl;
		
		for (i = zero;i < repeat_count - minus_count ;i++) {	//출력 변수가 있는 만큼 반복
			out.fill('.');
			out.width(12);	out << std::oct << print_int[i];	//8진수 10진수 16진수 출력 std::oct, std::dec, std::hex
			out.width(11);	out << std::dec << print_int[i];
			out.width(9);	out << std::hex << print_int[i] << std::endl;
		}
		return;
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		const int repeat_count = 5;  //전체 문자열 받을 횟수, 필요에 따라서 변경 가능
		const int zero = 0;
		const int format = 1000;

		std::string str[repeat_count]; //입력스트림 받는 버퍼
		std::string int_extract_str[repeat_count]; //숫자 추출용 버퍼
		int print_int[repeat_count];  //실수의 정수부
		int print_int2[repeat_count]; //실수의 소수부 * 소수출력공간
		int * ptr1 = NULL; //최대값용 포인터
		int * ptr2 = NULL; //최대값용 포인터2
		double print_float[repeat_count];
		int minus_count = 0;
		int Ascii_0 = 48;
		int Ascii_9 = 57;
		int i = 0, j = 0;
		

		for (i = zero; i < repeat_count;i++) {  //stdin에서 입력 받기
			in >> str[i];
		}

		for (i = zero;i < repeat_count; i++)
		{
			for (j = NULL;j < str[i].size(); j++)  //입력받은 5개 문자열중 숫자만 추출 str.at(int) = 문자열에서 숫자,부호,점 값을 char로 가져옴
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

		for (i = zero;i < repeat_count;i++)        //숫자 Ascii값 추출한 문자열이 NULL값이 아니면 출력용 int변수에 넣어주기
		{
			if (int_extract_str[i].size() != NULL)
			{
				try {
					print_int[j] = std::stoi(int_extract_str[i]); //정수부
					print_float[j] = std::stof(int_extract_str[i]) - std::stoi(int_extract_str[i]); //실수부
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
				if (print_float[j] < 0.0001 && print_float[j] >= 0)  //실수부 반올림 오류 처리
					print_float[j] = 0;
				print_int2[j] = print_float[j] * format; //실수부를 출력자릿수 만큼 곱해줌, 출력시 정수로 출력
				j++;
			}
			else {
				minus_count++;
			}
		}

		for (i = zero; i < repeat_count - 1; i++)  //최대값 순차비교
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
				//최대값 가리킴 유지
			}
		}
				

		for (i = zero;i < repeat_count - minus_count;i++) {	//출력 포맷부분
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

		if (*ptr1 < 0) //최대값 출력
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

//공백을 만나면 in 퍼오기 기능이 일단 멈춤, 다음 버퍼에 값이 있으면 그 값을 읽어오고 사용자 입력은 받지 않음		
			//out << "파일 포인터의 위치는 " << in.tellg() << std::endl;



			/*
			if (in.fail())
			{
				out << "예외처리 구문 진입" << std::endl;
				count_string = 0;
				in.clear();
				in.ignore(256, '\n');
				out << "예외처리 파일 포인터의 위치는 " << in.tellg() << std::endl;
				out << "count_string의 값은 " << count_string<<std::endl;
				out << "in.fail()은? " <<in.fail() << std::endl;


				j--;
			}			*/


			//for (i = 0;i < 5;i++)
					//	num[i] = atoi(cstr[i]);

