#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#define min(x, y) (x) < (y) ? (x) : (y)
#define max(x, y) (x) > (y) ? (x) : (y)

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int idx=0;
    int cnt=0;
    int lastIdx=0;
    stack<pair<int,int>> ds, ps;
    for(int i=0;i<n;++i){
        if(deliveries[i]!=0){
            ds.push({i+1,deliveries[i]});
        }
        if(pickups[i]!=0){
            ps.push({i+1,pickups[i]});
        }
    }
    while(1){
        if(ds.empty() && ps.empty()){
            break;
        }
        int ds_dist=-1, ps_dist=-1;
        if(!ds.empty()){
            ds_dist=ds.top().first*2;
        }
        if(!ps.empty()){
            ps_dist=ps.top().first*2;
        }
    
        answer+=max(ds_dist, ps_dist);
        
        int to_del=cap, to_pick=cap;
        int cur_ds=ds.size(), cur_ps=ps.size();
        for(int i=0;i<cur_ds;++i){
            int curNum=ds.top().second;
            
            if(to_del>curNum){
                to_del-=curNum;
                ds.pop();
            }else{
                
                ds.top().second-=to_del;
                if(ds.top().second<=0){
                    ds.pop();
                }
                break;
            }
        }
        // cout<<"next"<<endl;
        for(int i=0;i<cur_ps;++i){
            int curNum=ps.top().second;
            if(to_pick>curNum){
                to_pick-=curNum;
                ps.pop();
            }else{
                ps.top().second-=to_pick;
                if(ps.top().second<=0){
                    ps.pop();
                }
                break;
            }
        }
        
    }
    
    
    return answer;
}
