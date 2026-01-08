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
        // n은 연속된 자연수의 합으로 나타낼 수 있음
        // 1<=n<=10^7, n을 연속된 자연수의 합으로 나타냈을 때, 경우의 수가 몇 개인지?
        ll n;
        cin>>n;
        ll L=1;
        ll R=1;
        ll sum=1;
        ll ans=1;
        while(L<=R && R<=n/2+1){
            // cout<<L<<" "<<R<<" "<<ans<<"\n";
            if(L==R){
                ++R;
                if(R<n){
                    sum+=R;
                }
                continue;
            }
            if(sum==n){
                ++ans;
                sum-=L;
                ++L;
                ++R;
                if(R<n){
                    sum+=R;
                }
                continue;
            }
            if(sum<n){
                ++R;
                if(R<n){
                    sum+=R;
                }
            }else{
                ++L;
                sum-=L-1;
            }
        }
        cout<<ans;
	} 
	return 0;
}