#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {

  char *title;
  int numSold; //in millions

  struct book *prevBook;
  struct book *nextBook;

} Book, *BookPtr;

BookPtr makeBook(char *title, int num); //returns a new book pointer struct with the given title and number sold in millions
void addBook(Book *topBook, BookPtr newBook);
void printList(Book topBook);
void removeBook(Book *topBook, char *title);

int main()
{

    Book firstBook;
    firstBook.title = "Harry Potter";
    firstBook.numSold = 20;
    firstBook.nextBook = NULL;
    firstBook.prevBook = NULL;

    BookPtr second = makeBook("Edge World", 5);
    addBook(&firstBook, second);

    printList(firstBook);

    BookPtr third = makeBook("Wheel of time", 20);
    addBook(&firstBook, third);

    printList(firstBook);

    removeBook(&firstBook, "Edge World");
    printList(firstBook);

    removeBook(&firstBook, "adbabd");
    //printList(firstBook);

    return 0;

}

BookPtr makeBook(char *title, int num)
{

    BookPtr newBook = malloc(sizeof(Book));
    newBook->title = title;
    newBook->numSold = num;
    newBook->prevBook = NULL;
    newBook->nextBook = NULL;

    return newBook;

}

void addBook(Book *topBook, BookPtr newBook)
{

    if(topBook->nextBook == NULL)
    {
        newBook->prevBook = topBook;
        topBook->nextBook = newBook;
    }
    else
    {

        BookPtr currentBook = topBook->nextBook;

        while(currentBook->nextBook != NULL) {currentBook = currentBook->nextBook;}

        currentBook->nextBook = newBook;
        newBook->prevBook = currentBook;

    }

}

void printList(Book topBook)
{

    printf("Book Title: %s\nMillions Sold: %d\n\n", topBook.title, topBook.numSold);

    BookPtr currentBook = topBook.nextBook;
    while(currentBook != NULL)
    {
        printf("Error");
        printf("Book Title: %s\nMillions Sold: %d\n\n", currentBook->title, currentBook->numSold);
        currentBook = currentBook->nextBook;

    }

}

void removeBook(Book *topBook, char *title)
{

    if(strcmp(topBook->title, title) == 0) {topBook->nextBook->prevBook = NULL; free(topBook);}
    else
    {

        BookPtr currentBook = topBook->nextBook;
        while(currentBook != NULL && strcmp(currentBook->title, title) != 0)
        {
            currentBook = currentBook->nextBook;
        }

        if(currentBook != NULL)
        {
                if(currentBook->nextBook != NULL)
                {

                    currentBook->prevBook->nextBook = currentBook->nextBook;
                    currentBook->nextBook->prevBook = currentBook->prevBook;
                    free(currentBook);
                }
                else{currentBook->prevBook->nextBook = NULL;}

        }

        else{printf("No book found with that title\n\n");}

    }

}
