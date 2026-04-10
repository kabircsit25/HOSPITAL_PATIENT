#include<stdio.h>
struct hosp_write
{
    char name[20];
    int age;
    char address[50];
    char condition[100];
    char ward[20];
};
int main(){
    struct hosp_write hpp;
    int i;
    FILE *fp;
    fp=fopen("hospital.txt","w");
    if(fp==NULL)
    {
        printf("Error opening file!");
        return 1;
    }
    printf("Enter the Details of 24 Patients:\n");
    printf("Name \t Age \t Address \t Condition \t Ward\n");
    for(i=1;i<=24;i++)
    {
        scanf("%s %d %s %s %s",hpp.name,&hpp.age,hpp.address,hpp.condition,hpp.ward);
        fprintf(fp,"%s\t%d\t%s\t%s\t%s\n",hpp.name,hpp.age,hpp.address,hpp.condition,hpp.ward);
    }
    fclose(fp);
    return 0;
}
