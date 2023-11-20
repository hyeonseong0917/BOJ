#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int T;
int K;
vector<string> gear;
vector<pair<int,int>> turn;
void Input(){
	cin>>T;
	for(int i=0;i<T;++i){
		string s="";
		cin>>s;
		gear.push_back(s);
	}
	 
	cin>>K;
	for(int i=0;i<K;++i){
		int a,b;
		cin>>a>>b;
		turn.push_back({a-1,b});
	}
	
}
bool visited[1000+1];
string turn_gear(string cur_str, int cur_dir){
	string new_str="";
	if(cur_dir==1){
		new_str+=cur_str[7];
		new_str+=cur_str.substr(0,7);
	}else{
		new_str=cur_str.substr(1,7);
		new_str+=cur_str[0];
	}
	return new_str;
}
void solve(){
	for(int i=0;i<K;++i){
		int cur_idx=turn[i].first;
		int cur_dir=turn[i].second;
		queue<pair<int,int>> q;
		q.push({cur_idx,cur_dir});
		for(int j=0;j<T;++j){
			visited[j]=0;
		}
		visited[cur_idx]=1;
		while(!q.empty()){
			// 현재 회전시킬 내용
			int idx=q.front().first;
			int dir=q.front().second;
			q.pop();
			// 1. idx주변 톱니바퀴들 확인
			if(idx-1>=0){
				if(gear[idx-1][2]!=gear[idx][6] && !visited[idx-1]){
					visited[idx-1]=1;
					q.push({idx-1,dir*-1});
				}
			}
			if(idx+1<T){
				if(gear[idx+1][6]!=gear[idx][2] && !visited[idx+1]){
					visited[idx+1]=1;
					q.push({idx+1,dir*-1});
				}
			}
			// 2. idx번째 톱니바퀴를 dir방향으로 회전시킬 예정
			gear[idx]=turn_gear(gear[idx],dir);
		}
	}
	int cnt=0;
	for(int i=0;i<T;++i){
		if(gear[i][0]=='1') ++cnt;
	}
	cout<<cnt<<endl;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	
	return 0;
}