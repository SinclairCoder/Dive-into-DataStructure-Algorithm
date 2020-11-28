#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int M = 1e4+100, N = 510;
struct Edge{
    int a,b,w;
}arr[M];
// backup为dist的备份数组，即上一次的数据，dist根据backup进行更新
int dist[N],backup[N];
int m,n,k;
int bellman_ford(){
    // 对距离数组初始化
    memset(dist,0x3f,sizeof dist);
    // 起点距自身的距离为0
    dist[1] = 0;
    // k条边的限制
    for(int i=0;i<k;i++){
        // backup保存的是dist的数据，然后在新的循环中，dist用过去的数据也就是backup进行更新
        memcpy(backup,dist,sizeof dist);
        for(int j=0;j<m;j++){
            auto e = arr[j];
            // 每次只松弛一条边
            dist[e.b] = min(dist[e.b],backup[e.a]+e.w);
        }
    }
    // 因为有负权边，所以不一定会是正无穷，可能会小一些
    if(dist[n]>0x3f3f3f3f/2) return -1;
    else return dist[n];
}
int main(){
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].w);
    }
    int t = bellman_ford();
    if(t==-1) puts("impossible");
    else cout << t << endl;
    return 0;
}
