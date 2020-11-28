#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+100,M = 2*N;
int e[M],ne[M],h[N],idx;
int n,m;
// 记录每个点的颜色
int color[N];
void add(int a,int b){
    e[idx] = b , ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u,int c){
    color[u] = c;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j,3-c)) return false;
        }
        // 如果两个相邻点的染色是一样的，则出现矛盾
        else if(color[j]==c) return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    // 一定要初始化
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        cin >> a >> b;
        // 无向图
        add(a,b), add(b,a);
    }
    bool flag = true;
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1)){
                flag = false; break;
            }
        }
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}
