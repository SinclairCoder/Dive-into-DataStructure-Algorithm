#include<iostream>

using namespace std;
const int N = 1e5+100;
int n,m;
int p[N];

int find(int x){
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i] = i;
    char op[2]; int a,b;
    while(m--){
        scanf("%s%d%d",op,&a,&b);
        if(op[0]=='M') p[find(a)] = find(b);
        else if(op[0]=='Q') {
            if(find(a)==find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
