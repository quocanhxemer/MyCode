#include <stdio.h>
#include <string.h>

typedef struct
{
    char book_name[30];
    char author_name[30];
    char publisher[20];
    int year;
    float price;
} book;

void Enter();
void Print();
void Sort();
void SearchTitle();
void SearchAuthor();

int main()
{
    char index = '0';
    while (index != '6')
    {
        printf("=======================\n");
        printf("1. Enter information of n books of HUST\n");
        printf("2. Print the information of the entered books on the screen\n");
        printf("3. Sort the descending information by year of publication and display\n");
        printf("4. Search for books by title\n");
        printf("5. Search books by author's name\n");
        printf("6. Exit\n");
        printf("=======================\n");

        scanf("%c", &index);
        fflush(stdin);
        switch (index)
        {
        case '1':
            Enter();
            break;
        case '2':
            Print();
            break;
        case '3':
            Sort();
            break;
        case '4':
            SearchTitle();
            break;
        case '5':
            SearchAuthor();
            break;
        case '6':
            printf("Exit...\n");
            break;
        default:
            printf("Invalid input!\n");
            getchar();
            break;
        }
        fflush(stdin);
    }
}

void Enter()
{
    FILE *p = fopen("HUST.txt", "w");
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    fprintf(p, "%d\n", n);
    book input;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter information for new book\n");
        printf("Enter book name: ");
        scanf("%s", input.book_name);
        printf("Enter author name: ");
        scanf("%s", input.author_name);
        printf("Enter publisher: ");
        scanf("%s", input.publisher);
        printf("Enter year: ");
        scanf("%d", &input.year);
        printf("Enter price: ");
        scanf("%f", &input.price);

        fprintf(p, "%s\n%s\n%s\n%d\n%f\n\n", input.book_name, input.author_name, input.publisher, input.year, input.price);
    }
    fclose(p);
}

void FileToBook(book *b, FILE *p)
{
    fscanf(p, "%s\n%s\n%s\n%d\n%f\n\n", b->book_name, b->author_name, b->publisher, &b->year, &b->price);
}

void PrintBook(book b)
{
    printf("%-30s%-30s%-10d%-10f\n", b.book_name, b.author_name, b.year, b.price);
}

void Print()
{
    FILE *p = fopen("HUST.txt", "r");
    if (p == NULL)
    {
        printf("No data!\n");
        getchar();
        return;
    }

    int n;
    fscanf(p, "%d", &n);
    printf("Total number of books: %d\n", n);

    book output;
    for (int i = 0; i < n; i++)
    {
        FileToBook(&output, p);
        PrintBook(output);
    }
    fclose(p);
    getchar();
}

void Sort()
{
    FILE *p = fopen("HUST.txt", "r");
    if (p == NULL)
    {
        printf("No data!\n");
        getchar();
        return;
    }

    FILE *sort = fopen("HUST2021.txt", "w");

    int n;
    fscanf(p, "%d", &n);
    fprintf(sort, "%d\n", n);

    book sorted[n];
    for (int i = 0; i < n; i++)
        FileToBook(&sorted[i], p);

    fclose(p);

    for (int i = 0; i < n; i++)
        for (int k = i + 1; k < n; k++)
            if (sorted[i].year < sorted[k].year)
            {
                book temp = sorted[i];
                sorted[i] = sorted[k];
                sorted[k] = temp;
            }
            else if (sorted[i].price < sorted[k].price)
            {
                book temp = sorted[i];
                sorted[i] = sorted[k];
                sorted[k] = temp;
            }

    for (int i = 0; i < n; i++)
    {
        fprintf(sort, "%s\n%s\n%s\n%d\n%f\n\n", sorted[i].book_name, sorted[i].author_name, sorted[i].publisher, sorted[i].year, sorted[i].price);
        Print(sorted[i]);
    }

    fclose(sort);

    getchar();
}

void SearchTitle()
{
}

void SearchAuthor() {}
