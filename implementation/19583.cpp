#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

string S,E,Q;
vector<pair<string,string>> chat_table;
void Input(){
	string s="";
	getline(cin,s);
	vector<string> to_split;
	string tmp="";
	for(int i=0;i<s.size();++i){
		if(s[i]==' '){
			to_split.push_back(tmp);
			tmp="";
		}else{
			tmp+=s[i];
		}
	}
	to_split.push_back(tmp);
	S=to_split[0];
	E=to_split[1];
	Q=to_split[2];
	// cout<<S<<" "<<E<<" "<<Q<<endl;
	while(1){
		string s="";
		getline(cin,s);
		if(s==""){
			break;
		}
		string chat_time="";
		string chat_name="";
		bool flag=0;
		for(int i=0;i<s.size();++i){
			if(s[i]==' '){
				flag=1;
				continue;
			}
			if(flag==0){
				chat_time+=s[i];
			}else{
				chat_name+=s[i];
			}
		}
		chat_table.push_back({chat_time,chat_name});
	}
}
//start 시간 <= finish 시간
bool isTimeRight(string start, string finish){
	string start_clock=start.substr(0,2);
	string finish_clock=finish.substr(0,2);
	int start_num=stoi(start_clock);
	int finish_num=stoi(finish_clock);
	if(start_num<finish_num){
		return 1;
	}else if(start_num>finish_num){
		return 0;
	}else{
		string start_min=start.substr(3,2);
		string finish_min=finish.substr(3,2);
		if(start_min<=finish_min){
			return 1;
		}else{
			return 0;
		}
	}
}
void solve(){
	map<string,int> IN,OUT;
	int cnt=0;
	for(int i=0;i<chat_table.size();++i){
		string cur_time=chat_table[i].first;
		string cur_name=chat_table[i].second;
		// cout<<i<<" "<<isTimeRight(E,cur_time)<<" "<<isTimeRight(cur_time,Q)<<endl;
		if(isTimeRight(cur_time,S)){
			//현재 시간이 s이전이라면	
			if(IN[cur_name]==0){
				IN[cur_name]=1;
			}
			
		}else if(isTimeRight(E,cur_time) && isTimeRight(cur_time,Q)){
			//현재 시간이 Q보다 크거나 같고 E보다 작거나 같다면
			if(IN[cur_name]==1 && OUT[cur_name]==0){
				OUT[cur_name]=1;
				++cnt;
			}
		}
	}
	cout<<cnt;
}
int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}