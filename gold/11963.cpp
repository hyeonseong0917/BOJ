#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll o=1;
    while(o--){
        ll n;
        cin>>n;
        vector<ll> v(n,0);
        vector<ll> check(n*2+1,0);
        for(ll i=0;i<n;++i){
            cin>>v[i];
            ++check[v[i]];
        }
        vector<ll> p;
        for(ll i=1;i<=2*n;++i){
            if(!check[i]){
                p.push_back(i);
            }
        }
        // 1 8 4 3
        // 6 7
        // 2 5 6 7
        ll ans=0;
        vector<ll> fst_vec;
        for(ll i=0;i<n/2;++i){
            fst_vec.push_back(v[i]);
        }
        sort(fst_vec.begin(),fst_vec.end());
        vector<ll> fst_p;
        for(ll i=n/2;i<n;++i){
            fst_p.push_back(p[i]);
        }
        ll idx=0;
        for(ll i=0;i<n/2;++i){
            // fst_vec[i]에 대응을 어떻게 할 것인지?
            while(1){
                if(idx>=n/2) break;
                if(fst_vec[i]<fst_p[idx]){
                    ++idx;
                    ++ans;
                    break;
                }
                ++idx;
            }
        }
        // cout<<ans<<endl;
        vector<ll> sed_vec;
        for(ll i=n/2;i<n;++i){
            sed_vec.push_back(v[i]);
        }
        sort(sed_vec.rbegin(),sed_vec.rend());
        // sed_vec은 내림차순 정렬

        vector<ll> sed_p;
        for(ll i=n/2-1;i>=0;--i){
            sed_p.push_back(p[i]);
        }
        // sed_p는 내림차순 정렬

        idx=0;
        for(ll i=0;i<n/2;++i){
            // sed_vec[i]에 대응을 어떻게 할 것인지?
            while(1){
                if(idx>=n/2) break;
                if(sed_vec[i]>sed_p[idx]){
                    ++idx;
                    ++ans;
                    break;
                }
                ++idx;
            }
        }
        cout<<ans;
    }
    return 0;
}