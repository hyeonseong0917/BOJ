#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
int main() {
	
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int cnt=1;
	while(cnt--){
		string a, b;
		cin>>a>>b;
		string min_a=a;
		string min_b=b;
		string max_a=a;
		string max_b=b;
		for(ll i=0;i<a.size();++i){
			if(a[i]=='5'){
				max_a[i]='6';
			}
			if(a[i]=='6'){
				min_a[i]='5';
			}
		}
		for(ll i=0;i<b.size();++i){
			if(b[i]=='5'){
				max_b[i]='6';
			}
			if(b[i]=='6'){
				min_b[i]='5';
			}
		}
		ll max_num=stoll(max_a)+stoll(max_b);
		ll min_num=stoll(min_a)+stoll(min_b);
		cout<<min_num<<" "<<max_num;
	}
	

	

	return 0;
}