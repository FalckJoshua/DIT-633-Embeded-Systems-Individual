#include <stdio.h>  // printf
#include <string.h> // atoi
#include <stdlib.h> // malloc, free

typedef struct Node // Define a structure for a node
{
    int number;        // The number that the node holds
    struct Node *next; // The next node in the list
} Node;                // Define the type of the structure

// Function to insert a node at the end of the list
void insertNode(Node **root, int number)
{
    Node *newNode = malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL)                  // Check if the memory allocation was successful
    {
        printf("Memory allocation failed");
        exit(1); // Exit the program
    }
    (*newNode).next = NULL;     // Set the next pointer of the new node to NULL
    (*newNode).number = number; // Set the number of the new node to the input number

    if (*root == NULL) // If the list is empty
    {
        *root = newNode; // Set the root to the new node
        return;          // Exit the function
    }

    Node *current = *root;          // Create a pointer to the root of the list
    while ((*current).next != NULL) // Loop through the list until the end is reached
    {
        current = (*current).next; // set the current node to the next node
    }
    (*current).next = newNode; // Set the next pointer of the last node to the new node
}

// Function to get the last two nodes in the list
void getLastTwoNodes(Node *root, Node **lastNode, Node **secondLastNode)
{
    *lastNode = NULL;       // Set the last node to NULL
    *secondLastNode = NULL; // Set the second last node to NULL

    while (root != NULL) // Loop through the list
    {
        *secondLastNode = *lastNode; // Set the second last node to the last node
        *lastNode = root;            // Set the last node to the current node
        root = (*root).next;         // Set the current node to the next node
    }
}

// Main function
int main(int argc, char *argv[])
{
    Node *root = NULL;    // Create a pointer to the root of the list
    insertNode(&root, 0); // Insert 0
    insertNode(&root, 1); // Insert 1

    Node *lastNode = NULL;       // Create a pointer to the last node
    Node *secondLastNode = NULL; // Create a pointer to the second last node

    int input = atoi(argv[1]);          // Convert the input to an integer
    int fibonacciNumber = 0;            // Create a variable to hold the fibonacci number
    for (int i = 0; i < input - 2; i++) // Loop through the list
    {

        getLastTwoNodes(root, &lastNode, &secondLastNode); // Get the last two nodes in the list
        if (lastNode != NULL && secondLastNode != NULL)    // If the last two nodes are not NULL
        {
            fibonacciNumber = (*lastNode).number + (*secondLastNode).number; // Calculate the fibonacci number
            insertNode(&root, fibonacciNumber);                              // Insert the fibonacci number into the list
        }
    }
    printf("Fibonacci number: %d\n", fibonacciNumber);

    while (root != NULL) // Loop through the list
    {
        Node *temp = root;   // Create a temporary pointer to the root
        root = (*root).next; // Set the root to the next node
        free(temp);          // Free the memory of the current node
    }
    return 0; // Exit the program
}