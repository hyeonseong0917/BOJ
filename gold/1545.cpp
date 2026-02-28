#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		string s;
		cin>>s;
		ll n=s.size();
		if(n==1){
			cout<<s;
			break;
		}
		sort(s.begin(),s.end());
		ll L,R;
		if(n%2==0){
			L=n/2-1;
			R=L+1;
		}else{
			L=n/2-1;
			R=n/2+1;
		}
		bool flag=0;
		while(L>=0 && R<n){
			if(s[L]==s[R]){
				ll idx=R+1;
				bool c=0;
				while(idx<n){
					if(s[R]!=s[idx]){
						char a=s[R];
						s[R]=s[idx];
						s[idx]=a;
						c=1;
						break;
					}
					++idx;
				}
				if(!c){
					flag=1;
					break;
				}
			}
			--L;
			++R;
		}
		if(flag){
			cout<<-1;
		}else{
			cout<<s;
		}
		
	}
		

	return 0;
}