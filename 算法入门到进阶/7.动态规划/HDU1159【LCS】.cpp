#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<cstring> 

using namespace std; 

int dp[1005][1005];

void output(int idx1,int idx2){
	if(!idx1&&idx2){
		return ;
	}
	if(mark[idx1][idx2]==0){
		output(idx1-1,idx2-1);
		printf("%c",)
	}
}
int main(){
	string s1,s2;
	while(cin>>s1>>s2){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=s1.length();i++){
			for(int j=1;j<=s2.length();j++){
				if(s1[i-1]==s2[j-1]){
					dp[i][j] = dp[i-1][j-1]+1;
				}
				else {
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
				} 
			}
		}
		cout << dp[s1.length()][s2.length()] << endl;
	}
	return 0;
}
