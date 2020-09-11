#include<bits/stdc++.h>

using namespace std;
const int mod = 998244353;
const int N = 1010;
string s[N]={
"",	
"2",
"4",
"16",
"264",
"46416",
"166416264",
"264641626446416",
"46416641626446416166416264",
"166416264641626446416166416264264641626446416"
};
int main(){
	int n;
	string ps;
	cin >> n;
	cin >> ps;
	for(int i=10;i<=n;i++){
		s[i] = s[i-3]+s[i-1].substr(5)+s[i-2];
	}
	string ress = s[n];
	int idx = -1;
	long long res = 0;
	while(true){
		idx = ress.find(ps,idx+1);
		if(idx!=-1){
			res = (res+1)%mod; 
		}
		else break; 
	}
	cout << res << endl;
	return 0;
} 
