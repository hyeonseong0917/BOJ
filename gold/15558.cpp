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
string board[2];
void Input() {
    cin>>n>>k;
    for(ll i=0;i<2;++i){
        cin>>board[i];
    }
}
void BFS(){
    ll y=0, x=0;
    bool flag=0;
    bool visited[2][n];
    for(ll i=0;i<n;++i){
        for(ll j=0;j<2;++j){
            visited[j][i]=0;
        }
    }
    queue<pair<ll,pair<ll,ll>>> q;
    // 0초에 0,0에 있음
    q.push({0,{0,0}});
    visited[0][0]=1;
    while(!q.empty() && !flag){
        ll cnt=q.front().first;
        ll y=q.front().second.first;
        ll x=q.front().second.second;
        // cout<<y<<" "<<x<<"\n";
        q.pop();
        // 현재 cnt초임
        // 움직임이 끝난 후 cnt칸을 삭제할거임
        // x+a>cnt면 가능
        
        // 1. 뒤로 이동
        ll fst_x=x-1;
        if(fst_x>cnt){
            if(!visited[y][fst_x] && board[y][fst_x]=='1'){
                visited[y][fst_x]=1;
                q.push({cnt+1,{y,fst_x}});
            }
        }
        // 2. 앞으로 이동
        ll sed_x=x+1;
        if(sed_x>=n){
            flag=1;
            break;
        }else{
            if(!visited[y][sed_x] && board[y][sed_x]=='1'){
                visited[y][sed_x]=1;
                q.push({cnt+1,{y,sed_x}});
            }
        }
        // 3. 옆 칸으로 이동
        ll trd_x=x+k;
        if(trd_x>=n){
            flag=1;
            break;
        }else{
            if(!visited[(y+1)%2][trd_x] && board[(y+1)%2][trd_x]=='1'){
                visited[(y+1)%2][trd_x]=1;
                q.push({cnt+1,{(y+1)%2,trd_x}});
            }
        }
    }
    if(flag){
        cout<<1;
    }else{
        cout<<0;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll o = 1;
    while(o--) {
        Input();
        BFS();
    }
    return 0;
}