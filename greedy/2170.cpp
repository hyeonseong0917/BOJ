#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// bool comp(pair<int,int> a, pair<int,int> b){
// 	if(a.second==b.second){
// 		return a.first<b.first;
// 	}
// 	return a.second<b.second;
// }
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N=0;
	cin>>N;
	vector<pair<int,int>> v;
	for(int i=0;i<N;++i){
		int a,b=0;
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end(),comp);
	long long curLen=v[0].second-v[0].first;
	long long res=0;
	int lastFirst=v[0].first;
	int lastFin=v[0].second;
	
	for(int i=1;i<N;++i){
		if(v[i].first>lastFin){
			res+=lastFin-lastFirst;
			lastFin=v[i].second;
			lastFirst=v[i].first;
		}else{
			lastFin=max(lastFin,v[i].second);
		}
		// cout<<curLen<<endl;
	}
	res+=lastFin-lastFirst;
	// res+=curLen;
	cout<<res;
	
	return 0;
}