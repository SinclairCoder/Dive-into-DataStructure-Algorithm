#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
const int N = 1e5+10,MAX = 2e9;
typedef pair<int,int> PII; 
vector<PII> intervel;

void merge(vector<PII>& intervel){
	int l = -MAX,r = -MAX;
	vector<PII> res; 
	for(auto&item:intervel){
		if(item.first>r){
			if(l!=-MAX) res.push_back({l,r});
			l = item.first, r = item.second; 
		}
		else {
			r = max(r,item.second);
		}
	}
	if(l!=-MAX) res.push_back({l,r}); 
	intervel = res;
} 
 
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		intervel.push_back({l,r});
	}
	merge(intervel);
	cout << intervel.size() << endl;
	return 0;
}
