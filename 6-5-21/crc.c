#include<stdio.h>

int xor(int a, int b)   {
    if (a == b)
        return 0;
    else
        return 1;
}

int main()  {
    int poly[4];
    int data[20];
    int original_data[20];
    int j = 0;
    int check_data[20];
    int data_size;
    int mod_data_size;
    int cur_pointer = 0;
    int count = 0;
    printf("Enter Polynomial\n");
    for (int i = 0; i < 4; i ++)
        scanf("%d", &poly[i]);
    
    printf ("Enter data size\n");
    scanf("%d", &data_size);

    printf("Enter data\n");

    for(int i = 0; i < data_size; i ++)
        scanf("%d", &data[i]);

    //copying original data

    for (int i = 0; i < data_size; i ++)
        original_data[i] = data[i];

    data[data_size] = 0;
    data[data_size + 1] = 0;
    data[data_size + 2] = 0;
    mod_data_size = data_size + 3;


    //////////////////////////////////////////////////////////

    // printf ("Data Entered\n");
    // for(int i = 0; i < data_size; i ++)
    //     printf ("%d\t", data[i]);
    // printf ("\n");

    // printf ("Modified data\n");
    // for(int i = 0; i < mod_data_size; i ++)
    //     printf ("%d\t", data[i]);
    // printf ("\n");


    /////////////////////////////////////////////////////////
    
    
    
    while (cur_pointer < data_size)
    {

        for(int i = cur_pointer; i < cur_pointer + 4; i ++, j++)
            data[i] = xor(data[i], poly[j]);
        
        j = 0;
        cur_pointer++;
    }


 //////////////////////////////////////////////////////////

    printf ("Data after doing CRC\n");
    for(int i = 0; i < mod_data_size; i ++)
        printf ("%d ", data[i]);
    printf ("\n\n");

    //copying original data to new array and appending reminder of crc
    for(int i = 0; i < data_size; i ++)
        check_data[i] = original_data[i];
    
    for (int i = 0; i < 3; i ++)
        check_data[data_size + i] = data[data_size + i];


 //////////////////////////////////////////////////////////

    printf ("Data after copying original data with remainder\n");
    for(int i = 0; i < mod_data_size; i ++)
        printf ("%d ", check_data[i]);
    printf ("\n\n");

    //doing crc again

    cur_pointer = 0;
    while (cur_pointer < data_size)
    {

        for(int i = cur_pointer; i < cur_pointer + 4; i ++, j++)
            check_data[i] = xor(check_data[i], poly[j]);
        
        j = 0;
        cur_pointer++;
    }

    // only for showing error condition
    // check_data[mod_data_size - 1] = 1;

    //////////////////////////////////////////////////////////

    printf ("Data after doing CRC again\n");
    for(int i = 0; i < mod_data_size; i ++)
        printf ("%d ", check_data[i]);
    printf ("\n\n");

    //checking remainder
    for (int i = 0; i < 3; i ++)
    {
        if(check_data[data_size+i] == 0)
        {
            count ++;
        }
    }
    
    if (count == 3)
        printf ("There is no error detected\n");
    
    else
        printf ("Error detected\n");

    return 0;
}