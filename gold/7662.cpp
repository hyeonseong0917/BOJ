#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define ll long long

int t=0;
int k=0;
priority_queue<ll> max_pq;
priority_queue<ll> min_pq;
map<ll,ll> m;
void solve(){
	cin>>t;
	while(t--){
		cin>>k;
		bool flag=1;
		m.clear();
		for(ll i=0;i<k;++i){
			char c;
			ll num;
			cin>>c>>num;
			if(c=='I'){
				max_pq.push(num);
				++m[num];
				min_pq.push(num*-1);
			}else{
				if(max_pq.empty() || min_pq.empty()) continue;
				if(num==1){
					while(!max_pq.empty()){
						ll cur_num=max_pq.top();
						// cout<<"max "<<cur_num<<" "<<m[cur_num]<<endl;
						if(m[cur_num]){
							--m[cur_num];
							max_pq.pop();
							break;
						}else{
							max_pq.pop();
						}
					}
				}else{

					while(!min_pq.empty()){
						ll cur_num=min_pq.top()*-1;
						// cout<<"min "<<cur_num<<" "<<m[cur_num]<<endl;
						if(m[cur_num]){
							--m[cur_num];
							min_pq.pop();
							break;
						}else{
							min_pq.pop();
						}
					}
				}
			}
		}
		priority_queue<ll> new_max_pq;
		while(!max_pq.empty()){
			if(!m[max_pq.top()]){
				max_pq.pop();	
			}else{
				new_max_pq.push(max_pq.top());
				max_pq.pop();
			}
		}
		while(!min_pq.empty()){
			min_pq.pop();
		}
		if(new_max_pq.empty()){
			cout<<"EMPTY"<<"\n";
			continue;
		}else{
			ll max_num=new_max_pq.top();
			ll min_num=0;
			while(!new_max_pq.empty()){
				if(new_max_pq.size()==1){
					min_num=new_max_pq.top();

				}
				new_max_pq.pop();
			}
			cout<<max_num<<" "<<min_num<<"\n";
		}
		

	}
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	solve();
	
	return 0;
}