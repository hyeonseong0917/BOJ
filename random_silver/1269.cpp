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
	int o=1;
	while(o--){
		int n,m;
		cin>>n>>m;
		vector<int> a(n,0);
		vector<int> b(m,0);
		map<int,int> ma,mb;
		for(int i=0;i<n;++i){
			cin>>a[i];
			++ma[a[i]];
		}
		for(int i=0;i<m;++i){
			cin>>b[i];
			++mb[b[i]];
		}
		// a-b구하기
		map<int,int> mc;
		int ans=0;
		for(int i=0;i<n;++i){
			if(mb[a[i]]) continue;
			if(!mc[a[i]]){
				++mc[a[i]];
				++ans;
			}
		}
		for(int i=0;i<m;++i){
			if(ma[b[i]]) continue;
			if(!mc[b[i]]){
				++mc[b[i]];
				++ans;
			}
		}
		cout<<ans;
	}
	return 0;
}