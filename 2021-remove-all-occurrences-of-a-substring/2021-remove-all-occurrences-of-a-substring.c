char* removeOccurrences(char* s, char* part) {
    int partLen = strlen(part);
    char *pos;

    while ((pos = strstr(s, part)) != NULL) 
    {
        memmove(pos, pos + partLen, strlen(pos + partLen) + 1); 
    }
    return s;
}