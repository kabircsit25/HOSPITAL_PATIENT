#include <stdio.h>
#include <string.h>

struct hosp_write {
    char name[20];
    int age;
    char address[50];
    char condition[100];
    char ward[20];
};

int main() {
    FILE *fp;
    struct hosp_write hpp;
    char searchCity[20];
    int count = 0;

    fp = fopen("hospital.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter city to search: ");
    scanf("%s", searchCity);

    printf("\nPatients from %s:\n\n", searchCity);

    // Top border
    printf("+----------------+-----+----------------+----------------+---------------+\n");

    // Header
    printf("| %-14s | %-3s | %-14s | %-14s | %-13s |\n",
           "Name", "Age", "Address", "Condition", "Ward");

    // Separator
    printf("+----------------+-----+----------------+----------------+---------------+\n");

    while (fscanf(fp, "%s %d %s %s %s",
                  hpp.name,
                  &hpp.age,
                  hpp.address,
                  hpp.condition,
                  hpp.ward) == 5) {

        if (strcmp(hpp.address, searchCity) == 0) {
            printf("| %-14s | %-3d | %-14s | %-14s | %-13s |\n",
                   hpp.name,
                   hpp.age,
                   hpp.address,
                   hpp.condition,
                   hpp.ward);

            count++;
        }
    }

    // Bottom border
    printf("+----------------+-----+----------------+----------------+---------------+\n");

    if (count == 0) {
        printf("\nNo patients found.\n");
    } else {
        printf("\nTotal patients found: %d\n", count);
    }

    fclose(fp);
    return 0;
}
