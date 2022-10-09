#include <stdio.h>

#define MAKS 10

void mainSortA();
void mainSortD();
void input(int [], int *);
void sortA(int [], int);
void sortD(int [], int);
void printData(int [], int);

int main()
{
    int opt;

    printf("MENU\n");
    printf("[1] Ascending Sort \n[2] Descending Sort\n\n");
    printf("SELECT MENU : ");
    scanf("%d", &opt);

    if(opt == 1){
        system("cls");
        mainSortA();
    } 
    else if(opt == 2) 
    {
        system("cls");
        mainSortD();
    }
    else{
        printf("\nInvalid Option");
    }
}

// ascending sort
void mainSortA()
{
    int data[MAKS];
    int lenght;

    input(data, &lenght);
    sortA(data, lenght);
    printData(data, lenght);
}

// descending sort
void mainSortD()
{
    int data[MAKS];
    int lenght;

    input(data, &lenght);
    sortD(data, lenght);
    printData(data, lenght);
}

void input(int x[], int *size)
{
    int lenght, i;

    printf("Total Data = ");
    scanf("%d", &lenght);

    for(i = 0; i < lenght; i++){
        printf("Data %d : ", i+1);
        scanf("%d", &x[i]);
    }

    *size = lenght;
}

void sortA(int x[], int size)
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

void sortD(int x[], int size)
{
    int i, j;
    int dummy;

    for(i = 0; i < size-1; i++){
        for(j = i + 1; j < size; j++){
            if(x[i] < x[j]){
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

    printf("\nData After Sort : \n");
    for(i = 0; i < size; i++){
        printf("Data of %d : %d \n", i+1, x[i]);
    }
}
