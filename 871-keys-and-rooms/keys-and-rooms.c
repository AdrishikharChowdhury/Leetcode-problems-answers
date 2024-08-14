#include <stdbool.h>
#include <stdlib.h>

void dfs(int** rooms, int* roomsColSize, int roomsSize, int room, bool* visited) {
    if (visited[room]) {
        return;
    }
    
    visited[room] = true;
    
    for (int i = 0; i < roomsColSize[room]; i++) {
        dfs(rooms, roomsColSize, roomsSize, rooms[room][i], visited);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    
    dfs(rooms, roomsColSize, roomsSize, 0, visited);
    
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }
    
    free(visited);
    return true;
}