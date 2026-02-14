#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll o=1;
    cin>>o;
    while(o--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(k==0){
            cout<<n<<"\n";
            cout<<s<<"\n";
            continue;
        }
        // k>=1
        vector<ll> g,h;
        for(ll i=0;i<n;++i){
            if(s[i]=='G'){
                g.push_back(i);
            }else{
                h.push_back(i);
            }
        }
        vector<ll> g_idx, h_idx;
        bool flag=0;
        vector<ll> check(100000,0);
        for(ll i=0;i<g.size();++i){
            if(g_idx.empty()){
                ll c=g[i]+k;
                if(c>=n-1){
                    c=n-1;
                    flag=1;
                }
                ++check[c];
                g_idx.push_back(c);
            }else{
                // g[i]가 현재 범위 이내에 있는지?
                ll last_g=g_idx[g_idx.size()-1];
                if((ll)(abs)(last_g-g[i])<=k) continue;
                ll c=g[i]+k;
                if(c>=n-1){
                    c=n-1;
                    flag=1;
                }
                
                if(last_g!=c){
                    ++check[c];
                    g_idx.push_back(c);
                }
            }
        }
        ll max_num=0;
        for(ll i=n-1;i>=0;--i){
            if(!check[i]){
                max_num=i;
                break;
            }
        }
        for(ll i=0;i<h.size();++i){
            if(h_idx.empty()){
                ll c=h[i]+k;
                if(c>=n-1){
                    // c는 [h[i]-k,h[i]+k]
                    c=max_num;
                }
                h_idx.push_back(c);
            }else{
                ll c=h[i]+k;
                if(c>=n-1){
                    c=max_num;
                }
                ll last_h=h_idx[h_idx.size()-1];
                if((ll)(abs)(last_h-h[i])<=k) continue;
                if(last_h!=c){
                    h_idx.push_back(c);
                }
            }
        }
        string ans="";
        for(ll i=0;i<n;++i){
            ans+='.';
        }
        for(ll i=0;i<g_idx.size();++i){
            ans[g_idx[i]]='G';
        }
        for(ll i=0;i<h_idx.size();++i){
            ans[h_idx[i]]='H';
        }
        ll c=g_idx.size()+h_idx.size();
        cout<<c<<"\n";
        cout<<ans<<"\n";
    }
    
    return 0;
}