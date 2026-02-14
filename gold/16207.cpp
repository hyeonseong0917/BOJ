#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll o=1;
    while(o--){
        ll n;
        cin>>n;
        vector<ll> v(n,0);
        for(ll i=0;i<n;++i){
            cin>>v[i];
        }
        sort(v.rbegin(),v.rend());
        ll fst_idx=0, sed_idx=0;
        ll ans=0;
        while(fst_idx+3<n){
            // fst_idx를 한 변으로 하는거 가능?
            if(v[fst_idx]==v[fst_idx+1]){
                // 가능
                // sed_idx를 한 변으로 하는거 가능?
                sed_idx=fst_idx+2;
                while(sed_idx<n-1){
                    if(v[sed_idx]==v[sed_idx+1] || v[sed_idx]==v[sed_idx+1]+1){
                        ans+=v[fst_idx]*min(v[sed_idx],v[sed_idx+1]);
                        break;
                    }
                    ++sed_idx;
                }
                fst_idx=sed_idx+2;
            }else{
                if(v[fst_idx]-1==v[fst_idx+1]){
                    // 1뺴고 가능
                    sed_idx=fst_idx+2;
                    // sed_idx를 한 변으로 하는거 가능?
                    sed_idx=fst_idx+2;
                    while(sed_idx<n-1){
                        if(v[sed_idx]==v[sed_idx+1] || v[sed_idx]==v[sed_idx+1]+1){
                            ans+=v[fst_idx+1]*min(v[sed_idx],v[sed_idx+1]);
                            break;
                        }
                        ++sed_idx;
                    }
                    fst_idx=sed_idx+2;
                }else{
                    ++fst_idx;
                }
            }
        }
        cout<<ans;
    }
    
    return 0;
}