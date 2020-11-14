
#include<bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)
int f(int x){
	int res = 0;
	while(x){
		res ++;
		x /= 10;
	}
	return res;
}
int main(){
	
	int l,r,a,b;
	int n;
	cin >> n;
	int arra[n][2],maxa;
	for(int i=0;i<n;i++)
		cin >> a >> b;
		arra[i][0] = a;
		arra[i][1] = b;
		cin >> l >> r;	
		maxa = max(l,max(maxa,r));
	}
	
	
	return 0;
} 
