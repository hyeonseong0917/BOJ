#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m,k;
		cin>>n>>m>>k;
		vector<string> v;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			sort(s.begin(),s.end());
			v.push_back(s);
		}
		sort(v.begin(),v.end());
		string ans_str="";
		for(ll i=0;i<k;++i){
			ans_str+=v[i];
		}
		sort(ans_str.begin(),ans_str.end());
		cout<<ans_str;
	}
	return 0;
}