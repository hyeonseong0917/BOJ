#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

string board[5+1];
bool get_sum(string board[5+1]){
	// 정삼각형
	ll y=0, x=4;
	ll sum=0;
	bool flag=0;
	// 왼쪽 대각선 변
	for(ll i=0;i<4;++i){
		sum+=board[y+i][x-i]-'A';
	}
	// cout<<sum<<endl;
	if(sum!=22){
		flag=1;
	}
	// 중앙 변
	y=3, x=1, sum=0;
	for(ll i=1;i<=7;i+=2){
		sum+=board[y][i]-'A';
	}
	// cout<<sum<<endl;
	if(sum!=22){
		flag=1;
	}

	// 오른쪽 대각선 변
	y=0, x=4, sum=0;
	for(ll i=0;i<4;++i){
		sum+=board[y+i][x+i]-'A';
	}
	// cout<<sum<<endl;
	if(sum!=22){
		flag=1;
	}


	// 역삼각형
	
	// 왼쪽 대각선 변
	y=1, x=1, sum=0;
	for(ll i=0;i<4;++i){
		sum+=board[y+i][x+i]-'A';
	}
	// cout<<sum<<endl;
	if(sum!=22){
		flag=1;
	}
	// 오른쪽 대각선 변
	y=1, x=7, sum=0;
	for(ll i=0;i<4;++i){
		sum+=board[y+i][x-i]-'A';
	}
	// cout<<sum<<endl;
	if(sum!=22){
		flag=1;
	}

	// 중앙 변
	y=1, x=1, sum=0;
	for(ll i=1;i<=7;i+=2){
		sum+=board[y][i]-'A';
	}
	// cout<<sum<<endl;
	if(sum!=22){
		flag=1;
	}
	if(!flag){
		return 1;
	}else{
		return 0;
	}
}
bool visited[12+1];
vector<pair<ll,pair<ll,ll>>> v;
vector<string> ans;
bool flag=0;
map<string,ll> m;
void pick(ll cy, ll cx){
	// cout<<cy<<" "<<cx<<endl;
	if(v.size()==12){
		string tmp_board[5+1];
		for(ll i=0;i<5;++i){
			tmp_board[i]=board[i];
		}
		for(ll i=0;i<v.size();++i){
			ll y=v[i].second.first;
			ll x=v[i].second.second;
			ll c=v[i].first;
			tmp_board[y][x]='A'+c;
		}
		bool cur_sum=get_sum(tmp_board);
		if(cur_sum){
			string tmp="";
			for(ll i=0;i<5;++i){
				for(ll j=0;j<9;++j){
					tmp+=tmp_board[i][j];
				}
			}
			ans.push_back(tmp);
		}
		return;
	}
	while(1){
		if(cx==9){
			cx=0;
			++cy;
		}
		if(cy==5){
			break;
		}
		if(board[cy][cx]!='x'){
			++cx;
			continue;
		}
		if(board[cy][cx]=='x'){
			for(ll k=0;k<12;++k){
				if(!visited[k]){
					visited[k]=1;
					v.push_back({k,{cy,cx}});
					board[cy][cx]='A'+k;
					pick(cy,cx+1);
					v.pop_back();
					visited[k]=0;
					board[cy][cx]='x';
				}
			}
		}

	}
	
}
string u[5+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		// abcdefghijkl 1에서 12까지
		for(ll i=0;i<5;++i){
			cin>>board[i];
			for(ll j=0;j<9;++j){
				if(board[i][j]!='.' && board[i][j]!='x'){
					++visited[(board[i][j]-'A')];
					v.push_back({board[i][j]-'A',{i,j}});
				}
			}
		}
		pick(0,0);
		ll as=ans.size();
		cout<<as;
		// for(ll i=0;i<5;++i){
		// 	cin>>u[i];
		// }
		// cout<<get_sum(u);
		// 합이 26
	}
	return 0;
}