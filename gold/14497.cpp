#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;

#define ll long long

ll dy[8]={-1,-1,-1,0,1,1,1,0};
ll dx[8]={-1,0,1,1,1,0,-1,-1};
string board[300+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		ll y,x;
		ll fy,fx;
		cin>>y>>x;
		cin>>fy>>fx;
		--y;
		--x;
		--fy;
		--fx;
		for(ll i=0;i<n;++i){
			cin>>board[i];
		}
		
	}
	return 0;
}