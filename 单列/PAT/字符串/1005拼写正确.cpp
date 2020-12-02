#include<iostream>

using namespace std;
int a;
int main(){
	string n;
	cin >> n;
	int sum = 0;
	for(auto&c:n){
		sum += c-'0';
	}
	string s = to_string(sum);
	string digit[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	for(int i=0;i<s.length();i++){
		if(!i) cout << digit[s[i]-'0'];
		else cout << " " << digit[s[i]-'0'];
	}
	
	return 0;
} 
