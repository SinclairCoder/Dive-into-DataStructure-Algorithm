#include<bits/stdc++.h>
using namespace std;


void print(int a[], int x[], int n){
	cout << "{";
	for(int i=0;i<n;i++){
		if(x[i]) printf("%d ",a[i]);
	}
	cout << "}" << endl;
	cout << endl;
}
void dfs(int a[], int x[], int n, int i){
	if(i>=n) {
		print(a,x,n);return ;
	}
	else{
		x[i] = 0; dfs(a,x,n,i+1);
		x[i] = 1; dfs(a,x,n,i+1);
	}
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	int x[n];
	memset(x,0,sizeof(x));
	dfs(a,x,n,0);
	return 0;
}
