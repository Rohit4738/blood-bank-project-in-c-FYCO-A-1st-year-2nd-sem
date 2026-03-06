#include <stdio.h>
#include <string.h>

int main() {

    int choice;
    char name[50];
    char blood[5];
    int age;

    FILE *fp;

    while(1)
    {
        printf("\n--- Blood Bank Menu ---\n");
        printf("1. Add Donor\n");
        printf("2. View Donors\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nEnter Name: ");
            scanf("%s", name);

            printf("Enter Age: ");
            scanf("%d", &age);

            printf("Enter Blood Group: ");
            scanf("%s", blood);

            if(age >= 18)
                printf("Eligible to donate blood\n");
            else
                printf("Not eligible to donate blood\n");

            fp = fopen("bloodbank.txt", "a");

            fprintf(fp,"%s %d %s\n", name, age, blood);

            fclose(fp);

            printf("Donor saved successfully!\n");
        }

        else if(choice == 2)
        {
            fp = fopen("bloodbank.txt", "r");

            printf("\n--- Donor List ---\n");

            while(fscanf(fp,"%s %d %s", name, &age, blood) != EOF)
            {
                printf("Name: %s | Age: %d | Blood Group: %s\n", name, age, blood);
            }

            fclose(fp);
        }

        else if(choice == 3)
        {
            printf("Exiting program...\n");
            break;
        }

        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
