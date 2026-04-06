#include <stdio.h>

struct employee
{
    int id;
    char name[30];

    float basic;

    float hra;
    float da;
    float ma;

    float pf;
    float tax;

    float gross;
    float net;
};

// Nepal Tax Slab Function
float calculateTax(float annualIncome)
{
    float tax = 0;

    if(annualIncome <= 500000)
    {
        tax = annualIncome * 0.01;
    }
    else if(annualIncome <= 700000)
    {
        tax = (500000 * 0.01) +(annualIncome - 500000) * 0.10;
    }
    else if(annualIncome <= 1000000)
    {
        tax = (500000 * 0.01) +(200000 * 0.10) + (annualIncome - 700000) * 0.20;
    }
    else
    {
        tax = (500000 * 0.01) +(200000 * 0.10) + (300000 * 0.20) + (annualIncome - 1000000) * 0.30;
    }

    return tax;
}

int main()
{
    struct employee emp[50];

    int n = 0;
    int choice;
    int i;
    int searchId;
    int found;

    while(1)
    {
        printf("\n------ NEPAL PAYROLL SYSTEM ------\n");
        printf("1 Add Employee\n");
        printf("2 Show All Employees\n");
        printf("3 Print One Salary Slip\n");
        printf("4 Print All Salary Slips\n");
        printf("5 Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            if(n >= 50)
            {
                printf("Employee limit reached\n");
                continue;
            }

            printf("Employee ID: ");
            scanf("%d",&emp[n].id);

            printf("Employee Name: ");
            scanf(" %[^\n]", emp[n].name);

            printf("Basic Monthly Salary: ");
            scanf("%f",&emp[n].basic);

            // Allowances
            emp[n].hra = emp[n].basic * 0.20;
            emp[n].da  = emp[n].basic * 0.10;
            emp[n].ma  = emp[n].basic * 0.05;

            // Gross salary
            emp[n].gross = emp[n].basic + emp[n].hra + emp[n].da + emp[n].ma;

            // PF Deduction
            emp[n].pf = emp[n].basic * 0.10;

            // Tax Calculation (Slab-based)
            float annualIncome = emp[n].gross * 12;
            float annualTax = calculateTax(annualIncome);
            emp[n].tax = annualTax / 12;

            // Net salary
            emp[n].net = emp[n].gross - (emp[n].pf + emp[n].tax);

            n++;

            printf("Employee added successfully\n");
        }

        else if(choice==2)
        {
            if(n == 0)
            {
                printf("No employees available\n");
                continue;
            }

            printf("\nID\tName\t\tBasic Salary\n");

            for(i=0;i<n;i++)
            {
                printf("%d\t%s\t\t%.2f\n",
                emp[i].id,
                emp[i].name,
                emp[i].basic);
            }
        }

        else if(choice==3)
        {
            printf("Enter Employee ID: ");
            scanf("%d",&searchId);

            found = 0;

            for(i=0;i<n;i++)
            {
                if(emp[i].id == searchId)
                {
                    printf("\n------ SALARY SLIP ------\n");

                    printf("Employee ID : %d\n",emp[i].id);
                    printf("Name        : %s\n\n",emp[i].name);

                    printf("Basic Salary : %.2f\n",emp[i].basic);
                    printf("HRA (20%%)    : %.2f\n",emp[i].hra);
                    printf("DA (10%%)     : %.2f\n",emp[i].da);
                    printf("MA (5%%)      : %.2f\n",emp[i].ma);

                    printf("\nGross Salary : %.2f\n",emp[i].gross);

                    printf("PF Deduction : %.2f\n",emp[i].pf);
                    printf("Tax (Slab)   : %.2f\n",emp[i].tax);

                    printf("\nNet Salary   : %.2f\n",emp[i].net);

                    found = 1;
                    break;
                }
            }

            if(found == 0)
            {
                printf("Employee not found\n");
            }
        }

        else if(choice==4)
        {
            if(n == 0)
            {
                printf("No employees available\n");
                continue;
            }

            for(i=0;i<n;i++)
            {
                printf("\n------ SALARY SLIP ------\n");

                printf("Employee ID : %d\n",emp[i].id);
                printf("Name        : %s\n\n",emp[i].name);

                printf("Basic Salary : %.2f\n",emp[i].basic);
                printf("HRA (20%%)    : %.2f\n",emp[i].hra);
                printf("DA (10%%)     : %.2f\n",emp[i].da);
                printf("MA (5%%)      : %.2f\n",emp[i].ma);

                printf("\nGross Salary : %.2f\n",emp[i].gross);

                printf("PF Deduction : %.2f\n",emp[i].pf);
                printf("Tax (Slab)   : %.2f\n",emp[i].tax);

                printf("\nNet Salary   : %.2f\n",emp[i].net);

                printf("\n----------------------------\n");
            }
        }

        else if(choice==5)
        {
            printf("Program terminated\n");
            break;
        }

        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
