#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long

ll a,b,c;
bool visited[200+1][200+1][200+1];
vector<ll> v;
vector<ll> check(200+1);

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		cin>>a>>b>>c;
		// 부피가 abc임
		// 앞에 두개는 비어있고 세번째는 꽉참
		visited[a][b][c]=1;
		v.push_back(c);
		++check[c];
		queue<pair<ll,pair<ll,ll>>> q;
		q.push({0,{0,c}});
		while(!q.empty()){
			ll A=q.front().first; // 현재 A에 있는 물의 양
			ll B=q.front().second.first; // 현재 B
			ll C=q.front().second.second; // 현재 C
			// cout<<A<<" "<<B<<" "<<C<<endl;
			q.pop();
			if(A==0){
				if(!check[C]){
					++check[C];
					v.push_back(C);
				}
			}
			// A->B
			// A->C
			if(A){
				// A에서 B로 옮기기
				// 1. A를 통째로 옮기거나
				// 2. B에서 꽉 채우기까지 남은 만큼만 옮기거나
				ll cur_num=min(A,b-B);
				if(!visited[A-cur_num][B+cur_num][C]){
					visited[A-cur_num][B+cur_num][C]=1;
					q.push({A-cur_num,{B+cur_num,C}});
				}
				// A에서 C
				cur_num=min(A,c-C);
				if(!visited[A-cur_num][B][C+cur_num]){
					visited[A-cur_num][B][C+cur_num]=1;
					q.push({A-cur_num,{B,C+cur_num}});
				}
			}
			// B->C
			// B->A
			if(B){
				// B에서 C
				ll cur_num=min(B,c-C);
				if(!visited[A][B-cur_num][C+cur_num]){
					visited[A][B-cur_num][C+cur_num]=1;
					q.push({A,{B-cur_num,C+cur_num}});
				}
				// B에서 A
				cur_num=min(B,a-A);
				if(!visited[A+cur_num][B-cur_num][C]){
					visited[A+cur_num][B-cur_num][C]=1;
					q.push({A+cur_num,{B-cur_num,C}});
				}
			}
			// C->A
			// C->B
			if(C){
				// C에서 A
				ll cur_num=min(C,a-A);
				if(!visited[A+cur_num][B][C-cur_num]){
					visited[A+cur_num][B][C-cur_num]=1;
					q.push({A+cur_num,{B,C-cur_num}});
				}
				// C에서 B
				cur_num=min(C,b-B);
				if(!visited[A][B+cur_num][C-cur_num]){
					visited[A][B+cur_num][C-cur_num]=1;
					q.push({A,{B+cur_num,C-cur_num}});
				}
			}
		}
		sort(v.begin(),v.end());
		for(ll i=0;i<v.size();++i){
			cout<<v[i]<<" ";
		}
	}
	return 0;
}