class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int result = 0;
        int min = arrays.get(0).get(0);
        int max = arrays.get(0).get(arrays.get(0).size() - 1);
        
        for (int i = 1; i < arrays.size(); i++) {
            result = Math.max(result, Math.max(Math.abs(arrays.get(i).get(arrays.get(i).size() - 1) - min),
                                               Math.abs(max - arrays.get(i).get(0))));
            min = Math.min(min, arrays.get(i).get(0));
            max = Math.max(max, arrays.get(i).get(arrays.get(i).size() - 1));
        }
        
        return result;
    }
}