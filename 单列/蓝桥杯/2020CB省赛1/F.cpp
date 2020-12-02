#include<iostream>

using namespace std;
long long n;
int main(){
	cin >> n;
	cout << n;
	long long k = n/2;
	while(k>0){
		cout << " " << k ;
		k /= 2;
	}
	return 0;
} 
