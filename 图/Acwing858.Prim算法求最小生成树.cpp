#include<bits/stdc++.h>

using namespace std;
const int N = 510,INF = 0x3f3f3f3f;
// 存储稠密图
int g[N][N];
// 存储当前点到集合的距离
int dist[N];
// 当前点是否在集合中
bool st[N];
int n,m;
int prim(){
    memset(dist,0x3f,sizeof dist);
    int res = 0;
    // 以1为起点
    dist[1] = 0; 
    for(int i=0;i<n;i++){
        int t = -1;
        // 从不在集合中的所有点中找到距离集合最近的
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])) t = j;
        }
        // 如果发现找到的这个点距离为正无穷，则直接返回
        if(dist[t]==INF) return INF;
        // 将这个点加入集合
        st[t] = true;
        res+= dist[t];
        // 更新集合外的点到集合的最短距离
        for(int j=1;j<=n;j++){
            if(!st[j]) dist[j] = min(dist[j],g[t][j]);
        }
    }
    return res;
}
int main(){
    cin >> n >> m;
    // 图一定要初始化
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        // 重边和自环
        g[a][b] = g[b][a] = min(g[a][b],c);
    }
    int t = prim();
    if(t==INF) puts("impossible");
    else cout << t << endl;
    return 0;
}
