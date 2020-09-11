#include<bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int i=m;i<n;i++)
#define MAXN 20
int maxv;   // 存放最优解总价值
int n;		// 物品总数 
int W; 		// 总重量 
int x[MAXN];
void disp(){
	cout << "选择物品的下标：";
	rep(i,0,n)
		if(x[i]) cout << i << " ";
	cout << endl; 
	cout << "最大价值为: " << maxv << endl;
}
void dfs(int i,int tw,int tv,int rw,int op[],int w[],int v[]){
	if(i>=n){
		if(tw==W&&tv>maxv){
			maxv = tv;
			rep(j,0,n)	x[j] = op[j];
		}
	}
	else {
		if(tw+w[i]<=W){  // 放入当前物品，并且小于总重量 才允许放入 
			op[i] = 1;
			dfs(i+1,tw+w[i],tv+v[i],rw-w[i],op,w,v);
		}
		op[i] = 0;  //  不能写在上面的if语句里面 
		if(rw+tw>W){  // 只有当前背包重量加上剩余未放入重量大于W时，才允许当前物品不放入 
			dfs(i+1,tw,tv,rw-w[i],op,w,v); //  尽管不放当前物品，rw还是要减去w[i] 
		} 
	}
} 
int main(){
	cin >> n; 
	cin >> W; 
	int w[n],v[n],op[n],rw;
	memset(op,0,sizeof(op));
	rep(i,0,n) {
		cin >> w[i]; rw += w[i]; 
	}
	rep(i,0,n) cin >> v[i];
	dfs(0,0,0,rw,op,w,v);
	disp();
	
	return 0;
} 
