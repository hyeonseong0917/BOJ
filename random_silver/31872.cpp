#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <cmath>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		// n개의 강의
		// i번째 강의실은 a[i]위치에 존재
		// 최대 k번 순간이동 가ㅡㅇ
		// 1152
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		// 1 4 5 6 9 14
		// 1 3 1 1 3 5
		vector<ll> diff;
		diff.push_back(v[0]);
		for(ll i=1;i<n;++i){
			diff.push_back(v[i]-v[i-1]);
		}
		sort(diff.begin(),diff.end());
		ll sum=0;
		for(ll i=0;i<n-k;++i){
			sum+=diff[i];
		}
		cout<<sum;
	} 
	return 0;
}