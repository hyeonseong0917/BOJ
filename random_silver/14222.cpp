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

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n,0);
        for(ll i=0;i<n;++i){
            cin>>v[i];
        }
        sort(v.rbegin(),v.rend());
        vector<ll> check(51,0);
        bool flag=0;
        for(ll i=0;i<n;++i){
            // i번째에는 n-i라는 수가 있어야 함
            bool c=0;
            for(ll j=n;j>=1;--j){
                if(check[j]) continue;
                // v[i]에서 연산을 수행해서 j를 만들 수 있는지?
                ll diff=j-v[i];
                if(diff<0) break;
                if(diff%k==0){
                    ++check[j];
                    c=1;
                    break;
                }
            }
            if(!c){
                ++check[v[i]];
            }
        }
        for(ll i=1;i<=n;++i){
            if(!check[i]){
                flag=1;
            }
        }
        if(flag){
            cout<<0;
        }else{
            cout<<1;
        }
	} 
	return 0;
}