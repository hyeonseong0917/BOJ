#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		string s;
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) {
			// 대문자인 경우
			if(s[i] >= 65 && s[i]<97) {
			if (s[i]+13>90) {
				s[i] = s[i] + 13 - 26;
			} else
				s[i] = s[i] + 13;
			} // 소문자인 경우
			else if (s[i]>=97 && s[i]<=122) {
			if(s[i]+13>122)
				s[i] = s[i] + 13 - 26;
			else
				s[i] = s[i] + 13;
			}
			cout << s[i];
		}
	} 
	return 0;
}