#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

string board[50+1];
ll parent[50+1];
ll FIND(ll y){
	if(parent[y]==y) return y;
	return parent[y]=FIND(parent[y]);
}
void UNION(ll y, ll x){
	y=FIND(y);
	x=FIND(x);
	if(y!=x){
		parent[y]=x;
	}
}
int check[50+1][50+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// n개의 방
		ll n;
		cin>>n;
		for(ll i=0;i<n;++i){
			cin>>board[i];
			parent[i]=i;
			for(ll j=0;j<n;++j){
				check[i][j]=0;
			}
		}
		if(n==1){
			if(board[0][0]=='0'){
				cout<<0;
			}else{
				if(board[0][0]>='a' && board[0][0]<='z'){
					cout<<(board[0][0]-'a')+1;
				}else{
					cout<<(board[0][0]-'A')+1+26;
				}
			}
			break;
		}
		bool flag=0;
		vector<pair<ll,pair<ll,ll>>> v;
		ll total_len=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<n;++j){
				if(board[i][j]!='0'){
					++check[i][j];
					++check[j][i];
					if(board[i][j]>='a' && board[i][j]<='z'){
						total_len+=(board[i][j]-'a')+1;
						v.push_back({(board[i][j]-'a')+1,{i,j}});
					}
					if(board[i][j]>='A' && board[i][j]<='Z'){
						total_len+=(board[i][j]-'A')+1+26;
						v.push_back({(board[i][j]-'A')+1+26,{i,j}});
					}
				}
			}
		}
		// 27+52+1+26=106
		sort(v.begin(),v.end());
		ll min_num=0;
		ll cnt=0;
		for(ll i=0;i<v.size();++i){
			ll cur_num=v[i].first;
			ll y=v[i].second.first;
			ll x=v[i].second.second;
			if(FIND(y)==FIND(x)) continue;
			UNION(y,x);
			// cout<<cur_num<<endl;
			min_num+=cur_num;
			++cnt;
		}
		if(cnt==n-1){
			cout<<total_len-min_num;
		}else{
			cout<<-1;
		}
		
	}	
	return 0;
}