#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

int N,M,D;
const int MAX=20+1;
int board[MAX][MAX];
int tmp_board[MAX][MAX];
vector<int> archor;
bool visited[MAX];
vector<pair<int,int>> enemy;
vector<pair<int,int>> tmp_enemy;
void Input(){
	cin>>N>>M>>D;
	for(int i=0;i<MAX;++i){
		visited[i]=0;
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>board[i][j];
			if(board[i][j]==1){
				enemy.push_back({i,j});
				tmp_enemy.push_back({i,j});
			}
			tmp_board[i][j]=board[i][j];
		}
	}
}

int maxNum=-1;
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first>b.first;
}
int taxi_dist(pair<int,int> a, pair<int,int> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
bool dist_comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	if(a.second.first==b.second.first) return a.second.second<b.second.second;
	return a.second.first<b.second.first;
}
int inVade(vector<int> archor){
	//archor의 원소들의 열의 N+1행에 궁수들이 배치되어 있음
	enemy=tmp_enemy;
	int cnt=0;
	vector<int> del_idx;
	map<int,int> m;
	vector<int> del_range_idx;
	map<int,int> can_archor_atk;
	vector<pair<int,pair<int,int>>> dist;
	while(!enemy.empty()){
		del_idx.clear();
		del_range_idx.clear();
		m.clear();
		can_archor_atk.clear();
		sort(enemy.begin(),enemy.end(),comp);
		for(int i=0;i<3;++i){
			//i번째 궁수
			dist.clear();//dist{idx,{거리,열 번호}}
			for(int j=0;j<enemy.size();++j){
				//j번째 적을 공격
				int y=enemy[j].first;
				int x=enemy[j].second;
				int cur_dist=taxi_dist({y,x},{N,archor[i]});
				if(cur_dist<=D){
					dist.push_back({j,{cur_dist,x}});
				}
			}
			if(!dist.empty()){
				sort(dist.begin(),dist.end(),dist_comp);
				if(!m[dist[0].first]){
					m[dist[0].first]=1;
					++cnt;
					del_idx.push_back(dist[0].first);	
				}
				
				
			}
			
		}
		
		sort(del_idx.begin(),del_idx.end());
		reverse(del_idx.begin(),del_idx.end());
		for(int i=0;i<del_idx.size();++i){
			enemy.erase(enemy.begin()+del_idx[i]);
		}
		if(!enemy.empty()){
			for(int i=0;i<enemy.size();++i){
				++enemy[i].first;
				if(enemy[i].first>=N){
					del_range_idx.push_back(i);
				}
			}
			sort(del_range_idx.begin(),del_range_idx.end());
			reverse(del_range_idx.begin(),del_range_idx.end());
			for(int i=0;i<del_range_idx.size();++i){
				enemy.erase(enemy.begin()+del_range_idx[i]);
			}
		}
		
		// for(int i=0;i<enemy.size();++i){
		// 	cout<<enemy[i].first<<" ";
		// }cout<<endl;
		// cout<<enemy.size()<<endl;
		// break;
	}
	return cnt;
}
void pick_archor(int idx){
	if(archor.size()==3){
		//궁수 3명을 선택한 상태
		maxNum=max(maxNum,inVade(archor));
		// for(int i=0;i<archor.size();++i){
		// 	cout<<archor[i]<<" ";
		// }cout<<endl;
		return;
	}
	//idx열에 궁수를 배치
	for(int i=idx;i<M;++i){
		if(!visited[i]){
			visited[i]=1;
			archor.push_back(i);
			pick_archor(i);
			archor.pop_back();
			visited[i]=0;
		}
	}
}
void solve(){
	// vector<int> v;
	// v.push_back(0);
	// v.push_back(2);
	// v.push_back(3);
	// cout<<inVade(v);
	pick_archor(0);
	cout<<maxNum;
}
int main() {
	// your code goes here
	Input();
	solve();
	
	return 0;
}