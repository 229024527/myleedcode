#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class MyVector{
private:
	T* data;
	int capacity;	//存储数组中可以容纳的最大的元素个数
	int size;	//存储数组中的元素个数

	//O(n)
	void resize(int newCapacity){
		assert(newCapacity >= size);
		T *newData = new T[newCapacity];
		for(int i=0; i<size; i++)
			newData[i] = data[i];
		delete[] data;

		data = newData;
		capacity = newCapacity;
	}

public:
	MyVector(){
		data = new T[10];
		capacity = 10;
		size = 0;
	}

	~MyVector(){
		delete[] data;
	}

	//Average:O(1)
	void push_back(T e){
		//assert(size < capacity);
		if(size == capacity)
			resize(2*capacity);
		data[size++] = e;
	}

	//Average:O(1)
	T pop_back(){

		assert(size > 0);
		T ret = data[size -1];
		size --;
		if(size == capacity/4)
			resize(capacity/2);

		return ret;
	}
};
