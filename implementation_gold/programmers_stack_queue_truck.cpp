#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int timer=0;
    bool visited[10000+1]={0,};
    queue<pair<int,int>> q; //현재 다리에 있는 트럭의 무게,위치
    int idx=0;
    while(1){
        if(idx==truck_weights.size() && q.empty()){
            break;
        }
        ++timer;
        //트럭 이동
        if(!q.empty()){
            queue<pair<int,int>> tmp;
            while(!q.empty()){
                int cur_weight=q.front().first;
                int cur_pos=q.front().second;
                q.pop();
                if(cur_pos+1<bridge_length){
                    tmp.push({cur_weight,cur_pos+1});
                }
            }
            q=tmp;
        }
        // ++idx;
        //트럭 적재
        if(q.size()<bridge_length && idx<truck_weights.size()){
            int sum=0;
            queue<pair<int,int>> tmp=q;
            while(!q.empty()){
                sum+=q.front().first;
                q.pop();
            }
            q=tmp;
            if(sum+truck_weights[idx]<=weight){
                q.push({truck_weights[idx],0});
                ++idx;    
            }
            
        }
    }
    answer=timer;
    return answer;
}