/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char* name;
    int height;
} Person;

int compare(const void* a, const void* b) {
    return ((Person*)b)->height - ((Person*)a)->height;
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    Person* people = (Person*)malloc(namesSize * sizeof(Person));
    
    for (int i = 0; i < namesSize; i++) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }
    
    qsort(people, namesSize, sizeof(Person), compare);
    
    char** result = (char**)malloc(namesSize * sizeof(char*));
    for (int i = 0; i < namesSize; i++) {
        result[i] = people[i].name;
    }
    
    *returnSize = namesSize;
    free(people);
    return result;
}