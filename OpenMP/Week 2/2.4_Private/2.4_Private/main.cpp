#include <stdio.h>
#include <omp.h>
#include <locale>

int main()
{
	setlocale(LC_ALL, "Russian");

	int n = 1;
	
	printf("n � ���������������� ������� (������): %d\n", n);

#pragma omp parallel private(n) num_threads(4)
	{
		printf("�������� n � ������ (�� �����): %d\n", n);
	
		n = omp_get_thread_num(); // ����������� n ����� �������� ������ (����)
		printf("�������� n � ������ (�� ������): %d\n", n);

	}
	printf("n � ���������������� ������� (�����): %d\n", n);
	return 0;
}
