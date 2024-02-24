#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    #define ppr pair<int, int>
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : meetings) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<ppr, vector<ppr>, greater<ppr> > pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        vector<int> vis(n, 0);

        while (!pq.empty()) {
            auto it = pq.top();
            int time=it.first; 
            int person=it.second;
            pq.pop();

            if (vis[person]) {
                continue;
            }
            vis[person] = true;
            for (auto it : adj[person]) {
                if (!vis[it.first] && it.second >= time) {
                    pq.push({it.second, it.first});
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    int n1 = 4;
    vector<vector<int>> meetings1 = {{0, 1, 5}, {0, 2, 7}, {1, 3, 6}, {2, 3, 8}};
    int firstPerson1 = 0;
    vector<int> result1 = solution.findAllPeople(n1, meetings1, firstPerson1);
    cout << "Test Case 1 Result: ";
    for (int person : result1) {
        cout << person << " ";
    }
    cout << endl;

    // Test case 2
    int n2 = 5;
    vector<vector<int>> meetings2 = {{0, 1, 5}, {0, 2, 7}, {1, 3, 6}, {2, 3, 8}, {3, 4, 9}};
    int firstPerson2 = 1;
    vector<int> result2 = solution.findAllPeople(n2, meetings2, firstPerson2);
    cout << "Test Case 2 Result: ";
    for (int person : result2) {
        cout << person << " ";
    }
    cout << endl;

    return 0;
}
