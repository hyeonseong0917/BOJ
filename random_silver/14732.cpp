#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

const int MAX=500+1;
bool check[MAX][MAX];

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		
		for(int j=a;j<c;++j){
			for(int k=b;k<d;++k){
				check[j][k]=1;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			if(check[i][j]){
				++cnt;
			}
		}
	}
	cout<<cnt;

	
	
	return 0;
}