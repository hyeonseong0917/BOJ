#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

ll n,m,k;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(ll o=1;o<=1;++o){
		cin>>n>>m>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// x번 마을에 둔다 -> x번 마을은 보존할 수 있음.
		// m개의 벽을 어떻게 세워야 가장 효율적일까?
		for(ll i=0;i<k;++i){
			ll a;
			cin>>a;
			// a번 위치에 돌이 떨어질 예정임
			
		}
	}
	return 0;
}