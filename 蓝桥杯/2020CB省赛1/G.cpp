#include<iostream>

using namespace std;

int main(){
	string s,res;
	cin >> s;
	int i =0;
	while(i<s.length()){
		if(s[i+1]>='0'&&s[i+1]<='9'){
			int k = s[i+1]-'0';
			for(int j=0;j<k;j++) res += s[i];
			i++; 
		}
		else res += s[i];
		i++; 
	}
	cout << res << endl;
	return 0;
} 
