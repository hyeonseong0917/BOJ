#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
using namespace std;


int N;
vector<pair<int,int>> v;
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end(),comp);
}
void solve(){
	int L=0, R=1000000+1;
	int ans=-1;
	while(L<=R){
		int mid=(L+R)/2;
		bool flag=0;
		int cur_time=mid;
		for(int i=0;i<v.size();++i){
			if(cur_time+v[i].first<=v[i].second){
				cur_time+=v[i].first;
			}else{
				flag=1;
				break;
			}
		}
		if(flag){
			R=mid-1;
		}else{
			L=mid+1;
			ans=max(ans,mid);
		}
	}
	cout<<ans;
}



int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	Input();
	solve();
	return 0;
}