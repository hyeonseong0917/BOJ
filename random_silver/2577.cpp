#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int a,b,c;
	cin>>a>>b>>c;
	int sum=1;
	sum*=a;
	sum*=b;
	sum*=c;
	string s=to_string(sum);
	vector<int> v(11,0);
	for(int i=0;i<s.size();++i){
		++v[s[i]-'0'];
	}
	for(int i=0;i<=9;++i){
		cout<<v[i]<<"\n";
	}
	return 0;
}