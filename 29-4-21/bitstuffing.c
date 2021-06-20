//  bit stuffing
//  insert 01111110 before and after each byte of data
//  whenever 5 consecutive 1's are found, insert 0 next to it

#include<stdio.h>
int main()
{
    int message[100];
    int num_of_1s = 0;
    int bit_stuffed_message[200];
    int j = 0;
    int n;

    printf ("Enter size of message\n");
    scanf ("%d", &n);
    printf ("Enter message in bits:\n");
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &message[i]);
    }

    for (int i = 0; i < n; i ++)
    {
        if (message[i] == 1)
        {
            bit_stuffed_message[j] = message[i];
            j++;
            num_of_1s ++;

            if (num_of_1s == 5)
            {
                bit_stuffed_message[j] = 0;
                j ++;
                num_of_1s = 0;
            }
        }
        else
        {
            bit_stuffed_message[j] = message[i];
            j ++;
        }
    }
    printf ("Bit stuffed message is:   ");
    for (int i = 0; i < j; i ++)
        printf ("%d  ", bit_stuffed_message[i]);
    printf ("\n");

    num_of_1s = 0;

    printf ("Bit unstuffed message is: ");
    for (int i = 0; i < j; i ++)
    {
        if (num_of_1s == 5)
        {
            i ++;
            num_of_1s = 0;
        }
        if (bit_stuffed_message[i] == 1)
        {
            printf ("%d  ", bit_stuffed_message[i]);
            num_of_1s ++;
        }
        else
        {
            printf ("%d  ", bit_stuffed_message[i]);
            num_of_1s = 0;
        }
    }
    printf("\n");

    return 0;
}