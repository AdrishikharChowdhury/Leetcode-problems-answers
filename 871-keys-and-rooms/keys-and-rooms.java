import java.util.*;

class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Set<Integer> visited = new HashSet<>();
        dfs(rooms, 0, visited);
        return visited.size() == rooms.size();
    }
    
    private void dfs(List<List<Integer>> rooms, int room, Set<Integer> visited) {
        if (visited.contains(room)) {
            return;
        }
        
        visited.add(room);
        
        for (int key : rooms.get(room)) {
            dfs(rooms, key, visited);
        }
    }
}