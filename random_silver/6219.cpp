#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int arr[4000000+1];
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		for(int i=1;i<=4000000;++i){
			arr[i]=0;
		}
		vector<int> v;
		arr[2]=1;
		v.push_back(2);
		for(int i=3;i<=4000000;i+=2){
			if(!arr[i]){
				v.push_back(i);
				arr[i]=1;
				for(int j=2;i*j<=4000000;++j){
					arr[i*j]=1;
				}
			}
		}
		int a,b,d;
		cin>>a>>b>>d;
		int cnt=0;
		for(int i=0;i<v.size();++i){
			if(v[i]<a) continue;
			if(v[i]>b) break;
			bool flag=0;
			while(v[i]){
				if(v[i]%10==d){
					flag=1;
					break;
				}
				v[i]/=10;
			}
			if(flag){
				++cnt;
			}
		}
		cout<<cnt;
	}
	return 0;
}