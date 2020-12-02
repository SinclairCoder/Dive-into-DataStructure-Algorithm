#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<stack>
#include<cstring>
#include<functional>

typedef long long ll;

using namespace std;
const int maxn = 1e6+9;

int main(){
	int n;
	cin >> n;
	cin.ignore();
//	getchar();
	while(n--){
		stack<char> st;
		char s[1010];
		scanf("%[^\n]",s);
		cout << s << endl;
		for(int i=0;i<strlen(s);i++){
			if(s[i]==' '||s[i]=='\n'||s[i]==EOF){
				while(!st.empty()){
					printf("%c",st.top());
					st.pop();
				}
				printf(" ");
			}
			else st.push(s[i]);
		}
		cout << endl;
	}
	return 0;
} 
