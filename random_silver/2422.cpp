#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

int N,M;
const int MAX=200+1;
int graph[MAX][MAX];
void Input(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			graph[i][j]=0;
		}
	}
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		graph[a][b]=1;
		graph[b][a]=1;
	}
}
int cnt=0;
void solve(){
	for(int i=1;i<=N;++i){
		for(int j=i+1;j<=N;++j){
			for(int k=j+1;k<=N;++k){
				if(i==j || i==k || j==k) continue;
				if(!graph[i][j] && !graph[i][k] && !graph[j][k]){
					++cnt;
				}
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	Input();
	solve();
	cout<<cnt;
	
	return 0;
}