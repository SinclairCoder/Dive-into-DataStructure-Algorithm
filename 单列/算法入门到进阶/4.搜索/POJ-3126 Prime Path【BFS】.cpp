//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
typedef long long ll;
using namespace std;
const int maxn = 1e5+10;
int n;
int prime[maxn],vis[maxn],dis[maxn];

void init(){
	fill(prime,prime+maxn,1);
	for(int i=2;i<maxn;i++){
		if(prime[i]){
			for(int j=2*i;j<maxn;j+=i){
				prime[j] = 0;
			}
		}
	}
	return ;
}

void bfs(int a,int b){
	queue<int> qu;
	qu.push(a);
	vis[a] = 1;
	while(qu.size()){
		int top = qu.front(); qu.pop();
		if(top==b){
			cout << dis[b] << endl;
			return ;
		}
		int a[4],t = top;
		for(int i=3;i>=0;i--){
			a[i] = t%10; t/= 10;
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<=9;j++){
				if(i==0&&j==0) continue;
				t = a[i]; a[i] = j;
				int next = a[0]*1000+a[1]*100+a[2]*10+a[3];
				if(prime[next]&&!vis[next]){
					qu.push(next);
					dis[next] = dis[top]+1;
					vis[next] = 1;
				}
				a[i] = t;
			}
		}
	}
	cout << "Impossible" << endl;
	return ;
	
}

int main(){
	cin >> n;
	init();
	while(n--){
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		int a,b;
		cin >> a >> b;
		bfs(a,b);
	}
	return 0;
} 
