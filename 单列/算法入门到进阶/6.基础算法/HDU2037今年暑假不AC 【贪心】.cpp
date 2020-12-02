#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1000;
struct timenode{
	int s;
	int e;
};
bool cmp(timenode a,timenode b){
	return a.e < b.e;
}
timenode t[maxn];
int main(){
	while(~scanf("%d",&n)&&n){
		for(int i=0;i<n;i++){
			cin >> t[i].s >> t[i].e;
		}
		int ans = 0,lastend = -1;
		sort(t,t+n,cmp);
		
		for(int i=0;i<n;i++){
			if(t[i].s>=lastend){
				ans++;
				lastend = t[i].e;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
