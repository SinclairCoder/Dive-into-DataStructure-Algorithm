#include<bits/stdc++.h>

using namespace std;
int n1,n2;
bool f1,f2;
bool check(string s){
	if(s.size()==0) return false;
	for(int i=0;i<s.size();i++){
		if(!isdigit(s[i])) return false;
	}
	int t = stoi(s);
	if(t<1||t>1000) return false;
	return true;
}
int main(){
	string s,num1,num2;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]==' ') {
			num1 = s.substr(0,i);
			num2 = s.substr(i+1);
			break;
		}
	}
	if(!check(num1)) num1 = "?",f1=true;
	if(!check(num2)) num2 = "?",f2=true;
	cout << num1 << " + " << num2 << " = ";
	if(!f1&&!f2) cout << stoi(num1)+stoi(num2) << endl;
	else cout << "?" << endl;
	return 0;
} 


