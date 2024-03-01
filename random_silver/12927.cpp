#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int check[1000+1];
vector<int> v;
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string s="t";
	string t;
	cin>>t;
	s+=t;
	int cnt=0;
	int N=s.size();
	for(int i=1;i<N;++i){
		if(s[i]=='Y'){
			++cnt;
			for(int j=i;j<=N;j+=i){
				if(s[j]=='Y'){
					s[j]='N';
				}else{
					s[j]='Y';
				}
			}
			// cout<<s<<endl;
		}
	}
	bool flag=0;
	for(int i=1;i<N;++i){
		if(s[i]=='Y'){
			flag=1;
			break;
		}
	}
	if(!flag){
		cout<<cnt;
	}else{
		cout<<-1;
	}
	return 0;
}