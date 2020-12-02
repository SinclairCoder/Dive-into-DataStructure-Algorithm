#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;
int N,M; 
const int MAXN = 1e5+10;
unordered_map<string,int> umap;
int main(){
	cin >> N;
	while(N--){
		int k; 
		string s; 
		cin >> k;
		bool flag = true;
		if(k==1) flag = false; 
		while(k--){
			cin >> s;
			if(flag) umap[s]=1;
		} 
	} 
	cin >> M;
	string s;
	int cnt = 0; // 用于输出格式控制 
	for(int i=1;i<=M;i++){
		cin >> s;
		if(!umap[s]){
			cnt++;
			umap[s]=-1;
			if(cnt==1) cout << s;
			else cout << " " << s;
		}
	}
	if(!cnt) cout << "No one is handsome" << endl;
	return 0;
} 
