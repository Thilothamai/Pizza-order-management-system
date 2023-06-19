#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int order_count = 0; 
struct pizza
{
   char * size;
   float price;
   char * topping[4];
   char * delivery[100];
   char * name[100];
   long long int   phone;
   char * address[100];
};
struct pizza order[100] = {};


char get_pizza_size(){
  char pizza_size;
  printf("Enter Your Pizza Size: ");
  scanf("%c",&pizza_size);
  return pizza_size;
}


char do_you_want_more_topping()
{
  char more_topping;
  printf("Enter your choice: ");
  scanf("%s",&more_topping);
  return more_topping;
}

int get_new_topping()
{

  int top_in = 0;
  printf("Enter topping: ");
  scanf("%d",&top_in);

  return top_in;
}
char * topping_name_by_id(int id)
{
  char * topping_name;
  switch(id){
    case 1:
    topping_name = "Bacon";
    break;
    case 2:
    topping_name = "Olives";
    break;
    case 3:
    topping_name = "Ham";
    break;
    case 4:
    topping_name = "Mushrooms";
    break;
    case 5:
    topping_name = "Pineapple";
    break;
    case 6:
    topping_name = "Salami";
    break;
    case 7:
    topping_name = "Anchovies";
    break;
    default:
    topping_name = "Cheese";
    break;
  }
  return topping_name;

}

void add_topping_to_order(int *arr, int order_count){
    int i;
    order[order_count].topping[0] = "Cheese";
    for (i=1; i <= 4; i++) 
    {
      if(arr[i] != 0)
      {
        char * name = topping_name_by_id(arr[i]);
        order[order_count].topping[i] = name;
      }
    }
}


