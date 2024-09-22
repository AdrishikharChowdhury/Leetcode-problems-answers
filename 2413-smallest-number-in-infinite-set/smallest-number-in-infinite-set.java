import java.util.PriorityQueue;
import java.util.HashSet;

class SmallestInfiniteSet {
    private int currentSmallest;
    private PriorityQueue<Integer> minHeap;
    private HashSet<Integer> set;

    public SmallestInfiniteSet() {
        currentSmallest = 1;
        minHeap = new PriorityQueue<>();
        set = new HashSet<>();
    }
    
    public int popSmallest() {
        if (!minHeap.isEmpty()) {
            int smallest = minHeap.poll();
            set.remove(smallest);
            return smallest;
        }
        return currentSmallest++;
    }
    
    public void addBack(int num) {
        if (num < currentSmallest && !set.contains(num)) {
            minHeap.offer(num);
            set.add(num);
        }
    }
}