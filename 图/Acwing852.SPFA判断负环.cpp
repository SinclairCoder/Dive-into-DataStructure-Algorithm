#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
const int N = 1e5+100;
int e[N],ne[N],h[N],w[N],idx;
// dist表示任意一点到当前点的距离，cnt表示任意一点到当前点最短距离对应的边数
int dist[N],cnt[N];
// 标记是否在队列中
bool st[N];
int n,m;
// 添加一条从a指向b，权为c的边
void add(int a,int b,int c){
    e[idx] = b,ne[idx]= h[a],w[idx]= c, h[a] = idx++;
}
bool spfa(){
//   这里区别于SPFA求最短路，这里不用初始化默认为0，因为负权边的存在，始终会进行最短距离的更新 
//    memset(dist,0x3f,sizeof dist);
//    dist[1] = 0;
    queue<int> q;
    // 因为起点不一定是从1开始，如果把全部点都加到队列里面，肯定可以找到负环
    for(int i=1;i<=n;i++) {
        q.push(i); st[i] = true;
    }
    while(q.size()){
        // 弹出队头
        int t = q.front(); q.pop(); st[t] = false;
        // 遍历所有出边
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            /// 更新距离
            if(dist[j]>dist[t]+w[i]){
                dist[j] = dist[t]+w[i];
                cnt[j] = cnt[t]+1;
                // 如果距离起点的边不小于n，那肯定有负权环
                if(cnt[j]>=n) return true;
                if(!st[j]){
                    q.push(j); st[j] = true;
                }
            }
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    // 一定要初始化
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    if(spfa()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
