#include<stdio.h>
#include<iostream> 
using namespace std;

int main() {
	
	char arr[128];
//	gets(arr);

	cin >> arr;
	//int len = strlen(arr);
	//cout << len << endl;

	for (int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] >= 'a' && arr[i] <= 'z') {
			arr[i] -= 32
			;
		}
		else if (arr[i] >= 'A' && arr[i] <= 'Z') {
			arr[i] += 32;
		}
	}
	cout << arr << endl;

	return 0;
}
