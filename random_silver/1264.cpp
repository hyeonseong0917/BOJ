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

int ans;
char s[256];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(1){
		ans = 0;
		
		cin.getline(s, 256);

		if (s[0] == '#') break;

		for (int i = 0; i < strlen(s) - 1; i++)
		{
			if (s[i] == 'a') ans++;
			if (s[i] == 'e') ans++;
			if (s[i] == 'i') ans++;
			if (s[i] == 'o') ans++;
			if (s[i] == 'u') ans++;
			if (s[i] == 'A') ans++;
			if (s[i] == 'E') ans++;
			if (s[i] == 'I') ans++;
			if (s[i] == 'O') ans++;
			if (s[i] == 'U') ans++;
		}
		cout << ans << '\n';
	} 
	return 0;
}