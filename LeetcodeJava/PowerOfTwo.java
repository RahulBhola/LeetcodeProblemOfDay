class PowerOfTwo {
    public boolean isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        while (n % 2 == 0) {
            n = n / 2;
        }
        return n == 1;
    }

    public static void main(String[] args) {
        PowerOfTwo pw = new PowerOfTwo();
        System.out.println(pw.isPowerOfTwo(8)); // true
        System.out.println(pw.isPowerOfTwo(9)); // false
    }
}