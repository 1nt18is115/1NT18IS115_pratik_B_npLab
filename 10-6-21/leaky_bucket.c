#include<stdio.h>
#include<unistd.h>

int main()  {
    int dataqueue[1000];
    int n;
    printf("Enter the number of elements to be sent\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i ++)    {
        scanf("%d", &dataqueue[i]);
    }
    printf("Sending all packets...\n");
    for(int i = 0; i < n; i ++) {
        sleep(3);
        printf("packet number %d is sent\n", i + 1);
        printf("%d is sent\n", dataqueue[i]);
    }
    return 0;
}