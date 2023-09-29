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
	int n=0;
	cin>>n;
	vector<int> c;
	for(int i=0;i<n;++i){
		int a=0;
		cin>>a;
		c.push_back(a);
	}
	sort(c.begin(),c.end());
	int sum=0;
	for(int i=0;i<c.size()-1;++i){
		sum+=c[i];
	}
	cout<<sum;
	return 0;
}