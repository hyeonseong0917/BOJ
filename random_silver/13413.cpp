#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s;
		string t;
		cin>>s;
		cin>>t;
		// wbwbwb
		// n<=100000
		// 2개의 서로 위치를 바꾼다
		// 1개의 색을 변경한다
		// 최소횟수
		// wbbww
		// wbwbw
		// 언제 위치를 바꿔야 할까?
		// 불협화음 b,w의 개수
		// 불협화음 w,b의 개수
		// 저 두 개수의 min 값 + max-min값
		ll fst_cnt=0, sed_cnt=0;
		for(ll i=0;i<n;++i){
			if(s[i]=='B' && t[i]=='W'){
				++fst_cnt;
			}
			if(s[i]=='W' && t[i]=='B'){
				++sed_cnt;
			}
		}
		cout<<max(fst_cnt,sed_cnt)<<"\n";
	}
	
	return 0;
}