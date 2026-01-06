#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long



int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		// n개의 소들이 있음 n<=1000
		// i번째 소는 bessie가 p[i]보다 작거나 같은 위치에 있거나,
		// p[i]보다 크거나 같은 위치에 있다고 증언
		// 그런데 거짓말이 있을 수 있음
		// 최소 거짓말의 개수?
		// n-최대 참말의 개수

		// g x: x보다 크거나 같음
		// l y: y보다 작거나 같음

		// 2
		// G 3
		// L 5
		// G 5
		// L 7

		// G x를 가져가는 경우 -> L x이상 모든 L을 다 가져갈 수 있음
		int n;
		cin>>n;
		vector<int> g,l;
		for(int i=0;i<n;++i){
			char c;
			cin>>c;
			int a;
			cin>>a;
			if(c=='G'){
			g.push_back(a);
			}else{
			l.push_back(a);
			}
		}
		if(g.empty() || l.empty()){
			cout<<0;
			return 0;
		}
		sort(g.begin(),g.end());
		sort(l.begin(),l.end());
		int true_cnt=0;
		for(int i=0;i<g.size();++i){
			int g_cnt=i+1;
			int l_cnt=0;
			// l_cnt:l에서 g[i]보다 크거나 같은 수의 개수
			// min_idx: l에서 g[i]보다 크거나 같은 최소의 인덱스
			int min_idx=l.size();
			int L=0, R=l.size()-1;
			while(L<=R){
			int mid=(L+R)/2;
			if(l[mid]>=g[i]){
				min_idx=min(min_idx,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
			}
			l_cnt=l.size()-min_idx;
			true_cnt=max(true_cnt,l_cnt+g_cnt);
		}
		cout<<n-true_cnt;
	}
	return 0;
}
