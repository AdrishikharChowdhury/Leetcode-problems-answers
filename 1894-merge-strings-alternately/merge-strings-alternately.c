

char * mergeAlternately(char * word1, char * word2){
    int len1=strlen(word1);
    int len2=strlen(word2);
    int mlen=len1+len2;
    char *merge;
    merge=(char *)malloc((mlen+1)*sizeof(char));
    int i=0,j=0,k=0;
    while(i<len1 && j<len2)
    {
        merge[k++]=word1[i++];
        merge[k++]=word2[j++];
    }
    while(i<len1)
    {
        merge[k++]=word1[i++];
    }
    while(j<len2)
    {
        merge[k++]=word2[j++];
    }
    merge[k]='\0';
    return merge;
}