class MissingNumber {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = ans ^ i;
        }
        for (int i = 0; i < nums.length; i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }

    public static void main(String[] args) {
        MissingNumber m = new MissingNumber();
        int[] arr = { 1, 3, 2, 5 }; // Create an array
        System.out.println("Missing number: " + m.missingNumber(arr)); // Pass the array to the method
    }
}
