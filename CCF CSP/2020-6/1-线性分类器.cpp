#include<iostream>
#include<vector>
using namespace std;

int n,m; 
int fun(int a,int b,int c,int x,int y){
	// ax+by+c=0
	int res = a*x+b*y+c;
	if(res>0) return 1;
	else return 0;
}
int main(){
	cin >> n >>m;
	int x,y;
	char label;
	vector<pair<int,int > > v1,v2;
	for(int i=0;i<n;i++){
		cin >> x >> y >> label;
		if(label=='A') v1.push_back({x,y});
		else if(label=='B') v2.push_back({x,y});
	} 
	int a,b,c,r0,r1; 
	for(int i=0;i<m;i++){
		cin >> c >> a >> b;
		r0=0,r1=0;
		for(auto &e:v1){
			if(fun(a,b,c,e.first,e.second)) r1++;
			else r0++;
		}
		if(r0*r1!=0) {
			cout << "No" << endl;
			 continue;
		}
		r0=0,r1=0;
		for(auto &e:v2){
			if(fun(a,b,c,e.first,e.second)) r1++;
			else r0++;
		}
		if(r0*r1!=0) {
			cout << "No" << endl;
			 continue;
		}
		else cout << "Yes" << endl;
	}
	
	return 0;
} 
