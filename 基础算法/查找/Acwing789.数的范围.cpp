#include<iostream>

using namespace std;
const int N = 1e5+10;
int n,m;
int a[N]; 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	while(m--){
		int x;
		scanf("%d",&x);
		int l = 0, r = n-1;
		while(l<r){
			int mid = l+r>>1;
			if(a[mid]>=x) r = mid;
			else l = mid+1;
		}
		if(a[l]!=x) {
			cout << "-1 -1" << endl; 
			continue;
		} 
		else {
			cout << l << " ";
			l = 0, r = n-1;
			while(l<r){
				int mid = l+r+1>>1;
				if(a[mid]<=x) l = mid;
				else r = mid-1;
			}
			cout << l << endl;
		}
	}
	return 0;
} 
