#include <stdio.h>
#include <string.h>

struct patient {
    char name[20];
    int age;
    char address[50];
    char condition[100];
    char ward[20];
};

int main() {
    FILE *fp, *temp;
    struct patient hpp;
    char deleteName[20];

    fp = fopen("hospital.txt", "r");
    temp = fopen("temp.txt", "w");

    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    while (fscanf(fp, "%s %d %s %s %s", 
           hpp.name, &hpp.age, hpp.address, hpp.condition, hpp.ward) == 5) {

        if (strcmp(hpp.name, deleteName) != 0) {
            fprintf(temp, "%s %d %s %s %s\n", 
                    hpp.name, hpp.age, hpp.address, hpp.condition, hpp.ward);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("hospital.txt");      // delete old file
    rename("temp.txt", "hospital.txt"); // rename new file

    printf("Record deleted successfully.\n");

    return 0;
}