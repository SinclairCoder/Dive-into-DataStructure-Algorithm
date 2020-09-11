#include<iostream>
#include<algorithm> 
#include<queue>
#include<cstring>
using namespace std;
int n,k,res,flag;
const int maxn = 1e6+10;
int dis[maxn];
int dx[4] = {-1,1,0,0},dy[4] = {0,0,-1,1};
queue<int> qu;
int bfs(){
	memset(dis,-1,sizeof(dis));
	dis[n] = 0;
	while(qu.size()){
		int top = qu.front(),x; qu.pop();
		for(int i=0;i<3;i++){
			switch(i){
				case 0: 
					x = top+1;break;
				case 1: 
					x = top-1;break;
				case 2: 
					x = top*2;break;
			}
			if(x>=0&&x<1000000&&dis[x]==-1){
				qu.push(x); dis[x] = dis[top] + 1;
			}
			if(x==k){
				return dis[k];
			}
		}
	}
	return dis[k];
}
int main(){
	cin >> n >> k;
	qu.push(n);
	cout << bfs() << endl;
	return 0;
} 


