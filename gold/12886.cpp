#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define ll long long

bool visited[1000+1][1000+1];
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll a,b,c;
		cin>>a>>b>>c;
		ll sum=a+b+c;
		if(sum%3!=0){
			cout<<0;
		}else{
			ll avg=sum/3;
			queue<pair<pair<ll,ll>,ll>> q;
			vector<ll> v;
			v.push_back(a);
			v.push_back(b);
			v.push_back(c);
			sort(v.begin(),v.end());
			q.push({{v[0],v[1]},v[2]});
			visited[v[0]][v[1]]=1;
			bool flag=0;
			while(!q.empty()){
				ll fst_num=q.front().first.first; //최약체
				ll sed_num=q.front().first.second;//그다음
				ll trd_num=q.front().second; //최강
				// cout<<fst_num<<" "<<sed_num<<" "<<trd_num<<endl;
				if(fst_num==sed_num && fst_num==trd_num && fst_num==avg){
					flag=1;
					break;
				}
				q.pop();
				vector<ll> fst_tmp, sed_tmp, trd_tmp;
				fst_tmp.push_back(fst_num*2);
				fst_tmp.push_back(sed_num-fst_num);
				fst_tmp.push_back(trd_num);
				
				sed_tmp.push_back(fst_num*2);
				sed_tmp.push_back(sed_num);
				sed_tmp.push_back(trd_num-fst_num);

				trd_tmp.push_back(fst_num);
				trd_tmp.push_back(sed_num*2);
				trd_tmp.push_back(trd_num-sed_num);

				sort(fst_tmp.begin(),fst_tmp.end());
				sort(sed_tmp.begin(),sed_tmp.end());
				sort(trd_tmp.begin(),trd_tmp.end());
				if(!visited[fst_tmp[0]][fst_tmp[1]]){
					visited[fst_tmp[0]][fst_tmp[1]]=1;
					q.push({{fst_tmp[0],fst_tmp[1]},fst_tmp[2]});
				}
				if(!visited[sed_tmp[0]][sed_tmp[1]]){
					visited[sed_tmp[0]][sed_tmp[1]]=1;
					q.push({{sed_tmp[0],sed_tmp[1]},sed_tmp[2]});
				}
				if(!visited[trd_tmp[0]][trd_tmp[1]]){
					visited[trd_tmp[0]][trd_tmp[1]]=1;
					q.push({{trd_tmp[0],trd_tmp[1]},trd_tmp[2]});
				}
			}
			if(flag){
				cout<<1;
			}else{
				cout<<0;
			}
			
		}
	}
	return 0;
}