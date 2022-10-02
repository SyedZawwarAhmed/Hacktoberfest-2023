#include <stdio.h>
int main()
{
    int menu, quantity;
    float purchase, disc, price, pay;
    
    printf("MENU OPTIONS\n");
    printf("[1] Fried Rice\n");
    printf("[2] Fried Noodle\n");
    printf("[3] Fried Chicken\n");
    printf("[4] Ice Tea\n");
    printf("PILIH MENU : ");
    scanf("%d", &menu);
    switch(menu)
    {
        case 1:
            system("cls");
            printf("You Choose Fried Rice\n\n");
            printf("Add Quantity : ");
            scanf("%d", &quantity);

            price       = 15000;
            purchase    = price * quantity;
            if(purchase >= 100000)
            {
                disc            = (purchase * 5) / 100;
            }
                pay             = purchase - disc;
                
            printf("TOTAL PURCHASE      : Rp%.f\n", purchase);
            printf("TOTAL DISCOUNT      : Rp%.f\n", disc);
            printf("TOTAL PAY           : Rp%.f\n", pay);
            break;
        case 2:
            system("cls");
            printf("You Choose Fried Noodle\n\n");
            printf("Add Quantity : ");
            scanf("%d", &quantity);

            price       = 12000;
            purchase    = price * quantity;
            if(purchase >= 100000)
            {
                disc            = (purchase * 5) / 100;
            }
                pay             = purchase - disc;
                
            printf("TOTAL PURCHASE      : Rp%.f\n", purchase);
            printf("TOTAL DISCOUNT      : Rp%.f\n", disc);
            printf("TOTAL PAY           : Rp%.f\n", pay);
            break;
        case 3:
            system("cls");
            printf("You Choose Fried Chicken\n\n");
            printf("Add Quantity : ");
            scanf("%d", &quantity);

            price       = 10000;
            purchase    = price * quantity;
            if(purchase >= 100000)
            {
                disc            = (purchase * 5) / 100;
            }
                pay             = purchase - disc;
                
            printf("TOTAL PURCHASE      : Rp%.f\n", purchase);
            printf("TOTAL DISCOUNT      : Rp%.f\n", disc);
            printf("TOTAL PAY           : Rp%.f\n", pay);
            break;
        case 4:
            system("cls");
            printf("You Choose Ice Tea\n\n");
            printf("Add Quantity : ");
            scanf("%d", &quantity);

            price       = 5000;
            purchase    = price * quantity;
            if(purchase >= 100000)
            {
                disc            = (purchase * 5) / 100;
            }
                pay             = purchase - disc;
                
            printf("TOTAL PURCHASE      : Rp%.f\n", purchase);
            printf("TOTAL DISCOUNT      : Rp%.f\n", disc);
            printf("TOTAL PAY           : Rp%.f\n", pay);
            break;
        default:
            printf("Option Invalid");
            break;
    }
}
