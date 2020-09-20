#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
string s1,s2,res;
int main(){
	getline(cin,s1);
	getline(cin,s2);
	unordered_map<char,int> umap;
	for(int i=0;i<s2.length();i++)
		umap[s2[i]]++;
	for(auto&c:s1){
		if(!umap[c]) res+= c;
	}
	cout << res << endl;
	return 0;
} 
