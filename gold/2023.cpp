#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

int n;
vector<string> v;
map<string,int> m;
void pick(string s){
	if(s.size()==n){
		v.push_back(s);
		return;
	}
	for(int i=1;i<=9;i+=2){
		if(i==5) continue;
		char c=i+'0';
		string t=s+c;
		if(m[t]) continue;
		m[t]=1;
		int t_num=stoi(t);
		bool flag=0;
		for(int j=3;j<=sqrt(t_num);j+=2){
			if(t_num%j==0){
				flag=1;
				break;
			}
		}
		if(!flag){
			pick(t);	
		}
		
		
	}
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>n;
	pick("2");
	pick("3");
	pick("5");
	pick("7");
	for(int i=0;i<v.size();++i){
		cout<<v[i]<<"\n";
	}
	return 0;
}