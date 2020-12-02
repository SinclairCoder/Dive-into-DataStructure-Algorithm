#include<iostream>
#include<map>
using namespace std;
const int N = 1e3+10;
pair<int,int> p[N];
map<pair<int,int>,int> svec;
int main(){
	int n,x,y;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x >> y;
		p[i] = make_pair(x,y);
		svec[p[i]]++;
	}
	int cnt[5] = {0,0,0,0,0};
	for(int i=0;i<n;i++){
		x = p[i].first;
		y = p[i].second;
		if(svec[make_pair(x,y+1)]&&svec[make_pair(x,y-1)]&&svec[make_pair(x+1,y)]&&svec[make_pair(x-1,y)]){
			cnt[svec[make_pair(x-1,y-1)]+svec[make_pair(x-1,y+1)]+svec[make_pair(x+1,y+1)]+svec[make_pair(x+1,y-1)]]++;
		}
	}
	for(int i=0;i<5;i++){
		cout << cnt[i] << endl;
	} 
	return 0;
}
