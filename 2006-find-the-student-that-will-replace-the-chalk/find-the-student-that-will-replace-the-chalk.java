public class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long sum = 0;
        for (int chalkPiece : chalk) {
            sum += chalkPiece;
        }

        k = (int) (k % sum); // Reduce k to be within one complete cycle

        for (int i = 0; i < chalk.length; i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        return 0;
    }
}