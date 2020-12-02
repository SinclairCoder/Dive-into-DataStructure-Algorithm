#include<iostream>

using namespace std;
const int maxn = 1e6+10;
int n;
int a[maxn];
void quick_sort(int l,int r){
    if(l>=r) return ;
    int i = l-1,j = r+1, p = a[(l+r)/2];
    while(i<j){
        do i++;while(a[i]<p);
        do j--;while(a[j]>p);
        if(i<j) swap(a[i],a[j]);
    }
    quick_sort(l,j);
    quick_sort(j+1,r);
    return ;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    quick_sort(0,n-1);
    
    for(int i=0;i<n;i++) {
        if(i)  cout << " ";
        cout << a[i];
    }
    return 0;
}
