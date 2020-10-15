#include<iostream>
using namespace std;

int main(){
	for(int i=0;i<2;i++){
		a = a+4;
		for(int j=0;j<5;j++){
			for(int k=0;k<6;k++){
				a = a+5;
			}
			a = a+7;
		}
		a = a + 8;
	}
	a = a + 9;
	return 0;
} 
