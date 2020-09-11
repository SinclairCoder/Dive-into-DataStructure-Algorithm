#include<bits/stdc++.h>

using namespace std;

int c;
bool cmp(double a,double b){
	return a<b;
}
int main(){
	
	while(~scanf("%d",&c)&&c){
		for(int i=0;i<c;i++){
			int n,v,w;
			scanf("%d%d%d",&n,&v,&w);
			double p[150];
			for(int j=0;j<n;j++){
				scanf("%lf",&p[j]);
			}
			sort(p,p+n,less<double>());
			int cnt = 0;
			double resp = 0.0;
			for(int i=0;i<n;i++){
				double tmp = (resp*cnt+p[i]/100.0)/(cnt+1);
//				cout << tmp << endl;
				if(tmp<=w/100.0) resp = tmp,cnt++;
				else break; 
			}
			if(cnt){
				printf("%d %.2lf\n",cnt*v,resp);
			}
			else printf("0 0.00\n");
		}
	}
	return 0;
}
