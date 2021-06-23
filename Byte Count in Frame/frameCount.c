#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char result[75];

void senderModule(int n) {
    int i,len;
    char frame[75], l[75];
    for(i = 0;i < n;i++) {
        printf("enter frame %d\n", i + 1);
        scanf("%s", &frame);
        len = strlen(frame);
        sprintf(l, "%d", len);
        strcat(l, frame);
        strcat(result, l);
        printf("length of frame: %d\n", len);
    }
    printf("message: %s\n", result);
}
void receiverModule() {
    int i, j, len;
    printf("frames received: \n");

    for(i = 0;i < strlen(result);i++) {
        len = result[i] - '0';
        for(j = i + 1;j <= (i+len);j++) {
            printf("%c", result[j]);
        }
        i = i + len;
        printf("\n");
    }
}
int main() {
    int n;
    printf("enter no. of frames: ");
    scanf("%d", &n);
    senderModule(n);
    receiverModule();
    return 0;
}

