/* Write a program to create a structure to store the information of n number of Employees. 
Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. 
Display the information of employees with gross salary. Use array of structure. */

#include<stdio.h>

struct employee
{
    int Emp_id; 
    char Name[15];
    char Designation[15];
    float basic_salary;
    float hra;
    float da;
};


int main(){
    int n, i;
    float gross;

    struct employee a[100];

    printf("\nEnter no. of employees: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("\nEnter employee %d information:",i+1);
        printf("\nEmployee ID: ");
        scanf("%d",&a[i].Emp_id);
        printf("\nName: ");
        scanf("%s",a[i].Name);
        printf("\nDesignation: ");
        scanf("%s",a[i].Designation);
        printf("\nBasic Salary: ");
        scanf("%f",&a[i].basic_salary);
        printf("\nHRA %%: ");
        scanf("%f",&a[i].hra);
        printf("\nDA %%: ");
        scanf("%f",&a[i].da);
    }

    printf("\nEmployee Information:\n");
    for(i=0;i<n;i++){
        printf("\nEmployee ID: %d", a[i].Emp_id);
        printf("\nName: %s",a[i].Name);
        printf("\nDesignation: %s",a[i].Designation);
        printf("\nBasic Salary: %.2f",a[i].basic_salary);
        printf("\nHRA: %.2f %%",a[i].hra);
        printf("\nDA: %.2f %%",a[i].da);
        gross = a[i].basic_salary + ((a[i].basic_salary * a[i].hra)/100) + ((a[i].basic_salary * a[i].da)/100);
        printf("\nGross Salary: %.2f\n",gross);
    }

    return 0;
}
