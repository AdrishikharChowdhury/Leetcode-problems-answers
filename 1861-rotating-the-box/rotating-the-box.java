class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length;
        int n = box[0].length;
        
        // Move stones to rightmost possible positions in each row
        for (int i = 0; i < m; i++) {
            int lastEmpty = n - 1;
            // Scan from right to left
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    lastEmpty = j - 1;
                } else if (box[i][j] == '#') {
                    // Move stone to lastEmpty position if possible
                    if (j < lastEmpty) {
                        box[i][lastEmpty] = '#';
                        box[i][j] = '.';
                        lastEmpty--;
                    } else {
                        lastEmpty = j - 1;
                    }
                }
            }
        }
        
        // Rotate 90 degrees clockwise
        char[][] result = new char[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = box[i][j];
            }
        }
        
        return result;
    }
}