#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int blocks;
    printf ("Enter number of blocks (1-23): ");
    blocks = GetInt();
    while (blocks <= 0)   // && blocks > 23)   //Among is not work
    {
        printf ("Not right! Try again: ");
        blocks = GetInt();
    }
    while (blocks >23)      //Not much
    {
        printf ("To many! Try again: ");
        blocks = GetInt();
    }    
    int x = 2;      //Build some figure
        do 
        { 
            int j = blocks; int d = x;
            do { printf (" "); j--; } while (j!=0);
            do { printf ("#"); d--; } while (d!=0);
            blocks-=1; x+=1;
            printf ("\n");
        } 
        while (blocks>0);
}