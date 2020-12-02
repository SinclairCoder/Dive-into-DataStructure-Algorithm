#include<iostream>
#include<vector>
using namespace std;
int n;
#define N 1010
string change(string s){
	string res;
	for(auto&c:s){
		if(c=='1') res+= '@';
		else if(c=='0') res += '%';
		else if(c=='l') res += 'L';
		else if(c=='O') res += 'o';
		else res += c;
	}
	return res;
} 
int main(){
	cin >> n;
	int m;
	vector<string> name,pwd;
	for(int i=0;i<n;i++){
		string cur_name,cur_pwd;
		cin >> cur_name >> cur_pwd;
		string cpwd = change(cur_pwd);
		if(cpwd!=cur_pwd){
			name.push_back(cur_name);
			pwd.push_back(cpwd); 
		}
	}
	m = pwd.size();
	if(!m){
		if(n==1) cout << "There is 1 account and no account is modified";
		else printf("There are %d accounts and no account is modified",n);
	}
	else{
		cout << m << endl;
		for(int i=0;i<m;i++){
			cout << name[i] << " " << pwd[i] << endl;
		}
	}
	return 0;
} 
