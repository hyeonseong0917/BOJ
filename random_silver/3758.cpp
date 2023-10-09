#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long

int n,k,t,m;

const int MAX=100+1;

vector<pair<int,pair<int,int>>> v[MAX]; //v[i][j]: i번째 학생의 j번째 문제에 대해 몇 번의 제출 횟수를 가지고 있었는지와 {점수,시간}
vector<pair<int,pair<int,int>>> result(MAX,{0,{0,0}}); // i번쨰 학생의 total 점수, 풀이 제출 횟수, 최종 제출 시간
vector<pair<pair<int,int>,pair<int,int>>> res; //{{idx,점수},{제출횟수, 최종 제출 시간}}
void Init(){
	for(int i=0;i<MAX;++i){
		v[i].clear();
	}
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			v[i].push_back({0,{0,0}});
		}
		result[i]={0,{0,0}};
	}
	res.clear();
}

bool comp(pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b){
	if(a.first.second==b.first.second){
		if(a.second.first==b.second.first){
			return a.second.second<b.second.second;
		}
		return a.second.first<b.second.first;
	}
	return a.first.second>b.first.second;
}

void solve(){
	for(int i=1;i<=n;++i){
		int cur_team=i;
		int cur_submit_cnt=0;
		int cur_score=0;
		int last_submit_time=0;
		for(int j=1;j<=k;++j){ 
			cur_score+=v[i][j].second.first;
			cur_submit_cnt+=v[i][j].first;
			last_submit_time=max(last_submit_time,v[i][j].second.second);
		}
		// cout<<i<<" "<<cur_score<<endl;
		result[i]={cur_score,{cur_submit_cnt,last_submit_time}};
	}
	// for(int i=1;i<=n;++i){
	// 	cout<<result[i].first<<" "<<result[i].second.first<<" "<<result[i].second.second<<endl;
	// }
	for(int i=1;i<=n;++i){
		res.push_back({{i,result[i].first},{result[i].second.first, result[i].second.second}});
	}
	sort(res.begin(),res.end(),comp);
	int rank=1;
	for(int i=0;i<res.size();++i){
		// cout<<res[i].first.first<<" "<<res[i].first.second<<" "<<res[i].second.first<<" "<<res[i].second.second<<endl;
		if(res[i].first.first==t){
			break;
		}
		++rank;
	}
	cout<<rank<<endl;
}

int main() {
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int p=0;
	cin>>p;
	while(p--){
		Init();
		cin>>n>>k>>t>>m;
		for(int i=0;i<m;++i){
			int a,b,c;
			cin>>a>>b>>c; // 팀, 문제번호, 점수
			v[a][b]={v[a][b].first+1, {max(c,v[a][b].second.first),i}};
		}
		solve();
	}

	return 0;
}