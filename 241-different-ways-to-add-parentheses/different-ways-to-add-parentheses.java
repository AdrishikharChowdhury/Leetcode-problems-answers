import java.util.*;

class Solution {
    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> result = new ArrayList<>();
        
        // Base case: if the expression is a single number
        if (!expression.contains("+") && !expression.contains("-") && !expression.contains("*")) {
            result.add(Integer.parseInt(expression));
            return result;
        }
        
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                // Split the expression at the operator
                String left = expression.substring(0, i);
                String right = expression.substring(i + 1);
                
                // Recursively compute results for left and right parts
                List<Integer> leftResults = diffWaysToCompute(left);
                List<Integer> rightResults = diffWaysToCompute(right);
                
                // Combine results
                for (int l : leftResults) {
                    for (int r : rightResults) {
                        int value = 0;
                        switch (c) {
                            case '+':
                                value = l + r;
                                break;
                            case '-':
                                value = l - r;
                                break;
                            case '*':
                                value = l * r;
                                break;
                        }
                        result.add(value);
                    }
                }
            }
        }
        
        return result;
    }
}