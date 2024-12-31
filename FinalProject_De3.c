#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char bookName[100];
    char author[50];
    char category[50];
    long long price;
} Book;

void inputBooks(Book *book, int *n) {
    printf("Enter number of books: ");
    scanf("%d", n);
    getchar();
    for (int i = 0; i < *n; i++) {
        book[i].id = i + 1;
        printf("Please insert book name: ");
        fgets(book[i].bookName, 100, stdin);
        book[i].bookName[strcspn(book[i].bookName, "\n")] = '\0';
        printf("Please insert author name: ");
        fgets(book[i].author, 50, stdin);
        book[i].author[strcspn(book[i].author, "\n")] = '\0';
        printf("Please insert category: ");
        fgets(book[i].category, 50, stdin);
        book[i].category[strcspn(book[i].category, "\n")] = '\0';
        printf("Please insert price: ");
        scanf("%lld", &book[i].price);
        getchar();
    }
}

void displayBook(Book *book, int n) {
    printf("|=======|====================|====================|===============|===============|\n");
    printf("|   ID  |         Bookname   |        Author      |     Category  |      Price    |\n");
    printf("|=======|====================|====================|===============|===============|\n");
    for (int i = 0; i < n; i++) {
        printf("|   %d   |   %-16s |   %-16s |   %-11s |   %11.2f |\n", book[i].id, book[i].bookName, book[i].author, book[i].category, (double)book[i].price);
    }
    printf("|=======|====================|====================|===============|===============|\n");
    printf("\n");
}

void addBook(Book *book, int n) {
    n++;
    book[n].id = n + 1;
    printf("Please insert book name: ");
    fgets(book[n].bookName, 100, stdin);
    book[n].bookName[strcspn(book[n].bookName, "\n")] = '\0';
    printf("Please insert author name: ");
    fgets(book[n].author, 50, stdin);
    book[n].author[strcspn(book[n].author, "\n")] = '\0';
    printf("Please insert price: ");
    scanf("%ld", &book[n].price);
    getchar();
}

void deleteBook(Book *book, int n) {
    int id;
    printf("Please insert book ID you want to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (book[i].id == id) {
            for (int j = i; j < n; j++) {
                book[j] = book[j + 1];
            }
            n--;
            break;
        }
    }
}

void menu () {
    Book book[50];
    int choice;
    int n;
    while (1) {
        printf("======================MENU=======================\n");
        printf("[1]. Please insert amount and book infomation: \n");
        printf("[2]. Display all book infomation: \n");
        printf("[3]. Add a book: \n");
        printf("[4]. Delete a book: \n");
        printf("[5]. Change book infomation: \n");
        printf("[6]. Search book by name: \n");
        printf("[7]. Sort books by price: \n");
        printf("[8]. Exit: \n");
        printf("=================================================\n");
        printf("Choice your option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputBooks(book, &n);
                break;
            case 2:
                displayBook(book, n);
                break;
            case 3:
                addBook(book, n);
                break;
            case 4:
                deleteBook(book, n);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}
