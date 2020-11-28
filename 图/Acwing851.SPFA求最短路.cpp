#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1e5+100;
int e[N],ne[N],h[N],w[N],idx;
int dist[N];
// 标记是否在队列中
bool st[N]; 
int n,m;
// 添加一条从a指向b的权为c的边
void add(int a,int b,int c){
    e[idx]=b,ne[idx]= h[a], w[idx] = c, h[a] = idx++;
}
int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    // 将起点加入队列
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(q.size()){
        int t = q.front(); q.pop();
        st[t] = false;
        // 遍历t的所有出边
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            // 更新距离
            if(dist[j]>dist[t]+w[i]){
                dist[j]=dist[t]+w[i];
                // 如果该点不在队列中
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
                
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}
int main(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    int t = spfa();
    if(t==-1) puts("impossible");
    else cout << t << endl; 
    return 0;
}
