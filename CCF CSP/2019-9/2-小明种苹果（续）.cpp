#include<bits/stdc++.h>

using namespace std;
const int N = 1e3+10;
int n,cnt;
int vis[N];
int main(){
	cin >> n;
	long long t,res = 0;
	for(int i=1;i<=n;i++){
		cin >> cnt >> t;
		int initc = t,curc = t;
		for(int j=1;j<cnt;j++){
			cin >> t;
			if(t>0) {
				if(initc>t) vis[i]=1,initc = t;
			}else {
				initc += t;
			}
		}
		res += initc;
	}
	int totaldrop = 0, tdrop =0;
	for(int i=1;i<=n;i++){
		totaldrop += vis[i]==1;
		if(i==1) {
			if(vis[n]&&vis[i]&&vis[i+1]) tdrop++;
		}
		else if(i==n){
			if(vis[n-1]&&vis[i]&&vis[1]) tdrop++;
		}
		else {
			if(vis[i-1]&&vis[i]&&vis[i+1]) tdrop++;
		}
	}
	cout << res << " " << totaldrop << " " << tdrop << endl;
	return 0;
}
