#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
const int maxn = 1e6+9;
int a[maxn];
int main(){
	int n,m,x;
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a)); 
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			a[x+500000]++;
		}
		int cnt = 0;
		for(int i=1000000;cnt<m;){
			if(a[i]){
				if(cnt) printf(" ");
				printf("%d",i-500000);
				cnt ++;
				a[i]--;
			} 
			else i--;
		}
		printf("\n");
	}
	return 0;
}

//#include<iostream>
//#include<algorithm>
//#include<functional>
//using namespace std;
//const int maxn = 1e6+9;
//int a[maxn];
//int main(){
//	int n,m;
//	while(~scanf("%d%d",&n,&m)){
//		for(int i=0;i<n;i++)
//			scanf("%d",a+i);
//		sort(a,a+n,greater<int>());
//		for(int i=0;i<m;i++){
//			if(i) printf(" ");
//			printf("%d",a[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
