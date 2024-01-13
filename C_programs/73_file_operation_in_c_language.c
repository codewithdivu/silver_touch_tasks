#include <stdio.h>
#include <string.h>

int main()
{

    FILE *filePointer;

    char dataToBeWritten[50] = "Hello how are you?";

    filePointer = fopen("divyesh.txt", "w");

    if (filePointer == NULL)
    {
        printf("divyesh.txt file failed to open.");
    }
    else
    {

        printf("The file is now opened.\n");

        if (strlen(dataToBeWritten) > 0)
        {

            fputs(dataToBeWritten, filePointer);
            fputs("\n", filePointer);
        }

        fclose(filePointer);

        printf("Data successfully written in file "
               "divyesh.txt\n");
        printf("The file is now closed.");
    }

    return 0;
}
