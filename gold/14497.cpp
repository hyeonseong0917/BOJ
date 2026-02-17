#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll n, m;
ll sy, sx, ey, ex;  // start_y, start_x, end_y, end_x
char table[301][301];
bool visited[301][301];
ll dy[4] = {-1, 0, 1, 0};
ll dx[4] = {0, 1, 0, -1};

void Input() {
    cin >> n >> m;
    cin >> sy >> sx >> ey >> ex;
    sy--; sx--; ey--; ex--;  // 0-based indexing
    
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            cin >> table[i][j];
        }
    }
    
    // visited 배열 초기화
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }
}

bool isRange(ll y, ll x) {
    return (y >= 0 && x >= 0 && y < n && x < m);
}

void BFS() {
    queue<pair<ll, ll>> q[2];
    q[0].push(make_pair(sy, sx));
    ll day = 0;
    
    while(true) {
        while(!q[day % 2].empty()) {
            pair<ll, ll> cur = q[day % 2].front();
            q[day % 2].pop();
            ll cy = cur.first;
            ll cx = cur.second;
            
            for(ll i = 0; i < 4; ++i) {
                ll ny = cy + dy[i];
                ll nx = cx + dx[i];
                
                if(!isRange(ny, nx)) continue;
                if(visited[ny][nx]) continue;
                
                visited[ny][nx] = true;
                
                if(table[ny][nx] == '0') {
                    q[day % 2].push(make_pair(ny, nx));
                }
                else if(table[ny][nx] == '1') {
                    q[(day + 1) % 2].push(make_pair(ny, nx));
                    table[ny][nx] = '0';
                }
                else if(table[ny][nx] == '#') {
                    cout << day + 1 << "\n";
                    return;
                }
            }
        }
        day++;
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