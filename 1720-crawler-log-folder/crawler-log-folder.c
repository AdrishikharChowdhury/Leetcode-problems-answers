int minOperations(char** logs, int logsSize) {
    int i,c=0;
    for(i=0;i<logsSize;i++)
    {
        if(strcmp(logs[i],"./")==0)
        continue;
        if(strcmp(logs[i],"../")==0)
        c=(c>0) ? c-1 : 0;
        else
        ++c;
    }
    return c;
}