#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[30];
    char id[12];
    char hometown[30];
    float gpa;
} sinhvien;

void Nhap(sinhvien *sv, int n, int count);
void In(sinhvien *sv, int count);
void timmssv(sinhvien *sv, int count);
void timgpaque(sinhvien *sv, int count);
void sapxep(sinhvien *sv, int count);

int main()
{
    int count = 0;
    sinhvien *sv = NULL;

    while (1)
    {
        fflush(stdin);
        printf("1. Nhap\n");
        printf("2. In\n");
        printf("3. Tim kiem mssv\n");
        printf("4. Tim kiem GPA que quan\n");
        printf("5. Sap xep\n");
        printf("6. Thoat\n");

        char index;
        scanf("%c", &index);

        if (index == '1')
        {
            printf("Nhap so luong sinh vien muon nhap them!\n");
            int n;
            scanf("%d", &n);
            count += n;
            sv = (sinhvien *)realloc(sv, (count) * sizeof(sinhvien));

            fflush(stdin);
            Nhap(sv, n, count);
        }
        else if (index == '2')
            In(sv, count);
        else if (index == '3')
            timmssv(sv, count);
        else if (index == '4')
            timgpaque(sv, count);
        else if (index == '5')
            sapxep(sv, count);
        else if (index == '6')
            break;
    }

    printf("Thoat chuong trinh thanh cong!");
}

void Nhap(sinhvien *sv, int n, int count)
{
    for (int i = count - n; i < count; i++)
    {
        printf("\nNhap sinh vien moi:\n");
        printf("Nhap ten: ");
        scanf("%[^\n]", sv[i].name);
        fflush(stdin);
        printf("Nhap id: ");
        scanf("%[^\n]", sv[i].id);
        fflush(stdin);
        printf("Nhap que quan: ");
        scanf("%[^\n]", sv[i].hometown);
        fflush(stdin);
        printf("Nhap GPA: ");
        scanf("%f", &sv[i].gpa);

        while (sv[i].gpa < 0 || sv[i].gpa > 4)
        {
            printf("Nhap sai GPA, nhap lai: ");
            scanf("%f", &sv[i].gpa);
        }

        fflush(stdin);
    }
}

void In(sinhvien *sv, int count)
{
    float gpatb = 0.0;
    printf("%-4s %-30s %-12s %-30s %-5s\n", "STT", "Ten", "MSSV", "Que quan", "GPA");
    for (int i = 0; i < count; i++)
    {
        printf("%-4d %-30s %-12s %-30s %-5.2f\n", i + 1, sv[i].name, sv[i].id, sv[i].hometown, sv[i].gpa);
        gpatb += sv[i].gpa;
    }

    printf("Diem GPA trung binh tat ca sinh vien: %.2f\n", gpatb / count);
}

void timmssv(sinhvien *sv, int count)
{
    printf("Nhap MSSV can tim: ");
    char search[12];
    scanf("%[^\n]", search);

    int found = 0;
    for (int i = 0; i < count; i++)
        if (!strcmp(search, sv[i].id))
        {
            found = 1;
            printf("Tim thay sinh vien %s\nMSSV: %s\nQuequan: %s\nGPA: %.2f\n", sv[i].name, sv[i].id, sv[i].hometown, sv[i].gpa);
        }

    if (!found)
        printf("Khong tim thay sinh vien!\n");
}

void timgpaque(sinhvien *sv, int count)
{
    printf("Nhap que quan sinh vien: ");
    char search[30];
    scanf("%[^\n]", search);

    int stt = 0;
    printf("Tim thay cac sinh vien sau co diem GPA lon hon GPA trung binh (la 2.5) gom:\n");
    printf("%-4s %-30s %-12s %-30s %-5s\n", "STT", "Ten", "MSSV", "Que quan", "GPA");
    for (int i = 0; i < count; i++)
        if (sv[i].gpa >= 2.5)
            if (!strcmp(strlwr(search), strlwr(sv[i].hometown)))
            {
                stt++;
                printf("%-4d %-30s %-12s %-30s %-5.2f\n", stt, sv[i].name, sv[i].id, sv[i].hometown, sv[i].gpa);
            }
}

void sapxep(sinhvien *sv, int count)
{
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
            if (sv[i].gpa < sv[j].gpa)
            {
                sinhvien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }

    In(sv, count);
}
