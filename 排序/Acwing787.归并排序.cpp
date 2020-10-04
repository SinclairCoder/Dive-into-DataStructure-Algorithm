#include<iostream>

using namespace std;
const int maxn = 1e5+10;
int a[maxn],tmp[maxn];
int n;
void merge_sort(int l,int r){
    if(l>=r) return ;
    // 选定中点
    int mid = l+r>>1;
    // 递归排序左右两边
    merge_sort(l,mid),merge_sort(mid+1,r);
    int k = 0,i = l, j = mid+1;
    // 合并
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];
    for(int i = l,j = 0;i<=r;i++,j++) a[i] = tmp[j]; 
    
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    merge_sort(0,n-1);
    for(int i=0;i<n;i++){
        if(i) cout << " ";
        cout << a[i];
    }
    return 0;
}
