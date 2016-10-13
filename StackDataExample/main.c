#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    //up to us what we put here
    char *title;
    int price;
    int barCode;
    char *genre;

} StackData;

typedef struct
{

    StackData data;
    struct Book *next;

} Book, *Bookptr;

typedef struct
{
    Bookptr top;
} Stack;

Stack initStack();
int empty(Stack S);
void push(Stack *S, StackData data);
Bookptr pop(Stack *S);
void displayStack(Stack S);

int main()
{

    Stack bargainBin = initStack();

    StackData s;
    s.title = "Harry Potter";
    s.price = 20;
    push(&bargainBin, s);

    s.title = "Data Structures in C";
    s.price = 25;
    push(&bargainBin, s);


    s.title = "AI: a modern Approach";
    s.price = 65;
    push(&bargainBin, s);

    displayStack(bargainBin);

    //pop(&bargainBin);
    //pop(&bargainBin);
    //displayStack(bargainBin);

    //pop(&bargainBin);
    //pop(&bargainBin);

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

void push(Stack *S, StackData data)
{

    Bookptr newBook = malloc(sizeof(Book));
    newBook->data = data;
    if(empty(*S))
    {
     newBook->next = NULL;
     newBook->data.barCode = 12345;
    }
    else
    {
      newBook->next = S->top;
      newBook->data.barCode = S->top->data.barCode + 1;
    }
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
    printf("Sold %s for %d\n\n", bookSold->data.title, bookSold->data.price);



    return bookSold;

}

void displayStack(Stack S)
{
    printf("What's left in stock:\n");
    Bookptr currentBook = S.top;
    while(currentBook != NULL)
    {

            printf("Title: %s  Price: %d Barcode: %d\n", currentBook->data.title, currentBook->data.price, currentBook->data.barCode);
            currentBook = currentBook->next;

    }

    printf("\n");

}
