//https://www.codechef.com/KICW2017/problems/REVCASE

#include<stdio.h>
#include<string.h>
int main()
{
    char str[100] = "";
    int i;
    scanf("%s",str);
    for(i=0;i<strlen(str);i++){
            /*
        if(str[i]<=90 && str[i]>=65)
            str[i] = str[i] + 32;
        else if(str[i]>=97 && str[i]<=122)
            str[i] = str[i] - 32;
            */
        if (str[i] >='A' && str[i] <= 'Z')
            str[i]+=32;
        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i]-=32;
    }
    printf("%s",str);
    return 0;
}
