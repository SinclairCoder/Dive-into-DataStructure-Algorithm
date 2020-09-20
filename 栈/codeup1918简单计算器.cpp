#include<iostream>
#include<map> 
#include<stack>
using namespace std;
stack<char> op;
stack<double> st;

void cal(){
	char c = op.top(); op.pop();
	double num1 = st.top();st.pop();
	double num2 = st.top(); st.pop();
	switch(c){
		case '+':st.push(num2+num1);break;
		case '-':st.push(num2-num1);break;
		case '*':st.push(num2*num1);break;
		case '/':st.push(num2/num1);break;
	}
}
double solve(string s){
	map<char,int> f;
	f['+']= 1, f['-'] = 1, f['*']=2,f['/']=2;
	for(int i=0;i<s.length();i++){
		if(i<s.length()&&isdigit(s[i])){
			int ans = 0;
			while(i<s.length()&&isdigit(s[i])){
				ans = ans*10+ s[i]-'0';i++; 
			}
			st.push(ans);
		}
		if(i<s.length()&&!isdigit(s[i])){
			if(op.size()==0||f[s[i]]>f[op.top()]){
				op.push(s[i]);
			}
			else {
				while(op.size()&&f[s[i]]<=f[op.top()]){
					cal(); 
				} 	
				op.push(s[i]);
			}
		}	
	}
	while(op.size()) cal();
	return st.top();	
}
int main(){
	string s;
	while(getline(cin,s)&&s!="0"){
		for(auto it=s.end();it!=s.begin();it--){
			if(*it==' ') s.erase(it);
		}
//		cout << s << endl;
		double res = solve(s);
		printf("%.2lf\n",res); 
	}
	return 0;
}
