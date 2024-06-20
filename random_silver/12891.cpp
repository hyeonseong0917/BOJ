#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		int n,p;
		cin>>n>>p;
		string s;
		cin>>s;
		int a,c,g,t;
		cin>>a>>c>>g>>t;
		int L=0, R=p-1;
		int ans=0;
		vector<int> v(4,0);
		for(int i=0;i<p;++i){
			if(s[i]=='A') ++v[0];
			if(s[i]=='C') ++v[1];
			if(s[i]=='G') ++v[2];
			if(s[i]=='T') ++v[3];
		}
		map<char,int> mapping;
		mapping['A']=0;
		mapping['C']=1;
		mapping['G']=2;
		mapping['T']=3;
		while(L<=R && R<n){
			if(v[0]==a && v[1]==c && v[2]==g && v[3]==t){
				++ans;
			}
			if(R+1<n){
				int cur_idx=mapping[s[L]];
				--v[cur_idx];
				int next_idx=mapping[s[R+1]];
				++v[next_idx];
			}
			++L;
			++R;
		}
		cout<<ans<<"\n";
	}
	

	

	return 0;
}