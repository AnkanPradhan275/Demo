//C program for Implementation of Singly Linked List
#include<stdio.h>
#include<stdlib.h>

//Define the Node structure
struct Node{
    int data;
    struct Node* next;
};

//Function to create a new node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a new element at the beginning of the singly linked list
void insertAtFirst(struct Node** head,int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

//Function to insert a new element at the end of the singly linked list
void insertAtEnd(struct Node** head,int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to insert a new element at a specififc position in the singly linked list
void insertAtPosition(struct Node** head,int data,int position)
{
    struct Node* newNode = createNode(data);
    if(position == 0)
    {
        insertAtFirst(head, data);
        return;
    }
    
    struct Node* temp = *head;
    for(int i = 0;temp != NULL && i < position - 1;i++)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//Function to delete the first node of the singly linked list
void deleteFromFirst(struct Node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = *head;
    *head  = temp->next;
    free(temp);
}

//Function to delete the last node of the singly linked list
void deleteFromEnd(struct Node** head)
{
    if(*head == NULL)
    {
        printf("List is empty \n");
    }
    
    struct Node* temp = *head;
    if (temp->next==NULL){
        free(temp);
        *head = NULL;
        return;
    }
    
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

//Function to delete a node at a specific position at a specific position in the singly linked list
void deleteAtPosition(struct Node** head,int position)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = *head;
    if(position == 0){
        deleteFromFirst(head);
        return;
    }
    for(int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL)
    {
        printf("Position out of range\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
//Function to print the linked list
void print(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf(" %d=>",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Driver code 
int main(){
    struct Node*head = NULL;
    int size,data,insertend,pos = 0, posdata,delpos,deldata;
    printf("\n Enter the size of linked list :");
    scanf("%d",&size);
    printf("\n Enter the elements: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&data);
        insertAtFirst(&head, data);
    }
    print(head);
    /*
    printf("\n Enter the data you want to enter at the end : ");
    scanf("%d",&insertend);
    insertAtEnd(&head, insertend);
    print(head);
    */

/*
    printf("\n Enter the position you want to enter : ");
    scanf("%d",&pos);
    
    printf("Enter the data you want to enter at the specific position %d:" , pos);
    scanf("%d",&posdata);
    insertAtPosition(&head, posdata, pos);
    print(head);
*/
/*    printf("Linked List after deleting the node :");
    deleteFromFirst(&head);
    print(head);
*/

/*    deleteFromEnd(&head);
    print(head);
    */
    printf("\n Enter the postion where you want to delete : ");
    scanf("%d", &delpos);
    deleteAtPosition(&head, delpos);
    print(head);
    
    return 0;
}