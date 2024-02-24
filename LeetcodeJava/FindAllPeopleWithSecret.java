import java.util.*;

class Solution {
    class Pair {
        int first;
        int second;
        
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        
        for (int[] it : meetings) {
            adj.get(it[0]).add(new Pair(it[1], it[2]));
            adj.get(it[1]).add(new Pair(it[0], it[2]));
        }
        
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(p -> p.first));
        pq.add(new Pair(0, 0));
        pq.add(new Pair(0, firstPerson));

        boolean[] vis = new boolean[n];

        while (!pq.isEmpty()) {
            Pair it = pq.poll();
            int time = it.first;
            int person = it.second;

            if (vis[person]) {
                continue;
            }
            vis[person] = true;
            for (Pair pair : adj.get(person)) {
                if (!vis[pair.first] && pair.second >= time) {
                    pq.add(new Pair(pair.second, pair.first));
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                ans.add(i);
            }
        }
        return ans;
    }
    
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        int n1 = 4;
        int[][] meetings1 = {{0, 1, 5}, {0, 2, 7}, {1, 3, 6}, {2, 3, 8}};
        int firstPerson1 = 0;
        List<Integer> result1 = solution.findAllPeople(n1, meetings1, firstPerson1);
        System.out.print("Test Case 1 Result: ");
        for (int person : result1) {
            System.out.print(person + " ");
        }
        System.out.println();

        // Test case 2
        int n2 = 5;
        int[][] meetings2 = {{0, 1, 5}, {0, 2, 7}, {1, 3, 6}, {2, 3, 8}, {3, 4, 9}};
        int firstPerson2 = 1;
        List<Integer> result2 = solution.findAllPeople(n2, meetings2, firstPerson2);
        System.out.print("Test Case 2 Result: ");
        for (int person : result2) {
            System.out.print(person + " ");
        }
        System.out.println();
    }
}
