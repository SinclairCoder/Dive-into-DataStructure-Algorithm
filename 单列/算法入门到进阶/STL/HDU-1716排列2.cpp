#include<iostream>
#include<algorithm> 
using namespace std;

int main(){
	int a[4],flag = 0;
	while(~scanf("%d%d%d%d",a+0,a+1,a+2,a+3)){
		if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0) break;
		if(flag) cout << endl; flag = 1;
		sort(a,a+4);
		int k = -1;
		do{
			if(a[0]==0) continue;
			if(k==-1) cout << a[0] << a[1] << a[2] << a[3];
			else if(k==a[0])
				cout << " " << a[0] << a[1] << a[2] << a[3];
			else {
				cout << endl;
				cout << a[0] << a[1] << a[2] << a[3];
			}
			k = a[0];
		}while(next_permutation(a,a+4));
		cout << endl;
	}
	return 0;
}
