#include<iostream>

using namespace std;

string a,b,c,d;
string week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
	cin >> a >> b >> c >> d;
	int k = 0;
	for(int i=k;i<a.length()&&i<b.length();i++){
		if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G') {
			k = i;
			cout << week[a[i]-'A'] << ' ';
			break;
		}
	}
	for(int j=k+1;j<a.length()&&j<b.length();j++){
		if(a[j]==b[j]&&(a[j]>='0'&&a[j]<='9'||a[j]>='A'&&a[j]<='N')){
			printf("%02d:",a[j]>='0'&&a[j]<='9'?a[j]-'0':a[j]-'A'+10);
			break;
		}
	}
	for(int i=0;i<c.length()&&i<d.length();i++){
		if(c[i]==d[i]&&(c[i]>='a'&&c[i]<='z'||c[i]>='A'&&c[i]<='Z')){
			printf("%02d",i);
		}
	}
	return 0;
}
