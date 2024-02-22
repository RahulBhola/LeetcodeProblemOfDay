public class FindTheTownJudge {
    public static int findJudge(int n, int[][] trust) {
        int[] in = new int[n + 1]; // corrected N to n
        int[] out = new int[n + 1]; // corrected N to n
        for (int[] a : trust) {
            out[a[0]]++;
            in[a[1]]++;
        }
        for (int i = 1; i <= n; ++i) { // corrected N to n
            if (in[i] == n - 1 && out[i] == 0)
                return i;
        }
        return -1;
    }

    public static void main(String[] args) {
        int n = 4; // for example, set the value of n
        int[][] arr = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}}; // for example, set the value of arr
        int result = findJudge(n, arr);
        System.out.println("The town judge is: " + result);
    }
}