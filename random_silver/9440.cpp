#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(1){
		ll n;
		cin>>n;
		if(n==0) break;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll L=0, R=-1;
		for(ll i=0;i<n;++i){
			if(v[i]!=0){
				R=i;
				break;
			}
		}
		if(R!=-1){
			ll k=R;
			ll cnt=0;
			while(R<n && L<k && cnt<2){
				ll tmp=v[L];
				v[L]=v[R];
				v[R]=tmp;
				++L;
				++R;
				++cnt;
			}
		}
		string fst_str="", sed_str="";
		for(ll i=0;i<n;++i){
			char c=v[i]+'0';
			if(i%2==0){
				fst_str+=c;
			}else{
				sed_str+=c;
			}
		}
		ll fst_num=stoll(fst_str);
		ll sed_num=stoll(sed_str);
		// cout<<fst_num<<" "<<sed_num<<endl;
		cout<<fst_num+sed_num<<"\n";
	}
	return 0;
}