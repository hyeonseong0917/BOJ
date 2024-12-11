#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll a,b;
		cin>>a>>b;
		string aa=to_string(a);
		string bb=to_string(b);
		reverse(aa.begin(),aa.end());
		reverse(bb.begin(),bb.end());
		ll aaa=stoll(aa);
		ll bbb=stoll(bb);
		ll c=aaa+bbb;
		string cc=to_string(c);
		reverse(cc.begin(),cc.end());
		ll ccc=stoll(cc);
		cout<<ccc;

	}
	return 0;
}