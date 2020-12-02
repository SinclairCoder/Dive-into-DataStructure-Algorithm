#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,m;
	cin >> n >> m;
	int idx = 0, total,maxApple = -1, res = 0;
	for(int i=1;i<=n;i++){
		cin >> total;
		int tApple = 0,t;
		for(int j=0;j<m;j++){
			cin >> t;
			tApple += t;
		} 
		res += total+tApple;
		if(-tApple>maxApple){
			maxApple = -tApple;
			idx = i;
		}
	}
	cout << res <<  " " << idx << " " << maxApple << endl;
	return 0;
}
