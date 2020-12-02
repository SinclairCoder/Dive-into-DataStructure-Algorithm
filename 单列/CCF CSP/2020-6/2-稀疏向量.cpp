#include<iostream>
#include<vector>
#include<unordered_map> 
#include<map>
using namespace std;

unordered_map<int,int> umap;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,a,b,idx,val;
	long long res = 0;
	cin >> n >> a >> b;
	for(int i=0;i<a;i++){
		cin >> idx >> val;
		umap[idx] = val;
	}
	for(int i=0;i<b;i++){
		cin >> idx >> val; 
		if(umap[idx]!=0) {
			res += umap[idx]*val;
		}
	}
	cout << res << endl;
	return 0;
} 
