#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
const int maxn = 1e5;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &b) const{
		return w<b.w;
	}
}edge[maxn];
int n,m,fa[maxn];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}
int main(){
	while(~scanf("%d",&n)&&n){
		int ans = 0;
		// init
		for(int i=1;i<=n;i++){
			fa[i] = i;
		}
		m = n*(n-1)/2;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		}
		// kruskalËã·¨
		sort(edge+1,edge+m+1);
		for(int i=1;i<=m;i++){
			int a = find(edge[i].u);
			int b = find(edge[i].v);
			if(a==b) continue;
			fa[b] = a;
			ans += edge[i].w; 
		}
		cout << ans << endl; 
	}
	return 0;
} 
