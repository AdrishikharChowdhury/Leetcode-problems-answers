// Java Solution
class NumberContainers {
    private Map<Integer, Integer> indexToNum;
    private Map<Integer, TreeSet<Integer>> numToIndices;

    public NumberContainers() {
        indexToNum = new HashMap<>();
        numToIndices = new HashMap<>();
    }
    
    public void change(int index, int number) {
        // Remove old number mapping if exists
        if (indexToNum.containsKey(index)) {
            int oldNum = indexToNum.get(index);
            numToIndices.get(oldNum).remove(index);
            if (numToIndices.get(oldNum).isEmpty()) {
                numToIndices.remove(oldNum);
            }
        }
        
        // Add new mapping
        indexToNum.put(index, number);
        numToIndices.computeIfAbsent(number, k -> new TreeSet<>()).add(index);
    }
    
    public int find(int number) {
        TreeSet<Integer> indices = numToIndices.get(number);
        return indices == null || indices.isEmpty() ? -1 : indices.first();
    }
}
