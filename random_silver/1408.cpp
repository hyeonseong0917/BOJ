#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string s,t;
	cin>>s;
	cin>>t;
	int fst_time=0;
	int sed_time=0;
	fst_time+=stoi(s.substr(6,2));
	fst_time+=stoi(s.substr(3,2))*60;
	fst_time+=stoi(s.substr(0,2))*3600;
	
	sed_time+=stoi(t.substr(6,2));
	sed_time+=stoi(t.substr(3,2))*60;
	sed_time+=stoi(t.substr(0,2))*3600;
	
	// cout<<sed_time-fst_time;
	
	if(sed_time<fst_time){
		sed_time+=3600*24;
	}
	int total_time=sed_time-fst_time;
	int fst_time_num=total_time/3600;
	string fst_ans="";
	if(fst_time_num/10==0){
		fst_ans="0";
	}
	// cout<<fst_time_num<<endl;
	fst_ans+=to_string(fst_time_num);
	total_time%=3600;
	
	int sed_time_num=total_time/60;
	string sed_ans="";
	if(sed_time_num/10==0){
		sed_ans="0";
	}
	sed_ans+=to_string(sed_time_num);
	total_time%=60;
	
	int trd_time_num=total_time;
	string trd_ans="";
	if(trd_time_num/10==0){
		trd_ans="0";
	}
	trd_ans+=to_string(trd_time_num);
	cout<<fst_ans<<":"<<sed_ans<<":"<<trd_ans;
	return 0;
}