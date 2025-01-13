#define MAX_N 100001

struct Node {
    int val;
    struct Node* next;
};

void build(struct Node* adj[], int** edges, int edgesSize) {
    for (int i = 0; i < edgesSize; i++) {
        // Add edge[0] -> edge[1]
        struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
        newNode1->val = edges[i][1];
        newNode1->next = adj[edges[i][0]];
        adj[edges[i][0]] = newNode1;
        
        // Add edge[1] -> edge[0]
        struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
        newNode2->val = edges[i][0];
        newNode2->next = adj[edges[i][1]];
        adj[edges[i][1]] = newNode2;
    }
}

void get(int p[], struct Node* adj[], int node, int dis, bool* vis) {
    int d = p[1];
    vis[node] = true;
    
    if (dis > d) {
        p[0] = node;
        p[1] = dis;
    }
    
    struct Node* curr = adj[node];
    while (curr != NULL) {
        if (!vis[curr->val]) {
            get(p, adj, curr->val, dis + 1, vis);
        }
        curr = curr->next;
    }
}

int minimumDiameterAfterMerge(int** edges1, int edges1Size, int* edges1ColSize, 
                             int** edges2, int edges2Size, int* edges2ColSize) {
    int n = edges1Size + 1;
    int m = edges2Size + 1;
    
    // Initialize adjacency lists
    struct Node* adj1[MAX_N] = {NULL};
    struct Node* adj2[MAX_N] = {NULL};
    
    // Build adjacency lists
    build(adj1, edges1, edges1Size);
    build(adj2, edges2, edges2Size);
    
    // First DFS on tree1
    int p1[2] = {-1, INT_MIN};
    bool* vis = (bool*)calloc(n, sizeof(bool));
    get(p1, adj1, 0, 0, vis);
    
    // Second DFS on tree1
    int p2[2] = {-1, INT_MIN};
    memset(vis, 0, n * sizeof(bool));
    get(p2, adj1, p1[0], 0, vis);
    int d1 = p2[1];
    
    // First DFS on tree2
    p1[0] = -1;
    p1[1] = INT_MIN;
    free(vis);
    vis = (bool*)calloc(m, sizeof(bool));
    get(p1, adj2, 0, 0, vis);
    
    // Second DFS on tree2
    p2[0] = -1;
    p2[1] = INT_MIN;
    memset(vis, 0, m * sizeof(bool));
    get(p2, adj2, p1[0], 0, vis);
    int d2 = p2[1];
    
    // Handle edge cases
    if (edges1Size == 0) d1 = 0;
    if (edges2Size == 0) d2 = 0;
    
    // Free memory
    free(vis);
    for (int i = 0; i < n; i++) {
        struct Node* curr = adj1[i];
        while (curr != NULL) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    
    for (int i = 0; i < m; i++) {
        struct Node* curr = adj2[i];
        while (curr != NULL) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    
    return fmax(fmax(d1, d2), (d1 + 1) / 2 + (d2 + 1) / 2 + 1);
}