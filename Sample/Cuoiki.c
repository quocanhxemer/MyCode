#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 100

typedef struct
{
    char name[40];
    int student;
    int lecturer;
    int phd;
    float spl;
} school_t;

school_t school[MAX];

void Nhaplieu();
void Hienthi();
void Viettatten();
void Xoavien();
void Sapxep();

int main()
{
    for (int i = 0; i < MAX; i++)
        school[i].student = -1;

    while (1)
    {
        system("cls");
        int index;
        printf("Chuong trinh quan li thong tin\n");
        printf("1. Nhap lieu.\n");
        printf("2. Hien thi bang thong tin.\n");
        printf("3. Viet tat ten.\n");
        printf("4. Xoa vien.\n");
        printf("5. Sap xep.\n");
        printf("6. Thoat chuong trinh.\n");

        printf("Nhap lua chon: ");
        scanf("%d", &index);
        system("cls");

        if (index == 1)
            Nhaplieu();
        else if (index == 2)
            Hienthi();
        else if (index == 3)
            Viettatten();
        else if (index == 4)
            Xoavien();
        else if (index == 5)
            Sapxep();
        else if (index == 6)
            break;
        else
            printf("Nhap sai, hay nhap lai!\n");

        getch();
    }
    printf("Thoat chuong trinh thanh cong!\n");
}

void Nhaplieu()
{
    printf("Nhap so Vien cua Truong: ");
    int sovien;
    scanf("%d", &sovien);

    while (sovien <= 0 || sovien > 100)
    {
        printf("Nhap sai, hay nhap lai!\n");
        scanf("%d", &sovien);
    }

    for (int i = 0; i < sovien; i++)
    {
        int check = 1;
        while (check)
        {
            printf("Nhap lieu cho vien thu %d:\n", i + 1);
            printf("Nhap ten vien: ");
            while (getchar() != '\n')
                ;
            scanf("%[^\n]", school[i].name);
            printf("Nhap so hoc sinh: ");
            scanf("%d", &school[i].student);
            printf("Nhap so giang vien: ");
            scanf("%d", &school[i].lecturer);
            printf("So phd: ");
            scanf("%d", &school[i].phd);

            if (school[i].student < 0 || school[i].phd < 0 || school[i].phd > school[i].lecturer)
                printf("Du lieu nhap sai! Hay nhap lai.\n");
            else
                check = 0;
        }
        school[i].spl = (float)school[i].student / (float)school[i].lecturer;
    }

    school[sovien].student = -1;

    Hienthi();
}

void Hienthi()
{
    int studentsum = 0, lectsum = 0, phdsum = 0;

    printf("%-5s%-40s%-20s%-20s%-20s%-6s\n", "STT", "Vien", "So SV", "So GV", "TS", "Ty le");
    for (int i = 0; school[i].student != -1 && i < MAX; i++)
    {
        printf("%-5d%-40s%-20d%-20d%-20d%-6.2f\n", i + 1, school[i].name, school[i].student, school[i].lecturer, school[i].phd, school[i].spl);
        studentsum += school[i].student;
        lectsum += school[i].lecturer;
        phdsum += school[i].phd;
    }

    printf("\n%-45s%-20d%-20d%-20d%-6.2f\n", "Toan truong", studentsum, lectsum, phdsum, lectsum ? (float)studentsum / (float)lectsum : 0);
}

char chuthuong(char c)
{
    if (c >= 'a' && c <= 'z')
        return c;
    return c + 32;
}

void Viettatten()
{
    for (int i = 0; school[i].student != -1 && i < MAX; i++)
    {
        if (strlen(school[i].name) <= 10)
            continue;
        int j = 0;
        for (int k = 0; k < strlen(school[i].name); k++)
        {
            school[i].name[j] = chuthuong(school[i].name[k]);
            j++;
            while (school[i].name[k] != ' ' && k < strlen(school[i].name))
                k++;
        }
        school[i].name[0] -= 32;
        school[i].name[j] = '\0';
    }
    printf("Da viet tat nhung vien tren 10 ki tu!\n");
}

void Xoavien()
{
    char vien[40];
    while (getchar() != '\n')
        ;
    int found = 0;
    printf("Nhap ten vien muon xoa: ");
    scanf("%[^\n]", vien);
    for (int i = 0; school[i].student != -1 && i < MAX; i++)
    {
        if (!strcmp(vien, school[i].name))
        {
            found = 1;
            for (int k = i; k < MAX; k++)
            {
                school[k] = school[k + 1];
                if (school[k + 1].student == -1)
                    school[k].student = -1;
            }
        }
    }
    if (found)
        printf("Da xoa vien %s!\n", vien);
    else
        printf("Khong tim thay vien %s!\n", vien);
}

void Sapxep()
{
    for (int i = 0; i < MAX && school[i].student != -1; i++)
    {
        for (int k = i + 1; k < MAX && school[k].student != -1; k++)
        {
            if (school[i].student < school[k].student)
            {
                school_t temp = school[i];
                school[i] = school[k];
                school[k] = temp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}
