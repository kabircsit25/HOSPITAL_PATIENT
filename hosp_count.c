#include<stdio.h>
struct hosp_count
{
    char name[20];
    int age;
    char address[50];
    char condition[100];
    char ward[20];
};
int main(){
    struct hosp_count hpp;
    int i, w1=0, w2=0, w3=0, w4=0, w5=0, w6=0, w7=0, w8=0, w9=0, w10=0, count=0;
    FILE *fp;
    fp=fopen("hospital.txt","r");
    if(fp==NULL)
    {
        printf("Error opening file!");
        return 1;
    }
    while(!feof)
    {
        fscanf(fp,"%s %d %s %s %s",hpp.name,&hpp.age,hpp.address,hpp.condition,hpp.ward);
        if(strcmp(hpp.ward,"")==0)
            w1++;
        else if(strcmp(hpp.ward,"Ward2")==0)
            w2++;
        else if(strcmp(hpp.ward,"Ward3")==0)
            w3++;
        else if(strcmp(hpp.ward,"Ward4")==0)
            w4++;
        else if(strcmp(hpp.ward,"Ward5")==0)
            w5++;
        else if(strcmp(hpp.ward,"Ward6")==0)
            w6++;
        else if(strcmp(hpp.ward,"Ward7")==0)
            w7++;
        else if(strcmp(hpp.ward,"Ward8")==0)
            w8++;
        else if(strcmp(hpp.ward,"Ward9")==0)
            w9++;
        else if(strcmp(hpp.ward,"Ward10")==0)
            w10++;
    }
    printf("Total number of patients: %d\n", count);
    fclose(fp);
    return 0;
}
