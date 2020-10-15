#include<iostream>


using namespace std;

int n,m;
const int N = 100;
int dp[N][N];
int main(){
	scanf("%d%d",&n,&m);
	dp[1][1] = 1;
	for(int i=1;i<=n;i++) dp[i][1] = 1;
	for(int j=1;j<=m;j++) dp[1][j] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			if(i%2==0&&j%2==0) dp[i][j] = 0;
			else dp[i][j] = dp[i][j-1]+dp[i-1][j];
		}
	}
	cout << dp[n][m] << endl;
	
	
	
	return 0;
}
