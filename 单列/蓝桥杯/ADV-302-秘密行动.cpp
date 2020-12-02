#include<iostream>

using namespace std;
const int N = 1e4+10;
int f[N][2],a[N];
int n;
int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	// f[i][0] 从前面爬到第i层   f[i][1] 从前面跳到第i层 
	f[1][0] = a[1];
	f[1][1] = 0;
	// f[i][0] = min{f[i-1][0],f[i-1][1]} + a[i]
	// f[i][1] = min{f[i-1][0],f[i-2][0]} 
	for(int i=2;i<=n;i++){
		f[i][0] = min(f[i-1][0],f[i-1][1]) + a[i];
		f[i][1] = min(f[i-1][0],f[i-2][0]);
	} 
	printf("%d",min(f[n][0],f[n][1]));
	
	return 0;
}
