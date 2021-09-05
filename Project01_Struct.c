#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Create a Struct that can stores:
    -Vehicle brand
    -Model + year
    -Plate(formto XXX-YYYY), where X are letters and Y are numbers
*/

struct Car {
        char brand[20];

        char model[20];
        
        char plate[20];
    
    int year;
};

    struct Car informations[20];

int main(){

    int option, i, l, y;
    char m[20];

    for(i = 0; i <=20;){

        printf("\n\nChoose an option: \n");
        printf("1- Register a new vehicle; \n");
        printf("2- List all vehicles; \n");
        printf("3- List all vehicles filtered by year of fabrication; \n");
        printf("4- List all vehicles above certain year; \n");
        printf("5- List all vehicles from the model; \n");
        printf("0- Exit. \n");

        printf("\nType:.... ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            
            printf("\n Brand:");
            scanf("%s", &informations[i].brand);

            printf("\n Model:");
            scanf("%s", &informations[i].model);

            printf("\n Plate:");
            scanf("%s", &informations[i].plate);

            printf("\n Year:");
            scanf("%d", &informations[i].year);

            i++;

            break;

        case 2:
            
            for (l = 0; l <=20; l++){

                if(l < i){

                    printf("\nBrand: %s", &informations[l].brand);
                    printf("\nModel: %s year %d", &informations[l].model, informations[l].year);
                    printf("\nPlate: %s\n", &informations[l].plate);


                }else{
                    l = 20;
                }

            }

            break;

        case 3:

            printf("Type the year:..... ");
            scanf("%d", &y);
            printf("\nThe models from year %d: \n", y);

            for (l = 0; l <=20; l++){

                if(l < i){

                    if(informations[l].year == y){
                        printf("\nBrand: %s", &informations[l].brand);
                        printf("\nModel: %s year %d", &informations[l].model, informations[l].year);
                        printf("\nPlate: %s\n", &informations[l].plate);
                    }

                }else{
                    printf("\nWe do not have vehicles from this year");
                    l = 20;
                }

            }

            break;

        case 4:
            
            printf("Model from year after:..... ");
            scanf("%d", &y);
            printf("\nThe model(s) from above the year %d: \n", y);

            for (l = 0; l <=20; l++){

                if(l < i){

                    if(informations[l].year > y){
                        printf("\nBrand: %s", &informations[l].brand);
                        printf("\nModel: %s year %d", &informations[l].model, informations[l].year);
                        printf("\nPlate: %s\n", &informations[l].plate);
                    }

                }else{
                    l = 20;
                }

            }

            break;

        case 5:
             
            printf("Type the model you want to consult:....");
            scanf("%s", m);
            printf("All vehicles from this model: %s\n", m);

            for (l = 0; l <=20; l++){

                if(l < i){

                    if(strcmp(&informations[l].model, m)==0){
                        printf("\nBrand: %s", &informations[l].brand);
                        printf("\nModel: %s year %d", &informations[l].model, informations[l].year);
                        printf("\nPlate: %s\n", &informations[l].plate);
                    }else{
                        printf("\nWe do not have vehicles from this model");
                    }

                }else{
                    l = 20;
                }

            }

            break;
        
        case 0: exit(0); //Ends the loop and returns 0;
            
            break;

        default:

            printf("Not a valid option, please type again");
            break;
        
        }

    }

    return 0;
}