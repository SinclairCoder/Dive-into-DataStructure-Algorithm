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
	// 按照左端点排序
	sort(intervel.begin(),intervel.end());
	vector<PII> res; 
	for(auto&item:intervel){
		// 如果新区间左端点大于当前区间右端点 
		if(item.first>r){
			// 新区间出现，进行更新 
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
