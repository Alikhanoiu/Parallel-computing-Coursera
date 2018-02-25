#include "submit.h"
#include "omp.h"
#include "stdlib.h"
#include "time.h"
#include "ex_function.h"

float* vec_random(int n, bool normal)
{
	float* rand_arr = new float[n];
	
	// ----------------------------------------------------------
	// ����������� 1. ����� ����� ����������� ������ ���� ��� ���
	// ----------------------------------------------------------


	if (normal)
		{
#pragma omp barrier // ��� ��������� �������������. �� � ���� �� ��� �� �������������, 
			        // �� ��� ���������� ���������� ��� ���������� ����� ���� ������
			        // ������������ �������, ��� ����������
			vec_random_norm(rand_arr, n);
		}
	// ----------------------------------------------------------------------------------------
	// -- ���� ��� ����� ���� ������������ � ����������� 1 ������ ���� � ������������ �������--
	// ----------------------------------------------------------------------------------------
return rand_arr;
}