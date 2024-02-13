public class PalindromicStringFinder {
    public static String findFirstPalindromicString(String[] array) {
        for (String str : array) {
            if (isPalindrome(str)) {
                return str;
            }
        }
        return null; // If no palindromic string is found
    }

    private static boolean isPalindrome(String str) {
        int i = 0;
        int j = str.length() - 1;

        while (i < j) {
            if (str.charAt(i) != str.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    public static void main(String[] args) {
        String[] array = {"hello", "level", "world", "radar", "openai"};
        String firstPalindromicString = findFirstPalindromicString(array);
        if (firstPalindromicString != null) {
            System.out.println("First palindromic string in the array: " + firstPalindromicString);
        } else {
            System.out.println("No palindromic string found in the array.");
        }
    }
}
