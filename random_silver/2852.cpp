#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<string,string>> v; // v[i]: {i+1번째 팀의 총 이기고 있던 시간}
int score[2+1]={0,}; //score[i]: i+1번째 팀의 현재 점수
vector<pair<int,string>> series; // {득점한 팀 정보, 언제 득점했는지}
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int team_num;
		string team_get_time;
		cin>>team_num;
		cin>>team_get_time;
		series.push_back({team_num,team_get_time});
	}
	v.push_back({"00","00"});
	v.push_back({"00","00"});
	score[0]=0;
	score[1]=0;
}
void time_add(int team_num, int start_idx, int fin_idx){
	if(fin_idx==N){
		series.push_back({team_num+1,"48:00"});
	}
	// team_num번째 팀의 총 이기고 있던  시간에
	// fin_idx에서 start_idx번째 시간을 뺀 값을 더해줌
	int cur_clock=stoi(v[team_num].first);
	int cur_min=stoi(v[team_num].second);
	
	int start_clock=stoi(series[start_idx].second.substr(0,2));
	int start_min=stoi(series[start_idx].second.substr(3,2));
	int fin_clock=stoi(series[fin_idx].second.substr(0,2));
	int fin_min=stoi(series[fin_idx].second.substr(3,2));
	int total_clock=fin_clock-start_clock;
	int total_min=fin_min-start_min;
	if(total_min<0){
		total_min+=60;
		total_clock-=1;
	}
	cur_clock+=total_clock;
	cur_min+=total_min;
	if(cur_min>=60){
		++cur_clock;
		cur_min-=60;
	}
	v[team_num].first=to_string(cur_clock);
	v[team_num].second=to_string(cur_min);
	if(v[team_num].first.size()==1){
		string tmp="0";
		tmp+=v[team_num].first;
		v[team_num].first=tmp;
	}
	if(v[team_num].second.size()==1){
		string tmp="0";
		tmp+=v[team_num].second;
		v[team_num].second=tmp;
	}
	
}
void solve(){
	int idx=0;
	int pre_idx=0;
	while(idx<=N){
		if(idx==N){
			break;
		}
		// idx번째 이벤트가 발생했음
		if(idx==0){
			++score[series[idx].first-1];	
		}
		if(score[0]==score[1]){
			// 넣은 골이 동점골이었음
			++idx;
			++score[series[idx].first-1];
		}else{
			// 동점골을 언제 넣는지  찾기
			int next_idx=N;
			for(int i=idx+1;i<N;++i){
				++score[series[i].first-1];
				if(score[0]==score[1]){
					next_idx=i;
					break;
				}
			}
			if(next_idx!=N){
				time_add(series[idx].first-1, idx, next_idx);
			}else{
				//동점골이 없었음, idx번째 값부터 48까지 차이값을 더해줌
				time_add(series[idx].first-1, idx, N);
			}
			idx=next_idx;
		}
		// cout<<v[0].first<<" "<<v[0].second<<endl;
		// cout<<v[1].first<<" "<<v[1].second<<endl;
	}
	cout<<v[0].first<<":"<<v[0].second<<"\n";
	cout<<v[1].first<<":"<<v[1].second<<"\n";
	
}


int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}