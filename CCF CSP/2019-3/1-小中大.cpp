#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n],maxv,minv,mid;
	for(int i=0;i<n;i++){
		cin >> a[i];
	} 
	maxv= a[0],minv = a[n-1];
	if(maxv<=minv) swap(maxv,minv);
	if(n%2) mid = a[n/2];
	else mid = a[n/2]+a[n/2-1]>>1;
	cout << maxv << " "<< mid << " " << minv << endl;  
}
