class Solution {
    public int maxHeightOfTriangle(int red, int blue) {
        return Math.max(calculateHeight(red, blue), calculateHeight(blue, red));
    }
    
    private int calculateHeight(int color1, int color2) {
        int height = 0;
        int currentRowBalls = 1;
        boolean useColor1 = true;
        
        while (true) {
            if (useColor1) {
                if (color1 >= currentRowBalls) {
                    color1 -= currentRowBalls;
                    height++;
                    currentRowBalls++;
                    useColor1 = false;
                } else {
                    break;
                }
            } else {
                if (color2 >= currentRowBalls) {
                    color2 -= currentRowBalls;
                    height++;
                    currentRowBalls++;
                    useColor1 = true;
                } else {
                    break;
                }
            }
        }
        
        return height;
    }
}