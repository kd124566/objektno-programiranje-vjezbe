
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template<typename TYPE>
TYPE min(TYPE& a, TYPE& b) {
	return a < b ? a : b;
}
int main() {
	int br1 = 2;
	int br2 = 3;
	cout << "Manji broj je: " << min(br1, br2) << endl;

	string str1 = "objektno";
	string str2 = "programiranje";
	cout << "Manji string je: " << min(str1, str2) << endl;
}
