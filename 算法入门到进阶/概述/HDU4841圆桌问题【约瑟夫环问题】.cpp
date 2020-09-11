#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<set>
#include<cstring>
#include<functional>

typedef long long ll;

using namespace std;
const int maxn = 1e6+9;
int main(){
	int n,m;
	vector<int> table;
	while(~scanf("%d%d",&n,&m)){
		table.resize(2*n);
		for(int i=0;i<2*n;i++) table[i] = i;
		int pos = 0;
		for(int i=0;i<n;i++){
			pos = (pos+m-1)%table.size();
			table.erase(table.begin()+pos);
		}
//		int j=0;
//		for(int i=0;i<2*n;i++){
//			if((i%50==0)&&i) printf("\n");
//			if(j<table.size()&&table[j]==i){
//				printf("G");
//				j++; 
//			}
//			else printf("B");
//		}
		char res[maxn];
		fill(res,res+maxn,'B');
		for(int i=0;i<table.size();i++){
			res[table[i]] = 'G';
		}
		for(int i=0;i<2*n;i++){
			if((i%50==0)&&i) printf("\n");
			printf("%c",res[i]);
		}
		printf("\n\n");
	}
	return 0;
}
