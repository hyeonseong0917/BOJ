#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // 열 배정 + set에 (y, col) 저장
    set<pair<long long,int>> grid;
    int col = 0;
    long long col_max = 0;
    for (int i = 0; i < n; i++) {
        if (col_max >= v[i]) {
            col++;
            col_max = 0;
        }
        col_max = v[i];
        grid.insert({v[i], col});
    }

    // set BFS
    int ans = 0;
    while (!grid.empty()) {
        ans++;
        queue<pair<long long,int>> q;
        auto start = *grid.begin();
        grid.erase(grid.begin());
        q.push(start);

        while (!q.empty()) {
            auto [y, c] = q.front(); q.pop();

            // 상하: 실제 y값 ±1, 같은 열
            // 좌우: 같은 y값, 열 ±1
            vector<pair<long long,int>> neighbors = {
                {y-1, c}, {y+1, c},
                {y, c-1}, {y, c+1}
            };
            for (auto nb : neighbors) {
                if (grid.count(nb)) {
                    grid.erase(nb);
                    q.push(nb);
                }
            }
        }
    }

    cout << ans << "\n" << n << "\n";
    return 0;
}