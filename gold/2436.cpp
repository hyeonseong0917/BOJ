#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

ll a,b;
ll q;
ll c;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		cin>>a>>b;
		// a: 최대공약수
		// b: 최소공배수
		q=b/a;
		// b=a*(fst_num/a)*(sed_num/a)
		// a*b=fst_num*sed_num
		// b=a*k
		// a*a*k=fst_num*sed_num
		// fst_num=a*x
		// sed_num=a*(k/x)
		ll k=b/a;
		// k는 최대 1에서 1억까지 가능하긴함
		// x는 [1,k-1]까지 가능한데, x와 k/x는 서로소여야함
		// x=6, k/x=15 인경우가 있을 수 있음
		// x=9, k/x=10
		// x=3, k/x=8
		// 2 48
		// 6 16
		ll sum=2023101800;
		ll fst_num=0;
		ll sed_num=0;
		// check[i]: i번째 수가 소수가 아니라면 1
		vector<ll> check(10000+1,0);
		for(ll i=2;i*i<=10000;++i){
			if(check[i]) continue;
			for(ll j=i*i;j<=10000;j+=i){
				++check[j];
			}
		}
		for(ll i=1;i<=10000;++i){
			ll x=i;
			// cout<<"fds"<<endl;
			if(k%x!=0) continue;
			ll y=k/x;
			// cout<<i<<endl;
			// x와 y가 서로소인지??
			vector<ll> vx,vy;
			// 1. x의 소인수들들 모으기
			for(ll j=1;j<=sqrt(x);++j){
				if(x%j==0){
					if(!check[j]){
						vx.push_back(j);
					}
					if(!check[x/j] && j!=x/j){
						vx.push_back(x/j);
					}
				}
			}
			// 2. y의 소인수들 모으기
			map<ll,ll> y_check;
			for(ll j=1;j<=sqrt(y);++j){
				if(y%j==0){
					if(!check[j]){
						++y_check[j];
						vy.push_back(j);
					}
					if(y/j<=10000 && !check[y/j] && j!=y/j){
						++y_check[y/j];
						vy.push_back(y/j);
					}
				}
			}
			bool flag=0;
			for(ll j=0;j<vx.size();++j){
				ll cur_num=vx[j];
				if(cur_num==1) continue;
				if(y_check[cur_num]){
					flag=1;
					break;
				}
			}
			if(!flag){
				ll cur_sum=a*x+a*(k/x);
				if(cur_sum<sum){
					sum=cur_sum;
					fst_num=a*x;
					sed_num=a*(k/x);
				}
			}

		}
		ll tmp=max(fst_num,sed_num);
		fst_num=min(fst_num,sed_num);
		sed_num=tmp;
		cout<<fst_num<<" "<<sed_num;
	}
	return 0;
}