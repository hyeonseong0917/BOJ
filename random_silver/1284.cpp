#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back
void solv(int number){
    string s = to_string(number);
    int res = 0;
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '1') {
            res += 2;
        } else if (s[i] == '0') {
            res += 4;
        } else{
            res += 3;
        }
    }
    cout << res + s.length() + 1 << '\n';
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
        int number;
        while (1){
            cin >> number;
            if(number == 0) break;
            solv(number);
        }
	} 
	return 0;
}