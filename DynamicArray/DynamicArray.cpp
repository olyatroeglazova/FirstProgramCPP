#include "stdafx.h"
#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray() 
	: size(10), capacity(10), array(new int[10]) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
DynamicArray::DynamicArray(const int newsize) 
	: size(newsize), capacity(newsize), array(new int[newsize]) {
	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}
}
DynamicArray::DynamicArray(const int newsize, const int n) 
	: size(newsize), capacity(newsize), array(new int[newsize]) {
	for (int i = 0; i < size; i++) {
		array[i] = n;
	}
}
DynamicArray::DynamicArray(const DynamicArray& arr)
	: size(arr.size), capacity(arr.capacity), array(new int[arr.size]) {
	for (int i = 0; i < size; i++) {
		array[i] = arr.array[i];
	}
}
DynamicArray::DynamicArray( DynamicArray&& arr)
	: size(arr.size), capacity(arr.capacity), array(arr.array) {
	arr.array = nullptr;
	arr.size = 0; 
	arr.capacity = 0;
}
DynamicArray::~DynamicArray() {
	delete[] array;
	size = 0;
}

int DynamicArray::length() {
	return size;
}
void DynamicArray::resize(const int newSize) {
	int *temp = new int[size];
	for (int i = 0; i < size; i++) {
		temp[i] = array[i];
	}
	delete[] array;
	array = new int[newSize];
	if (capacity >= newSize) {
		for (int i = 0; i < newSize; i++) {
			array[i] = temp[i];
		}
		size = newSize;
	}
	else {
		for (int i = 0; i < size; i++) {
			array[i] = temp[i];
		}
		for (int i = size; i < newSize; i++) {
			array[i] = 0;
		}
		size = newSize;
		capacity = newSize;
	}
}

int& DynamicArray::operator[](const int n) {
	if (n < 0 || n >= size) {
		throw "Ошибка!";
	}
	return array[n];
}

DynamicArray& DynamicArray::operator=(const DynamicArray& arr) {
	if (this != &arr) {
		delete[] array;
		size = arr.size;
		array = new int[size];
		for (int i = 0; i < size; i++) {
			array[i] = arr.array[i];
		}
	}
	return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& arr) {
	std::swap(array, arr.array);
	return *this;
}

bool DynamicArray::operator==(const DynamicArray &arr) const {
	if (this == &arr) {
		return true;
	}
	if (size != arr.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (array[i] != arr.array[i]) {
			return false;
		}
	}
	return true;
}

bool DynamicArray::operator!=(const DynamicArray &arr) const {
	return !(arr==*this);
}

bool DynamicArray::operator<(const DynamicArray &arr) const {
	if (this == &arr) {
		return false;
	}
	int min = (size < arr.size) ? size : arr.size;
	for (int i = 0; i < min; i++) {
		if (array[i] == arr.array[i]) {
			continue;
		}
		return array[i] < arr.array[i];
	}
	return false;
}

bool DynamicArray::operator>(const DynamicArray &arr) const {
	if (this == &arr) {
		return false;
	}
	int min = (size < arr.size) ? size : arr.size;
	for (int i = 0; i < min; i++) {
		if (array[i] == arr.array[i]) {
			continue;
		}
		return array[i] > arr.array[i];
	}
	return false;
}

bool DynamicArray::operator<=(const DynamicArray &arr) const {
	return !(arr < *this);
}

bool DynamicArray::operator>=(const DynamicArray &arr) const {
	return !(*this < arr);
}

DynamicArray DynamicArray::operator+(const DynamicArray &arr) {
	DynamicArray tmp(size + arr.size);
	for (int i = 0; i < size; i++) {
		tmp[i] = array[i];
	}
	for (int i = 0; i < arr.size; i++) {
		tmp[i+size] = arr.array[i];
	}
	return tmp;
}

std::ostream& operator<<(std::ostream& os, const DynamicArray& arr) {
	os << "[";
	for (int i = 0; i < arr.size; i++) {
		os << arr.array[i] << (i == arr.size - 1 ? "]" : ", ");
	}
	return os;
}

std::istream& operator>>(std::istream& is, DynamicArray& arr) {
	for (int i = 0; i < arr.size; i++) {
		is >> arr.array[i];
	}
	return is;
}