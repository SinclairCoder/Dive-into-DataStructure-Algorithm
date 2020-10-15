#include<iostream>
#include<cmath>
using namespace std;
// ´ð°¸ 11 
double fun(int k){
	double res = 1-pow(0.99,k)+1.0/k;
	return res;
}
int main(){
	double res = 0;
	int k;
	for(int i=1;i<=1000;i++){
		if(i==1||fun(i)<res){
			res = fun(i);
			k = i;
		}
	}
	cout << k << endl;
	return 0;
} 
