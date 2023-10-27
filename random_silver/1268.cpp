#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int arr[1000+5][5];
int cnt[1000+5];
bool check[1000+5][1000+5];
vector<pair<int,int>> v; //{겹치는 학생 수, 학생 번호}
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
	for(int i=0;i<1000+5;++i){
		for(int j=0;j<5;++j){
			arr[i][j]=0;
		}
		cnt[i]=0;
	}
	for(int i=0;i<1000+5;++i){
		for(int j=0;j<1005;++j){
			check[i][j]=0;
		}
	}
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<5;++j){
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<5;++i){
		// i번째 학년에 대해
		
		for(int j=0;j<N;++j){
			// j번째 사람의 겹치는 숫자 카운트
			int people_cnt=0;	
			for(int k=0;k<N;++k){
				if(j==k) continue;
				if(arr[j][i]==arr[k][i] && !check[j][k]){
					check[j][k]=1;
					++people_cnt;	
				}
				
			}
			cnt[j]+=people_cnt;
		}
	}
	for(int i=0;i<N;++i){
		v.push_back({cnt[i],i});
	}
	sort(v.begin(),v.end(),comp);
	cout<<v[0].second+1;
	return 0;
}