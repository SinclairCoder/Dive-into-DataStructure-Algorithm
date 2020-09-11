#include<bits/stdc++.h>

using namespace std;
#define N 9
#define rep(i,m,n) for(int i=m;i<n;i++)

/*
	求解1到n的全排列问题，复杂度O(n!) 
*/ 
int cnt = 0;
void disp(int a[], int n){
	rep(i,0,n)
		cout << a[i] << " ";
	cout << endl;
	cnt ++;
}
void dfs(int a[],int n,int i){
	if(i>=n){
		disp(a,n);
	}
	else {
		rep(j,i,n){
			swap(a[j],a[i]);
			dfs(a,n,i+1);
			swap(a[j],a[i]);
		}
	}
}
int main(){
	int n;
	cin >> n;
	int a[n];
	rep(i,0,n) cin >> a[i];
	dfs(a,n,0); // 一定要从0开始，自身和自身交换 
	cout << cnt << "种" << endl; 
	return 0;
} 
