#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 31*1440+10;
double sum[maxn];
int cost[24];
int n; 
struct Record{
	string name;
	string format_time;
	string state;
	int minutes;
	Record(char* _name,char* _ftime,char* _state,int _min){
		name = _name;
		format_time = _ftime;
		state = _state;
		minutes = _min;
	};
	bool operator< (const Record& t) const{
		return minutes < t.minutes;
	}
};
map<string,vector<Record>> persons;
int main(){
	for(int i=0;i<24;i++) cin >> cost[i];
	for(int i=1;i<maxn;i++) sum[i] = sum[i-1]+ cost[((i-1)%1440)/60]/100.0; // 计算每一分钟至当月一号一点的花费 
	cin >> n;
	char name[22],state[10],format_time[30];
	int month,day,hour,minute,minutes;
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d:%d %s",name,&month,&day,&hour,&minute,state);
		sprintf(format_time,"%02d:%02d:%02d",day,hour,minute);
		minutes = (day-1)*1440+hour*60+minute;
		persons[name].push_back(Record(name,format_time,state,minutes));	 
	}
	for(auto&person:persons){
		string cname = person.first; 
		vector<Record> Rvec = person.second;
		double total = 0.0;
		sort(Rvec.begin(),Rvec.end());
		for(int i=0;i+1<Rvec.size();i++){
			Record a = Rvec[i], b = Rvec[i+1];
			if(a.state=="on-line"&&b.state=="off-line"){
				if(!total){
					printf("%s %02d\n",cname.c_str(),month);
				}
				double c = sum[b.minutes] - sum[a.minutes];
				printf("%s %s %d $%.2lf\n",a.format_time.c_str(),b.format_time.c_str(),b.minutes-a.minutes,c);
				total += c;
			}	
		}
		if(total) printf("Total amount: $%.2lf\n",total);
	}
	return 0;
}
