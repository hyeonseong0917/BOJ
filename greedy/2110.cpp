#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,C;
vector<long long> x;
vector<pair<long long,long long>> seg;
long long ans=0;
long long INF=1222232421;
void Input(){
	cin>>N>>C;
	for(int i=0;i<N;++i){
		long long a=0;
		cin>>a;
		x.push_back(a);
	}
	sort(x.begin(),x.end());
}	
void solve(){
	
	int L=1;
	int R=x[x.size()-1]-x[0];
	int cnt=1;
	int ans=0;
	while(L<=R){
		//cnt 초기화
		cnt=1;
		//최소 간격이 mid라면?
		int mid=(L+R)/2;
		//초기 target 값은 0번째 값(0번째 값을 무조건 포함 시키는 것으로 가정)
		int target=x[0];
		for(int i=1;i<x.size();++i){
			if(x[i]-target>=mid){
				//최소 간격이 mid이므로 이전 값과 현재 값의 차이가 mid보다 큰 집은 포함 시켜야 함
				//이전 값을 update
				target=x[i];
				++cnt;
			}
		}
		if(cnt>=C){
			//포함시킨 집의 개수가 C보다 크거나 같다면 간격 값을 update
			//집의 개수가 많더라도 최적 해의 간격보다 작을 수 밖에 없기 때문에 max써도됨
			ans=max(ans,mid);
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	cout<<ans;
	
}

int main() {
	// your code goes here
	Input();
	solve();
	return 0;
}