#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int minutes;
    printf ("Print your time in shower (in minutes):");
    minutes = GetInt ();
    if (minutes > 1000)         //Lets check number
        printf ("This is too much!\n");
    else if (minutes > 0 && minutes <= 1000)    //If all OK...
    {
        int kbottle = minutes * 12;
        printf ("Number of bottle: %d\n", kbottle);
    }
    else
        printf ("This is not true!\n");         //If kbottle <= 0
}