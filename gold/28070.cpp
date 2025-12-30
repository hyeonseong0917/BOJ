#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

#define ll long long

map<string,ll> m;
vector<string> p;
ll cnt=1;
void UPDATE(){
	string year="2000";
	string month="01";
	while(1){
		string cur_date=year+'-'+month;
		p.push_back(cur_date);
		m[cur_date]=cnt++;
		if(cur_date=="9999-12") break;
		if(month=="12"){
			ll new_year_num=stoll(year)+1;
			string new_year=to_string(new_year_num);
			year=new_year;
			month="01";
		}else{
			ll new_month_num=stoll(month)+1;
			string new_month=to_string(new_month_num);
			if(new_month.size()==1){
				string tmp="0";
				tmp+=new_month;
				new_month=tmp;
			}
			month=new_month;
		}
	}
}
int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	// cin>>o;
	while(o--){
		p.push_back("");
		UPDATE();
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			string a,b;
			cin>>a;
			cin>>b;
			v.push_back({m[a],m[b]});
		}
		// cout<<cnt<<endl;
		vector<ll> diff(cnt+1);
		for(ll i=0;i<n;++i){
			++diff[v[i].first];
			--diff[v[i].second+1];
		}
		vector<ll> psum(cnt+1,0);
		psum[1]=diff[1];
		ll max_num=psum[1];
		string max_str=p[1];
		for(ll i=2;i<=cnt;++i){
			psum[i]=psum[i-1]+diff[i];
			if(max_num<psum[i]){
				max_num=psum[i];
				max_str=p[i];
			}
		}
		cout<<max_str;
	}
	return 0;
}