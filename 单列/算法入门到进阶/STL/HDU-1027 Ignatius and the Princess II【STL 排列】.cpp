#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[10010];
int main(){
	while(~scanf("%d%d",&n,&m)){
		int cnt = 1;
		for(int i=1;i<=n;i++) a[i] = i;
		while(cnt!=m&&next_permutation(a+1,a+1+n)){
			cnt++;
		}
		for(int i=1;i<=n;i++){
			if(i!=1) cout << " ";
			cout << a[i]; 
		}
		cout << endl; 
	}
	return 0;
} 
