#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<set>
#include<string>
#include<functional>

typedef long long ll;

using namespace std;

int main(){
	vector<int> a;
	a.push_back(5);a.push_back(6);
	a.push_back(7);a.push_back(8);
	a.push_back(9);a.push_back(10);
	a.push_back(11);a.push_back(12);
	
	a.insert(a.begin()+1,100);
	a.erase(a.begin()+1);
	for(int i=0;i<a.size();i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
