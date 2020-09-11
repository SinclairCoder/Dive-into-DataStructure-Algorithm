#include<iostream>
#include<algorithm>
#include<set>
#include<string> 
using namespace std;
int n;
int main(){
	while(~scanf("%d",&n)&&n){
		set<string> A,B;
		string a,b;
		while(n--){
			cin >> a >> b;
			A.insert(a),A.insert(b); // 所有选手进入A集合 
			B.insert(b); // 失败的进入B集合 
		}
		if(A.size()-B.size()==1) cout << "Yes" << endl;
		else cout << "No" << endl; 
	}
	
}
