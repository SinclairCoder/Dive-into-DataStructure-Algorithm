#include<iostream>

using namespace std;
int a,b;
int main(){
	cin >> a >> b;
	int c = a+b;
	string s = to_string(c);
	string res;
	for(int i=s.length()-1,j=0;i>=0;i--){
		res  = s[i]+res;
		j++;
		if(j%3==0&&i&&s[i-1]!='-') res = ','+res;
	}
	cout << res << endl;
	return 0;
} 
