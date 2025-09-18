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
	ll o=1;
	while(o--){
		ll e, em, m, mh, h;
		cin>>e>>em>>m>>mh>>h;
		ll c=min(e,min(m,h));
		ll ans=c;
		e-=c;
		m-=c;
		h-=c;
		while(em || mh){
			if(e==0){
				if(em==0){
					break;
				}
				--em;
				++e;
				if(e && m && h){
					++ans;
					--e;
					--m;
					--h;
				}
				continue;
			}
			if(h==0){
				if(mh==0){
					break;
				}
				--mh;
				++h;
				if(e && m && h){
					++ans;
					--e;
					--m;
					--h;
				}
				continue;
			}
			if(m==0){
				if(!em){
					--mh;
					++m;
				}else if(!mh){
					--em;
					++m;
				}else{
					if(e+em>=mh+h){
						++m;
						--em;
					}else{
						++m;
						--mh;
					}
				}
				if(e && m && h){
					++ans;
					--e;
					--m;
					--h;
				}
				continue;
			}
		}
		cout<<ans;
	}
	return 0;
}