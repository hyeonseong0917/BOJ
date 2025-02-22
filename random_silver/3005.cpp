#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll r,c;
		cin>>r>>c;
		vector<string> board;
		for(ll i=0;i<r;++i){
			string k;
			cin>>k;
			board.push_back(k);
		}
		vector<string> ans;
		for(ll i=0;i<r;++i){
			for(ll j=0;j<c;++j){
				string cur_str="";
				if(i==0 || board[i-1][j]=='#'){
					// 밑으로 뻗음 # 나오거나 r-1까지
					for(ll k=i;k<r;++k){
						if(board[k][j]=='#') break;
						cur_str+=board[k][j];
					}
					if(cur_str.size()>=2){
						ans.push_back(cur_str);
					}
				}
				cur_str="";
				if(j==0 || board[i][j-1]=='#'){
					for(ll k=j;k<c;++k){
						if(board[i][k]=='#') break;
						cur_str+=board[i][k];
					}
					if(cur_str.size()>=2){
						ans.push_back(cur_str);
					}
				}
			}
		}
		sort(ans.begin(),ans.end());
		cout<<ans[0];
	}

	return 0;
}