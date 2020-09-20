#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<list>
#include<set>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 150;
int n,m;
struct Edge{
	int u,v,w;
}edge[N*N];
int f[N];
int find(int x){
	if(x!=f[x]) return f[x] = find(f[x]);
	return f[x];
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int kruskal(){
	int ans = 0;
	for(int i=1;i<=n;i++) f[i] = i;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=m;i++){
		int b = find(edge[i].u);
		int c = find(edge[i].v);
		if(b==c) continue;
		f[c] = b;
		ans += edge[i].w; 
	} 
	return ans;
}
int main(){
	while(cin>>n&&n){
		m = n*(n-1)/2;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		}
		printf("%d\n",kruskal());
	} 
	return 0;
} 
