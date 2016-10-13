#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    char *title;
    int price;
    struct Book *next;

} Book, *Bookptr;

typedef struct
{
    Bookptr top;
} Stack;

Stack initStack();
int empty(Stack S);
void push(Stack *S, char *title, int price);
Bookptr pop(Stack *S);
void displayStack(Stack S);

int main()
{

    Stack bargainBin = initStack();
    push(&bargainBin, "Harry Potter", 15);
    push(&bargainBin, "Data Structures In C", 25);
    push(&bargainBin, "AI: A modern Approach", 65);
    displayStack(bargainBin);

    pop(&bargainBin);
    pop(&bargainBin);
    displayStack(bargainBin);

    pop(&bargainBin);
    pop(&bargainBin);

    return 0;
}

Stack initStack()
{

    Stack newStack;
    newStack.top = NULL;
    return newStack;

}

int empty(Stack S)
{
    return (S.top == NULL);
}

void push(Stack *S, char *title, int price)
{

    Bookptr newBook = malloc(sizeof(Book));
    newBook->title = title;
    newBook->price = price;

    if(empty(*S)) {newBook->next = NULL;}
    else {newBook->next = S->top;}

    S->top = newBook;

}

Bookptr pop(Stack *S)
{

    if(empty(*S))
    {
        printf("No books left in stock\n");
        exit(1);
    }


    Bookptr bookSold = S->top;
    S->top = S->top->next;
    printf("Sold %s for %d\n\n", bookSold->title, bookSold->price);

    return bookSold;

}

void displayStack(Stack S)
{
    printf("What's left in stock:\n");
    Bookptr currentBook = S.top;
    while(currentBook != NULL)
    {

            printf("Title: %s  Price: %d\n", currentBook->title, currentBook->price);
            currentBook = currentBook->next;

    }

    printf("\n");

}
