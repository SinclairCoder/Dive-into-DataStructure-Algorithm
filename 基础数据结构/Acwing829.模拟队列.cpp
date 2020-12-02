#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5+10;
int m,hh,tt=-1;
int q[N];
string op;
int main(){
	cin >> m;
	while(m--){
		cin >> op;
		if(op=="push"){
			int x;
			cin >> x;
			q[++tt] = x;
		}
		else if(op=="pop"){
			hh++;
		}
		else if(op=="empty"){
			if(hh<=tt) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
		else if(op=="query"){
			cout << q[hh] << endl;
		}
	}
	return 0;
} 
