#include <stdio.h>
#include <stdlib.h>
#include <string>

int main()
{
    string name,profession,;

    FILE *file;
    file = fopen("data.txt","w");
    if(file == NULL)
    {
        printf("File is Empty.");
        return 1;
    }
    fprintf(file,"NAME : ",name);
    fprintf(file,"Profession : ",reg);
    fprintf(file,"Age : ",age)
    fclose(file);

    file = fopen("data.txt","r");
    if(file==NULL)
    {
        printf("Empty File.");
        return 2;
    }
    char arr[100];
    if(fgets(arr,sizeof(arr),file))
    {
        printf("Read from data.txt : %s",arr);
    }
    fclose(file);


    return 0;
}