int main()
{
   char pizza_size;

   NEW_ORDER:
   printf("\nSelect pizza size:\n");
   printf("\t s = Small | m = Medium | l = Large\n");

   GET_PIZZA_SIZE:
   pizza_size = get_pizza_size();
   switch(pizza_size) 
   {
      case 's' :
         printf("You have selected small size pizza.\n");
         order[order_count].size = "Small";
         order[order_count].price = 5.0;
         order[order_count].topping[0] = "Cheese";
         break;
      case 'm' :
         printf("You have selected medium size pizza.\n");
         order[order_count].size = "Medium";
         order[order_count].price = 8.0;
         order[order_count].topping[0] = "Cheese";
         break;
      case 'l' :
         printf("You have selected large size pizza.\n");
         order[order_count].size = "Large";
         order[order_count].price = 12.0;
         order[order_count].topping[0] = "Cheese";
         break;
      default :
         printf("\nPlease Enter Valid Character: only s/m/l allowed.\n" );
         goto GET_PIZZA_SIZE;
   }
    char T;
    printf("\nBy default Your Pizza order comes with topping cheese default. You can add more toppings.You will be charged extra $1 for each toppings. \n");
    printf("Select Toppings:\n");
    printf(" Enter 1 for Bacon \nEnter 2 for Olives \nEnter 3 for Ham \nEnter 4 for Mushroom \nEnter 5 for Pinapple\nEnter 6 for Salami \nEnter 7 for Anchovies\n");

    printf("\nDo you want to add more toppings?\n");
    printf("\t Enter y for Yes | n for No\n");

    int topping_count = 0;
    int top_list[4] = {0,0,0,0};
    WANT_MORE_TOPPINGS:
    T = do_you_want_more_topping();
    int topping_id = 0;
    switch(T) {
      case 'y' :
      if(topping_count  >= 4){
        printf("You have already selected four toppings:\n");
        add_topping_to_order(top_list,order_count);
        break;
      }
      
      topping_id = get_new_topping();
      if(topping_id < 0 || topping_id == 0 || topping_id > 6){
        printf("Topping out of range!!");
        printf("\nDo you want to add more toppings?\n");
        printf("\t y = Yes | n = No\n");
        goto WANT_MORE_TOPPINGS;
      }
      else
      { 
          char * tname;
        tname = topping_name_by_id(topping_id);
        printf("You selected: %s\n",tname);
        
        if(*tname!=(get_new_topping(4)))
        {
          top_list[topping_count] = topping_id;
          topping_count = topping_count +1;
          printf("\nDo you want to add more toppings?\n");
          printf("\t y = Yes | n = No\n");
          goto WANT_MORE_TOPPINGS;
        }
        else{
          printf("\nThis topping already selected.\n");
          printf("\nDo you want to add more toppings?\n");
          printf("\t y = Yes | n = No\n");
          goto WANT_MORE_TOPPINGS;
        }
      }
         break;
      case 'n' :
        add_topping_to_order(top_list,order_count);
         break;
      default :
         printf("Please Enter Valid Character: Only y/n allowed.\n" );
         goto WANT_MORE_TOPPINGS;

   }
   
    ASK_ANOTHER_ORDER:

   printf("\nDo you like to order another pizza?\n");
    printf("\t y = yes | n = no\n");
    char another_order;
    printf("Enter your choice: ");
    scanf("%s",&another_order);

    switch(another_order){
      case 'y' :
      order_count = order_count+1;
      goto NEW_ORDER;
      break;

      case 'n' :
      break;

      default:
      printf("Please enter valid value. y/n allowed.\n");
      goto ASK_ANOTHER_ORDER;
      break;
    }

     
DELIVARY_TYPE:
   printf("\nYou want your order to be collected or delivered?\n");
    printf("\t c = collected | d = delivered\n");
    char delivery_type_id;
    char * delivery_type;
    printf("Enter your choice: ");
    scanf("%s",&delivery_type_id);
    char your_name[100];
    long long int  your_phone;
    char your_address[100];

    switch(delivery_type_id){
      case 'c' :
        delivery_type = "collected";
        printf("\nEnter Your Name: ");
        scanf("%s",your_name);
        printf("Enter Your Phone: ");
        scanf("%lld",&your_phone);
        break;

      case 'd':
        delivery_type = "delivered";
        printf("\nEnter Your Name: \n");
        scanf("%s",your_name);
        printf("Enter Your Phone: \n");
        scanf("%lld",&your_phone);
        printf("Enter Your Address: \n");
        scanf("%s",your_address);
        break;

      default:
        printf("Please enter valid value. c/d allowed.\n");
        goto DELIVARY_TYPE;
        break;
    }
    int i, j , k;
printf("\n\n\nYour Order Details:\n");
printf("\n|*********************************************************************************|\n");
printf("|*********************************************************************************|\n\n\n");
for ( i = 0; i < order_count+1; i++ ) 
{
  printf("Pizza %d:""\n",i+1);
  printf("Size: %s\n", order[i].size );
  printf("Price: $%f\n", order[i].price );
   printf("Toppings:  ");
          int top_length;
          char * topp[5];
          char topping[100] = {'\0'};
          for(k=1;k<=4;k++)
          {
            char * topp = order[i].topping[k];
            if(topp != NULL)
            {
              top_length = strlen(topp);
              if(top_length > 0)
              {
                printf("%s\t",topp);
              }
            }
          }
        printf("\n");
      }
      printf("\n");
      printf("Delivary type: %s\n", delivery_type );
      printf("Name: %s\n", your_name );
      printf("Phone: %lld\n", your_phone );
      if(delivery_type_id == 'd')
      {
        printf("Address: %s\n",your_address);
      }
    float total_cost = 0;
    for(i=0;i<order_count+1;i++)
    {
         float pizza_cost= order[i].price;
         int  topping_count=0;
         int top_length=0;

         for(k=1;k<=4;k++)
         {
             char* topp= order[i].topping[k];
            if(topp !=NULL)
            {
                     if(top_length>= 0)
                     {
                         topping_count++;
                     }

            }
          }

          total_cost = total_cost + pizza_cost + topping_count;SS
          float topping_cost = topping_count;
           printf("Topping cost : $%f\n",topping_cost);
     }
     
     printf("\nTotal cost: $%f\n\n",total_cost);
     if(delivery_type_id == 'd' && total_cost <30)
     {
         printf("Total cost less than $30 so additional $8 delivery fee will be added.\n");
         printf("\nTotal cost including delivery fee: $%f\n\n",total_cost+8);

     }

printf("\n\n|*********************************************************************************|\n");
printf("\n|*********************************************************************************|\n\n");

return 0;

}
