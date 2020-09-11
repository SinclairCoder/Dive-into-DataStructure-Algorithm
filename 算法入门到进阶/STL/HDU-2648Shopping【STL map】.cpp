#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;
int n,m;
int main(){
	while(cin >> n){
		string s;
		for(int i=0;i<n;i++) cin >> s;
		cin >> m;
		map<string,int> maps;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				int p;
				cin >> p >> s;
				maps[s]+= p;
			}	
			int rank = 1;
			map<string,int>::iterator it = maps.begin();
			for(;it!=maps.end();it++){
				if(it->second>maps["memory"]) rank++;
			}
			cout << rank << endl;
		} 
	}
	
	return 0;
}
