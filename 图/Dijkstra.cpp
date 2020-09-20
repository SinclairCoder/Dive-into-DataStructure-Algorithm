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

#define INF 0x3f3f3f3f
#define N 550
int n,m,s,d;

int dis[N],fee[N],edge[N][N],f[N][N],vis[N];

void dijkstra(){
	for(int i=0;i<n;i++) dis[i] = edge[s][i];
	for(int i=0;i<n;i++) fee[i] = f[s][i];
	fee[s] = 0;
	int e = s;
	for(int i=0;i<n;i++){
		vis[e] = 1;
		for(int j=0;j<n;j++){
			if(!vis[j]){
				if(dis[e]+edge[e][j]<dis[j]){
					dis[j] = dis[e]+edge[e][j];
					fee[j] = f[e][j]+fee[e];
				}
				else if(dis[e]+edge[e][j]==dis[j]){
					fee[j] = min(fee[j],fee[e]+f[e][j]);
				}
			}
		}
		int min = INF;
		e = n;
		for(int j=0;j<n;j++){
			if(!vis[j]&&min>dis[j]){
				min = dis[j];
				e = j;
			}
		}
		if(e==n) break;
	}
}
int main(){
	cin >> n >> m >> s >> d;
	int x,y,z,w;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			edge[i][j] = edge[j][i] = INF;
			f[i][j] = f[j][i] = INF;
		}
		edge[i][i] = f[i][i] = 0;
	} 
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&x,&y,&z,&w);
		edge[x][y] = edge[y][x] = z;
		f[x][y] = f[y][x] = w;
	}
	dijkstra();
	cout << dis[d] << " " << fee[d] << endl;
}
