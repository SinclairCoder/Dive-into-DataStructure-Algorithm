#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e4+100;
int w[N],n,m;
int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> w[i];
	}
	while(m--){
//		next_permutation(w+1,w+n+1);
//      手动实现next_permutation
		int k = n;
		while(w[k-1]>w[k]) k--;
		int t = k;
		while(w[t+1]>w[k-1]) t++;
		swap(w[k-1],w[t]);
		reverse(w+k,w+n+1); 
	}
	for(int i=1;i<=n;i++){
		cout << w[i] << " "; 
	}
	
	return 0;
} 
