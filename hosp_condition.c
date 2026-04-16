#include<stdio.h>
#include<string.h>
struct hosp_write
{
    char name[20];
    int age;
    char address[50];
    char condition[100];
    char ward[20];
};
int main()
{
    int i;
    struct hosp_write hpp[24];
    FILE *fp;
    fp = fopen("hospital.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    printf("\nPatients with Critical Condition:\n\n");
    // Top border
    printf("+----------------+-----+----------------+----------------+---------------+\n");
    // Header
    printf("| %-14s | %-3s | %-14s | %-14s | %-13s |\n",
           "Name", "Age", "Address", "Condition", "Ward");
    // Separator
    printf("+----------------+-----+----------------+----------------+---------------+\n");
    for(i = 0; i < 24; i++)
    {
        if(fscanf(fp, "%s %d %s %s %s",
     hpp[i].name,
     &hpp[i].age,
      hpp[i].address,
      hpp[i].condition,
    hpp[i].ward) != 5)
        {
            break;
        }
        if(strcmp(hpp[i].condition, "Critical") == 0)
        {
            printf("| %-14s | %-3d | %-14s | %-14s | %-13s |\n",
                   hpp[i].name,
                   hpp[i].age,
                   hpp[i].address,
                   hpp[i].condition,
                   hpp[i].ward);
        }
    }
    // Bottom border
    printf("+----------------+-----+----------------+----------------+---------------+\n");
    fclose(fp);
    return 0;
}
