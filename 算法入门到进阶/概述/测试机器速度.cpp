#include<iostream>
#include<ctime>
using namespace std;
typedef long long ll;
const int n = 1e8;
int main(){
	int t = 0;
	clock_t start,end;
	start = clock();
	for(int i=0;i<n;i++) t++;
	end = clock();
	cout << (double)(end-start)/CLOCKS_PER_SEC << endl;
	return 0;
}
