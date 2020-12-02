#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
// v1,v2¼×ÒÒµÄ¾ÆÁ¿ 
int v1,v2,n;
// in1,in2¼×ÒÒºÈÁË¼¸±­ 
int in1,in2;
int main(){
	cin >> v1 >> v2 >> n;
	while(n--){
		int a1,a2,b1,b2;
		cin >> a1 >> a2 >> b1 >> b2;
		int sum = a1+b1;
		if(a2==sum&&b2==sum){
			in1++,in2++;
		}
		else if(a2==sum) {
			in1++;
		}
		else if(b2==sum){
			in2++;	
		}
		if(in1>v1){
			cout << "A" << endl;
			cout << in2 << endl;
			break;
		}
		if(in2>v2){
			cout << "B" << endl;
			cout << in1 << endl;
			break; 
		} 
	}
	return 0;
} 
