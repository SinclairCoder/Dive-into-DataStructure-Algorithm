#include<iostream>

using namespace std;

int fun(int x){
	if(x%7==0) return false;
	while(x){
		int t = x%10;
		if(t==7) return false;
		x/=10;
	}
	return true;
}
int main(){
	int n;
	cin >> n; 
	int idx = 0,cnt=0;
	while(true){
		idx++;
		if(fun(idx)) {
			cnt++;
		}
		if(cnt==n) break;
	}
	int res[4] = {0,0,0,0};
	for(int i=1;i<=4;i++){
		for(int j=i;j<=idx;j+=4){
			if(!fun(j)) res[i-1]++;
		}
	}
	for(int i=0;i<4;i++){
		cout << res[i] << endl;
	}
	return 0;
}
