#include<iostream>
typedef long long ll;
using namespace std;
int n,f;
void dfs(unsigned long long int t,int step){
	if(f||step>18) return ;
	if(t%n==0){
//		printf("%lld\n",t);
		cout << t << endl;
		f = 1;
		return ;
	}
	dfs(t*10,step+1);
	dfs(t*10+1,step+1);
	return ; 
}
int main(){
	while(~scanf("%d",&n)&&n){
		f = 0;
		dfs(1,0);
	}
	return 0;
} 
