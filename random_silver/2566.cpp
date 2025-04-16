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

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	// cin>>t;
	while(t--){
		ll max_num=0;
        ll y=1,x=1;
        for(ll i=0;i<9;++i){
            for(ll j=0;j<9;++j){
                ll a;
                cin>>a;
                if(max_num<a){
                    y=i+1;
                    x=j+1;
                    max_num=a;
                }
            }
        }
        cout<<max_num<<"\n";
        cout<<y<<" "<<x;
	} 
	return 0;
}