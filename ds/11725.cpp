#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

const int MAX=100000+1;
vector<int> g[MAX];
int depth[MAX];
bool visited[MAX];

void search(int cur_node, int height){
	depth[cur_node]=height;
	visited[cur_node]=1;
	for(int i=0;i<g[cur_node].size();++i){
		int next_node=g[cur_node][i];
		if(!visited[next_node]){
			search(next_node,height+1);
		}
		
	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N=0;
	cin>>N;
	for(int i=1;i<=N;++i){
		depth[i]=0;
	}
	for(int i=0;i<N-1;++i){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	search(1,0);
	for(int i=2;i<=N;++i){
		int cur_depth=depth[i];
		for(int j=0;j<g[i].size();++j){
			int next=g[i][j];
			if(depth[next]<cur_depth){
				cout<<next<<"\n";
				break;
			}
		}
	}
	// cout<<depth[5];
	return 0;
}