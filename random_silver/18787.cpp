#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
    ll n;
    cin>>n;
    string a,b;
    cin>>a;
    cin>>b;
    ll idx=0;
    ll ans=0;
    while(idx<n){
      bool flag=0;
      while(a[idx]!=b[idx] && idx<n){
        flag=1;
        ++idx;
      }
      if(flag) ++ans;
      ++idx;
    }
    cout<<ans;
	} 
	return 0;
}