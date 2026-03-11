#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    char name[50];
    char blood[5];
    char contact[15];
    char expiry[15];
    int age;
    FILE *fp;

    while(1)
    {
        printf("\n--- Blood Bank Menu ---\n");
        printf("1. Add Donor\n");
        printf("2. View Donors\n");
        printf("3. View Total Blood Types\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nEnter Name: ");
            scanf("%s", name);
            printf("Enter Age: ");
            scanf("%d", &age);
            printf("Enter Blood Group (e.g. A+, O-): ");
            scanf("%s", blood);
            printf("Enter Contact Number: ");
            scanf("%s", contact);
            printf("Enter Blood Expiry Date (DD/MM/YYYY): ");
            scanf("%s", expiry);

            if(age >= 18)
                printf("Eligible to donate blood\n");
            else
                printf("Not eligible to donate blood\n");

            fp = fopen("bloodbank.txt", "a");
            fprintf(fp, "%s %d %s %s %s\n", name, age, blood, contact, expiry);
            fclose(fp);
            printf("Donor saved successfully!\n");
        }
        else if(choice == 2)
        {
            fp = fopen("bloodbank.txt", "r");
            if(fp == NULL)
            {
                printf("No donors found!\n");
                continue;
            }
            printf("\n--- Donor List ---\n");
            while(fscanf(fp, "%s %d %s %s %s", name, &age, blood, contact, expiry) != EOF)
            {
                printf("Name: %s | Age: %d | Blood Group: %s | Contact: %s | Expiry: %s\n",
                       name, age, blood, contact, expiry);
            }
            fclose(fp);
        }
        else if(choice == 3)
        {
            // Count each blood type
            int Apos=0, Aneg=0, Bpos=0, Bneg=0;
            int ABpos=0, ABneg=0, Opos=0, Oneg=0;

            fp = fopen("bloodbank.txt", "r");
            if(fp == NULL)
            {
                printf("No donors found!\n");
                continue;
            }

            while(fscanf(fp, "%s %d %s %s %s", name, &age, blood, contact, expiry) != EOF)
            {
                if(strcmp(blood, "A+") == 0)  Apos++;
                else if(strcmp(blood, "A-") == 0)  Aneg++;
                else if(strcmp(blood, "B+") == 0)  Bpos++;
                else if(strcmp(blood, "B-") == 0)  Bneg++;
                else if(strcmp(blood, "AB+") == 0) ABpos++;
                else if(strcmp(blood, "AB-") == 0) ABneg++;
                else if(strcmp(blood, "O+") == 0)  Opos++;
                else if(strcmp(blood, "O-") == 0)  Oneg++;
            }
            fclose(fp);

            printf("\n--- Total Blood Types Available ---\n");
            printf("A+  : %d\n", Apos);
            printf("A-  : %d\n", Aneg);
            printf("B+  : %d\n", Bpos);
            printf("B-  : %d\n", Bneg);
            printf("AB+ : %d\n", ABpos);
            printf("AB- : %d\n", ABneg);
            printf("O+  : %d\n", Opos);
            printf("O-  : %d\n", Oneg);
        }
        else if(choice == 4)
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
