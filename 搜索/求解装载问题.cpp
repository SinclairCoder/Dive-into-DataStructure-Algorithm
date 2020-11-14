
#include<bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)
#define MAXN 20
/*
	n个集装箱装上一艘载重为W的轮船，集装箱i的重量为wi
	不考虑体积，求装上船的集装箱重量为W,并且箱子数量最少 
*/
int n;
int W;
int maxW;
int minnum = 999999;
int x[MAXN];
void disp(){
	cout << "选择物品的下标：";
	rep(i,0,n)
		if(x[i]) cout << i << " ";
	cout << endl; 
	cout << "最小数量为: " << minnum << endl;
	cout << "重量为: " << maxW << endl;
}
void dfs(int num,int tw,int rw,int op[],int w[],int i){
	if(i==n){
		if(tw==W&&num<minnum){
			maxW = tw;
			minnum = num;
			rep(j,0,n) x[j] = op[j]; 
		}
	}
	else {
		if(tw+w[i]<=W){
			op[i] = 1;
			dfs(num+1,tw+w[i],rw-w[i],op,w,i+1);
		}
		op[i] = 0;
		if(tw+rw>W){
			dfs(num,tw,rw-w[i],op,w,i+1);
		}
	}
} 
int main(){
	cin >> n;
	cin >> W;
	int rw=0,w[n],op[n];
	memset(op,0,sizeof(op));
	rep(i,0,n) {
		cin >> w[i];
		rw += w[i];
	}
	dfs(0,0,rw,op,w,0);
	disp();
	
	
	
	return 0;
} 
