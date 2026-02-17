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
map<pair<ll,ll>,vector<pair<ll,ll>>> check;
void Input(){
    cin>>n>>m;
    for(ll i=0;i<m;++i){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        check[{a,b}].push_back({c,d});
    }
}
bool isRange(ll y, ll x){
    return (y>=1 && x>=1 && y<=n && x<=n);
}
ll dy[4]={-1,0,1,0};
ll dx[4]={0,1,0,-1};
map<pair<ll,ll>,ll> pos_check;
void BFS(){
    ll ans=1;
    queue<pair<ll,ll>> q;
    q.push({1,1});
    bool visited[n+1][n+1];
    bool fired[n+1][n+1];
    for(ll i=0;i<n+1;++i){
        for(ll j=0;j<n+1;++j){
            visited[i][j]=0;
            fired[i][j]=0;
        }
    }
    fired[1][1]=1;
    visited[1][1]=1;
    ll fs=0;
    while(!q.empty()){
        ll qs=q.size();
        ll y=q.front().first;
        ll x=q.front().second;
        q.pop();
        // 언제 종료해야하지?
        if(qs<fs) break;
        if(!fired[y][x]){
            ++fs;
            q.push({y,x});
            continue;
        }
        fs=0;

        // 불을 켤 수 있는 방의 최대 개수
        // y,x에 연결된 모든 방의 불을 킴
        // vector<pair<ll,ll>> v;
        for(ll i=0;i<check[{y,x}].size();++i){
            ll ny=check[{y,x}][i].first;
            ll nx=check[{y,x}][i].second;
            if(!fired[ny][nx]){
                fired[ny][nx]=1;
                // v.push_back({ny,nx});
                ++ans;
            }
        }
        // 불 켜진 곳으로 "직선 이동으로" 갈 수 있는지? y,x에서 ny,nx까지..
        // 근데 그 사이에 빈 칸이 하나의 분기점 끝에서 열었을 때 생긴다면?
        /// 근데 분기점 하나의 끝이 바로 다음 step 열었을 때 생긴다면?
        for(ll i=0;i<4;++i){
            ll ny=y+dy[i];
            ll nx=x+dx[i];
            if(!isRange(ny,nx)) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx]=1;
            q.push({ny,nx});
        }
        
    }
    cout<<ans;
}
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    ll o=1;
    while(o--){
        Input();
        BFS();
    }
    return 0;
}