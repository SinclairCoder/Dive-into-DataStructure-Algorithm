#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<cmath>

using namespace std;
typedef long long ll; 
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rep1(i,m,n) for(int i=m;i>=n;i--)
#define pb push_back

int main(){
	int n = 1543,cnt = 0;
	while(n){
		if(n&1){
			n--;cnt++;
			n /= 2;
		}
		else n /= 2;
	}
	cout << cnt << endl;
	return 0;
}
