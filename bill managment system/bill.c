#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void Menu();
void placeOrder();
void printOrder();
void PrintBill();
struct Node
{
  int item_code;
  char item_name[20];
  int quantity;
  int amount;
  struct Node *next;
};
struct Node *head = 0;

int main()
{
  system("COLOR F5");
  int y;
  do
  {
    printf("\n\n\n\t\t\t\t\t\t*************************************\n");
    printf("\t\t\t\t\t\t\t\tWELCOME\t\t\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t*************************************\n");
    printf("\n\n\n\n");
    printf("\t\t\t\tHow may I help you?\n\n\t\t\t\tPlease select desired option:\n");
    printf("\t\t\t\t1. Show menu.\n");
    printf("\t\t\t\t2. Place Order\n");
    printf("\t\t\t\t3. Generate bill\n");
    printf("\t\t\t\t4. Exit App\n");
    int x;
    printf("\n\t\t\t\tEnter the desired option : ");
    scanf("%d", &x);
    printf("\n\n");
    switch (x)
    {
    case 1:
      Menu();
      break;
    case 2:
      placeOrder();
      break;
    case 3:
      PrintBill();
      break;
    case 4:
      goto exit;

    default:
      printf("INVALID INPUT\n");
      break;
    }
    printf("Do you want to continue? Press any key for Yes & 0 for No:");
    scanf("%d", &y);
  } while (y);
exit:
  return 0;
}
void placeOrder()
{
  printf("Place your order now....\n");
  struct Node *temp = head;
  int choice;
  do
  {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = 0;
    int code, quantity;
    printf("Enter the item code:");
    scanf("%d", &code);
    newNode->item_code = code;
    printf("Enter the quantity:");
    scanf("%d", &quantity);
    newNode->quantity = quantity;
    switch (code)
    {
    case 1:
      strcpy(newNode->item_name, "Chilli Potato");
      newNode->amount = quantity * 80;
      break;
    case 2:
      strcpy(newNode->item_name, "Momos");
      newNode->amount = quantity * 70;
      break;
    case 3:
      strcpy(newNode->item_name, "Chicken Roll");
      newNode->amount = quantity * 120;
      break;
    case 4:
      strcpy(newNode->item_name, "Chowmein");
      newNode->amount = quantity * 70;
      break;
    case 5:
      strcpy(newNode->item_name, "Chicken Chowmein");
      newNode->amount = quantity * 90;
      break;
    case 6:
      strcpy(newNode->item_name, "Mutton Keema");
      newNode->amount = quantity * 280;
      break;
    case 7:
      strcpy(newNode->item_name, "Veg Fried Rice");
      newNode->amount = quantity * 100;
      break;
    case 8:
      strcpy(newNode->item_name, "Chicken Korma");
      newNode->amount = quantity * 250;
      break;
    case 9:
      strcpy(newNode->item_name, "Malai Chaap");
      newNode->amount = quantity * 150;
      break;
    case 10:
      strcpy(newNode->item_name, "Paneer Tikka");
      newNode->amount = quantity * 150;
      break;
    default:
      printf("Item does not exist\n");
    }
    // CASE 1: FIRST NODE
    if (head == 0)
    {
      head = newNode;
      temp = newNode;
    }
    // CASE 2: OTHER NODES
    else
    {
      temp->next = newNode;
      temp = temp->next;
    }
    printf("ORDER MORE: Press 1 for Yes and 0 for No:");
    scanf("%d", &choice);
  } while (choice);
}
void printOrder()
{
  struct Node *temp = head;
  // CASE 1: NO NODE
  if (head == 0)
    printf("NO ORDER\n");
  // CASE 2: NODE PRESENT
  else
  {
    printf("\n-------------------------------------");
    printf("\n|CODE |      ITEM      |QUANT|AMOUNT|");
    printf("\n-------------------------------------");
    while (temp != 0)
    {
      printf("\n%d     |", temp->item_code);
      printf("%16s|", temp->item_name);
      printf("  %d  |", temp->quantity);
      printf("%6d|", temp->amount);
      printf("\n------------------------------------- ");
      temp = temp->next;
    }
  }
}
int sum()
{
  int sum = 0;
  struct Node *temp = head;
  while (temp != 0)
  {
    sum += temp->amount;
    temp = temp->next;
  }
  return sum;
}
void PrintBill()
{
  printf("*************");
  printf("  TOKEN   ");
  printf("**************\n\n");
  printf("DATE:%s CASHIER:ABCDE ABCDEF\n", __DATE__);
  printOrder();
  int price = sum();
  printf("\n      Total bill amount = %d\n", price);
  printf("-------------------------------------");
  printf("\n\n");
}
void Menu()
{
  printf("CODE  DISH NAME                PRICE\n");
  printf("1.    Chilli Potato            80\n");
  printf("2.    Momos                    70[10P]\n");
  printf("3.    Chicken Roll             120\n");
  printf("4.    Chowmein                 70\n");
  printf("5.    Chicken Chowmein         90\n");
  printf("6.    Mutton Keema             280\n");
  printf("7.    Veg Fried Rice           100\n");
  printf("8.    Chicken Korma            250\n");
  printf("9.    Malai Chaap              150\n");
  printf("10.   Paneer Tikka             150\n");
  printf("\n\n");
}
