#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

vector<int> v;
bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first>b.first;
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	int sum=0;
	cin>>N;
	map<int,int> m;
	for(int i=0;i<N;++i){
		int a=0;
		cin>>a;
		++m[a];
		sum+=a;
		v.push_back(a);
	}
	int M=sum/N;
	sum-=M*N;
	double cur_num=(double)sum/N;
	if(cur_num>=0){
		if(cur_num>=0.5){
			++M;
		}
	}else{
		if(cur_num<=-0.5){
			--M;
		}
	}
	cout<<M<<endl;

	sort(v.begin(),v.end());
	cout<<v[v.size()/2]<<endl;
	int max_num=-1;
	vector<pair<int,int>> g;
	for(int i=0;i<N;++i){
		if(m[v[i]]){
			g.push_back({m[v[i]],v[i]});
			m[v[i]]=0;
		}
	}
	sort(g.begin(),g.end(),comp);
	if(N==1){
		cout<<g[0].second<<endl;
	}else{
		if(g[0].first==g[1].first){
			cout<<g[1].second<<endl;
		}else{
			cout<<g[0].second<<endl;
		}
	}
	

	cout<<v[N-1]-v[0];
	return 0;
}