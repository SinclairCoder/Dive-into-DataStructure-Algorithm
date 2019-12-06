
#include<bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)
#define MAXN 200
int n;
int W;
int x[MAXN];
void disp(){
	rep(i,0,n){
		if(x[i]) cout << i << " "; 
	}
	cout << endl;
}
bool dfs(int tw,int rw,int i,int op[],int w[]){
	if(i==n){
		if(tw==W){
			rep(j,0,n) x[j] = op[j];
			return true;
		}
	}
	else {
		if(tw+w[i]<=W){
			op[i] = 1;
			dfs(tw+w[i],rw-w[i],i+1,op,w);
		}
		op[i] = 0;
		if(tw+rw>W) dfs(tw,rw-w[i],i+1,op,w);
	}
} 
int main(){
	cin >> n;
	cin >> W;
	int w[n],op[n],rw=0;
	rep(i,0,n){
		cin >> w[i];
		rw += w[i];
	}
	dfs(0,rw,0,op,w);
	disp();
	return 0;
} 
