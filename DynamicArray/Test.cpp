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
	cout << "Вызван конструктор по умолчанию. Первый массив: " << arr1 << endl;
	DynamicArray arr2(3);
	cout << "Вызван конструктор по размеру. Второй массив: " << arr2 << endl;
	DynamicArray arr3(7, 5);
	cout << "Вызван конструктор по размеру и числу. Третий массив: " << arr3 << endl;
	DynamicArray arr4 = arr3;
	cout << "Вызван конструктор копирования. Четвертый массив: " << arr4 << endl;
	DynamicArray arr5 = DynamicArray(arr4);
	cout << "Вызван конструктор перемещения. Пятый массив: " << arr5 << endl;
	cout << endl;
	cout << "Размер пятого массива: " << arr5.length() << endl;
	arr5.resize(3);
	cout << "Теперь пятый массив имеет размер 3: " << arr5 << endl;
	arr5.resize(10);
	cout << "Теперь пятый массив имеет размер 10: " << arr5 << endl;
	cout << endl;
	cout << "Первый массив равен второму? " << ((arr1 == arr2) ? "да" : "нет") << endl;
	cout << "Первый массив не равен второму? " << ((arr1 != arr2) ? "да" : "нет") << endl;
	cout << "Первый массив меньше второго? " << ((arr1<arr2) ? "да" : "нет") << endl;
	cout << "Первый массив меньше или равен второму? " << ((arr1 <= arr2) ? "да" : "нет") << endl;
	cout << "Первый массив больше второго? " << ((arr1>arr2) ? "да" : "нет") << endl;
	cout << "Первый массив больше или равен второму? " << ((arr1 >= arr2) ? "да" : "нет") << endl;
	DynamicArray arr6 = arr2 + arr5;
	cout << "Конкатенация второго и пятого массива: " << arr6 << endl;
	_getch();
	return 0;
}