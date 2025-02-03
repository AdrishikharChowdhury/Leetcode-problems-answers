import java.util.Arrays;

class Solution {
    public boolean isFreqSame(int[] a, int[] b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    public boolean checkInclusion(String s1, String s2) {
        int i;
        int[] freq = new int[26];
        for (i = 0; i < s1.length(); i++) {
            freq[s1.charAt(i) - 'a'] += 1;
        }
        int windSize = s1.length();
        for (i = 0; i < s2.length(); i++) {
            int windIdx = 0, idx = i;
            int[] windFreq = new int[26];
            while (windIdx < windSize && idx < s2.length()) {
                windFreq[s2.charAt(idx) - 'a'] += 1;
                windIdx += 1;
                idx += 1;
            }
            if (isFreqSame(freq, windFreq)) {
                return true;
            }
        }
        return false;
    }
}

