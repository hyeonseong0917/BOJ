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
        ll ans=0;
        ll n;
        cin>>n;
        priority_queue<ll> pq;
        ll max_num=0;
        for(ll i=0;i<n;++i){
            ll a;
            cin>>a;
            pq.push(a*-1);
        }
        if(n==1){
            cout<<0;
            break;
        }
        // 5 8 8
        while(!pq.empty()){
            if(pq.size()==1){
                break;
            }
            ll a=pq.top()*-1;
            pq.pop();
            ll b=pq.top()*-1;
            pq.pop();
            ans+=a+b;
            pq.push((a+b)*-1);
        }
        cout<<ans;
    }
    return 0;
}