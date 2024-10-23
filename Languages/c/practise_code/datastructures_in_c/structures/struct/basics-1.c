#include <stdio.h>

typedef struct storyBooks{
    char *title;
    char *author;
    int book_id;
} book;

int main ()
{
    book book1 = {"rational man", "andrew tate", 200};
    book book2 = {"art of war", "san zu", 201};
    

    printf("the book %s by %s has its book id as %d\n", book1.title, book1.author, book1.book_id);

    return (0);
}