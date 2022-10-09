#include <stdio.h>

int main()
{
    int menu;

    printf("MENU PLANE FIGURE\n");
    printf("[1] RECTANGLE\n");
    printf("[2] RECTABGULAR\n");
    printf("[3] CIRCLE\n");
    printf("PLEASE SELECT  : ");
    scanf("%d", &menu);

    switch(menu)
    {
        case 1:
            system("cls");
            rectangle();
            break;
        case 2:
            system("cls");
            rectangular();
            break;
        case 3:
            system("cls");
            circle();
            break;
        default:
            printf("Invalid Option\n");
            break;
    }
}

void rectangle()
{
    float s, l, k;
    printf("YOU SELECT RECTANGLE\n\n");
    printf("input side value          : ");
    scanf("%f", &s);

    l   = s * s;
    k   = 4 * s;

    printf("VALUE AREA                : %.2f\n", l);
    printf("ROUND VALUE               : %.2f\n", k);
}

void rectangular()
{
    float p, le, l, k;
    printf("YOU SELECT RECTANGULAR\n\n");
    printf("Input Length              : ");
    scanf("%f", &p);
    printf("Input Width Value         : ");
    scanf("%f", &le);

    l   = p * le;
    k   = 2 * (p + le);

    printf("VALUE AREA                : %.2f\n", l);
    printf("ROUND VALUE               : %.2f\n", k);
}

void circle()
{
    float phi = 3.14, l, k, r;
    printf("YOU SELECT CIRCLE\n\n");
    printf("Enter Radius Value        : ");
    scanf("%f", &r);

    k   = 2 * phi * r;
    l   = phi * r * r;

    printf("VALUE AREA                : %.2f\n", l);
    printf("ROUND VALU                : %.2f\n", k);
}