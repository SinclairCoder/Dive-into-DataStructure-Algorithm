#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;


int main(){

	int T;
	while(~scanf("%d",&T)){
		while(T--){
			int n; string s;
			cin >> n >> s;
			if(s=="FIFO"){
				queue<int> qu;
				while(n--){
					string inout; int x;
					cin >> inout;
					if(inout=="IN"){
						cin >> x;
						qu.push(x);
					}
					else if(inout=="OUT"){
						if(qu.size()){
							cout << qu.front() << endl;
							qu.pop();
						}
						else cout << "None" << endl;
					}
				}
			}
			else if(s=="FILO"){
				stack<int> st;
				while(n--){
					string inout; int x;
					cin >> inout;
					if(inout=="IN"){
						cin >> x;
						st.push(x);
					}
					else if(inout=="OUT"){
						if(st.size()){
							cout << st.top() << endl;
							st.pop();
						}
						else cout << "None" << endl;
					}
				}
			}
		}
	}
	
	return 0;
}
