#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long


vector<int> v[1000+1];
vector<bool> visited(1000+1,0);
void dfs(int cur_num){
	for(int i=0;i<v[cur_num].size();++i){
		int next_num=v[cur_num][i];
		if(!visited[next_num]){
			visited[next_num]=1;
			dfs(next_num);
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		int n,m;
		cin>>n>>m;
		
		for(int i=0;i<m;++i){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			if(!visited[i]){
				visited[i]=1;
				dfs(i);
				++ans;
			}
		}
		cout<<ans;
	}
	return 0;
}