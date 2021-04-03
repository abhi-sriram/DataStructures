

#include <stdio.h>
#include <string.h>

// String match code using brute force method

int main()
{
    char s1[100] = "abcaabcabca",s2[10] = "bca";
    int patternMatchCount = 0;
    int s1Length = strlen(s1), s2Length = strlen(s2);
    int flag=0;
    for (int i = 0; i <(s1Length-s2Length+1) ; i++) {
        for (int j = 0; j < s2Length; j++) {
            
            if(s1[i+j]==s2[j]){
                flag++;
            }
        }
        if(flag==s2Length){
            patternMatchCount++;
        }
        flag=0;
    }
    printf("Match Count: %d",patternMatchCount);
    

    return 0;
}
