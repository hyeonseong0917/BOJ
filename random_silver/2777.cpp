#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n<10){
			cout<<1<<"\n";
		}else{
			// 소수인지?
			bool is_prime=1;
			if(n%2==0){
				// 소수 아님
				is_prime=0;
			}else{
				for(ll i=3;i<=sqrt(n);i+=2){
					if(n%i==0){
						is_prime=0;
						break;
					}
				}
			}
			if(is_prime){
				cout<<-1<<"\n";
			}else{
				// 소인수 중에 prime이 있으면 안됨

				ll cnt=0;
				while(n!=1 && !is_prime){
					is_prime=1;
					for(ll i=9;i>=2;--i){
						if(n%i==0){
							++cnt;
							n/=i;
							is_prime=0;
							break;
						}
					}
				}
				if(is_prime){
					cout<<-1<<"\n";
				}else{
					cout<<cnt<<"\n";
				}

			}
			
		}
	}
	return 0;
}