#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll n,m,K;
string board[10+1];
ll dp[10+1][10+1][5+1];
ll dy[8]={-1,-1,-1,0,0,1,1,1};
ll dx[8]={-1,0,1,-1,1,-1,0,1};

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>n>>m>>K;
		for(ll i=0;i<n;++i){
			cin>>board[i];
		}
		vector<string> v;
		for(ll i=0;i<K;++i){
			string s;
			cin>>s;
			v.push_back(s);
		}
		for(ll i=0;i<K;++i){
			string s=v[i];
			for(ll j=0;j<n;++j){
				for(ll k=0;k<m;++k){
					for(ll p=0;p<5;++p){
						dp[j][k][p]=0;
					}
				}
			}
			for(ll j=0;j<n;++j){
				for(ll k=0;k<m;++k){
					if(board[j][k]==s[0]){
						dp[j][k][0]=1;
					}
				}
			}
			for(ll j=1;j<s.size();++j){
				for(ll k=0;k<n;++k){
					for(ll p=0;p<m;++p){
						if(s[j]==board[k][p]){
							for(ll q=0;q<8;++q){
								ll ny=(k+dy[q]+n)%n;
								ll nx=(p+dx[q]+m)%m;
								dp[k][p][j]+=dp[ny][nx][j-1];
							}
						}
					}
				}
			}
			ll cnt=0;
			for(ll j=0;j<n;++j){
				for(ll k=0;k<m;++k){
					cnt+=dp[j][k][s.size()-1];
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}