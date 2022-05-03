#include <iostream>
#include <map>

using namespace std;

int main(){
	map<int, int> myMap;

	if(myMap.find(42) == myMap.end())
		cout << "Can not find element 42" << endl;
	else
		cout << "Element 42 is in the map" << endl;

	cout << myMap[42] << endl;
	return 0;
}
