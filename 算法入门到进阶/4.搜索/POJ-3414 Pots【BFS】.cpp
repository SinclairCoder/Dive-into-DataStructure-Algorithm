#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
int a,b,c,va=0,vb=0;
vector<string> res;
void fill(int x){
	string s;
	if(x==1){
		va = a; s = "FILL(1)";
	}
	else if(x==2){
		vb = b; s = "FILL(2)";
	}
	res.push_back(s);
}
void pour(int x,int y){
	int tot = va+vb;
	string s;
	if(x==1&&y==2){
		vb = min(b,tot);
		va = tot - vb;
		s = "POUR(1,2)";
	} else {
		va = min(a,tot);
		vb = tot - va;
		s = "POUR(2,1)";
	}
	res.push_back(s);
}
void drop(int x){
	string s;
	if(x==1) {
		va = 0; s = "DROP(1)";
	}
	else if(x==2) {
		vb = 0; s = "DROP(2)";	
	}
	res.push_back(s);
}
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
void print(){
	cout << res.size() << endl;
	for(int i=0;i<res.size();i++){
		cout << res[i] << endl;
	}
}
int main(){
	cin >> a >> b >> c;
	if(c%gcd(a,b)!=0) {
		cout << "impossible" << endl;
		return 0;
	}
	if(a>b){
		while(va!=c&&vb!=c){
			fill(1);
			while(va){
				pour(1,2);
				if(va==c||vb==c) {
					print();return 0;
				}
				if(vb==b) drop(2);
				if(va==c||vb==c) {
					print();return 0;
				}
			}
		}
	}
	else {
		while(va!=c&&vb!=c){
			fill(2);
			while(vb){
				pour(2,1);
				if(va==c||vb==c) {
					print();return 0;
				}
				if(va==a) drop(1);
				if(va==c||vb==c) {
					print();return 0;
				}
			}
		}
	}
	print();
	return 0;
} 
