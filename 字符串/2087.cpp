#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<list>
#include<set>
#include<cmath>
#include<queue>

using namespace std;
const int maxn = 1010;
char str[maxn], pattern[maxn];
int Next[maxn];
int cnt = 0;
void getfail(char*p, int plen){
	Next[0] = 0, Next[1] = 0;
	for(int i=1;i<plen;i++){
		int j = Next[i];
		while(j&&p[i]!=p[j]) j = Next[j];
		Next[i+1] = (p[i]==p[j])?j+1:0;
	}
}
void kmp(char *s,char * p){
	int last = -1;
	int slen = strlen(s), plen = strlen(p);
	getfail(p,plen);
	int j = 0;
	for(int i=0;i<slen;i++){
		while(j&&s[i]!=p[j]) j = Next[j];
		if(s[i]==p[j]) j++;
		if(j==plen){
			if(i-last>=plen){
				cnt ++;
				last = i;
			}
		}
	} 
}
int main(){
	
	while(~scanf("%s",str)){
		if(str[0]=='#') break;
		scanf("%s",pattern);
		cnt = 0;
		kmp(str,pattern);
		cout << cnt << endl;
	}
	return 0;
}
