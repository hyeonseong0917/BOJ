#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

ll n,m;
string board[50+1];
ll psum[50+1][50+1];
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
			for(ll j=0;j<m;++j){
				psum[i][j]=0;
			}
		}
		psum[0][0]=board[0][0]-'0';
		for(ll i=1;i<n;++i){
			psum[i][0]=psum[i-1][0]+(board[i][0]-'0');
		}
		for(ll i=1;i<m;++i){
			psum[0][i]=psum[0][i-1]+(board[0][i]-'0');
		}
		for(ll i=1;i<n;++i){
			for(ll j=1;j<m;++j){
				psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+(board[i][j]-'0');
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				if(i==n-1 && j==m-1) break;
				// fst_num: psum[i][j];
				if(i==n-1 || j==m-1){
					if(i==n-1){
						// 열 기준
						for(ll k=j+1;k<m-1;++k){
							// fst: [j+1,k]열까지
							// sed: [k+1,m-1]열까지
							ll fst_num=psum[n-1][k]-psum[i][j];
							ll sed_num=psum[n-1][m-1]-psum[n-1][k];
							ans=max(ans,psum[i][j]*fst_num*sed_num);
						}
						// 행 기준
						for(ll k=0;k<n-1;++k){
							ll fst_num=psum[k][m-1]-psum[k][j];
							ll sed_num=psum[n-1][m-1]-psum[i][j]-fst_num;
							ans=max(ans,psum[i][j]*fst_num*sed_num);
						}
					}else{
						// j==m-1
						for(ll k=i+1;k<n-1;++k){
							// fst: [i+1,k]행까지
							// sed: [k+1,n-1]행까지
							ll fst_num=psum[k][j]-psum[i][j];
							ll sed_num=psum[n-1][m-1]-psum[i][j]-fst_num;
							ans=max(ans,psum[i][j]*fst_num*sed_num);
						}

						// 열 기준
						for(ll k=0;k<m-1;++k){
							ll fst_num=psum[n-1][k]-psum[i][k];
							ll sed_num=psum[n-1][m-1]-fst_num-psum[i][j];
							ans=max(ans,psum[i][j]*fst_num*sed_num);
						}
					}
				}else{
					ll fst_num=psum[n-1][j]-psum[i][j];
					ll sed_num=psum[i][m-1]-psum[i][j];
					ll com_num=psum[n-1][m-1]-fst_num-sed_num-psum[i][j];
					ans=max(ans,max(psum[i][j]*(fst_num+com_num)*sed_num,psum[i][j]*fst_num*(sed_num+com_num)));
				}
			}
		}
		cout<<ans;
		// 123
		// 456
		// 789
		// 3개의 직사각형의 곱을 최대로

		// y:[0,50]
		// x:[0,50]

	}
	return 0;
}