#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows=moveTime.size();
        int cols=moveTime[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        vector<vector<int>> time(rows, vector<int>(cols, INT_MAX));

        minHeap.emplace(0,0,0);
        time[0][0]=0;
        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};

        while(!minHeap.empty()){
            auto [currentTime, x, y]=minHeap.top();
            minHeap.pop();
            if(x==rows-1 && y==cols-1) return currentTime;

            for(const auto& [dx, dy]: directions){
                int newX=x+dx, newY=y+dy;
                if(newX>=0 && newX<rows && newY>=0 && newY<cols){ //limitrofes
                    int waitTime=max(moveTime[newX][newY]-currentTime, 0);
                    int newTime=currentTime + 1 + waitTime;
                    if(newTime < time[newX][newY]){
                        time[newX][newY]=newTime;
                        minHeap.emplace(newTime, newX, newY);
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    return 0;
}