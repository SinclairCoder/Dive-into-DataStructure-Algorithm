#include<bits/stdc++.h>

using namespace std;

int solve(string s){
	map<char,int> f;
	f['+']= 1, f['-'] = 1, f['x']=2,f['/']=2;
	stack<char> op;
	stack<int> st;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			st.push(s[i]-'0');
		} 
		else {
			if(op.size()==0){
				op.push(s[i]);
			}
			else {
				if(f[s[i]]<=f[op.top()]){
					char c = op.top(); op.pop();
					int num1 = st.top();st.pop();
					int num2 = st.top(); st.pop();
//					cout << num2 << " " << num1 << endl;
					if(c=='+') st.push(num2+num1);
					else if(c=='-') st.push(num2-num1);
					else if(c=='x') st.push(num2*num1);
					else if(c=='/') st.push(num2/num1);
					op.push(s[i]);
				} else {
					op.push(s[i]); 
				}
			}
		}
	}
	while(op.size()){
			char c = op.top(); op.pop();
			int num1 = st.top(); st.pop();
			int num2 = st.top(); st.pop();
			if(c=='+') st.push(num2+num1);
			else if(c=='-') st.push(num2-num1);
			else if(c=='x') st.push(num2*num1);
			else if(c=='/') st.push(num2/num1);
	}
	return st.top();
	
}
int main(){
	int n;
	cin >> n;
	string s;
	for(int i=0;i<n;i++){
		cin >> s;
		if(solve(s)==24) cout << "Yes" << endl;
		else cout << "No" << endl;
	} 
	return 0;
}

