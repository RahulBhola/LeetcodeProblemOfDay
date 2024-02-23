#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits> // for INT_MAX
using namespace std;

class CheapestFlightWithinKSpot {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz-- > 0) {
                int node = q.front().first;
                int cost = q.front().second;
                q.pop();

                if (!adj.count(node)) continue;

                for (const auto& next : adj[node]) {
                    int neighbour = next.first;
                    int price = next.second;
                    if (price + cost >= dist[neighbour]) continue;
                    dist[neighbour] = price + cost;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    CheapestFlightWithinKSpot solution;

    int n = 3; // number of nodes
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}}; // flights array representing [source, destination, price]
    int src = 0; // source node
    int dst = 2; // destination node
    int k = 1; // maximum number of stops allowed
    
    // Call the method and print the result
    int cheapestPrice = solution.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest price: " << cheapestPrice << endl;

    return 0;
}
