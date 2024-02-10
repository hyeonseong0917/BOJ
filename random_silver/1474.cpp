#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define ll long long

vector<string> v;
map<int,int> m;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	int total_len=0;
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		total_len+=s.size();
		v.push_back(s);
	}
	int K=(M-total_len)%(N-1);
	for(int i=1;i<N;++i){
		if('a'<=v[i][0] && v[i][0]<='z' && K){
			m[i]=1;
			--K;
		}
	}
	if(K){
		for(int i=N-1;i>=0;--i){
			if(K && 'A'<=v[i][0] && v[i][0]<='Z'){
				m[i]=1;
				--K;	
			}
		}
	}
	string s=v[0];
	for(int i=1;i<N;++i){
		string tmp="";
		int Q=(M-total_len)/(N-1);
		if(m[i]){
			++Q;
		}
		for(int j=0;j<Q;++j){
			tmp+='_';
		}
		s+=tmp;
		s+=v[i];
	}
	cout<<s;
	
	return 0;
}