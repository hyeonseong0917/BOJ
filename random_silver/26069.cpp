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
        int n;
        cin>>n;
        map<string,int> m;
        m["ChongChong"]=1;
        int ans=1;
        for(int i=0;i<n;++i){
            string a,b;
            cin>>a>>b;
            if(m[a] || m[b]){
            if(!m[a]){
                ++m[a];
                ++ans;
            }
            if(!m[b]){
                ++m[b];
                ++ans;
            }
            }
        }
        cout<<ans;
	} 
	return 0;
}