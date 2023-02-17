// Create one database using header linked listand file system to store the details of a shopping card given by the Shopping Mall.
//     Shopping Card(Card_ID, Customer_Name, Points, Date_of_Birth, Last_date_of_trasaction, address)
//     Item(Item_ID, Item_Name, Price, Quantity)
// Implement the following modules / sub - modules using menu driven approach :
//  Keep the Card_ID and Item_ID Unique(Duplicated entry should not be allowed and prompted)
//  Update function to update the address only(if required).Other fields can’t be updated by the customer.
//  A customer can buy different products listed and accordingly points will be assigned as follows :
//      Type of Item     Points for every Rs. 100 purchase
//          Grocery                     1
//         Garments                     5
//       Electronics                   10
//  When the manager of the shopping mall decides(decides a date), a discount of 10 % can be given to 10 customers those 
// who have first accumulated 1000 points.The customer may immediately redeem the points and get 10 % discount and its 
// points will be reset to zero, else keep it for later use.The next 10 customer will get the discount in the next
// month same date.This process continues.
//  When the manager of the shopping mall decides(decides a date), a discount of 15 % can be given to 5 customers those 
// who have first accumulated 1000 points and are senior citizens(age & gt;60).The customer may immediately redeem the 
// points and get 10 % discount and its points will be reset to zero, else keep it for later use.This process is repeated in
// every month.
//  Display the customer details and item details as per requirements.
//  Add new customer as well as new items.
//  Delete existing customer if the last transaction date is before one year.
//  The system should show the items out of stock during the purchase.

#include <stdio.h>
#include <string.h>

struct item
{
    int itemID;
    char itemName[100];
    float price;
    int quantity;
    struct item* next;
}*itemStart = NULL;

struct shoppingCard
{
    int cardID;
    char customerName[100];
    int points;
    int d_dob, m_dob, y_dob;
    int d_trans, m_trans, y_trans;
    char address[100];
    struct shoppingCard* next;
    struct item* itemList;
}*shoppingCardStart = NULL;


struct shoppingCard* getToCard(int cardId)
{
    struct shoppingCard* card = shoppingCardStart;
    while (!card)
    {
        if (card->cardID == cardId)
            return card;
        card = card->next;
    }
    return NULL;
}

int isCardIdUnique(int cardId)
{
    struct shoppingCard* card = NULL;
    card = getToCard(cardId);

    if (!card)
    {
        printf("Card ID Exists\n");
        return 0;
    }
    return 1;
}

int isItemIdUnique(int cardId, int itemId)
{
    struct shoppingCard* card = NULL;
    card = getToCard(cardId);

    if (!card)
    {
        printf("Shopping Card not found\n");
        return 0;
    }
    struct item* item = card->itemList;
    while (!item)
    {
        if (item->itemID == itemId)
        {
            printf("Item ID Exists\n");
            return 0;
        }
        item = item->next;
    }
    return 1;
}

void update(char address[], int cardId)
{
    struct shoppingCard* card = getToCard(cardId);
    if (!card)
    {
        printf("Shopping Card not found\n");
        return;
    }
    strcpy(card->address, address);
}

void points(char ch, struct shoppingCard* card, int mrp)
{
    int add = mrp / 100;
    switch (ch)
    {
    case 'g':
        card->points += add;
        break;

    case 'G':
        card->points += (add * 5);
        break;

    case 'E':
        card->points += (add * 10);

    default:
        break;
    }
}

void displayCustomer()
{
    struct shoppingCard* card = shoppingCardStart;
    while (!card)
    {
        printf("\nCard ID : %d", card->cardID);
        printf("\nCustomer Name : %s", card->customerName);
        printf("\nPoints : %d", card->points);
        printf("\nDate Of Birth : %d/%d/%d", card->d_dob, card->m_dob, card->y_dob);
        printf("\nDate Of Last Transcaction : %d/%d/%d", card->d_trans, card->m_trans, card->y_trans);
        printf("\nAddress : %s", card->address);
        card = card->next;
    }

}

void displayItem(struct shoppingCard* card)
{
    struct item* item = card->itemList;
    while (!item)
    {
        printf("\nItem ID : %d", item->itemID);
        printf("\nItem Name : %s", item->itemName);
        printf("\nPrice : %d", item->price);
        printf("\nQuantity : %d", item->quantity);
        item = item->next;
    }
}

void addNewCustomer(int cardId, char name[], int d_dob, int m_dob, int y_dob, char address[])
{
    if (isCardIdUnique(cardId))
    {
        struct shoppingCard* card = (struct shoppingCard*)malloc(sizeof(struct shoppingCard));
        card->cardID = cardId;
        strcpy(card->address, address);
        strcpy(card->customerName, name);
        card->d_dob = d_dob;
        card->m_dob = m_dob;
        card->y_dob = y_dob;
        card->points = 0;
        card->d_trans = card->m_trans = card->y_trans = 0;

    }
}