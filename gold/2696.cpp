#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

// gfjfjkj
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=0;
	cin>>t;
	while(t--){
		ll M=0;
		cin>>M;
		priority_queue<ll> LQ,RQ;
		vector<ll> v;
		vector<ll> ans;
		for(ll i=0;i<M;++i){
			ll a=0;
			cin>>a;
			v.push_back(a);
		}
		ll mid=v[0];
		ans.push_back(mid);
		for(ll i=1;i<M;++i){
			if(mid>v[i]){
				LQ.push(v[i]);
			}else{
				RQ.push(v[i]*-1);
			}
			if(i%2==0){
				ll LQS=0, RQS=0;
				if(!LQ.empty()){
					LQS=LQ.size();
				}
				if(!RQ.empty()){
					RQS=RQ.size();
				}
				// if(i==2){
				// 	cout<<LQS<<" "<<RQS<<endl;
				// }
				if(LQS==RQS){
					ans.push_back(mid);
				}else{
					if(LQS>RQS){
						RQ.push(mid*-1);
						mid=LQ.top();
						LQ.pop();
					}else{
						LQ.push(mid);
						mid=RQ.top()*-1;
						RQ.pop();
					}
					ans.push_back(mid);
				}
			}
		}
		cout<<ans.size()<<"\n";
		ll n=0;
		for(ll i=0;i<ans.size();++i){
			++n;
			cout<<ans[i];
			if(n%10==0){
				cout<<"\n";
			}else{
				cout<<" ";
			}
		}
		if(n%10!=0){
			cout<<"\n";
		}

	}
	
	return 0;
}