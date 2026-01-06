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
		int n,k;
		cin>>n>>k;
		// n명의 이름이 성적 순으로 주어질 때, 좋은 친구가 몇 쌍인지?
		// n은 최대 30만, k<=n
		// 좋은 친구 = 등수 차이가 k보다 작거나 같고, 이름의 길이가 같은 경우
		// 2글자<=이름<=20글자
		// vector: name_len[20+1]
		// 등수는 항상 오름차순으로 넣어짐
		// name_len[x]={길이가 x인 a의 등수, 길이가 y인 b의 등수...}
		// x=2~x=20 특정 x에 대해 큰 등수의 쌍만 구하면 고유한 쌍의 개수를 구할 수 있음
		vector<string> v;
		vector<int> name_len[20+1];
		for(int i=0;i<n;++i){
			string a;
			cin>>a;
			v.pb(a);
			int as=a.size();
			name_len[as].push_back(i);
		}
		ll ans=0;
		for(int i=2;i<=20;++i){
			for(int j=0;j<name_len[i].size();++j){
			int cur_rank=name_len[i][j];
			// name_len[i]에서, cur_rank+k보다 작거나 같은 최대의 인덱스를 구함
			int L=j+1;
			int R=name_len[i].size()-1;
			int max_idx=j;
			while(L<=R){
				int mid=(L+R)/2;
				if(name_len[i][mid]<=cur_rank+k){
				max_idx=max(max_idx,mid);
				L=mid+1;
				}else{
				R=mid-1;
				}
			}
			ans+=max_idx-j;
			}
		}
		cout<<ans;
	}
	return 0;
}
