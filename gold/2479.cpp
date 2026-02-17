#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n,k;
char board[1000+1][1000+1];
ll dp[1000+1];
ll dist[1000+1][1000+1];
ll s,f;
ll INF=2023101800;
void Input(){
    cin>>n>>k;
    for(ll i=0;i<n;++i){
        for(ll j=0;j<k;++j){
            cin>>board[i][j];
            dist[i][j]=0;
        }
        dp[i]=INF;
    }
    cin>>s>>f;
    --s;
    --f;
}
// dp[i]: i를 만드는데 소요된 최소 스텝
vector<ll> tmp;
void dfs(ll cur_num, ll max_num){
    ll ts=tmp.size();
    if(ts==max_num){
        return;
    }
    for(ll i=0;i<n;++i){
        if(dist[i][cur_num]==1){
            if(dp[i]==dp[cur_num]-1){
                tmp.push_back(i);
                dfs(i,max_num);
                break;
            }
        }
    }
}
void solve(){
    bool visited[1000+1];
    for(ll i=0;i<n;++i){
        for(ll j=i+1;j<n;++j){
            // i와 j의 거리
            ll cnt=0;
            for(ll p=0;p<k;++p){
                if(board[i][p]!=board[j][p]){
                    ++cnt;
                }
            }
            dist[i][j]=cnt;
            dist[j][i]=cnt;
        }
        visited[i]=0;
    }
    dp[s]=0;
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        ll p=q.front();
        q.pop();
        if(p==f) break;
        for(ll i=0;i<n;++i){
            if(dist[p][i]!=1) continue;
            if(dp[i]>dp[p]+1){
                dp[i]=dp[p]+1;
                q.push(i);
            }
        }
    }
    if(dp[f]==INF){
        cout<<-1;
    }else{
        ll max_num=dp[f];
        tmp.push_back(f);
        dfs(f,max_num+1);
        for(ll i=max_num;i>=0;--i){
            cout<<tmp[i]+1;
            if(i!=0){
                cout<<" ";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll o = 1;
    while(o--) {
        Input();
        solve();
    }
    return 0;
}