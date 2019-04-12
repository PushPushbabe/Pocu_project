#include <Turboc.h>



void printfloat(float f)

{

	unsigned t;

	char temp[35], bin[35];



	// ��Ʈ�� �ٷ�� ������ ������ ������ �����Ѵ�.

	t = *(unsigned *)&f;



	// ���� ���θ� ������ 32�ڸ��� 2���� ���ڿ��� ��ȯ

	itoa(t, bin, 2);

	memset(temp, '0', 35);

	strcpy(temp + 32 - strlen(bin), bin);



	// ��ȣ, ���� ������ ������ �ϳ��� ����

	bin[0] = temp[0];

	bin[1] = ' ';

	strncpy(bin + 2, temp + 1, 8);

	bin[10] = ' ';

	strcpy(bin + 11, temp + 9);



	printf("�Ǽ�=%f(%s), ", f, bin);



	// ���� ���

	printf("������ = %d\n", (t >> 23 & 0xff) - 127);

}



void main()

{

	printfloat(0.375f);

	printfloat(3.14f);

	printfloat(-0.5f);

	printfloat(0.1f);

}