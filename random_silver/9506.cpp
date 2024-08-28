#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(1){
		ll n;
		cin>>n;
		if(n==-1) break;
		vector<ll> tmp;
		for(ll i=1;i<=sqrt(n);++i){
			if(n%i!=0) continue;
			tmp.push_back(i);
			if(i!=n/i && i!=n && n/i!=n){
				tmp.push_back(n/i);
			}
		}
		sort(tmp.begin(),tmp.end());
		ll sum=0;
		for(ll i=0;i<tmp.size();++i){
			sum+=tmp[i];
		}
		// cout<<n<<" "<<sum<<endl;
		
		if(sum==n){
			cout<<n<<" = ";
			for(ll i=0;i<tmp.size();++i){
				cout<<tmp[i];
				if(i!=tmp.size()-1){
					cout<<" + ";
				}
			}
			cout<<"\n";
		}else{
			cout<<n<<" is NOT perfect."<<"\n";
		}
	}
	
	return 0;
}