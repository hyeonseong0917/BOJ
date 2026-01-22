#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back

string board[50+1];
ll check[50+1][50+1];
ll n,m;
bool isRange(ll y, ll x){
  return (y>=0 && x>=0 && y<n && x<m);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
    // 1139
      
      cin>>n>>m;
      for(int i=0;i<n;++i){
        cin>>board[i];
        for(int j=0;j<m;++j){
          check[i][j]=0;
        }
      }
      ll ans=0;
      for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
          if(check[i][j]) continue;
          if(board[i][j]=='-'){
            ++ans;
            ++check[i][j];
            ll y=i;
            ll x=j;
            while(1){
              if(isRange(y,x) && board[y][x]==board[i][j]){
                ++check[y][x];
                x+=1;
              }else{
                break;
              }
            }
          }else{
            ++ans;
            ++check[i][j];
            ll y=i;
            ll x=j;
            while(1){
              if(isRange(y,x) && board[y][x]==board[i][j]){
                ++check[y][x];
                y+=1;
              }else{
                break;
              }
            }
          }
        }
      }
      cout<<ans;
	} 
	return 0;
}