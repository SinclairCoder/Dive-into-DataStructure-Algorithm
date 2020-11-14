#include<bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for(int i=m;i<n;i++)
int n;
int cnt = 0;
void dfs(int x){
	if(x==0){
		cnt ++;
		return ;
	}
	else {
		if(x>=3) dfs(x-3);
		if(x>=2) dfs(x-2);
		if(x>=1) dfs(x-1);
	}
} 
int main(){
	cin >> n;
	dfs(n);
	cout << cnt << endl; 
	return 0;
} 
