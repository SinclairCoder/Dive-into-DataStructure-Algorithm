#include<bits/stdc++.h>

using namespace std;

int main(){
	long n;
	cin >> n;
	int a[n],maxv,minv;
	double mid;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	} 
	maxv= a[0],minv = a[n-1];
	if(maxv<=minv) swap(maxv,minv);
	if(n%2) mid = a[n/2];
	else mid = (a[n/2]+a[n/2-1])/2.0;
	if(int(mid)==mid)
		printf("%d %d %d",maxv,(int)mid,minv);
	else printf("%d %.1lf %d",maxv,mid,minv);
}
