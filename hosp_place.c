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

//Kathmandu patients by Arun -1

void displayKathmanduPatients()
{
    struct hosp_write hpp;
    FILE *fp;
    fp = fopen("hospital.txt", "r");
    int count = 0;
    char searchCity[20];
    printf("\nEnter city to filter: ");
    scanf("%s", searchCity);
    printf("\n\nPatients from %s:\n", searchCity);
    //printf("Name \t \t Age  \t Address\t Condition \t Ward\n");
    // Top border
    printf("+----------------+-----+----------------+----------------+---------------+\n");
    // Header
    printf("| %-14s | %-3s | %-14s | %-14s | %-13s |\n",
           "Name", "Age", "Address", "Condition", "Ward");
    // Separator
    printf("+----------------+-----+----------------+----------------+---------------+\n");
    rewind(fp);
    for(int i = 0; i < 24; i++)
    {
        if(fscanf(fp, "%s %d %s %s %s", hpp.name, &hpp.age, hpp.address, hpp.condition, hpp.ward) != 5)
            break; // Stop if reading fails
        if(strstr(hpp.address, searchCity) != NULL)
        {
            printf("%-14s   | %-3d | %-14s | %-14s | %-13s |\n", hpp.name, hpp.age, hpp.address, hpp.condition, hpp.ward);
            count++;
        }
    }
    printf("+----------------+-----+----------------+----------------+---------------+\n");
    if(count == 0)
        printf("No patients found from %s.\n", searchCity);
        printf("\nTotal patients from %s: %d\n", searchCity, count);
}
int main()

{

    FILE *fp;
    struct hosp_write hpp;
    //Path to the file is given as per the system, so it may be different for other system. So, change the path according to your system. For example, if you are using linux, then the path will be like this: fp = fopen("/home/user/HOSPITAL_PATIENT/output/hospital.txt", "r");

    //fp = fopen("C:/Users/hp/HOSPITAL_PATIENT/output/hospital.txt", "r");

    //path in main function is not required as the path is already given in the displayKathmanduPatients function. So, I have commented the path in main function and added the path in displayKathmanduPatients function. So, you can change the path in displayKathmanduPatients function according to your system.
    
    fp = fopen("hospital.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file!");
        return 1;
    }
    displayKathmanduPatients();
}

