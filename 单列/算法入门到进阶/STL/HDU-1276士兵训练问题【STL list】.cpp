#include<iostream>
#include<list>
#include<algorithm>

using namespace std;
int n;
int main(){
	int t;
	cin >> t;
		while(t--){
			cin >> n;
			list<int> l;
			list<int>::iterator it;
			for(int i=1;i<=n;i++) l.push_back(i);
			int k = 2;
			while(l.size()>3){
				int num = 0;
				for(it=l.begin();it!=l.end();){
					num++;
					if(num%k==0) {
						it = l.erase(it);
					}
					else it++;
				}
				k==2?k=3:k=2;
			}
			for(it=l.begin();it!=l.end();it++){
				if(it!=l.begin()) cout << " ";
				cout << *it ;
			} 
			cout << endl;
		}
	return 0;
}
