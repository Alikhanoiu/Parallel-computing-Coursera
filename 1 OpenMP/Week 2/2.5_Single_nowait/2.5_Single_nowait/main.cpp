#include <iostream>
#include <stdio.h>
#include <omp.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	double k = 0;
#pragma omp parallel num_threads(4) firstprivate(k)
	{
		printf("����� ���������� single ��� nowait \n");
#pragma omp single
		{
			// ������ ���� �������� ��� ����, ����� ����� �������� �����-������ ������
			for (int i = 0; i < 100000; i++)
			{
				k += (double)i / (i + 1);
			}
			printf("� ��������� single \n");
		}
		printf("����� ��������� single ��� nowait. ��� ��������� ������� �� ����� ������ ����������. k = %f \n",k);

#pragma omp barrier // ������ ��������� �������������� ������, � ��������� ������� ��� ����� �����������. 

		printf("����� ���������� single c nowait \n");
#pragma omp single nowait
		{
			// ������ ���� �������� ��� ����, ����� ����� �������� �����-������ ������
			for (int i = 0; i < 100000; i++)
			{
				k += (double)i / (i + 1);
			}
			printf("� ��������� single \n");
		}
		printf("����� ��������� single c nowait. ��� ��������� ����� ���� ������ ����������. k =  %f \n", k);
	}
	return 0;
}
