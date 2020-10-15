#include<iostream>
using namespace std;
int n = 10000; 
// ´ð°¸3880 
int main(){
	int i = 1;
	for(;;i++){
		if((i/60)%2==0){
			if(n>=10) n -= 10;
			else break;
		} 
		else n += 5;
	}
	cout << i-1 << endl;
	return 0;
} 
