#include <stdio.h>

#define MAKS 10

void input(int [], int *);
void sort(int [], int);
void printData(int [], int);

int main()
{
    int data[MAKS];
    int lenght;

    input(data, &lenght);
    sort(data, lenght);
    printData(data, lenght);
}

void input(int x[], int *size)
{
    int lenght, i;

    printf("Total Data = ");
    scanf("%d", &lenght);

    for(i = 0; i < size; i++){
        printf("Data %d : ", i+1);
        scanf("%d", &x[i]);
    }

    *size = lenght;
}

void sort(int x[], int size)
{
    int i, j;
    int dummy;

    for(i = 0; i < size-1; i++){
        for(j = i + 1; j < size; j++){
            if(x[i] > x[j]){
                dummy   = x[i];
                x[i]    = x[j];
                x[j]    = dummy;
            }
        }
    }
}

void printData(int x[], int size)
{
    int i;

    printf("Data After Sort : \n\n");
    for(i = 0; i < size; i++){
        printf("Data of %d : %d \n", i+1, x[i]);
    }
}