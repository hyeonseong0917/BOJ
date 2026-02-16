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
        vector<ll> v(6,0);
        ll sum=0;
        ll max_num=0;
        for(ll i=0;i<6;++i){
            cin>>v[i];
            sum+=v[i];
            max_num=max(max_num,v[i]);
        }
        // sort(v.begin(),v.end());
        if(n==1){
            cout<<sum-max_num;
            break;
        }
        ll ans=250000000000000+1;
        vector<ll> c;
        ll fst_num=min(v[0],v[5]);
        c.push_back(fst_num);
        ll sed_num=min(v[1],v[4]);
        c.push_back(sed_num);
        ll trd_num=min(v[2],v[3]);
        c.push_back(trd_num);
        sort(c.begin(),c.end());
        fst_num=c[0];
        sed_num=c[1];
        trd_num=c[2];

        ll fst_sum=2*n*n*fst_num;
        ll sed_sum=2*(2*n*sed_num+n*(n-2)*fst_num);
        ll trd_sum=trd_num*4+4*(n-2)*sed_num+(n-2)*(n-2)*fst_num;
        ans=min(ans,fst_sum+sed_sum+trd_sum);
        
        cout<<ans;
    }
    return 0;
}