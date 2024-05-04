#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


#define ll long long
vector<int> v,q;
int main() {
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int a=0;
		cin>>a;
		v.push_back(a);
	}
	for(int i=1;i<=N;++i){
		q.push_back(i);
	}
	int idx=0;
	int delete_cnt=0;
	int ans=0;
	int a=0;
	while(1){
		// ++a;
		// if(a==10){
		// 	break;
		// }
		if(delete_cnt==M){
			break;
		}
		if(v[idx]==q[0]){
			vector<int> tmp;
			for(int i=1;i<q.size();++i){
				tmp.push_back(q[i]);
			}
			q=tmp;
			++idx;
			++delete_cnt;
			continue;
		}
		int fst_cnt=0, sed_cnt=0;
		int qs=q.size();
		for(int i=0;i<qs;++i){
			if(q[i]!=v[idx]){
				++fst_cnt;
			}else{
				break;
			}
		}
		for(int i=qs-1;i>=0;--i){
			if(q[i]!=v[idx]){
				++sed_cnt;
			}else{
				break;
			}
		}
		// cout<<fst_cnt<<" "<<sed_cnt<<" "<<v[idx]<<endl;
		// for(int i=0;i<q.size();++i){
		// 	cout<<q[i]<<" ";
		// }cout<<endl;
		vector<int> fst_tmp;
		vector<int> sed_tmp;
		if(fst_cnt<=sed_cnt){
			for(int i=0;i<fst_cnt;++i){
				fst_tmp.push_back(q[i]);
			}
			ans+=fst_cnt;
			for(int i=fst_cnt;i<qs;++i){
				sed_tmp.push_back(q[i]);
			}
			q.clear();
			for(int i=0;i<sed_tmp.size();++i){
				q.push_back(sed_tmp[i]);
			}
			for(int i=0;i<fst_tmp.size();++i){
				q.push_back(fst_tmp[i]);
			}
		}else{
			for(int i=qs-sed_cnt-1;i<qs;++i){
				fst_tmp.push_back(q[i]);
			}
			ans+=fst_tmp.size();
			for(int i=0;i<qs-sed_cnt-1;++i){
				sed_tmp.push_back(q[i]);
			}
			q.clear();
			for(int i=0;i<fst_tmp.size();++i){
				q.push_back(fst_tmp[i]);
			}
			for(int i=0;i<sed_tmp.size();++i){
				q.push_back(sed_tmp[i]);
			}
		}
		
		
	}
	
	cout<<ans;
	return 0;
}