
/*
	求解1到n的全排列问题，复杂度O(n!) 
*/ 
#include<bits/stdc++.h>
using namespace std;
int n;
void dfs(vector<int>&arr,int u){
	if(u>=arr.size()){
		for(int i=0;i<n;i++){
			if(!i){
				cout << arr[i];
			}
			else cout << " " << arr[i];
		}
		cout << endl;
		return ;
	}
	for(int j=u;j<n;j++){
		swap(arr[j],arr[u]);
		dfs(arr,u+1);
		swap(arr[j],arr[u]);
	}
}
int main(){
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) arr[i] = i+1;
	dfs(arr,0);
	return 0;
}
