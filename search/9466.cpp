#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX=100000+1;
int t=0,n=0;
vector<int> g[MAX];
bool visited[MAX];
bool is_cycle[MAX];
int cnt=0;
queue<int> q;
void dfs(int cur_node){
	// cout<<cur_node<<endl;
	visited[cur_node]=1;
	q.push(cur_node);
	int next_node=g[cur_node][0];
	
	if(visited[next_node]){
		bool flag=0;
		while(!q.empty()){
			int cur_num=q.front();
			q.pop();
			if(cur_num==next_node){
				flag=1;
			}
			if(flag){
				// cout<<cur_node<<" "<<cur_num<<endl;
				is_cycle[cur_num]=1;
			}
		}
		return;
	}
	dfs(next_node);
	
		
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n;
		cnt=0;
		for(int i=0;i<MAX;++i){
			g[i].clear();
			is_cycle[i]=0;
			visited[i]=0;
		}
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			g[i+1].push_back(a);
		}
		for(int i=0;i<n;++i){
			if(!visited[i+1]){
				q=queue<int>();
				dfs(i+1);
				// cout<<endl;
			}
			
		}
		for(int i=1;i<=n;++i){
			if(is_cycle[i]){
				++cnt;
			}
		}
		cout<<n-cnt<<"\n";
	}
	return 0;
}