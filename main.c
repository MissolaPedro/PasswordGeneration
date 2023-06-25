#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void shuffle(char *array, int size)
{
    srand(time(NULL));

    for (int i = size - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);

        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void generateMixed(char *vector1, char *vector2, char *vector3, int size, char *password)
{
    strcat(password, vector1);
    strcat(password, vector2);
    strcat(password, vector3);

    shuffle(password, size);
}

void generateLetters(int size, char *password)
{
    char letters[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    srand(time(NULL));

    for (int i = 0; i < size; ++i)
    {
        int randomIndex = rand() % 52;
        password[i] = letters[randomIndex];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (password[i] == password[i + 1] - 1)
            {
                password[i + 1] = '0' + rand() % 52;
            }
        }
    }

    password[size] = '\0';
}

void generateNumbers(int size, char *password)
{
    for (int i = 0; i < size; ++i)
    {
        password[i] = '0' + rand() % 10;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (password[i] == password[i + 1] - 1)
            {
                password[i + 1] = '0' + rand() % 10;
            }
        }
    }

    password[size] = '\0';
}

void generateSymbols(int size, char *password)
{
    char symbols[28] = {'!', '@', '#', '$', '%', '&', '*', '(', ')', '-', '+', '=', '_', '`', '[', ']', '{', '}', '<', '>', '|', ',', '.', ':', ';', '^', '~', '?'};

    srand(time(NULL));

    for (int i = 0; i < size; ++i)
    {
        int randomIndex = rand() % 28;
        password[i] = symbols[randomIndex];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (password[i] == password[i + 1] - 1)
            {
                password[i + 1] = '0' + rand() % 28;
            }
        }
    }

    password[size] = '\0';
}

void generateLettersNoRepeat(int size, char *password)
{
    char letters[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    srand(time(NULL));

    char used[52] = {0};

    for (int i = 0; i < size; ++i)
    {
        int randomIndex = rand() % 52;

        while (used[randomIndex] == 1)
        {
            randomIndex = rand() % 52;
        }

        used[randomIndex] = 1;
        password[i] = letters[randomIndex];
    }

    password[size] = '\0';
}

void generateNumbersNoRepeat(int size, char *password)
{
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    srand(time(NULL));

    int used[10] = {0};

    for (int i = 0; i < size; ++i)
    {
        int randomIndex = rand() % 10;

        while (used[randomIndex] == 1)
        {
            randomIndex = rand() % 10;
        }

        used[randomIndex] = 1;
        password[i] = numbers[randomIndex];
    }

    password[size] = '\0';
}

void generateSymbolsNoRepeat(int size, char *password)
{
    char symbols[] = {'!', '@', '#', '$', '%', '&', '*', '+', '-', '='};

    srand(time(NULL));

    int used[10] = {0};

    for (int i = 0; i < size; ++i)
    {
        int randomIndex = rand() % 10;

        while (used[randomIndex] == 1)
        {
            randomIndex = rand() % 10;
        }

        used[randomIndex] = 1;
        password[i] = symbols[randomIndex];
    }

    password[size] = '\0';
}

void generatePassword(int size, int option, char *password, int option_unique)
{
    switch (option)
    {
    case 1:
        if (option_unique == 1)
        {
            generateLettersNoRepeat(size, password);
        }
        else if (option_unique == 2)
        {
            generateLetters(size, password);
        }

        break;
    case 2:
        if (option_unique == 1)
        {
            generateNumbersNoRepeat(size, password);
        }
        else if (option_unique == 2)
        {
            generateNumbers(size, password);
        }
        break;
    case 3:
        if (option_unique == 1)
        {
            generateSymbolsNoRepeat(size, password);
        }
        else if (option_unique == 2)
        {
            generateSymbols(size, password);
        }

        break;
    case 4:
    {
        char *vector1 = (char *)malloc(size * sizeof(char));
        char *vector2 = (char *)malloc(size * sizeof(char));
        char *vector3 = (char *)malloc(size * sizeof(char));

        int division = size / 3;
        int remainder = size % 3;

        generateLetters(division, vector1);
        generateNumbers(division, vector2);
        generateSymbols(division + remainder, vector3);

        generateMixed(vector1, vector2, vector3, size, password);

        free(vector1);
        free(vector2);
        free(vector3);

        break;
    }
    default:
        printf("\nDigite uma opção válida.\n");
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE *planilha = fopen("senhas.csv", "w");
    fprintf(planilha, "Senhas");
    fclose(planilha);

    while (true)
    {
        printf("Gerador de senhas\n");

        int option;
        printf("\nComo deseja que seja gerada a senha?\n");
        printf("1 - Letras\n");
        printf("2 - Números\n");
        printf("3 - Símbolos\n");
        printf("4 - Misto\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        while (true)
        {
            if (option < 1 || option > 5)
            {
                printf("\nOpção invalida");
                printf("\nSelecione outra opção: ");
                scanf("%i", &option);
            }

            if (option >= 1 && option <= 5)
            {
                break;
            }
        }

        if (option == 5)
        {
            printf("\nEncerrando o programa.\n");
            exit(0);
        }

        int option_unique;
        printf("\nDeseja gerar uma senha sem repetições?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n");
        printf("Opção: ");
        scanf("%d", &option_unique);

        while (true)
        {
            if (option_unique < 1 || option_unique > 2)
            {
                printf("\nOpção invalida");
                printf("\nSelecione outra opção: ");
                scanf("%i", &option_unique);
            }

            if (option >= 1 && option <= 5)
            {
                break;
            }
        }

        if (option_unique == 1)
        {
            printf("\nNumero maximo de caracteres permitidos é 8");
        }

        int size;
        printf("\nInforme quantos caracteres deseja para a senha: ");
        scanf("%d", &size);

        if (option_unique == 1 && size > 8)
        {
            printf("\nNumero de carecters excedido");
            printf("\nRedefinindo o tamanho da senha para 8");
            size = 8;
        }

        char password[size + 1];
        memset(password, 0, sizeof(password));

        FILE *senhaFile = fopen("senhas.csv", "a");
        generatePassword(size, option, password, option_unique);
        printf("\nSenha gerada: %s\n\n\n", password);
        fprintf(senhaFile, "\n%s", password);
        fclose(senhaFile);
    }

    return 0;
}