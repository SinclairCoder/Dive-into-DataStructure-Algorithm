#include<iostream>

using namespace std;
const int N = 1010;
int a[N][N], prefix[N][N],n,m,q;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	// ÇóÇ°×ººÍ 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]+a[i][j]-prefix[i-1][j-1];
		}
	}
	int x1,y1,x2,y2;
	while(q--){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int res = prefix[x2][y2]-prefix[x2][y1-1]-prefix[x1-1][y2]+prefix[x1-1][y1-1];
		printf("%d\n",res);
	}
	return 0;
} 
