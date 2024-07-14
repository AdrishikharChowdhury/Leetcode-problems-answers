class Solution {
    public String countOfAtoms(String formula) {
        Stack<Map<String, Integer>> stack = new Stack<>();
        Map<String, Integer> map = new HashMap<>();
        int i = 0, n = formula.length();
        
        while (i < n) {
            char c = formula.charAt(i);
            i++;
            if (c == '(') {
                stack.push(map);
                map = new HashMap<>();
            } else if (c == ')') {
                int num = 0;
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    num = num * 10 + formula.charAt(i++) - '0';
                }
                if (num == 0) num = 1;
                if (!stack.isEmpty()) {
                    Map<String, Integer> temp = map;
                    map = stack.pop();
                    for (String name : temp.keySet()) {
                        map.put(name, map.getOrDefault(name, 0) + temp.get(name) * num);
                    }
                }
            } else {
                int start = i - 1;
                while (i < n && Character.isLowerCase(formula.charAt(i))) i++;
                String name = formula.substring(start, i);
                int num = 0;
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    num = num * 10 + formula.charAt(i++) - '0';
                }
                if (num == 0) num = 1;
                map.put(name, map.getOrDefault(name, 0) + num);
            }
        }
        
        TreeMap<String, Integer> sortedMap = new TreeMap<>(map);
        StringBuilder sb = new StringBuilder();
        for (String name : sortedMap.keySet()) {
            sb.append(name);
            int count = sortedMap.get(name);
            if (count > 1) {
                sb.append(count);
            }
        }
        return sb.toString();
    }
}