#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+100;
struct Edge{
    int a,b,w;
}arr[N];
int p[N];
int n,m;
bool cmp(Edge a,Edge b){
    return a.w < b.w;
}
int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
    }
    sort(arr+1,arr+m+1,cmp);
    for(int i=1;i<=n;i++) p[i] = i;
    int cnt = 0 , res = 0;
    for(int i=1;i<=m;i++){
        int fa = find(arr[i].a), fb = find(arr[i].b);
        if(fa==fb) continue;
        cnt ++;
        res += arr[i].w;
        p[fb] = fa;
    }
    if(cnt<n-1) puts("impossible");
    else cout << res << endl;
    return 0;
}
