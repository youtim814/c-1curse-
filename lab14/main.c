#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

struct measurement
{
    int upperLim;
    int lowerLim;
    float fallibility;
}typedef msr;

struct productToBuy
{
    char name[20];
    int price;
    int amount;
    char seller[20];

}typedef prd;

struct measureInstrument
{
    char name[20];
    int warrantyPeriod;
    msr measurements[10];
    prd productsToBuy[10];
    int measurementsAmount;
    int prAmount;

} instr;
void input(FILE *); // створення нового файлу
void print(FILE *); // перегляд файлу
void app(FILE *); // додавання в файл

FILE *tf2;

int main ()
{
 SetConsoleCP(1251); //встановлення кодування Windows-1251 в потік введення
 SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в потік виведення

 FILE *tf;
 input(tf);
 print(tf);
 readBF();

 return 0;
}
// функція створення нового файлу
void input(FILE *tf)
{
 char ch;
 tf = fopen("file1.dat", "wb");
 tf2 = fopen("sellers.dat", "wb");

 system("cls");
 printf("\n Enter\n");
 do
 {
 printf("\n Name: ");
 scanf("%s",&instr.name);
 printf(" Warranty period: ");
 scanf("%d", &instr.warrantyPeriod);
 printf("Enter amount of measurements:");
 scanf("%d",&instr.measurementsAmount);
 printf("Enter amount of product to buy:");
 scanf("%d",&instr.prAmount);

 printf("Enter measurement parametres:\n");
 for(int i=0;i<instr.measurementsAmount;i++)
 {
     printf("Upper limit:");
     scanf("%d",&instr.measurements[i].upperLim);
     printf("Lower limit:");
     scanf("%d",&instr.measurements[i].lowerLim);
     printf("Fallibility:");
     scanf("%f",&instr.measurements[i].fallibility);
 }
printf("\nEnter bought products parametres:\n");
 for(int j=0;j<instr.prAmount;j++)
 {
        printf("\t\t%d\n",j+1);
        printf("Enter name of product u bought:");
        scanf("%s",&instr.productsToBuy[j].name);
        fflush(stdin);
        printf("Enter price of product u bought:");
        scanf("%d",&instr.productsToBuy[j].price);

        printf("Enter amount of product u bought:");
        scanf("%d",&instr.productsToBuy[j].amount);
        printf("Enter name of seller:");
        scanf("%s",&instr.productsToBuy[j].seller);

        fwrite(&instr.productsToBuy[j].seller, sizeof(instr.productsToBuy[j].seller), 1, tf2);
        fwrite(&instr.productsToBuy[j].price, sizeof(int), 1, tf2);
        fflush(stdin);
 }


 fwrite(&instr, sizeof(instr), 1, tf); // запис в файл однієї структури t1
 printf("\n Finish? y/n \n");
 ch = getch ();// перехоплюємо натиснену клавішу
 }
 while(ch!= 'y');

 fclose (tf);

 fclose (tf2);
}
// функція перегляду файлу
void print(FILE *tf)
{
 int k;
 system("cls");
 tf = fopen("file1.dat", "rb"); // відкриття бінарного файлу для читання
 k = 1;
 fread(&instr, sizeof(instr), 1, tf); // читання з файлу однієї структури t1
 while (!feof(tf)) // поки не кінець файлу
 {
 printf("\n %3d Instument %10s Warranty period %4d Msr Amount %4d Measurements parametres Products parametres", k, instr.name, instr.warrantyPeriod,instr.measurementsAmount);
 for(int i=0;i<instr.measurementsAmount;i++)
 {
     printf("\n%70d)Upper Lim:%d",1+i,instr.measurements[i].upperLim);
     printf("\n%70d)Lower Lim:%d",1+i,instr.measurements[i].lowerLim);
     printf("\n%70d)Fallibility:%4.2f",1+i,instr.measurements[i].fallibility);
 }
 for(int j=0;j<instr.prAmount;j++)
 {
        printf("\n%90d)name of product:%s",j+1,instr.productsToBuy[j].name);
        printf("\n%90d)price of product:%d",j+1,instr.productsToBuy[j].price);
        printf("\n%90d)amount of product: %d",j+1,instr.productsToBuy[j].amount);
        printf("\n%90d)name of seller:%s",j+1,&instr.productsToBuy[j].seller);
 }

 fread(&instr, sizeof(instr), 1, tf);
 k++;
 }
 getch();
}

void readBF()
{
    tf2=fopen("sellers.dat", "rb");
    int i=0;
    int summ=0;

    fread(&instr.productsToBuy[i].seller, sizeof(instr.productsToBuy[i].seller), 1, tf2);
    fread(&instr.productsToBuy[i].price, sizeof(int), 1, tf2);
    system("cls");
    while (!feof(tf2))
    {
        printf("\nprice:%d",instr.productsToBuy[i].price);
        printf("\nseller:%s",instr.productsToBuy[i].seller);
        printf("\n");
        summ=summ+instr.productsToBuy[i].price;

         fread(&instr.productsToBuy[i].seller, sizeof(instr.productsToBuy[i].seller), 1, tf2);
        fread(&instr.productsToBuy[i].price, sizeof(int), 1, tf2);
    }
    fclose(tf2);
    printf("\nTotal Summ=%d",summ);
}
