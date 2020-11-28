#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 510;
int g[N][N]; // 稠密图用邻接矩阵
int dist[N]; // 距离起点的距离
bool st[N]; // 标记是否找到最短距离
int n,m;

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    // 循环n次
    for(int i=0;i<n;i++){
        int t = -1; // 从未找到最短距离的点的集合中找距离起点最短的点
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[j]<dist[t])) t = j;
        }
        st[t] = true; // 进行标记
        for(int j=1;j<=n;j++){
            dist[j] = min(dist[j],dist[t]+g[t][j]);  // 更新距离
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;  //如果第n个点路径为无穷大即不存在最短路径
    else return dist[n];
    
}

int main(){
    cin >> n >> m;
    // 可以避免自环
    memset(g,0x3f,sizeof g);  // 按字节初始化
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        // 避免重边的情况
        g[x][y] = min(g[x][y],z);
        
    }
    cout << dijkstra()<< endl;
    return 0;
}
