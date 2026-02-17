#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n,m;
char board[1000+1][1000+1];
bool visited[1000+1][1000+1];
ll tonari_cnt[1000+1][1000+1];
queue<pair<ll,ll>> q;
ll dy[8]={-1,-1,-1,0,1,1,1,0};
ll dx[8]={-1,0,1,1,1,0,-1,-1};
bool isRange(ll y, ll x){
    return (y>=0 && x>=0 && y<n && x<m);
}
void Input(){
    cin>>n>>m;
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            visited[i][j]=0;
            cin>>board[i][j];
            tonari_cnt[i][j]=0;
        }
    }
}

void solve(){
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            if(board[i][j]!='.'){
                ll cnt=0;
                for(ll k=0;k<8;++k){
                    ll ny=i+dy[k];
                    ll nx=j+dx[k];
                    if(!isRange(ny,nx)) continue;
                    if(board[ny][nx]=='.'){
                        ++cnt;
                    }
                }
                tonari_cnt[i][j]=cnt;
            }
        }
    }
    // 핵심 로직은 어떻게?
    // 첫 번째로는 .과 인접한 좌표들 모두 넣기
    // 그 이후부터는 삭제가 일어나는 원소에 대해서만 인접 원소들을 큐에 넣음
    queue<pair<ll,ll>> q;
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            if(board[i][j]=='.') continue;
            if(tonari_cnt[i][j]>=(board[i][j]-'0')){
                visited[i][j]=1;
                q.push({i,j});
            }
        }
    }
    // cout<<"tonari ===== \n";
    // for(ll i=0;i<n;++i){
    //     for(ll j=0;j<m;++j){
    //         cout<<tonari_cnt[i][j];
    //     }cout<<"\n";
    // }
    
    ll ans=0;
    queue<pair<ll,ll>> tmp;
    while(1){
        while(!q.empty()){
            ll y=q.front().first;
            ll x=q.front().second;
            // cout<<y<<" "<<x<<"\n";
            q.pop();
            board[y][x]='.';
            for(ll i=0;i<8;++i){
                ll ny=y+dy[i];
                ll nx=x+dx[i];
                if(!isRange(ny,nx)) continue;
                if(board[ny][nx]=='.') continue;
                ++tonari_cnt[ny][nx];
                if(tonari_cnt[ny][nx]>=(board[ny][nx]-'0') && !visited[ny][nx]){
                    // if(ny==1 && nx==3){
                    //     cout<<tonari_cnt[ny][nx]<<"fwefwefwe"<<" "<<board[]endl;
                    // }
                    visited[ny][nx]=1;
                    tmp.push({ny,nx});
                }
            }
        }
        // cout<<"board ===== \n";
        // for(ll i=0;i<n;++i){
        //     for(ll j=0;j<m;++j){
        //         cout<<board[i][j];
        //     }cout<<"\n";
        // }
        // cout<<"tonari ===== \n";
        // for(ll i=0;i<n;++i){
        //     for(ll j=0;j<m;++j){
        //         cout<<tonari_cnt[i][j];
        //     }cout<<"\n";
        // }
        if(tmp.empty()){
            if(ans!=0){
                ++ans;
            }
            break;
        }else{
            ++ans;
            while(!tmp.empty()){
                pair<ll,ll> p=tmp.front();
                tmp.pop();
                q.push(p);
            }
            
        }
    }
    cout<<ans;
    
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