#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
        while(1){
        int n,m;
        cin>>n>>m;
        if(n==0 && m==0) break;
        vector<int> a(n,0), b(m,0);
        for(int i=0;i<n;++i){
          cin>>a[i];
        }
        for(int i=0;i<m;++i){
          cin>>b[i];
        }
        // 동시에 가지고 있는 cd의 개수
        int idx=0;
        int ans=0;
        for(int i=0;i<n;++i){
          int cur_num=a[i];
          // cur_num이 b에도 있는지?
          while(idx<m){
            if(cur_num==b[idx]){
              ++ans;
              break;
            }
            if(cur_num<b[idx]) break;
            ++idx;
          }
        }
        cout<<ans<<"\n";
      }
	} 
	return 0;
}