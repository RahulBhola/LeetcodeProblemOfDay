import java.util.Arrays;

public class BagOfTokens {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);

        int start = 0;
        int end = tokens.length - 1;

        int max = 0;
        int curr = 0;

        while(start <= end){
            if(power >= tokens[start]){
                curr+=1;
                power-=tokens[start];
                start++;
            }
            else if(max>0){
                power += tokens[end];
                end--;
                curr-=1;
            }
            else{
                break;
            }
            max = Math.max(max, curr);
        } 
        return max;
    }
}
