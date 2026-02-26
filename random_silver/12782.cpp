#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define ll long long


int main() {
    ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    ll o;
    cin>>o;
    while(o--){
        string a,b;
        cin>>a;
        cin>>b;
        // a=0, b=1
        ll fst_cnt=0;

        // a=1, b=0
        ll sed_cnt=0;
        for(ll i=0;i<a.size();++i){
            if(a[i]==b[i]) continue;
            if(a[i]=='0'){
                ++fst_cnt;
            }else{
                ++sed_cnt;
            }
        }
        cout<<max(fst_cnt,sed_cnt)<<"\n";
        
    }
    return 0;
}