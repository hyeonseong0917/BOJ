#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;	
	while(o--){
		ll m,n;
		cin>>m>>n;
		vector<pair<string,int>> v;
		vector<string> idx;
		idx.push_back("zero");
		idx.push_back("one");
		idx.push_back("two");
		idx.push_back("three");
		idx.push_back("four");
		idx.push_back("five");
		idx.push_back("six");
		idx.push_back("seven");
		idx.push_back("eight");
		idx.push_back("nine"); //idx[9]
		for(ll i=m;i<=n;++i){
			string s=to_string(i);
			string cur_str="";
			for(ll j=0;j<s.size();++j){
				cur_str+=idx[s[j]-'0'];
			}
			v.push_back({cur_str,i});
		}
		sort(v.begin(),v.end());
		ll cnt=0;
		for(ll i=0;i<v.size();++i){
			cout<<v[i].second;
			++cnt;
			if(cnt%10==0){
				cout<<"\n";
			}else{
				cout<<" ";
			}
		}

	}
	return 0;
}