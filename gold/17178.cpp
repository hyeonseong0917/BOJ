#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

#define ll long long

bool comp(string cur_str, string next_str){
	char cur_str_char=cur_str[0];
	char next_str_char=next_str[0];
	string cur_str_num=cur_str.substr(2);
	string next_str_num=next_str.substr(2);
	// cur_str이 더 큰경우
	if(cur_str_char>next_str_char){
		return 0;
	}
	// 첫 문자가 같은경우
	if(cur_str_char==next_str_char){
		if(stoll(cur_str_num)>stoll(next_str_num)){
			return 0;
		}else{
			return 1;
		}
	}
	return 1;
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<string> v,sv;
		for(ll i=0;i<5*n;++i){
			string a;
			cin>>a;
			v.push_back(a);
			sv.push_back(a);
		}
		sort(sv.begin(),sv.end(),comp);
		ll fst_idx=0, sed_idx=0;
		// sv: 정렬된 답지
		// v: 현재 처리해야 하는것
		stack<string> waited_st;
		while(fst_idx<5*n){
			if(v[fst_idx]==sv[sed_idx]){
				++fst_idx;
				++sed_idx;
			}else{
				// comp(a,b): a가 b보다 더 앞에온다면 1
				// v[fst_idx]!=sv[sed_idx]
				if(waited_st.empty()){
					waited_st.push(v[fst_idx]);
					++fst_idx;
				}else{
					string cur_waited=waited_st.top();
					if(cur_waited==sv[sed_idx]){
						waited_st.pop();
						++sed_idx;
					}else{
						waited_st.push(v[fst_idx]);
						++fst_idx;
					}
				}
			}
		}
		bool flag=0;
		while(!waited_st.empty()){
			string cur_waited=waited_st.top();
			waited_st.pop();
			if(cur_waited==sv[sed_idx]){
				++sed_idx;
			}else{
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"BAD";
		}else{
			cout<<"GOOD";
		}
	}
	return 0;
}