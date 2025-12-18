#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

ll n,m;
string board[1000+1];
string ans[1000+1];
ll visited[1000+1][1000+1];
ll cy, cx;
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
char dir[4]={'U','R','D','L'};
bool isRange(ll y, ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
void BFS(){
	queue<pair<ll,ll>> q;
	q.push({cy,cx});
	visited[cy][cx]=1;
	char c=board[cy][cx];
	ans[cy][cx]='.';
	while(!q.empty()){
		ll y=q.front().first;
		ll x=q.front().second;
		q.pop();
		for(ll i=0;i<4;++i){
			ll ny=y+dy[i];
			ll nx=x+dx[i];
			if(!isRange(ny,nx)) continue;
			if(board[ny][nx]!=c) continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx]=1;
			ans[ny][nx]='.';
			q.push({ny,nx});
		}
	}
}
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m;
		for(ll i=0;i<n;++i){
			cin>>board[i];
			string tmp="";
			for(ll j=0;j<m;++j){
				tmp+='#';
				visited[i][j]=0;
			}
			ans[i]=tmp;
		}
		cin>>cy>>cx;
		--cy;
		--cx;
		string s;
		cin>>s;
		for(ll i=0;i<s.size();++i){
			char c=s[i];
			if(c=='W'){
				// BFS: cy,cx와 같은 구역 다 와드설치
				BFS();
			}else{
				// ans[cy][cx]='.';
				for(ll j=0;j<4;++j){
					if(c==dir[j]){
						cy+=dy[j];
						cx+=dx[j];
					}
				}
			}
		}
		ans[cy][cx]='.';
		for(ll i=0;i<4;++i){
			ll ny=cy+dy[i];
			ll nx=cx+dx[i];
			if(!isRange(ny,nx)) continue;
			ans[ny][nx]='.';
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cout<<ans[i][j];
			}cout<<"\n";
		}
	}
	return 0;
}