#include<bits/stdc++.h>
using namespace std;


#define rep(i,m,n) for(int i=m;i<n;i++)
#define pb push_back

int res = 0;
void print(vector<int> v){
	rep(i,0,v.size()){
		cout << v[i] << " ";
	}
	cout << endl;
}

void dfs(int a[], int n, int i, vector<int> path){
	if(i>=n){
		print(path);
		res++; // 统计个数 
		return ;
	}
	else {
		dfs(a,n,i+1,path);
		path.pb(a[i]);
		dfs(a,n,i+1,path);
	}
}
int main(){
	int n;
	cin >> n;
	int a[n];
	rep(i,0,n)
		cin >> a[i];
	vector<int> path;
	dfs(a,n,0,path);
	cout << "Total : " << res << endl; 
	return 0;
}
