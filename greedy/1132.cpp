#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define ll long long
int N;
vector<string> v;
string ans="";
void Input(){
	cin>>N;
	for(int i=0;i<N;++i){
		string s;
		cin>>s;
		v.push_back(s);
	}
}
string string_add(string s1 ,string s2){
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	int fst_size=s1.size();
	int sed_size=s2.size();
	for(int i=0;i<max(fst_size,sed_size);++i){
		if(i>=fst_size){
			s1+='0';
		}
		if(i>=sed_size){
			s2+='0';
		}
	}
	
	string add_ans="";
	int carry=0;
	for(int i=0;i<max(fst_size,sed_size);++i){
		int cur_add=(s1[i]-'0')+(s2[i]-'0')+carry;
		if(cur_add>=10){
			carry=1;
			cur_add-=10;
		}else{
			carry=0;
		}
		add_ans+=(cur_add+'0');
	}
	if(carry){
		add_ans+='1';
	}
	reverse(add_ans.begin(),add_ans.end());
	return add_ans;
}
bool comp(pair<ll,int> a, pair<ll,int> b){
	return a.first>b.first;
}
void solve(){
	vector<ll> val(10,0);
	vector<pair<ll,int>> val_idx;
	for(int i=0;i<v.size();++i){
		string s=v[i];
		reverse(s.begin(),s.end());
		for(int j=0;j<s.size();++j){
			ll cur_num=(ll)pow(10,j);
			val[s[j]-'A']+=cur_num;
		}
	}
	for(int i=0;i<10;++i){
		val_idx.push_back({val[i],i});
	}
	sort(val_idx.begin(),val_idx.end(),comp); //val이 높은 숫자부터
	ll cur_num=9;
	for(int i=0;i<10;++i){
		val_idx[i].first=cur_num--;
	}
	reverse(val_idx.begin(),val_idx.end()); //val이 낮은 숫자부터
	// 예외처리 val_idx[i].first==0이고 val_idx[i].second가 어떤 문자열의 가장 첫번째(실제 숫자로는 마지막) 숫자라면?
	while(1){
		bool is_swap=0;
		for(int i=0;i<9;++i){
			// i번째 value를 확인, 마지막 value 확인하면 문제 잘못
			if(val_idx[i].first==0){
				char c=val_idx[i].second+'A';
				
				for(int j=0;j<v.size();++j){
					if(v[j][0]==c){
						is_swap=1;
						break;
					}
				}
				if(is_swap){
					ll tmp=val_idx[i].first;
					val_idx[i].first=val_idx[i+1].first;
					val_idx[i+1].first=tmp;
				}
				break;
			}
		}
		if(!is_swap){
			break;
		}	
	}
	sort(val_idx.begin(),val_idx.end(),comp);
	map<char,ll> m;
	for(int i=0;i<10;++i){
		m[val_idx[i].second+'A']=val_idx[i].first;
	}
	for(int i=0;i<v.size();++i){
		string s="";
		for(int j=0;j<v[i].size();++j){
			s+=m[v[i][j]]+'0';
		}
		ans=string_add(s,ans);
	}
	cout<<ans;
	
}

int main() {
	// your code goes here
	Input();
	solve();
	
	return 0;
}