#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

ll board[1000+1][1000+1];
ll n,m,k;
bool isRange(ll y ,ll x){
	return (y>=0 && x>=0 && y<n && x<m);
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;	
	// 1 2 3 4 5
	// 2 3 4 5 6
	// 3 4 5 6 7
	while(o--){
		
		cin>>n>>m>>k;
		// n*m에서 k이하의 수
		ll cur_num=1;
		for(ll i=0;i<m;++i){
			for(ll j=0;j<n;++j){
				board[j][i]=cur_num+j;
			}
			++cur_num;
		}
		cur_num=board[n-1][m-1];
		if(k>=cur_num){
			cout<<"YES"<<"\n";
			for(ll i=0;i<n;++i){
				for(ll j=0;j<m;++j){
					cout<<board[i][j]<<" ";
				}cout<<"\n";
			}
		}else{
			cout<<"NO";
		}
	}
	return 0;
}