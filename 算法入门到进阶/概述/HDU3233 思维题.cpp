#include<iostream>

using namespace std;
typedef long long ll;
int main(){
	int T,n,B,i=0;
	double s,p;
	while(cin>>T>>n>>B&&(T&&n&&B)){
		i++;
		double sum = 0;
		while(T--){
//			cin >> s >> p;
			scanf("%lf%lf",&s,&p);
			sum += s*(100-p)*0.01;
		}
		printf("Case %d: %0.2lf\n\n",i,sum/(1.0*B));	
	} 
	return 0;
} 
