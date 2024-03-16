#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll N;
	cin>>N;
	vector<ll> v(N,0);
	map<ll,ll> m;
	ll max_cnt=0;
	ll max_num=(ll)pow(2,62)+(ll)1;
	for(ll i=0;i<N;++i){
		cin>>v[i];
		++m[v[i]];
		if(max_cnt<m[v[i]]){
			max_cnt=m[v[i]];
			max_num=v[i];
		}else if(max_cnt==m[v[i]] && v[i]<max_num){
			max_cnt=m[v[i]];
			max_num=v[i];
		}
	}
	cout<<max_num;
	
	return 0;
}