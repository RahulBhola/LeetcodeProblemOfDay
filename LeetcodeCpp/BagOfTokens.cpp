#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int start = 0;
        int end = tokens.size() - 1;

        int maxi = 0;
        int score = 0;

        while(start <= end){
            if(power >= tokens[start]){
                power-=tokens[start];
                score+=1;
                start++;
            }
            else if(maxi > 0){
                power += tokens[end];
                score-=1;
                end--;
            }
            else{
                break;
            }
            maxi = max(maxi, score);
        } 
        return maxi;
    }
};