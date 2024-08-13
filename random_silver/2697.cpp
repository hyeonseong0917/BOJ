#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll n=s.size();
		vector<string> ans;
		for(ll i=n-1;i>=1;--i){
			string tmp="";
			string tmp_s=s;
			for(ll j=i-1;j>=0;--j){
				// cout<<s[i]<<" "<<s[j]<<endl;
				if(s[i]>s[j]){
					char c=s[j];
					tmp_s[j]=tmp_s[i];
					tmp_s[i]=c;
					for(ll k=0;k<=j;++k){
						tmp+=tmp_s[k];
					}
					vector<char> v;
					for(ll k=j+1;k<n;++k){
						v.push_back(tmp_s[k]);
					}
					sort(v.begin(),v.end());
					for(ll k=0;k<v.size();++k){
						tmp+=v[k];
					}
					break;
				}
			}
			// cout<<s<<" "<<tmp<<endl;
			if(s<tmp){
				ans.push_back(tmp);
			}
		}
		if(ans.empty()){
			cout<<"BIGGEST"<<"\n";
			continue;
		}
		sort(ans.begin(),ans.end());
		cout<<ans[0]<<"\n";

	}
	return 0;
}