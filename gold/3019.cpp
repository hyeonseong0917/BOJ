#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

ll c,p;

int main() {
	// your code goes here
	int t=1;
	while(t--){
		cin>>c>>p;
		vector<ll> v(c,0);
		for(ll i=0;i<c;++i){
			cin>>v[i];
		}
		ll ans=0;
		if(p==1){
			ans+=c;
			for(ll i=0;i+3<c;++i){
				if(v[i]==v[i+1] && v[i+1]==v[i+2] && v[i+2]==v[i+3]){
					++ans;
				}
			}
		}else if(p==2){
			for(ll i=0;i+1<c;++i){
				if(v[i]==v[i+1]){
					++ans;
				}
			}
		}else if(p==3){
			for(ll i=0;i+2<c;++i){
				if(v[i]==v[i+1] && v[i+2]==v[i+1]+1){
					++ans;
				}
			}
			for(ll i=0;i+1<c;++i){
				if(v[i]==v[i+1]+1){
					++ans;
				}
			}
		}else if(p==4){
			for(ll i=0;i+2<c;++i){
				if(v[i]==v[i+1]+1 && v[i+1]==v[i+2]){
					++ans;
				}
			}
			for(ll i=0;i+1<c;++i){
				if(v[i+1]==v[i]+1){
					++ans;
				}
			}
		}else if(p==5){
			for(ll i=0;i+1<c;++i){
				if(v[i]==v[i+1]+1){
					++ans;
				}
			}
			for(ll i=0;i+2<c;++i){
				if(v[i]==v[i+1] && v[i+1]==v[i+2]){
					++ans;
				}
			}
			for(ll i=0;i+1<c;++i){
				if(v[i]+1==v[i+1]){
					++ans;
				}
			}
			for(ll i=1;i+1<c;++i){
				if(v[i]+1==v[i-1] && v[i-1]==v[i+1]){
					++ans;
				}
			}
		}else if(p==6){
			for(ll i=0;i+2<c;++i){
				if(v[i]==v[i+1] && v[i+1]==v[i+2]){
					++ans;
				}
			}
			for(ll i=0;i+1<c;++i){
				if(v[i]==v[i+1]){
					++ans;
				}
			}
			for(ll i=0;i+2<c;++i){
				if(v[i]+1==v[i+1] && v[i+1]==v[i+2]){
					++ans;
				}
			}
			for(ll i=0;i+1<c;++i){
				if(v[i]==v[i+1]+2){
					++ans;
				}
			}
		}else if(p==7){
			for(ll i=0;i+2<c;++i){
				if(v[i]==v[i+1] && v[i+1]==v[i+2]){
					++ans;
				}
			}
			for(ll i=0;i+1<c;++i){
				if(v[i+1]==v[i]+2){
					++ans;
				}
			}
			for(ll i=0;i+2<c;++i){
				if(v[i]==v[i+1] && v[i]==v[i+2]+1){
					++ans;
				}
			}
			for(ll i=0;i+1<c;++i){
				if(v[i]==v[i+1]){
					++ans;
				}
			}
		}
		cout<<ans;
		
	}

	return 0;
}