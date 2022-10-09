#include <stdio.h>
#include <string.h>

int palindrome(char *, int, int);

int main()
{
    char text [20];
    int in  = 0, i = 0;
    int n   = sizeof(text)/sizeof(text[0]);

    printf("Enter Text : ");
    scanf("%s", text);

    if(palindrome(text, i, strlen(text) - 1)){
        printf("%s is palindrome", text);
    }
    else
    {
        printf("%s is not palindrome", text);
    }
}

int palindrome(char *txt, int x, int y)
{
    if(NULL == txt || x < 0 || y < 0)
        return 0;
    if(x >= y)
        return 1;
    if(txt[x] == txt[y])
        return palindrome(txt, x+1, y-1);
    return 0;
}

