#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    ll n;
    cin >> n;
    vector<ll> v(n,0);
    vector<ll> passed(n,0);
    vector<ll> next(n, -1);
    
    for(ll i=0;i<n;++i){
        cin >> v[i];
    }
    
    if(n==1){
        cout << 1;
        return 0;
    }
    
    sort(v.begin(), v.end());
    
    // 각 소의 패스 대상 계산
    next[0] = 1;  // 첫 번째는 무조건 오른쪽
    for(ll i=1; i<n-1; ++i){
        ll L = v[i] - v[i-1];
        ll R = v[i+1] - v[i];
        if(L <= R){
            next[i] = i-1;
        } else {
            next[i] = i+1;
        }
    }
    next[n-1] = n-2;  // 마지막은 무조건 왼쪽
    
    // passed 배열 계산
    for(ll i=0; i<n; ++i){
        passed[next[i]]++;
    }
    
    ll ans = 0;
    
    // 1. 아무도 패스해주지 않는 소
    for(ll i=0; i<n; ++i){
        if(!passed[i]) {
            ans++;
        }
    }
    
    // 2. 길이 2인 독립 사이클
    for(ll i=0; i<n; ++i){
        if(i < next[i] && next[next[i]] == i && passed[i] == 1 && passed[next[i]] == 1){
            ans++;
        }
    }
    
    cout << ans;
    return 0;
}