/*Ashraf Ali - 19315281*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nextNode;
} Node;

void copy(Node **head, int arr[], int n); //Copys the contents of an array to a linkedlist
void printLinkedList(Node *head);         //Prints the contents of our linked list

int main()
{
    int length; // Stores the length of our array

    /*Input the size of the array*/
    printf("Input the length of your array: ");
    scanf("%d", &length);
    int arr[length];
    /*Inputs the contents of our array*/
    for (int i = 0; i < length; i++)
    {
        printf("Enter index %d: ", i);
        scanf("%d", &arr[i]);
    }

    Node *head = NULL;        //Creates a header for our linkedlist
    copy(&head, arr, length); //Copys the contents of the array to our linkedlist
    printLinkedList(head);    //Prints the linked list
}

/*Copys the contents of an array to a linkedlist*/
void copy(Node **head, int arr[], int n)
{
    /*Only copies our array if the length of the linked list is greater than 0*/
    if (n > 0)
    {
        Node *temp = malloc(sizeof(Node)); //Pointer to our node
        temp->data = arr[0];               //Inputs the contents of the first element of the array into our linkedlist
        temp->nextNode = NULL;             //Sets the next node to null
        *head = temp;                      //Sets the head of our linked list to the current pointer
        for (int i = 1; i < n; i++)
        {
            Node *cur = malloc(sizeof(Node)); //Creates a new node
            temp->nextNode = cur;             //Sets the next node of our temp equal to our cur node
            cur->data = arr[i];               //Fills the cur node with the current int in our array
            cur->nextNode = NULL;             //Sets the next node to Null
            temp = cur;                       //Increments our temp pointer
        }
    }
}

/*Prints the contents of our linked list*/
void printLinkedList(Node *head)
{
    /*Loops through every element in the linked list using a temp pointer
    And prints out the data stored in it*/
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->nextNode;
    }
    printf("NULL\n");
}