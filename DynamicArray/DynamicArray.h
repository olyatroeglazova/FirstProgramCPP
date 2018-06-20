#pragma once
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
class DynamicArray {


	int* array;
	int size;
	int capacity;

public:

	DynamicArray();
	DynamicArray(const int);
	DynamicArray(const int, const int);
	DynamicArray(const DynamicArray &arr);
	DynamicArray( DynamicArray &&arr);
	~DynamicArray();

	int length();
	void resize(const int);

	int& operator[](const int);
	DynamicArray& operator=(const DynamicArray&);
	DynamicArray& operator=(DynamicArray&&);
	bool operator==(const DynamicArray &other) const;
	bool operator!=(const DynamicArray &other) const;
	bool operator<(const DynamicArray &other) const;
	bool operator>(const DynamicArray &other) const;
	bool operator<=(const DynamicArray &other) const;
	bool operator>=(const DynamicArray &other) const;
	DynamicArray operator+(const DynamicArray &other);
	friend std::ostream& operator<<(std::ostream&, const DynamicArray&);
	friend std::istream& operator>>(std::istream&, DynamicArray&);



};

#endif 