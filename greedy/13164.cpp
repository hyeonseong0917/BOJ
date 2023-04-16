#include <iostream>
#define ll long long
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//1:41
//N명을 인접한 사람들로 구성된 K개의 조로 나누는데, 각 조의 키 차이 최소로
// 만약 남은 사람의 개수 == 남은 조의 개수라면 종료
//1 3 5 6 10
// 2 2 1 4
// 1 3 4 9 10
//  2 1 5 1
// 1 3 4 5
// 1 7 11 101 102 K==3
//  6  4  90 1 => 더 작은 diff이 나타나면 버리기?
// 7 11 101 102 K==2
//  4  90  1 => 더 큰 diff이 나타나면 그 전 값들 묶어주기
// 101 102 K==1
// 1 7 14 17 22
//  6 7  3  5
// 1 101/ 240/ 398 498 K==3
//  100 101 196 100
// 전체 배열에 대해 K-1개만큼 /를 그을 수 있음 => diff이 큰 순으로 없앤다?
// 0  1   2    3     4  5   6
// 10 70 140  240 / 440 540 /720
//  60 70 100 200      100  180 
//diff{시작 idx, diff}
// idx까지 더한 값이 해당 조에서의 키 차이
//tmp[3,5] : 3다음 위치에 /=>diff[0,1,2], diff[4] 5 다음 위치에 / 존재

//tmp[3, 7, 8, 10]
bool comp(pair<int,int> a, pair<int,int> b){
	return a.second>b.second;
}
int main() {
	// your code goes here
	ll ans=0;
	int N,K=0;
	cin>>N>>K;
	const int MAX=300000+1;
	int arr[MAX];
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	vector<pair<int,int>> v;
	vector<int> diff;
	for(int i=0;i<N-1;++i){
		v.push_back({i,arr[i+1]-arr[i]});
		diff.push_back(arr[i+1]-arr[i]);
	}
	sort(v.begin(),v.end(),comp);
	vector<int> tmp;
	for(int i=0;i<K-1;++i){
		tmp.push_back(v[i].first);
	}
	sort(tmp.begin(),tmp.end());
	int curIdx=0;
	for(int i=0;i<tmp.size();++i){
		// cout<<tmp[i]<<endl;
		int tmpIdx=tmp[i];
		while(1){
			if(curIdx==tmpIdx){
				++curIdx;
				break;
			}
			// cout<<v[curIdx].second<<endl;
			// cout<<diff[curIdx];
			ans+=diff[curIdx];
			++curIdx;
		}
	}
	if(curIdx<N-1){
		for(int i=curIdx;i<N-1;++i){
			ans+=diff[i];
		}
	}
	cout<<ans;
	return 0;
}