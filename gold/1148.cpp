#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		vector<string> v;
		
		while(1){
			string s;
			cin>>s;
			if(s=="-"){
				break;
			}
			v.push_back(s);
		}
		vector<string> board;
		while(1){
			string s;
			cin>>s;
			if(s=="#"){
				break;
			}
			board.push_back(s);
		}
		for(ll i=0;i<board.size();++i){
			string cur_board=board[i];
			vector<ll> board_check(26,0);
			for(ll j=0;j<9;++j){
				++board_check[cur_board[j]-'A'];
			}
			vector<ll> center_cnt(26,0);
			for(ll j=0;j<v.size();++j){
				string cur_str=v[j];
				vector<ll> tmp_check(26,0);
				for(ll k=0;k<cur_str.size();++k){
					++tmp_check[cur_str[k]-'A'];
				}
				// board_check로 만들 수 있는지?
				bool flag=0;
				for(ll k=0;k<26;++k){
					if(board_check[k]<tmp_check[k]){
						flag=1;
						break;
					}
				}
				if(!flag){
					for(ll k=0;k<26;++k){
						if(tmp_check[k]){
							++center_cnt[k];
						}
					}
				}
			}
			ll min_num=2023101800;
			ll max_num=0;
			for(ll j=0;j<26;++j){
				if(!board_check[j]) continue;
				if(center_cnt[j]<min_num){
					min_num=center_cnt[j];
				}
				if(max_num<center_cnt[j]){
					max_num=center_cnt[j];
				}
			}
			string min_str="", max_str="";
			for(ll j=0;j<26;++j){
				if(!board_check[j]) continue;
				if(center_cnt[j]==min_num){
					min_str+=('A'+j);
				}
				if(center_cnt[j]==max_num){
					max_str+=('A'+j);
				}
			}
			cout<<min_str<<" "<<min_num<<" "<<max_str<<" "<<max_num<<"\n";
		}
		
	}
	return 0;
}