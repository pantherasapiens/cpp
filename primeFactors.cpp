#include<iostream>
using namespace std;
// prime factors
int n;
int main(){
	cout << "Enter:";
	cin >> n;
	int arr[10];
	int i = 0;
	while(n>0){
		arr[i]=n%2;
		n=n/2;
		i++;
	}
	while(i>0){
		i--;
		cout << arr[i] << "\t";
	}
	return 0;
}
