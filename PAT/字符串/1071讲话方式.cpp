#include<iostream>
#include<unordered_map>

using namespace std;
string s;
char to_lower(char c){
	if(c>='A'&&c<='Z') return c+32;
	return c;
} 
bool check(char c){
	if(c>='A'&&c<='Z') return true;
	if(c>='a'&&c<='z') return true;
	if(c>='0'&&c<='9') return true;
	return false;
}
unordered_map<string,int> umap;
int main(){
	getline(cin,s);
	
	for(int i=0;i<s.length();i++){
		if(check(s[i])){
			int j = i;
			string word;
			while(j<s.length()&&check(s[j])) word+= to_lower(s[j]), j++;
			umap[word]++;
			i = j-1;
		}
	}
	string res;
	int cnt=0;
	for(auto&item:umap){
		if(item.second>cnt){
			cnt = item.second;
			res = item.first;
		}
	}
	cout << res << ' ' << cnt << endl;
	return 0;
}
