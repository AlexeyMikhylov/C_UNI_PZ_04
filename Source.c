#include <stdio.h>
#include <stdlib.h>

#define esc 27

int main()
{
    run_examples();
}

int run_examples(void)
{
    int example;

    printf("\nRunning examples\n0 for exit\n");
    printf("Input example number: "); scanf_s("%d", &example);

    switch (example)
    {
    case 0:
        printf("<exit>\n"); exit(1);
    case 10:
        example1(); run_examples();
    case 20:
        example2(); run_examples();
    case 30:
        example3(); run_examples();
    case 40:
        example4(); run_examples();
    case 50:
        example5(); run_examples();
    case 60:
        example6(); run_examples();
    case 1:
        ex1(); run_examples();
    case 2:
        ex2(); run_examples();
    case 3:
        ex3(); run_examples();
    case 4:
        ex4(); run_examples();
    default:
        printf("Incorrect input\n"); run_examples();
    }
}

int example1(void)
{
    FILE* fp; // Declaring a variable of the FILE type
    char name[] = "test1.txt";
    // Checking for an error when opening a stream:
    if ((fp = fopen(name, "w+")) == NULL)
    {
        printf("Could not open the file");
        (void)getchar();
        return 0;
    }
    // The file was opened successfully:
    printf("Managed to open the file");
    fprintf(fp, "Hello, World!");
    fclose(fp);

    (void)getchar();
    return 0;
}

int example2(void)
{
    FILE* fp;
    char buffer[128];
    char name[] = "test2.txt"; //if file not exists, creates file
    if ((fp = fopen(name, "w")) == NULL)
    {
        printf("Could not open the file");
        (void)getchar();
        return 0;
    }
    // The file was opened successfully:
    printf("Managed to open the file");
    fp = fopen(name, "w"); //open for w-write
    fprintf(fp, "Hello, World!"); //write (if file exists, overwrites)
    fclose(fp); //close

    // Reading from a file
    fp = fopen(name, "r"); //open for r-read
    fgets(buffer, 127, fp); // fgets(char *_Buffer, int_MaxCount, FILE *_Stream)
    fclose(fp); //close
    printf("\n%s", buffer); //output

    (void)getchar();
}

int example3(void)
{
    FILE* fp;
    char c;
    char name[] = "test3.txt";
    fp = fopen(name, "w");
    fprintf(stdout, "Enter any characters (Enter); q = exit!!!\n");

    do {
        c = getchar();
        fprintf(fp, "%c", c);
        fprintf(stdout, "%c", c);
        fflush(fp);
    } while (c != 'q');
    fclose(fp);

    (void)getchar();
}

int example4(void)
{
    FILE* input = NULL;
    char c;
    input = fopen("test4.txt", "rt");
    if (input == NULL)
    {
        printf("Error opening file");
        (void)getchar();
        exit(0);
    }
    while (fscanf(input, "%c", &c) == 1)
    {
        fprintf(stdout, "%c", c);
    }
    fclose(input);
    (void)getchar();
}

int example5(void)
{
    FILE *S1, *S2;
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);
    S1 = fopen("S1.txt", "w+t");
    fprintf(S1, "%d", x);
    fclose(S1);
    S1 = fopen("S1.txt", "r");
    S2 = fopen("S2.txt", "w");
    fscanf(S1,  
        "%d", &y);
    y += 3;
    fclose(S1);
    fprintf(S2, "%d\n", y);
    fclose(S2);
    return 0;
}

int example6(void)
{
    FILE* input = NULL;
    char c;
    input = fopen("test6.txt", "rt");
    if (input == NULL)
    {
        printf("Error opening file");
        (void)getchar();
        exit(0);
    }
    while (fscanf(input, "%c", &c) == 1)
    {
        fprintf(stdout, "%c", c);
    }
    fclose(input);
    (void)getchar();
}

//EXERCISEZ

int ex1(void)
{
    FILE* fp;
    FILE* fp_copy;
    int mode;
    char buffer[128];
    char name[] = "ex1.txt";
    char name_copy[] = "ex1.copy.txt";

    if ((fp = fopen(name, "w")) == NULL)
    {
        printf("Could not open the file");
        (void)getchar();
        return 0;
    }

    fp = fopen(name, "w");
    fprintf(fp, "111 222 333 444 555");
    fclose(fp);

    printf("modes:\n[1] - output\n[2] - copy file\n");
    printf("Select mode: "); scanf_s("%d", &mode);

    switch (mode)
    {
    case 1:
        fp = fopen(name, "r");

        fgets(buffer, 127, fp);
        printf("\n%s", buffer);

        fclose(fp);
        break;
    case 2:
        fp_copy = fopen(name_copy, "w");
        fp = fopen(name, "r");

        fgets(buffer, 127, fp);
        fprintf(fp_copy, "%s", buffer);

        fclose(fp, fp_copy);
        break;
    default:
        printf("incorrect input\n");
        break;
    }
}

int ex2(void)
{
    FILE* fp;
    char c;
    char name[] = "ex2.txt";
    fp = fopen(name, "w");

    fprintf(stdout, "Input characters\n[Enter] for input\n[Esc] for exit\n");

    do {
        c = getch();
        fprintf(fp, "%c", c);
        fprintf(stdout, "%c", c);
        fflush(fp);
    } while (c != esc);

    fclose(fp);

    //(void)getchar();
}

int ex3(void)
{
    FILE* file;
    char name[] = "ex3.txt";
    int i = 0, temp = 0;

    file = fopen(name, "w");
    fprintf(file, "111 222 555 333 444");
    fclose(file);

    file = fopen("ex3.txt", "r");

    while (!feof(file))
    {
        fscanf(file, "%d", &i);
        //printf("%d \n", i);

        if (i > temp) {
            temp = i;
        }
    }
    fclose(file);

    printf("Max is %d", temp);

    (void)getchar();
}

int ex4(void)
{
    FILE* file4;
    char c, name[] = "ex4.txt";
    int count = 0;

    file4 = fopen(name, "w");
    fprintf(file4, "abc\ndef\nghj\nklm\nnop\nasasas\n");
    fclose(file4);

    file4 = fopen(name, "r");

    for (c = getc(file4); c != EOF; c = getc(file4)) {
        if (c == '\n') {
            count = count + 1;
        }
    }

    fclose(file4);
    printf("The file %s has %d lines\n ", name, count);
}