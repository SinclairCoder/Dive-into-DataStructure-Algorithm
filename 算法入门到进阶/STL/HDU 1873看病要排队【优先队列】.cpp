#include<iostream>
#include<queue>
#include<string>

using namespace std;
struct Node{
	int id;
	int priority;
	Node(int i,int p){
		id = i;priority = p;
	}
	bool operator<(const Node&b) const{
		if(priority==b.priority) return id>b.id;
		else return priority < b.priority;
	}
};
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		priority_queue<Node> qu[3];
		int t = 0;
		while(n--){
			string in; int a,b;
			cin >> in >> a;
			if(in=="IN"){
				t++;
				cin >> b;
				qu[a-1].push(Node(t,b));
			}
			else if(in=="OUT"){
				if(qu[a-1].size()){
					Node e = qu[a-1].top();
					qu[a-1].pop();
					cout << e.id << endl;
				}
				else cout << "EMPTY" << endl;
			}
		}
	}
	return 0;
}
