/***Name: Ahmed Ghoneim..
 * This program is for an online store for selling t-shirts from student organizations in the USF
 ***/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ORG_NAME_LEN 50
#define SIZE_LEN 3
struct tshirt {
char org_name[ORG_NAME_LEN+1];
char size[SIZE_LEN+1];
double price;
int quantity;
struct tshirt *next;
};


struct tshirt * add_to_inventory(struct tshirt *inventory);
void search_by_organization(struct tshirt *inventory);
void search_by_size(struct tshirt *inventory);
void print_inventory(struct tshirt *inventory);
void clear_inventory(struct tshirt *inventory);
int read_line(char str[], int n);
void help();

int main() {
char code;
struct tshirt *inventory = NULL;
help();
printf("\n");
for (;;) {

printf("Enter operation code: ");
scanf(" %c", &code);
while(getchar() != '\n')
;

switch (code) {
case 'a':
inventory = add_to_inventory(inventory);
break;
case 'h':
help();
break;
case 'o':
search_by_organization(inventory);
break;
case 's':
search_by_size(inventory);
break;
case 'p':
print_inventory(inventory);
break;
case 'q':
clear_inventory(inventory);
return 0;
default:
printf("Illegal operation code!\n");
}
printf("\n");
}
}

void help() {
printf("List of operation codes:\n");
printf("\t'a' for adding a t-shirt to the inventory;\n");
printf("\t'h' for help;\n");
printf("\t'o' for searching t-shirts by organization;\n");
printf("\t's' for searching t-shirts by size;\n");
printf("\t'p' for printing the inventory;\n");
printf("\t'q' for quit.\n");
}
struct tshirt * add_to_inventory(struct tshirt *inventory) {

//creating linkedlists
struct tshirt *new_tshirt = (struct tshirt*)malloc(sizeof(struct tshirt));
struct tshirt *temp = inventory;

//taking inputs from user
printf("Enter Org name: ");
read_line(new_tshirt->org_name,ORG_NAME_LEN+1);

printf("Enter tshirt size: ");
read_line(new_tshirt->size,SIZE_LEN+1);

//if statements for the first input
if(inventory == NULL) {
	inventory = new_tshirt;
	new_tshirt->next = NULL;
	
	printf("Enter price: ");
	scanf("%lf", &new_tshirt->price);
	
	printf("Enter Quantity: ");
	scanf("%d", &new_tshirt->quantity);
	return inventory;
}

//while statement to go over the list to check if the shirt exists or not
while(temp!=NULL)
        {
            if(strcmp(temp->org_name,new_tshirt->org_name)==0 && strcmp(temp->size,new_tshirt->size)==0)
            {
                printf(" this t-shirt already exists\n");
                free(new_tshirt);
                return inventory;
            }
            temp = temp->next;
        }
        
        printf("Enter price \n ");
        scanf("%lf",&new_tshirt->price);
        printf("Enter Quantity \n ");
        scanf("%d",&new_tshirt->quantity);

        temp = inventory;

	//going over every item in the linked list
        while(temp->next!=NULL)
            temp = temp->next;
        
        temp->next = new_tshirt;
        new_tshirt->next = NULL;

        return inventory;

}
void search_by_organization(struct tshirt *inventory) {

//creating a linkedlist
struct tshirt *p = inventory;
char word[ORG_NAME_LEN+1];

printf("Enter Org name: ");
read_line(word,ORG_NAME_LEN+1);
int flag = 0;

//while statement to check if the item exists or no
while(p != NULL) {
	if(strcmp(p->org_name, word)==0) {
		printf("A tshirt of this %s organization exists.\n",word);
		
		flag = 1;	
		char org[ORG_NAME_LEN+1];
		strcpy(org,p->org_name);
		
		char size[SIZE_LEN+1];
		strcpy(size,p->size);

		double price = p->price;
                int quantity = p->quantity;
                p = p->next;
                printf("|----------------------------------------------------|-----|-------|------|\n");
                printf("| Student organization | Sz. | Price | Qty. |\n");
                printf("|----------------------------------------------------|-----|-------|------|\n");
                printf("| %-50s | %-3s | %5.2f | %4d |\n", org, size, price, quantity);
                printf("|----------------------------------------------------|-----|-------|------|\n");
                return;
        }
            p = p->next;
    }
	 if(flag == 0)
                printf("t-shirt not found!");

}
void search_by_size(struct tshirt *inventory) {

    //creating linked list
    struct tshirt *temp = inventory;
    char word[SIZE_LEN+1];
    printf("Enter T-shirt size: ");
    read_line(word,SIZE_LEN+1);
    int flag = 0;
    while(temp!=NULL)
    {
	//checking if the size exists or not
        if(strcmp(temp->size,word)==0)
        {
            printf("tshirt of size : %s, exists.\n",word);
            printf("T-shirt details\n");
	    
	    flag = 1;	
            char org[ORG_NAME_LEN+1];
            strcpy(org,temp->org_name);

            char size[SIZE_LEN+1];
            strcpy(size,temp->size);

            double price = temp->price;
            int quantity = temp->quantity;
            temp = temp->next;
            printf("|----------------------------------------------------|-----|-------|------|\n");
            printf("| Student organization | Sz. | Price | Qty. |\n");
            printf("|----------------------------------------------------|-----|-------|------|\n");
            printf("| %-50s | %-3s | %5.2f | %4d |\n", org, size, price, quantity);
            printf("|----------------------------------------------------|-----|-------|------|\n");
        }
        
	temp = temp->next;
            
}
	if(flag == 0)
		printf("t-shirt not found!");
}

void print_inventory(struct tshirt *inventory) {

struct tshirt *temp = inventory;

//creating a linkedlist and going over every item in it
while(temp!=NULL) {

	char org[ORG_NAME_LEN+1];
	strcpy(org, temp->org_name);

	char size[SIZE_LEN+1];
	strcpy(size,temp->size);

	double price = temp->price;
	int quantity = temp->quantity;
	temp = temp->next;

printf("|----------------------------------------------------|-----|-------|------|\n");
printf("| Student organization                               | Sz. | Price | Qty. |\n");
printf("|----------------------------------------------------|-----|-------|------|\n");
printf("| %-50s | %-3s | %5.2f | %4d |\n", org, size, price, quantity);
printf("|----------------------------------------------------|-----|-------|------|\n");
}
	if(inventory == NULL){
              printf("No t-shirt found!");
}

}
void clear_inventory(struct tshirt *inventory) {
struct tshirt *temp;
  while(temp!= NULL)
  {
      struct tshirt *done = temp;
      temp = temp->next;
      if( temp!= NULL)
           free(done);
  }
}
int read_line(char str[], int n) {
int ch, i=0;
while (isspace(ch = getchar()))
;
str[i++] = ch;
while ((ch = getchar()) != '\n') {
if (i < n)
str[i++] = ch;    
}
str[i] = '\0';
return i;
}
