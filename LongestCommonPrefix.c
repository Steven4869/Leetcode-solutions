#include<limits.h>
char * longestCommonPrefix(char ** strs, int strsSize){
   int minimum = INT_MAX;
    for(int i=0;i<strsSize;i++){
        if(strlen(strs[i])<minimum)
            minimum=strlen(strs[i]);
    }
    int count =0;
    for(int i=0;i<minimum;i++){
        for(int j=1;j<strsSize;j++){
            if(strs[0][i]!=strs[j][i]){
                minimum=0;
                count--;
                break;
            }
        }
        count++;
    }
    char* string = (char*)calloc(count+1,sizeof(char));
    string[count] = '\0';
    for(int i = 0 ; i < count ; i++){
        string[i] = strs[0][i];
    }
    return string;
}