#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int main(){
	cin >> n;
	int maxl = sqrt(n)+1;
	// ans：1不算在内，所以从0开始 
	// st: 最长连续因子的开始，应该从0开始，如果到最后还是0说明这是个质数或者是1 
	int ans = 0,st;
	for(int i=2;i<=maxl;i++){
		int tmp = 1,j;
		for(j=i;j<=maxl;j++){
			tmp*= j;
			// 不是因子的时候要break 
			if(n%tmp!=0) break;
		}
		// 此时j所对应的数字不符合要求 
		if(j-i>ans){
			ans = j-i;
			st = i;
		}
	} 
	if(st==0){
		cout << "1" << endl;
		cout << n << endl;
	} 
	else {
		cout << ans << endl; 
		for(int i=st;i<st+ans;i++){
			if(i==st) cout << i;
			else cout << '*' << i;
		}
		cout << endl;
	}
	
	return 0;
} 
