#include<iostream>

using namespace std;

const int N = 1e5+10; 
int n,m,a[N],prefix[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=5;i++) 
		scanf("%d",&a[i]),prefix[i] = prefix[i-1]+a[i];
	int l,r;
	while(m--){
		scanf("%d%d",&l,&r);
		printf("%d\n",prefix[r]-prefix[l-1]);
	}
	return 0;
} 
