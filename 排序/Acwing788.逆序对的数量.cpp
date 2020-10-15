#include<iostream>

using namespace std;
typedef long long ll;
const int N = 1e5+10;
int  a[N],tmp[N];
int n;

ll merge_sort(int l,int r){
	if(l>=r) return 0;
	int mid = l+r>>1;
	int k = 0,i = l, j = mid+1;
    ll res = merge_sort(l,mid)+merge_sort(mid+1,r);
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]) tmp[k++] = a[i++];
		else {
			tmp[k++] = a[j++];
			res += mid-i+1;
		}
	}
	while(i<=mid) tmp[k++] = a[i++];
	while(j<=r) tmp[k++] = a[j++];
	for(int i=l,j=0;i<=r;i++,j++) a[i] = tmp[j];
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	cout << merge_sort(0,n-1);
	return 0;
} 
