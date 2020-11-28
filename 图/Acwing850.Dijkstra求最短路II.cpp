#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e6+10;
typedef pair<int,int> PII;
// 稀疏图用邻接表存储
int h[N],w[N],e[N],ne[N],idx;
int dist[N]; // 距离起点的距离
bool st[N]; // 标记是否已更新为最短距离
int n,m;
// 加一条a指向b的边，权重为c
void add(int a,int b,int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1}); // 第一关键字是距离，第二关键字是编号
    while(heap.size()){
        int distance = heap.top().first, id = heap.top().second;
        heap.pop();
        if(st[id]) continue; // 如果已经更新过了就跳过
        st[id] = true; 
        for(int i = h[id];i!=-1;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[id]+w[i]){
                dist[j] = dist[id]+w[i]; // 更新距离
                heap.push({dist[j],j}); 
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}
int main(){
    cin >> n >>m;
    // 初始化链表头
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    cout << dijkstra() << endl;
    return 0;
}
