#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long


int V,E;
const int MAX=400+1;
int INF=1222232421;
vector<vector<pair<int,int>>> v;
int ans=INF;
int dist[MAX][MAX]={0};

void Input(){
	cin>>V>>E;
	for(int i=1;i<=V;++i){
		for(int j=1;j<=V;++j){
			dist[i][j]=INF;
		}
	}
	v.resize(V+1);
	for(int i=0;i<E;++i){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		dist[a][b]=c;
	}
}


void solve(){
	
	for(int i=1;i<=V;++i){
		// i번 정점을 경유하는 경우에 대해
		for(int j=1;j<=V;++j){
			for(int k=1;k<=V;++k){
				if(dist[j][i]!=INF && dist[i][k]!=INF){
					dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
				}
			}
		}
		
	}
	for(int i=1;i<=V;++i){
		ans=min(ans,dist[i][i]);
	}
	if(ans>=INF){
		cout<<-1;
	}else{
		cout<<ans;
	}
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