#include<iostream>
#include<algorithm> 
#include<queue>
using namespace std;
int n,m;
char maze[50][50];
int dx[4] = {-1,1,0,0},dy[4] = {0,0,-1,1};
int main(){
	while(~scanf("%d%d",&n,&m)&&n&&m){
		int res = 1;
		queue<int> qu;
		for(int i=0;i<m;i++){
			scanf("%s",maze[i]);
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(maze[i][j]=='@') {
					qu.push(i*n+j);break;	
				}
			}
		}
		while(qu.size()){
			int e = qu.front(); qu.pop();
			for(int i=0;i<4;i++){
				int xx = e/n+dx[i], yy = e%n+dy[i];
				if(xx>=0&&xx<m&&yy>=0&&yy<n&&maze[xx][yy]=='.'){
					qu.push(xx*n+yy);
					res ++;
					maze[xx][yy] = '#';
				}
			}
		}
		cout << res << endl;
	}
	return 0;
} 
