#include <stdio.h>
#include <string.h>
typedef struct {
    struct name{
        char first[10];
        char last[10];
    }n;
    char branch[10];
    char rollNo[10];
    struct DOB{
        int date;
        int month;
        int year;
    }dob;
    char company[10];
    int annualPackage;
    struct DOJ{
        int date;
        int month;
        int year;
    }doj;
}Student;

void readData(Student s[])
{
    for(int i=0;i<500;i++)
    {
        printf("For student %d: ",i+1);
        printf("Please enter First name: ");
        scanf("%s",s[i].n.first);
        printf("Please enter Last name: ");
        scanf("%s",s[i].n.last);
        printf("Please enter Branch: ");
        scanf("%s",s[i].branch);
        printf("Please enter roll number: ");
        scanf("%s",s[i].rollNo);
        printf("Please enter DOB:\n");
        printf("Date: ");
        scanf("%d",&s[i].dob.date);
        printf("Month: ");
        scanf("%d",&s[i].dob.month);
        printf("Year: ");
        scanf("%d",&s[i].dob.year);
        printf("Please enter company name: ");
        scanf("%s",s[i].company);
        printf("Please enter annual package: ");
        scanf("%d",&s[i].annualPackage);
        printf("Please enter DOJ:\n");
        printf("Date: ");
        scanf("%d",&s[i].doj.date);
        printf("Month: ");
        scanf("%d",&s[i].doj.month);
        printf("Year: ");
        scanf("%d",&s[i].doj.year);
    }
    printf("Thank you: ");
}

void printRecord(Student s)
{
    printf("Name of Student: %s %s",s.n.first,s.n.last);
    puts("");
    printf("Branch: %s",s.branch);
    puts("");
    printf("Roll: %s",s.rollNo);
    puts("");
    printf("DOB: %d-%d-%d",s.dob.date,s.dob.month,s.dob.year);
    puts("");
    printf("Name of company: %s",s.company);
    puts("");
    printf("Annual Package: %d",s.annualPackage);
    puts("");
    printf("DOB: %d-%d-%d",s.doj.date,s.doj.month,s.doj.year);
    puts("");
}

void printAccPackage(Student s[])
{
    for(int i=0;i<499;i++)
    {
        for(int j=0;j<499-i;j++)
        {
            if(s[j].annualPackage > s[j+1].annualPackage)
            {
                Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    int i=0;
    while(i<500)
    {
        if(s[i].annualPackage == s[i+1].annualPackage)
        {
            if(strcmp(s[i].n.first, s[i+1].n.first) < 0)
            {
                printRecord(s[i]);
                i++;
                printRecord(s[i]);
                i++;
            }
        }
        else
        {
            printRecord(s[i]);
            i++;
        }
    }
}

int main()
{
    Student s[500];
    
    readData(s);
    printAccPackage(s);
    
    return 0;
}