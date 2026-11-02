```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Function to check password strength
int checkStrength(char password[])
{
    int length = strlen(password);
    int upper = 0, lower = 0, digit = 0, special = 0;
    int i, score = 0;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (isupper((unsigned char)password[i]))
            upper = 1;
        else if (islower((unsigned char)password[i]))
            lower = 1;
        else if (isdigit((unsigned char)password[i]))
            digit = 1;
        else
            special = 1;
    }

    printf("\n========== PASSWORD ANALYSIS ==========\n");
    printf("Password Length: %d\n", length);
    printf("Uppercase Letters: %s\n", upper ? "Present" : "Missing");
    printf("Lowercase Letters: %s\n", lower ? "Present" : "Missing");
    printf("Numbers: %s\n", digit ? "Present" : "Missing");
    printf("Special Characters: %s\n", special ? "Present" : "Missing");

    // Calculate score
    if (length >= 8)
        score++;
    if (length >= 12)
        score++;
    if (upper)
        score++;
    if (lower)
        score++;
    if (digit)
        score++;
    if (special)
        score++;

    printf("\nPassword Strength: ");

    if (length < 8 || score <= 2)
    {
        printf("WEAK\n");
    }
    else if (score <= 4)
    {
        printf("MEDIUM\n");
    }
    else
    {
        printf("STRONG\n");
    }

    return score;
}

// Function to give suggestions
void giveSuggestions(char password[])
{
    int length = strlen(password);
    int upper = 0, lower = 0, digit = 0, special = 0;
    int i, suggestions = 0;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (isupper((unsigned char)password[i]))
            upper = 1;
        else if (islower((unsigned char)password[i]))
            lower = 1;
        else if (isdigit((unsigned char)password[i]))
            digit = 1;
        else
            special = 1;
    }

    printf("\n========== IMPROVEMENT TIPS ==========\n");

    if (length < 12)
    {
        printf("- Use a longer password, ideally 12 or more characters.\n");
        suggestions++;
    }

    if (!upper)
    {
        printf("- Consider including an uppercase letter.\n");
        suggestions++;
    }

    if (!lower)
    {
        printf("- Consider including a lowercase letter.\n");
        suggestions++;
    }

    if (!digit)
    {
        printf("- Consider including a number.\n");
        suggestions++;
    }

    if (!special)
    {
        printf("- Consider including a special character.\n");
        suggestions++;
    }

    if (suggestions == 0)
        printf("Good job! Your password meets all the checks.\n");

    printf("\nRemember: Avoid names, birthdays, and common passwords.\n");
}

// Main function
int main()
{
    char password[MAX];
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("      CYBERSAFE PASSWORD CHECKER\n");
        printf("====================================\n");
        printf("1. Check Password Strength\n");
        printf("2. Get Improvement Suggestions\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        getchar(); // Clear newline from input

        switch (choice)
        {
            case 1:
            {
                printf("\nEnter a password to analyze: ");

                if (fgets(password, MAX, stdin) == NULL)
                {
                    printf("Unable to read input.\n");
                    return 1;
                }

                password[strcspn(password, "\n")] = '\0';

                if (strlen(password) == 0)
                {
                    printf("Password cannot be empty.\n");
                    break;
                }

                checkStrength(password);
                break;
            }

            case 2:
            {
                printf("\nEnter a password for suggestions: ");

                if (fgets(password, MAX, stdin) == NULL)
                {
                    printf("Unable to read input.\n");
                    return 1;
                }

                password[strcspn(password, "\n")] = '\0';

                if (strlen(password) == 0)
                {
                    printf("Password cannot be empty.\n");
                    break;
                }

                giveSuggestions(password);
                break;
            }

            case 3:
                printf("\nThank you for using CyberSafe!\n");
                printf("Stay safe online!\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1, 2, or 3.\n");
        }

    } while (choice != 3);

    return 0;
}
```
