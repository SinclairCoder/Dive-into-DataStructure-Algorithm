#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;

int cnt[26];
int main(){
	string s;
	while(cin>>s&&s!="END"){
		sort(s.begin(),s.end());
		priority_queue<int,vector<int>,greater<int> > qu;
		int count = 1;
		for(int i=1;i<s.length();i++){
			if(s[i]!=s[i-1]){
				qu.push(count);
				count = 1;
			}
			else count++;
		}
		qu.push(count);
		int naiveLen = s.length()*8;
//		cout << qu.size() << endl;
//		cout << qu.top() << endl;
		int ans = 0;
		if(qu.size()==1) {
			printf("%d %d 8.0\n",naiveLen,s.length());
			continue;
		}
		while(qu.size()>1){
			int a = qu.top(); qu.pop();
			int b = qu.top(); qu.pop();
			qu.push(a+b);
			ans += a+b;
		}
		qu.pop();
		double res = naiveLen*1.0/(1.0*ans);
		printf("%d %d %.1lf\n",naiveLen,ans,res); 
	}
	return 0;
}
