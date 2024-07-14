#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    int count;
} Element;
typedef struct {
    Element elements[MAX_ELEMENTS];
    int size;
} AtomCount;
void mergeAtomCount(AtomCount* dest, AtomCount* src, int multiplier) {
    for (int i = 0; i < src->size; i++) {
        int found = 0;
        for (int j = 0; j < dest->size; j++) {
            if (strcmp(dest->elements[j].name, src->elements[i].name) == 0) {
                dest->elements[j].count += src->elements[i].count * multiplier;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(dest->elements[dest->size].name, src->elements[i].name);
            dest->elements[dest->size].count = src->elements[i].count * multiplier;
            dest->size++;
        }
    }
}

int compareElements(const void* a, const void* b) {
    return strcmp(((Element*)a)->name, ((Element*)b)->name);
}

char* countOfAtoms(char* formula) {
    int len = strlen(formula);
    AtomCount stack[100];
    int stackTop = 0;
    
    stack[stackTop++] = (AtomCount){0};
    
    for (int i = 0; i < len; i++) {
        if (formula[i] == '(') {
            stack[stackTop++] = (AtomCount){0};
        } else if (formula[i] == ')') {
            int num = 0;
            i++;
            while (i < len && isdigit(formula[i])) {
                num = num * 10 + (formula[i] - '0');
                i++;
            }
            i--;
            if (num == 0) num = 1;
            
            AtomCount top = stack[--stackTop];
            mergeAtomCount(&stack[stackTop - 1], &top, num);
        } else if (isupper(formula[i])) {
            char name[MAX_NAME_LENGTH] = {formula[i]};
            int nameLen = 1;
            while (i + 1 < len && islower(formula[i + 1])) {
                name[nameLen++] = formula[++i];
            }
            name[nameLen] = '\0';
            
            int num = 0;
            while (i + 1 < len && isdigit(formula[i + 1])) {
                num = num * 10 + (formula[++i] - '0');
            }
            if (num == 0) num = 1;
            
            AtomCount* top = &stack[stackTop - 1];
            int found = 0;
            for (int j = 0; j < top->size; j++) {
                if (strcmp(top->elements[j].name, name) == 0) {
                    top->elements[j].count += num;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(top->elements[top->size].name, name);
                top->elements[top->size].count = num;
                top->size++;
            }
        }
    }
    
    AtomCount* result = &stack[0];
    qsort(result->elements, result->size, sizeof(Element), compareElements);
    
    char* output = malloc(10000);
    int pos = 0;
    for (int i = 0; i < result->size; i++) {
        pos += sprintf(output + pos, "%s", result->elements[i].name);
        if (result->elements[i].count > 1) {
            pos += sprintf(output + pos, "%d", result->elements[i].count);
        }
    }
    
    return output;
}