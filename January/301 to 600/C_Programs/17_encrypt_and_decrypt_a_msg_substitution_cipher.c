#include <stdio.h>
#include <string.h>

void encryptDecrypt(char *message, int key)
{
    for (int i = 0; i < strlen(message); ++i)
    {
        message[i] = message[i] + key;
    }
}

int main()
{
    char message[100];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter a key: ");
    scanf("%d", &key);

    encryptDecrypt(message, key);

    printf("Encrypted/Decrypted message: %s\n", message);

    return 0;
}
