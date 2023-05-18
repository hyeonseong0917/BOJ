#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000+1;

int V, E;
int parent[MAX];
int n,m,l;

bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
	return a.first<b.first;
}
int Find(int num){
	if(num==parent[num]){
		return num;
	}
	int next=Find(parent[num]);
	parent[num]=next;
	return next;
}
void Union(int a, int b){
	parent[Find(a)]=Find(b);
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> V >> E;
	for (int i = 1; i <= V; ++i){
		parent[i] = i;
	} 
	vector<pair<int,pair<int,int>>> v;
	for (int i = 0; i < E; ++i){
		int a,b,c=0;
		cin>>a>>b>>c;
		v.push_back({c,{a,b}});
	}
	sort(v.begin(),v.end(),comp);
	long long sum=0;
	for(int i=0;i<E;++i){
		int a=v[i].second.first;
		int b=v[i].second.second;
		int c=v[i].first;
		if(Find(a)!=Find(b)){
			sum+=c;
			Union(a,b);
		}
	}
	cout<<sum;
    return 0;
}