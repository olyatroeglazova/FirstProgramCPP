#include "stdafx.h"
#include "DynamicArray.h"
#include <iostream>
#include <conio.h>
#include <clocale>


using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	DynamicArray arr1;
	cout << "������ ����������� �� ���������. ������ ������: " << arr1 << endl;
	DynamicArray arr2(3);
	cout << "������ ����������� �� �������. ������ ������: " << arr2 << endl;
	DynamicArray arr3(7, 5);
	cout << "������ ����������� �� ������� � �����. ������ ������: " << arr3 << endl;
	DynamicArray arr4 = arr3;
	cout << "������ ����������� �����������. ��������� ������: " << arr4 << endl;
	DynamicArray arr5 = DynamicArray(arr4);
	cout << "������ ����������� �����������. ����� ������: " << arr5 << endl;
	cout << endl;
	cout << "������ ������ �������: " << arr5.length() << endl;
	arr5.resize(3);
	cout << "������ ����� ������ ����� ������ 3: " << arr5 << endl;
	arr5.resize(10);
	cout << "������ ����� ������ ����� ������ 10: " << arr5 << endl;
	cout << endl;
	cout << "������ ������ ����� �������? " << ((arr1 == arr2) ? "��" : "���") << endl;
	cout << "������ ������ �� ����� �������? " << ((arr1 != arr2) ? "��" : "���") << endl;
	cout << "������ ������ ������ �������? " << ((arr1<arr2) ? "��" : "���") << endl;
	cout << "������ ������ ������ ��� ����� �������? " << ((arr1 <= arr2) ? "��" : "���") << endl;
	cout << "������ ������ ������ �������? " << ((arr1>arr2) ? "��" : "���") << endl;
	cout << "������ ������ ������ ��� ����� �������? " << ((arr1 >= arr2) ? "��" : "���") << endl;
	DynamicArray arr6 = arr2 + arr5;
	cout << "������������ ������� � ������ �������: " << arr6 << endl;
	_getch();
	return 0;
}