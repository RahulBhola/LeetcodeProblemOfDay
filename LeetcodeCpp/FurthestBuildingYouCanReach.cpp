class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;

        int i = 0, difference=0;

        for(i=0; i<heights.size()-1; i++){
            difference = heights[i+1] - heights[i];

            if(difference <= 0)   continue;

            bricks -= difference;
            pq.push(difference);

            if(bricks<0){
                bricks+=pq.top();
                pq.pop();
                ladders--;
            }
            if(ladders<0)break;
        }
        return i;
    }
};