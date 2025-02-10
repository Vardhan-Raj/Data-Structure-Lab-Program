#include<stdio.h>
// structure definition
struct employee
{
    char Name[20];
    char Designation[20];
    int basic_salary;
    int hra;
    int da;
};

// main method
int main(){
    int n;
    printf("Enter the no. of employees : ");
    scanf("\n%d", &n);
    struct employee emp[n];
    for(int i=0;i<n;i++){
        printf("Enter employee %d information : \n", i+1);
        scanf("%s %s %d %d %d", emp[i].Name, emp[i].Designation, &emp[i].basic_salary, &emp[i].hra, &emp[i].da);
    }
    for (int i = 0; i < n; i++){
        printf("Name : %s\nDesignation : %s\nBasic Salary : %d\nHRA : %d%%\nDA : %d%%\n", emp[i].Name, emp[i].Designation, emp[i].basic_salary, emp[i].hra, emp[i].da);
        printf("Gross Salary : %.2f", emp[i].basic_salary + (emp[i].basic_salary * emp[i].hra * 0.01) + (emp[i].basic_salary*emp[i].da * 0.01));
    }
    return 0;
}