#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

vector<ll> check(12,0);
string board[5];
string tmp_board[5];
vector<string> v;
vector<pair<ll,ll>> p[6];
vector<pair<ll,ll>> star_pos;
bool isStar(string tmp_board[5]){
	// 합이 22
	bool flag=1;
	for(ll i=0;i<6;++i){
		// i번째 조건 만족?
		ll sum=0;
		for(ll j=0;j<4;++j){
			sum+=tmp_board[p[i][j].first][p[i][j].second]-'A';
		}
		if(sum!=22){
			flag=0;
			break;
		}
	}
	return flag;
}
vector<ll> c;
void pick(ll idx, ll pos_idx){
	if(!v.empty()){
		return;
	}
	if(idx==star_pos.size()){
		ll c_idx=0;
		for(ll i=0;i<star_pos.size();++i){
			ll y=star_pos[i].first;
			ll x=star_pos[i].second;
			board[y][x]='A'+c[c_idx++];
		}
		if(isStar(board)){
			string tmp="";
			for(ll i=0;i<5;++i){
				tmp+=board[i];
			}
			v.push_back(tmp);
		}
		return;
	}
	for(ll i=0;i<12;++i){
		if(!check[i]){
			check[i]=1;
			c.push_back(i);
			ll y=star_pos[pos_idx].first;
			ll x=star_pos[pos_idx].second;
			board[y][x]='A'+c[idx];

			pick(idx+1,pos_idx+1);

			c.pop_back();
			check[i]=0;
			board[y][x]='x';
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		for(ll i=0;i<5;++i){
			cin>>board[i];
			for(ll j=0;j<9;++j){
				if(board[i][j]>='A' && board[i][j]<='L'){
					ll c=board[i][j]-'A';
					++check[c];
				}
				if(board[i][j]=='x'){
					star_pos.push_back({i,j});
				}
			}
			tmp_board[i]=board[i];
		}
		// 정삼각형좌변
		p[0].push_back({0,4});
		p[0].push_back({1,3});
		p[0].push_back({2,2});
		p[0].push_back({3,1});

		// 정삼각형 밑변
		p[1].push_back({3,1});
		p[1].push_back({3,3});
		p[1].push_back({3,5});
		p[1].push_back({3,7});

		// 정삼각형 우변
		p[2].push_back({0,4});
		p[2].push_back({1,5});
		p[2].push_back({2,6});
		p[2].push_back({3,7});

		// 역삼각형 밑변
		p[3].push_back({1,1});
		p[3].push_back({1,3});
		p[3].push_back({1,5});
		p[3].push_back({1,7});

		// 역삼각형 좌변
		p[4].push_back({1,1});
		p[4].push_back({2,2});
		p[4].push_back({3,3});
		p[4].push_back({4,4});

		// 역삼각형 우변
		p[5].push_back({4,4});
		p[5].push_back({3,5});
		p[5].push_back({2,6});
		p[5].push_back({1,7});
		

		pick(0,0);
		if(!v.empty()){
			sort(v.begin(),v.end());
			string k=v[0];
			vector<string> k_tmp;
			string k_tmp_str="";
			for(ll i=0;i<k.size();++i){
				k_tmp_str+=k[i];
				ll ks=k_tmp_str.size();
				if(ks==9){
					k_tmp.push_back(k_tmp_str);
					k_tmp_str="";
				}
			}
			for(ll i=0;i<5;++i){
				cout<<k_tmp[i]<<"\n";
			}
		}
	}
	return 0;
}