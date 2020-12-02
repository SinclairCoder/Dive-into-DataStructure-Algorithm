#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int hh,mm; 
void print(int x){
	string s = "Dang";
	for(int i=0;i<x;i++) cout << s;
	cout << endl;
}
int main(){
	char c;
	
	cin >> hh >> c >> mm;
	if(hh>12||hh>=12&&mm>0){
		if(mm==0) print(hh-12);
		else print(hh-11);
	}
	else {
		printf("Only %02d:%02d.  Too early to Dang.\n",hh,mm);
	}
	return 0;
} 
