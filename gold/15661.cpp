#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;


int N;
const int MAX=20+1;
int S[MAX][MAX];
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>S[i][j];
		}
	}
}
vector<int> cur_picked;
vector<int> next_picked;
bool visited[MAX];
void Init(){
	for(int i=0;i<MAX;++i){
		visited[i]=0;
	}
	cur_picked.clear();
	next_picked.clear();
}
int ans=1222232421;
void dfs(int idx, int cs){
	if(cur_picked.size()==cs){
		bool check[MAX];
		next_picked.clear();
		for(int i=0;i<N;++i){
			check[i]=0;
		}
		for(int i=0;i<cs;++i){
			check[cur_picked[i]]=1;
		}
		for(int i=0;i<N;++i){
			if(!check[i]){
				next_picked.push_back(i);
			}
		}
		int fst_sum=0;
		int sed_sum=0;
		for(int i=0;i<cur_picked.size();++i){
			for(int j=0;j<cur_picked.size();++j){
				if(i==j) continue;
				fst_sum+=S[cur_picked[i]][cur_picked[j]];	
			}
		}
		for(int i=0;i<next_picked.size();++i){
			for(int j=0;j<next_picked.size();++j){
				if(i==j) continue;
				sed_sum+=S[next_picked[i]][next_picked[j]];	
			}
		}
		ans=min(ans,abs(fst_sum-sed_sum));
		return;
	}
	if(idx==N){
		return;
	}
	for(int i=idx;i<N;++i){
		if(!visited[i]){
			visited[i]=1;
			cur_picked.push_back(i);
			dfs(i,cs);
			visited[i]=0;
			cur_picked.pop_back();
		}
	}
}
void solve(){
	for(int i=2;i<=N/2;++i){
		Init();
		dfs(0,i);	
	}
	cout<<ans;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Init();
	Input();
	solve();
	
	
	
	return 0;
}