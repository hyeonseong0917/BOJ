#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define ll long long

ll n,m;
vector<ll> v;
vector<ll> tmp;
void dfs(){
    ll ts=tmp.size();
    if(ts==m){
        for(ll i=0;i<ts;++i){
            cout<<tmp[i];
            if(i!=ts-1){
                cout<<" ";
            }
        }
        cout<<"\n";
        return;
    }
    map<ll,ll> check;
    for(ll i=0;i<n;++i){
        if(check[v[i]]) continue;
        ++check[v[i]];
        tmp.push_back(v[i]);
        dfs();
        tmp.pop_back();
    }
}
int main() {
    ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    cin>>n>>m;
    for(ll i=0;i<n;++i){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    dfs();
    return 0;
}