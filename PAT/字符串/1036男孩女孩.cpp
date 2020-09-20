#include<iostream>
#include<vector>
using namespace std;
int n;
int main(){
	cin >> n;
	string boy_name,boy_id,girl_name,girl_id;
	int boy_grade,girl_grade;
	for(int i=0;i<n;i++){
		string name,sex,id;
		int grade;
		cin >> name >> sex >> id >> grade ;
		if(sex=="M"){
			if(boy_name.empty()||grade<boy_grade){
				boy_name = name;
				boy_id = id;
				boy_grade = grade;
			}
		}
		if(sex=="F"){
			if(girl_name.empty()||grade>girl_grade){
				girl_name = name;
				girl_id = id; 
				girl_grade = grade;
			}
		}	
	} 
	if(girl_name.length()){
		cout << girl_name << ' ' << girl_id << endl;;
	}
	else cout << "Absent" << endl;
	if(boy_name.length()){
		cout << boy_name << ' ' << boy_id << endl;
	}
	else cout << "Absent" << endl;
	if(boy_name.length()&&girl_name.length()){
		cout << girl_grade - boy_grade << endl; 
	}
	else cout << "NA" << endl;
	return 0;
} 
