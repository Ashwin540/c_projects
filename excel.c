#include <stdio.h>
#include <string.h>
#define MAX 50
#include<stdlib.h>

struct user {
    char username[MAX];
    char password[MAX];
};

void showVisaFree() {
    printf("\n--- VISA FREE COUNTRIES FOR INDIAN PASSPORT HOLDERS ---\n");
    printf("1.  Nepal\n");
    printf("2.  Bhutan\n");
    printf("3.  Maldives (90 days)\n");
    printf("4.  Mauritius (90 days)\n");
    printf("5.  Trinidad and Tobago (90 days)\n");
    printf("6.  Ecuador\n");
    printf("7.  Haiti\n");
    printf("8.  Micronesia\n");
    printf("9.  Cook Islands\n");
    printf("10. Vanuatu\n");
    printf("11. Jamaica\n");
    printf("12. Dominicia\n");
    printf("13. Tanzania\n");
    printf("14. Grenada\n");
    printf("15. Qatar\n");
    printf("16. Barbados\n");
    printf("17. Senegal\n");
}

void showVisaOnArrival() {
    printf("\n--- VISA ON ARRIVAL COUNTRIES FOR INDIAN PASSPORT HOLDERS ---\n");
    printf("1.  Thailand\n");
    printf("2.  Indonesia\n");
    printf("3.  Cambodia\n");
    printf("4.  Laos\n");
    printf("5.  Jordan\n");
    printf("6.  Tuvalu\n");
    printf("7.  Kenya\n");
    printf("8.  El Salvador\n");
    printf("9.  Mozambique\n");
    printf("10. Macao\n");
    printf("11. Laos\n");
    printf("12. Zambia\n");
    printf("13. Togo\n");
    printf("14. Zimbabwe\n");
    printf("15. Bolivia\n");
    printf("16. Comoros\n");
    printf("17. Samoa\n");
    printf("18. Saint Vincent and the grenadines\n");
    printf("19. Saint Kitts and Nevis\n");
}

void showEVisa() {
    printf("\n--- E-VISA COUNTRIES FOR INDIAN PASSPORT HOLDERS ---\n");
    printf("1.  Sri Lanka\n");
    printf("2.  Turkey\n");
    printf("3.  Kenya\n");
    printf("4.  Myanmar\n");
    printf("5.  Zambia\n");
    printf("6.  Azerbaijan\n");
    printf("7.  Oman\n");
    printf("8.  Malaysia\n");
    printf("9.  Indonesia\n");
    printf("10. Singapore\n");
    printf("11. Jordan\n");
    printf("12. Uzbekistan\n");
    printf("13. Russia\n");
    printf("14. New Zealand\n");
    printf("15. Madagascar\n");
    printf("16. Tajikistan\n");
    printf("17. Kyrgyzstan\n");
    printf("18. Ethiopia\n");
    printf("19. Kazakhstan\n");
    printf("20. Lesotho\n");
    printf("21. Djibouti\n");
    printf("22. Georgia\n");
    printf("23. Rwanda\n");
    printf("24. Ugand\n");
    printf("25. Colombia\n");
    printf("26. Benin\n");
    printf("27. Iran\n");
}


// Function to register a new user
int registeruser() {
    struct user ru;
    FILE *el = fopen("userdata.csv", "a");

    if (el == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    printf("------------- Registration ----------------\n\n");
    printf("\t\tUsername: ");
    scanf("%49s", ru.username);
    printf("\t\tPassword: ");
    scanf("%49s", ru.password);

    fprintf(el, "%s,%s\n", ru.username, ru.password); // Stores data in CSV format
    fclose(el);

    printf("\nUser registered successfully!\n");
    return 1;
}

// Function to authenticate login
int loginuser() {
    struct user ru, lu;
    char line[150];  // Buffer to read a line
    FILE *el = fopen("userdata.csv", "r");

    if (el == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    printf("--------------- Login ----------------\n\n");
    printf("\t\tUsername: ");
    scanf("%49s", lu.username);
    printf("\t\tPassword: ");
    scanf("%49s", lu.password);

    while (fgets(line, sizeof(line), el) != NULL) {
        // Read each line and parse username, password
        if (sscanf(line, "%49[^,],%49s", ru.username, ru.password) == 2) {
            if (strcmp(lu.username, ru.username) == 0 && strcmp(lu.password, ru.password) == 0) {
                fclose(el); // Close file early, no need to keep reading
                printf("\nWelcome, %s!\n", lu.username);

                int choice;
                do {
                    printf("\n======== TRAVEL GUIDE FOR INDIAN PASSPORT HOLDERS ========\n");
                    printf("1. Show VISA FREE Countries\n");
                    printf("2. Show VISA ON ARRIVAL Countries\n");
                    printf("3. Show E-VISA Countries\n");
                    printf("4. Logout\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            showVisaFree();
                            break;
                        case 2:
                            showVisaOnArrival();
                            break;
                        case 3:
                            showEVisa();
                            break;
                        case 4:
                            printf("Logging out...\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (choice != 4);

                return 1; // Successful login
            }
        }
    }

    printf("\nInvalid username or password.\n");
    fclose(el);
    return 0;
}


int main() {
    int ch;

    do {
        printf("\n1. Register\n2. Login\n3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                registeruser();
                break;
            case 2:
                loginuser();
                break;
            case 3:
                printf("Thank you!\n");
                break;
            default:
                printf("Choose a valid option from above.\n");
                break;
        }
    } while (ch != 3);

    return 0;
}
