#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

const int MAX=100000+1;
int N,K;
bool visited[MAX];
vector<int> v[MAX];
void Input(){
	cin>>N>>K;
}
bool isRange(int num){
	return (num>=0 && num<=100000);
}
void BFS(){
	queue<pair<int,int>> q; //{위치,시간}
	visited[N]=1;
	q.push({N,0});
	vector<int> ans;
	while(!q.empty()){
		int cur_pos=q.front().first;
		int cur_time=q.front().second;
		q.pop();
		// cout<<cur_pos<<endl;
		if(cur_pos==K){
			cout<<cur_time<<"\n";
			int next_pos;
			ans.push_back(K);
			while(1){
				if(cur_pos==N){
					break;
				}
				next_pos=v[cur_pos][0];
				ans.push_back(next_pos);
				cur_pos=next_pos;
				
			}
			reverse(ans.begin(),ans.end());
			for(int i=0;i<ans.size();++i){
				cout<<ans[i]<<" ";
			}
			return;
		}
		int first_walk=cur_pos-1;
		int second_walk=cur_pos+1;
		int teleport=cur_pos*2;
		if(isRange(first_walk) && !visited[first_walk]){
			q.push({first_walk,cur_time+1});
			visited[first_walk]=1;
			v[first_walk].push_back(cur_pos);
		}
		if(isRange(second_walk) && !visited[second_walk]){
			q.push({second_walk,cur_time+1});
			visited[second_walk]=1;
			v[second_walk].push_back(cur_pos);
		}
		if(isRange(teleport) && !visited[teleport]){
			q.push({teleport,cur_time+1});
			visited[teleport]=1;
			v[teleport].push_back(cur_pos);
		}
	}
	
}

void solve(){
	Input();
	BFS();
	// BFS();
}


int main() {
	// your code goes here
	solve();
	
	return 0;
}