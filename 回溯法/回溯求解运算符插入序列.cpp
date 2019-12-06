#include<bits/stdc++.h>

using namespace std;
#define N 9
#define rep(i,m,n) for(int i=m;i<n;i++)

void dfs(char op[],int sum,int preadd,int a[],int i){
	if(i==N){
		if(sum==100){
			printf(" %d",a[0]);
			rep(j,1,N){
				if(op[j]!=' ') printf("%c",op[j]);
				printf("%d",a[j]);
			}
			printf("=100\n");
		}
		return ;
	}
	op[i] = '+';
	sum += a[i];
	dfs(op,sum,a[i],a,i+1);
	sum -= a[i];   // 回退 
	op[i] = '-';
	sum -= a[i];
	dfs(op,sum,-1*a[i],a,i+1);
	sum += a[i];  // 回退 
	op[i] = ' ';
	sum -= preadd;
	int tmp;
	if(preadd>0)
		tmp = preadd*10+a[i];
	else tmp = preadd*10-a[i];
	sum += tmp; // 重新计算后加回来
	dfs(op,sum,tmp,a,i+1);
	sum -= tmp; // 回退
	sum +=  preadd; 
	
}
int main(){
	int a[N];
	char op[N];
	rep(i,0,N) a[i] = i+1;
	cout << "结果为：" << endl;
	dfs(op,a[0],a[0],a,1);
	return 0;
} 
