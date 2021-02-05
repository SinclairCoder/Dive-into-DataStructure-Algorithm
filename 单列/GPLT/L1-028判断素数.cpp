#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

bool check(int x){
	if(x==1) return false;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0) return false; 
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		ll x;
		cin >> x;
		if(check(x)) cout << "Yes" << endl;
		else cout << "No" << endl;
	} 
	
	return 0;
} 
