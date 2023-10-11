#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


const int MAX=5000+1;
#define ll long long
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N=0,M=0;
	cin>>N>>M;
	vector<pair<string,int>> v;
	vector<int> character;
	vector<string> ans;
	for(int i=0;i<N;++i){
		string s;
		int p;
		cin>>s;
		cin>>p;
		v.push_back({s,p});
	}
	for(int i=0;i<M;++i){
		int a=0;
		cin>>a;
		character.push_back(a);
	}
	for(int i=0;i<character.size();++i){
		int L=0, R=N-1;
		int mid=0;
		while(L<=R){	
			mid=(L+R)/2;
			if(v[mid].second>=character[i]){
				// 현재 character의 값보다 기준 전투력이 더 세다면
				R=mid-1;
				// cout<<R<<endl;
			}else{
				L=mid+1;
			}
		}
		ans.push_back(v[R+1].first);
	}
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]<<"\n";
	}
	
	return 0;
}