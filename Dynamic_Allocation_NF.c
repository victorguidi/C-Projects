#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct clients{
    char name[30];
    int year;
    float ammount;
};

int main(){

    struct clients *clt;
    int option, n, d=0, v=0;
    float a;
    char name[30];
    char name1[30];

    printf("Welcome, Choose an option to begin:");

    do
    {
        printf("\n1 - Create a new list(This also overwrite any previous list);\n");
        printf("2 - Find a person in the list;\n");
        printf("3 - Delete a person from the list.\n");
        printf("4 - Find the highest ammount.\n");
        printf("5 - Add a new register to the list.\n");
        printf("6 - Search based on the ammount.\n");
        printf("0 - End the program.\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:

            printf("\nType how many clients you want to register:");
            scanf("%d", &n);

            // allocating memory for n numbers of struct person
            clt = (struct clients*) malloc(n * sizeof(struct clients));

            for (int i=0; i < n; i++)
            {
            printf("Type the name and the birth year:");
            // To access members of 1st struct person,
            scanf("%s %d", (clt+i)->name, &(clt+i)->year);

            printf("\nType the ammount:");
            scanf("%f", &(clt+i)->ammount);
            }

        break;

        case 2:

            printf("Type the name you want to find:");
            scanf("%s", name);

            for(int i = 0; i < n; i++){

            if (strcmp(&clt[i].name, name)==0)
            {
                printf("\nThats the name:");

                printf("\nName: %s\n", (clt+i)->name);
                printf("Birth Year: %d\n", (clt+i)->year);
                printf("Ammount: %.2f\n", (clt+i)->ammount);
                d++;
            }
            }

        if(d == 0)
            printf("This name doesn't exist\n");
        break;

        case 3:

            printf("Type the name you want to delete:");
            scanf("%s", name1);

            for(int i = 0; i < n; i++) {

                if (strcmp(&clt[i].name, name1)==0)
                {
                    printf("\nThats the name:");

                    printf("\nName: %s\n", (clt+i)->name);
                    printf("Birth Year: %d\n", (clt+i)->year);
                    printf("Ammount: %.2f\n", (clt+i)->ammount);
                    d++; //Sentinel value?
                }

                if ( 1 == d && i+1 != n ) // if the sentinel is set, but we're not off the end of the list yet
                {
                    memcpy(clt+i, clt+i+1, sizeof( struct clients )); 
                }
            }

            n--; // reduce the list length
        break;

        case 4:

            for(int c = 0; c < n; c++){
                if(&(clt+c)->ammount > &(clt+v)->ammount)
                    v = c;
            }

            printf("\nName: %s\n", (clt+v)->name);
            printf("Birth Year: %d\n", (clt+v)->year);
            printf("The highest ammount is: %.2f \n", clt[v].ammount);

        break;

        case 5:

            n++;
            (struct clients*) realloc(clt, sizeof(struct clients) * n);

            printf("Type the name and the birth year:");
            scanf("%s %d", (clt+n-1)->name, &(clt+n-1)->year);

            printf("\nType the ammount:");
            scanf("%f", &(clt+n-1)->ammount);
            
        break;

        case 6:

            printf("Ammount above value: ");
            scanf("%f", &a);

            printf("\nResult(s):");

            for(int i = 0; i < n; i++){

                if (clt[i].ammount > a)
                {

                    printf("\nName: %s\n", (clt+i)->name);
                    printf("Birth Year: %d\n", (clt+i)->year);
                    printf("Ammount: %.2f\n", (clt+i)->ammount);
                
                }
            }

        break;

        }

    } while (option != 0);
    
    return 0;
}
