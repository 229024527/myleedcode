//二分查找法
#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include <stdlib.h>

using namespace std;

namespace MyUtil{
	int *generateRandomArray(int n, int rangeL, int  rangeR){
		assert(n>0 && rangeL<=rangeR);
		int *arr = new int[n];

		srand(time(NULL));
		for(int i=0; i<n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		return arr;
	}

	int *generateOrderedArray(int n){
		assert(n>0);
		int *arr = new int[n];
		for(int i=0; i<n; i++)
			arr[i] = i;
		return arr;
	}
}

template<typename T>
int binarySearch(T arr[], int n, T target){

	int l=0, r=n;//在[l...r)的范围里寻找target
	while(l<r){//当l==r时，区间[l...r)依然是有效的
		int mid=l+(r-l)/2;//(l+r)/2有溢出可能
		if(arr[mid]==target)
			return mid;

		if(target > arr[mid])
			l=mid+1;//target在[mid+1...r)中
		else	//target<arr[mid]
			r=mid;//target在[l...mid-1)中

	}

	return -1;
}

int main(){

	int n=1000000;
	int* data = MyUtil::generateOrderedArray(n);

	clock_t startTime = clock();
	for(int i=0; i<n; i++)
		assert(i==binarySearch(data, n, i));
	clock_t endTime = clock();

	cout<<"binarySearch test complete."<<endl;
	cout<<"Time cost: "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;

	return 0;
}
