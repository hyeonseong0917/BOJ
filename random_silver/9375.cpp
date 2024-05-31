#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> cnt(30+1,0);
		map<string,int> m;
		int idx=1;
		for(int i=0;i<n;++i){
			string s,t;
			cin>>s;
			cin>>t;
			if(!m[t]){
				m[t]=idx++;
			}
			++cnt[m[t]];
		}
		int ans=1;
		for(int i=1;i<=30;++i){
			if(cnt[i]>0){
				ans*=(cnt[i]+1);
			}
		}
		ans-=1;
		cout<<ans<<"\n";
	}
	
	return 0;
}