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
      ll n;
      cin>>n;
      queue<ll> q;
      while(1){
        ll a;
        cin>>a;
        if(a==-1) break;
        if(a==0){
          q.pop();
        }else{
          ll qs=q.size();
          if(qs==n) continue;
          q.push(a);
        }
      }
      if(q.empty()){
        cout<<"empty";
      }else{
        while(!q.empty()){
          ll c=q.front();
          q.pop();
          cout<<c<<" ";
        }
      }
	} 
	return 0;
}