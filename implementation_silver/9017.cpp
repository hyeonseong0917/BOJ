#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int t=0;
int N=0;
const int MAX=1000+1;
int team[MAX];
int team_num[MAX];
int score[MAX];
vector<int> team_score[MAX];
void Init(){
	
	for(int i=0;i<MAX;++i){
		team[i]=0;
		team_num[i]=0;
		score[i]=0;
		team_score[i].clear();
	}
}
bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	if(a.first==b.first){
		return a.second.second<b.second.second;
	}
	return a.first<b.first;
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		cin>>N;
		Init();
		for(int i=0;i<N;++i){
			cin>>team[i];
			++team_num[team[i]];
		}
		int cnt=1;
		for(int i=0;i<N;++i){
			if(team_num[team[i]]==6){
				score[i]=cnt++;
			}
			// cout<<i<<" "<<score[i]<<endl;
		}
		for(int i=0;i<N;++i){
			if(score[i]){
				team_score[team[i]].push_back(score[i]);
			}	
		}
		
		vector<pair<int,pair<int,int>>> ans; //{점수,{팀번호,5번째값}}
		for(int i=0;i<N;++i){
			int cur_team=team[i];
			if(team_score[cur_team].size()==6){
				int cur_sum=0;
				for(int j=0;j<4;++j){
					cur_sum+=team_score[cur_team][j];
				}
				ans.push_back({cur_sum,{cur_team,team_score[cur_team][4]}});
			}
		}
		sort(ans.begin(),ans.end(),comp);
		cout<<ans[0].second.first<<"\n";
		
	}
	return 0;
}