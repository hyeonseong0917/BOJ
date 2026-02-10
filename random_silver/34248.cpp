#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int one = 0, two = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) one++;
        else if (a[i] == 2) two++;
    }
    
    if (one >= two) {
        one -= two;
        two = 0;
    }
    
    if (one % 3 == 0 && two == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}