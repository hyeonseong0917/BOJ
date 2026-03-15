#include <iostream>
#include <vector>
using namespace std;

int parent[100002];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);  // 경로 압축
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<long long> ans(n + 1, 0);
    for (int i = 1; i <= n + 1; i++) parent[i] = i;

    while (q--) {
        int a, b;
        long long x;
        cin >> a >> b >> x;

        int cur = find(a);  // a 이상의 첫 미색칠 칸
        while (cur <= b) {
            ans[cur] = x;
            parent[cur] = cur + 1;  // 색칠됐으니 다음 칸으로 점프
            cur = find(cur + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i < n) cout << ' ';
    }
    cout << '\n';

    return 0;
}