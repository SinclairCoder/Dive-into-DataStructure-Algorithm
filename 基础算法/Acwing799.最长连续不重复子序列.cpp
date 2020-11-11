#include<iostream>
#include<unordered_map>

using namespace std;
int n;
const int N = 1e5+10;
int a[N];
unordered_map<int,int> umap;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int res = 0;
    for(int i=0,j=0;i<n;i++){
        umap[a[i]]++;
        while(umap[a[i]]>1){
            umap[a[j]]--;
            j++;
        }
        res = max(res,i-j+1);
    }
    cout << res << endl;
    return 0;
}
