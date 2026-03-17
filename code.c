#include <stdio.h>

int main()
{
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
        printf("-------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nEnter Name: ");
            scanf("%s", name);
            printf("Enter Age: ");
            scanf("%d", &age);
            printf("Enter Blood Group (A+ A- B+ B- AB+ AB- O+ O-): ");
            scanf("%s", blood);
            printf("Enter Contact Number: ");
            scanf("%s", contact);
            printf("Enter Expiry Date (DD/MM/YYYY): ");
            scanf("%s", expiry);

            if(age >= 18)
                printf("Eligible to donate blood\n");
            else
                printf("Not eligible to donate blood\n");

            fp = fopen("bloodbank.txt", "a");
            fprintf(fp, "%s %d %s %s %s\n", name, age, blood, contact, expiry);
            fclose(fp);
            printf("Donor saved!\n");
        }

        else if(choice == 2)
        {
            fp = fopen("bloodbank.txt", "r");

            if(fp == NULL)
            {
                printf("No donors found!\n");
            }
            else
            {
                printf("\n--- Donor List ---\n");
                while(fscanf(fp, "%s %d %s %s %s", name, &age, blood, contact, expiry) != EOF)
                {
                    printf("Name: %s | Age: %d | Blood: %s | Contact: %s | Expiry: %s\n",
                           name, age, blood, contact, expiry);
                }
                fclose(fp);
            }
        }

        else if(choice == 3)
        {
            int Apos  = 0, Aneg  = 0;
            int Bpos  = 0, Bneg  = 0;
            int ABpos = 0, ABneg = 0;
            int Opos  = 0, Oneg  = 0;

            fp = fopen("bloodbank.txt", "r");

            if(fp == NULL)
            {
                printf("No donors found!\n");
            }
            else
            {
                while(fscanf(fp, "%s %d %s %s %s", name, &age, blood, contact, expiry) != EOF)
                {
                    // compare blood group one character at a time
                    if    (blood[0]=='A' && blood[1]=='+' && blood[2]=='\0') Apos++;
                    else if(blood[0]=='A' && blood[1]=='-' && blood[2]=='\0') Aneg++;
                    else if(blood[0]=='B' && blood[1]=='+' && blood[2]=='\0') Bpos++;
                    else if(blood[0]=='B' && blood[1]=='-' && blood[2]=='\0') Bneg++;
                    else if(blood[0]=='A' && blood[1]=='B' && blood[2]=='+')  ABpos++;
                    else if(blood[0]=='A' && blood[1]=='B' && blood[2]=='-')  ABneg++;
                    else if(blood[0]=='O' && blood[1]=='+' && blood[2]=='\0') Opos++;
                    else if(blood[0]=='O' && blood[1]=='-' && blood[2]=='\0') Oneg++;
                }
                fclose(fp);

                printf("\n--- Total Blood Types ---\n");
                printf("A+  : %d\n", Apos);
                printf("A-  : %d\n", Aneg);
                printf("B+  : %d\n", Bpos);
                printf("B-  : %d\n", Bneg);
                printf("AB+ : %d\n", ABpos);
                printf("AB- : %d\n", ABneg);
                printf("O+  : %d\n", Opos);
                printf("O-  : %d\n", Oneg);
            }
        }

        else if(choice == 4)
        {
            printf("Exiting...\n");
            break;
        }

        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
