#include <stdio.h>
#include <string.h>

void addDonor();
void viewDonor();
void deleteDonor();
void editDonor();

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Blood Bank Menu ---\n");
        printf("1. Add Donor\n");
        printf("2. View Donors\n");
        printf("3. Edit Donor\n");
        printf("4. Delete Donor\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addDonor();
                break;

            case 2:
                viewDonor();
                break;

            case 3:
                editDonor();
                break;

            case 4:
                deleteDonor();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addDonor()
{
    char name[50];
    char blood[5];
    int age;

    FILE *fp;

    printf("\nEnter Name (use _ instead of space): ");
    scanf("%s",name);

    printf("Enter Age: ");
    scanf("%d",&age);

    printf("Enter Blood Group: ");
    scanf("%s",blood);

    if(age >= 18)
        printf("Eligible to donate blood\n");
    else
        printf("Not eligible to donate blood\n");

    fp = fopen("bloodbank.txt","a");

    fprintf(fp,"%s %d %s\n",name,age,blood);

    fclose(fp);

    printf("Donor saved successfully!\n");
}

void viewDonor()
{
    char name[50];
    char blood[5];
    int age;

    FILE *fp;

    fp = fopen("bloodbank.txt","r");

    if(fp == NULL)
    {
        printf("No donor records found.\n");
        return;
    }

    printf("\n--- Donor List ---\n");

    while(fscanf(fp,"%s %d %s",name,&age,blood) != EOF)
    {
        printf("Name: %s | Age: %d | Blood Group: %s\n",name,age,blood);
    }

    fclose(fp);
}

void deleteDonor()
{
    char deleteName[50];
    char name[50];
    char blood[5];
    int age;

    FILE *fp,*temp;

    printf("Enter donor name to delete: ");
    scanf("%s",deleteName);

    fp = fopen("bloodbank.txt","r");
    temp = fopen("temp.txt","w");

    while(fscanf(fp,"%s %d %s",name,&age,blood) != EOF)
    {
        if(strcmp(name,deleteName) != 0)
        {
            fprintf(temp,"%s %d %s\n",name,age,blood);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("bloodbank.txt");
    rename("temp.txt","bloodbank.txt");

    printf("Donor deleted successfully!\n");
}

void editDonor()
{
    char editName[50];
    char name[50];
    char blood[5];
    int age;

    FILE *fp,*temp;

    printf("Enter donor name to edit: ");
    scanf("%s",editName);

    fp = fopen("bloodbank.txt","r");
    temp = fopen("temp.txt","w");

    while(fscanf(fp,"%s %d %s",name,&age,blood) != EOF)
    {
        if(strcmp(name,editName) == 0)
        {
            printf("Enter new age: ");
            scanf("%d",&age);

            printf("Enter new blood group: ");
            scanf("%s",blood);
        }

        fprintf(temp,"%s %d %s\n",name,age,blood);
    }

    fclose(fp);
    fclose(temp);

    remove("bloodbank.txt");
    rename("temp.txt","bloodbank.txt");

    printf("Donor updated successfully!\n");
}
