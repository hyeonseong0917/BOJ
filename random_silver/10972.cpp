#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=1;
	while(t--){
		int N;
		cin>>N;
		vector<int> v(N,0);
		for(int i=0;i<N;++i){
			cin>>v[i];
		}
		bool flag=0;
		for(int i=N-1;i>=1;--i){
			if(v[i-1]<v[i]){
				flag=1;
				vector<int> tmp;
				for(int j=N-1;j>=i;--j){
					if(v[j]>v[i-1]){
						int t=v[i-1];
						v[i-1]=v[j];
						v[j]=t;
						break;
					}
				}
				for(int j=i;j<N;++j){
					tmp.push_back(v[j]);
				}
				sort(tmp.begin(),tmp.end());
				for(int j=i;j<N;++j){
					v[j]=tmp[j-i];
				}
				
				break;
			}
		}
		if(flag){
			for(int i=0;i<v.size();++i){
				cout<<v[i]<<" ";
			}
		}else{
			cout<<-1;
		}
	}
	return 0;
}