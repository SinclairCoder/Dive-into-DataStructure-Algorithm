#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 1e5+10;
int n,m;
int e[N],ne[N],h[N],idx;
int q[N],degree[N];

void add(int a,int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool topsort(){
	int hh = 0, tt = -1;
	for(int i=1;i<=n;i++){
		if(!degree[i]) q[++tt] = i;
	}
	while(hh<=tt){
		int t = q[hh++];
		for(int i=h[t];i!=-1;i=ne[i]){
			int j = e[i];
			degree[j]--;
			if(!degree[j]) q[++tt] = j;
		}
	}
	// 如果全部入队，则说明存在拓扑序 
	return tt==n-1;
}
int main(){
	cin >> n >> m;
	memset(h,-1,sizeof h);
	while(m--){
		int a,b;
		cin >> a >> b;
		add(a,b);
		degree[b]++;
	}
	if(topsort()){
		cout << q[0];
		for(int i=1;i<n;i++) cout << ' ' << q[i];
	}
	else cout << "-1" << endl;
	return 0;
}
