#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define ll long long


vector<pair<int,char>> v;
int N=0;
bool isRange(int num){
	return (num>=0 && num<N);
}
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int fst_size, sed_size;
	cin>>fst_size>>sed_size;
	string s1,s2;
	cin>>s1;
	cin>>s2;
	for(int i=0;i<fst_size;++i){
		v.push_back({1,s1[fst_size-i-1]});
	}
	for(int i=0;i<sed_size;++i){
		v.push_back({-1,s2[i]});
	}
	N=fst_size+sed_size;
	int cnt=0;
	cin>>cnt;
	// 방향,char
	while(cnt--){
		int i=0;
		while(i<N-1){
			if(v[i].first==1 && v[i+1].first==-1){
				pair<int,char> tmp;
				tmp=v[i];
				v[i]=v[i+1];
				v[i+1]=tmp;
				i+=2;
			}else{
				i+=1;
			}
		}
		
	}
	for(int i=0;i<v.size();++i){
		cout<<v[i].second;
	}

	return 0;
}