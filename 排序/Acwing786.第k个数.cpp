#include<iostream>

using namespace std;

int n,k;
const int maxn = 1e6+10;
int a[maxn];
int quick_sort(int l,int r,int k){
	if(l==r) return a[l];
	int x = a[l], i = l-1,j = r+1;
	while(i<j){
		while(a[++i]<x);
		while(a[--j]>x);
		if(i<j) swap(a[i],a[j]);
	}
	// 左边区间的长度 
	int sl = j-l+1;
	if(k<=sl) return quick_sort(l,j,k);
	return quick_sort(j+1,r,k-sl);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	cout << quick_sort(0,n-1,k) << endl;
	return 0;
} 
