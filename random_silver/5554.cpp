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
		int i, tmp, sum = 0;
		for(i=0; i<4; i++) {
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum/60);
		printf("%d\n", sum%60);
		return 0;
	} 
	return 0;
}