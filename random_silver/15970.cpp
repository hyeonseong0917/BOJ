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
	int N=0;
	vector<int> v[MAX];
	cin>>N;
	//N가지 색
	for(int i=0;i<N;++i){
		int x,y;
		cin>>x>>y;
		v[y].push_back(x);
		//y번째 색의 좌표 x
	}
	for(int i=0;i<MAX;++i){
		sort(v[i].begin(),v[i].end());
	}
	ll cnt=0;
	for(int i=0;i<MAX;++i){
		if(!v[i].empty()){
			cnt+=v[i][1]-v[i][0];
			cnt+=v[i][v[i].size()-1]-v[i][v[i].size()-2];
			for(int j=1;j<v[i].size()-1;++j){
				cnt+=min(v[i][j]-v[i][j-1],v[i][j+1]-v[i][j]);
			}
		}
	}
	cout<<cnt;	
	return 0;
}