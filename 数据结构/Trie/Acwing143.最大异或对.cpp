#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N = 1e5+100;
int a[N],son[31*N][2], idx;
int n;
void insert(int a){
    int p = 0;
    for(int i=30;i>=0;i--){
        int u = (a>>i)&1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int a){
    int p = 0,res = 0;
    for(int i=30;i>=0;i--){
        int u = (a>>i)&1;
        if(son[p][!u]){
            p = son[p][!u]; res = res*2+!u;
        }
        else {
            p = son[p][u]; res = res*2+u;
        }
    }
    return res;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int res = 0;
    for(int i=0;i<n;i++){
        insert(a[i]);
        res = max(res,a[i]^query(a[i]));
    }
    cout << res << endl;
    return 0;
}
