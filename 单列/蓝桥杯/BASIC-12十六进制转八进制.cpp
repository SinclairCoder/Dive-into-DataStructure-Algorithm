//#include<iostream>
//
//
//using namespace std;
//const int maxn = 100010; 
//int n;
//string s;
//string hexarr[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
//			"1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
//int main(){
//	cin >> n;
//	while(n--){
//		cin >> s;
//		string bin,oct;
//		for(int i=0;i<s.length();i++){
//			bin += hexarr[isdigit(s[i])?s[i]-'0':s[i]-'A'+10];
//		}
//		if(bin.length()%3==1) bin.insert(0,"00");
//		else if(bin.length()%3==2) bin.insert(0,"0");
//		for(int i=0;i<bin.length();i+=3){
//			int ans = 0;
//			for(int j=i;j<i+3;j++){
//				ans = ans*2+bin[j]-'0';
//			}
//			oct += ans+'0';
//		}
//		while(oct[0]=='0') oct.erase(oct.begin());
//		cout << oct << endl;
//	} 
//	return 0;
//} 
#include<iostream>
using namespace std;
void MaxSequence(int* a,int n);
int main()
{
	int i,n;
	cin>>n;
	int* a = new int[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	MaxSequence(a,n);
	return 0;
}
void MaxSequence(int* a,int n)
{
	int i,j=0,k=0;
	int flag = 0;
	int sum = 0,max = 0;
	for(i=0;i<n;i++){
		sum = sum + a[i];
		if(max<sum){
			max = sum;
			k = i;
		}
		if(sum<0){
			sum  = 0;
		}
		if(a[i]>=0){
			flag = 1;
		}
	}
	if(!flag){
		cout<<0<<" "<<0<<" "<<0<<endl;
		return ;
	}
	sum = 0;
	for(i=k;i>=0;i--){
		sum = sum+a[i];
		if(sum == max)
			j = i;
	}

	if(max){
		cout<<max<<" "<<a[j]<<" "<<a[k]<<endl;
	}else{
		cout<<0<<" "<<a[0]<<" "<<a[n-1]<<endl;
	}
}
