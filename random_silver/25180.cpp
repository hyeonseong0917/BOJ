#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		if(n<=9){
			cout<<1;
		}else{
			// n>=10
			// ans>=2
			// 9889
			// 88888 40
			// 99499 40
			// n의 홀짝성으로 구분?
			// n이 짝수라면 무조건 99?

			// 989
			ll ans=0;
			while(n){
				if(n>=18){
					n-=18;
					ans+=2;
				}else{
					// n<18
					if(n<=9){
						++ans;
						break;
					}
					ll m=min((ll)(n/2),9ll);
					n-=m*2;
					ans+=2;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}