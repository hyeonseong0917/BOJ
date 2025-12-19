#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

ll check[100+10][100+10];

bool isRange(ll y, ll x){
    return (y>=1 && x>=1 && y<=100 && x<=100);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	while(t--){
		ll n;
        cin>>n;
        for(ll i=1;i<=100;++i){
            for(ll j=1;j<=100;++j){
                check[i][j]=0;
            }
        }
        
        for(ll i=0;i<n;++i){
            ll a,b;
            cin>>a>>b;
            // [b,a]에서 [b+10,a+10] 
            // 테두리만
            for(ll j=b;j<b+10;++j){
                for(ll k=a;k<a+10;++k){
                    ++check[j][k];
                }
            }
        }
        ll ans=0;
        ll dy[4]={-1,0,1,0};
        ll dx[4]={0,1,0,-1};
        for(ll i=1;i<=100;++i){
            for(ll j=1;j<=100;++j){
                if(check[i][j]){
                    ll cnt=0;
                    for(ll k=0;k<4;++k){
                        ll ny=i+dy[k];
                        ll nx=j+dx[k];
                        if(!isRange(ny,nx)) continue;
                        if(check[ny][nx]){
                            ++cnt;
                        }
                    }
                    if(cnt!=4){
                        ++ans;
                    }
                    if(cnt==2){
                        ++ans;
                    }
                }
            }
        }
        cout<<ans;

	} 
	return 0;
}