#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 510, INF = 1e9+10;
int dist[N][N];
int n,m,Q;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
int main(){
    cin >> n >> m >> Q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // 注意自环
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        // 避免重边
        dist[a][b] = min(dist[a][b],c);
    }    
    floyd();
    while(Q--){
        int a,b;
        cin >> a >> b;
        if(dist[a][b]>INF/2) puts("impossible");
        else cout << dist[a][b] << endl;
    }
    return 0;
}
