#include<iostream>
#include<cstring> 
using namespace std;
int arr[10];
int idx;
string s;
int main(){
	cin >> s;
	memset(arr,-1,sizeof arr);
	for(int i=0;i<s.length();i++){
		int t = s[i]-'0';
		if(arr[t]==-1) arr[t] = 1;
	}
	for(int i=9;i>=0;i--){
		if(arr[i]!=-1) arr[i] = idx++;
	}
	cout << "int[] arr = new int[]{";
	int first = 0;
	for(int i=9;i>=0;i--){
		if(arr[i]!=-1){
			if(!first){
				cout << i;
				first = 1;
			}
			else  cout << "," << i;
		}
	}
	cout << "};" << endl;
	first = 0;
	cout << "int[] index = new int[]{";
	for(int i=0;i<s.length();i++){
		if(!first){
			cout << arr[s[i]-'0'];
			first = 1;
		}
		else cout << "," << arr[s[i]-'0'];
	}
	cout << "};" << endl;
	return 0;
} 
