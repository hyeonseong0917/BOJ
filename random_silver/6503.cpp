#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long


int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(1){
		string t;
		getline(cin,t);
		if(t.compare("0")==0) break;
		int m=stoi(t);
		string s="";
		getline(cin,s);
		// 최대 m개의 서로 다른 문자열로 구성된 가장 긴 부분 문자열의 길이
		int L=0;
		int R=0;
		int N=s.size();
		int cnt=0; // 지금까지 서로 다른 문자들의 개수
		int ans=-1;
		map<char,int> mm;
		// ++m[s[L]];
		while(L<=R && R<N){
			if(cnt<=m){
				// R먹기
				if(!mm[s[R]]){
					++cnt;	
				}
				++mm[s[R]];
				if(cnt<=m){
					ans=max(ans,R-L+1);	
				}
				++R;
			}else{
				// L빼기
				--mm[s[L]];
				if(!mm[s[L]]){
					--cnt;
				}
				++L;
			}
			// cout<<N<<endl;
			// cout<<L<<" "<<R<<" "<<cnt<<endl;
		}
		cout<<ans<<"\n";
	}

	return 0;
}