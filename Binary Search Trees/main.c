#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int value;

    struct Node *leftNode;
    struct Node *rightNode;

} Node, *Nodeptr;

Nodeptr makeNode(int val);
void addNode(Nodeptr topNode, int val);
void printTree(Nodeptr topNode);
Nodeptr returnNode(Nodeptr topNode, int val);

int main()
{
    Nodeptr topNode = makeNode(5);
    addNode(topNode, 9);
    addNode(topNode, 11);
    addNode(topNode, 4);
    addNode(topNode, 6);
    addNode(topNode, 2);
    addNode(topNode, 1);
    addNode(topNode, 13);
    addNode(topNode, 8);
    addNode(topNode, 112);
    addNode(topNode, 24);
    addNode(topNode, 3);
    addNode(topNode, 7);
    printTree(topNode);

    returnNode(topNode, 4);
    returnNode(topNode, 6);
    returnNode(topNode, 7);
    returnNode(topNode, 35);
    return 0;
}


Nodeptr makeNode(int val)
{

    Nodeptr newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    return newNode;

}

void addNode(Nodeptr topNode, int val)
{

    Nodeptr newNode = makeNode(val);

    Nodeptr currentNode = topNode;
    while(currentNode != NULL)
    {

        if(currentNode->value > newNode->value)
        {
            if(currentNode->leftNode == NULL)
            {

                currentNode->leftNode = newNode;
                break;
            }
            currentNode = currentNode->leftNode;

        }
        else
        {
            if(currentNode->rightNode == NULL)
            {
                currentNode->rightNode = newNode;
                break;
            }
            currentNode = currentNode->rightNode;

        }


    }

}

void printTree(Nodeptr topNode)
{

   printf("Val: %d\n", topNode->value);
   if(topNode->leftNode != NULL)
   {printf("Left Node "); printTree(topNode->leftNode);}
   if(topNode->rightNode != NULL)
   {printf("Right Node "); printTree(topNode->rightNode);}

}

Nodeptr returnNode(Nodeptr topNode, int val)
{

    int nodesVisited = 1;
    Nodeptr currentNode = topNode;

    while(currentNode != NULL && currentNode->value != val)
    {

            if(currentNode->value > val) {currentNode = currentNode->leftNode;}
            else{currentNode = currentNode->rightNode;}
            nodesVisited++;
    }

    if(currentNode == NULL) {printf("That value is not in the list\n"); return NULL;}
    else{printf("Value %d found, visited %d nodes\n", val, nodesVisited);}

}
