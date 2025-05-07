#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define ll long long


ll solve(string a, string b){
	ll cnt=0;
	ll idx1=0, idx2=0;
	while(1){
		while(idx1<a.size() && a[idx1]=='a'){
			++idx1;
		}
		while(idx2<a.size() && b[idx2]=='a'){
			++idx2;
		}
		if(idx1>=a.size() || idx2>=a.size()){
			break;
		}
		cnt+=abs(idx1-idx2);
		++idx1;
		++idx2;
	}
	return cnt;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		// ab는 좋은 문자열
		// s가 좋은 문자열이면 aSb도 좋은 ㅜㄴ자열
		// S와 T가 좋은 문자열이라면 ST도 좋은 문자열
		// A에서 인접한 두 문자를 서로 바꾸는 연산 수행
		// B로 바꾸려면 몇 번의 연산이 필요한지?
		// 중간에 나타나는 문자열도 좋은 문자열이어야함
		ll n;
		cin>>n;
		for(ll i=0;i<n;++i){
			string a,b;
			cin>>a>>b;
			ll as=a.size();
			ll bs=b.size();
			if(as!=bs){
				// cout<<"he";
				cout<<-1<<"\n";
			}else{
				cout<<solve(a,b)<<"\n";
			}
			
		}
	}
	return 0;
}