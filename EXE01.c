#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Criar uma struct que armazena:
    -Marca do veículo
    -Modelo + ano de fabricação
    -Placa(formato XXX-YYYY), onde X denota letras e Y denota os números
*/

struct Carro {
        char marca[20];

        char modelo[20];
        
        char placa[20];
    
    int ano;
};

    struct Carro cadastro[20];

int main(){

    int opcao, i, l, y;
    char m[20];

    for(i = 0; i <=20;){

        printf("\n\nEscolha a sua opcao: \n");
        printf("1- Inserir um novo veiculo; \n");
        printf("2- Listar os veiculos cadastrados; \n");
        printf("3- Listar os veiculos filtrando-se por ano de fabricacao; \n");
        printf("4- Listar os veiculos com o ano de fabricacao acima de um certo valor especificado pelo usuario; \n");
        printf("5- Listar os veiculos filtrando-se pelo modelo; \n");
        printf("0- Sair. \n");

        printf("\nDigite:.... ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            
            printf("\n Marca:");
            scanf("%s", &cadastro[i].marca);

            printf("\n Modelo:");
            scanf("%s", &cadastro[i].modelo);

            printf("\n Placa:");
            scanf("%s", &cadastro[i].placa);

            printf("\n Ano:");
            scanf("%d", &cadastro[i].ano);

            i++;

            break;

        case 2:
            
            for (l = 0; l <=20; l++){

                if(l < i){

                    printf("\nMarca: %s", &cadastro[l].marca);
                    printf("\nModelo: %s ano %d", &cadastro[l].modelo, cadastro[l].ano);
                    printf("\nPlaca: %s\n", &cadastro[l].placa);

                }else{
                    l = 20;
                }

            }

            break;

        case 3:

            printf("Digite o ano:..... ");
            scanf("%d", &y);
            printf("\nOs modelos do ano de %d: \n", y);

            for (l = 0; l <=20; l++){

                if(l < i){

                    if(cadastro[l].ano == y){
                        printf("\nMarca: %s", &cadastro[l].marca);
                        printf("\nModelo: %s ano %d", &cadastro[l].modelo, cadastro[l].ano);
                        printf("\nPlaca: %s\n", &cadastro[l].placa);
                    }

                }else{
                    l = 20;
                }

            }

            break;

        case 4:
            
            printf("Modelos acima do ano:..... ");
            scanf("%d", &y);
            printf("\nOs modelo(s) listados acima de %d sao: \n", y);

            for (l = 1; l <=20; l++){

                if(l < i){

                    if(cadastro[l].ano > y){
                        printf("\nMarca: %s", &cadastro[l].marca);
                        printf("\nModelo: %s ano %d", &cadastro[l].modelo, cadastro[l].ano);
                        printf("\nPlaca: %s\n", &cadastro[l].placa);
                    }

                }else{
                    l = 20;
                }

            }

            break;

        case 5:
             
            printf("Digite o modelo que deseja consultar:....");
            scanf("%s", m);
            printf("Lista de veiculo(s) do modelo: %s\n", m);

            for (l = 1; l <=20; l++){

                if(l < i){

                    if(strcmp(&cadastro[l].modelo, m)==0){
                        printf("\nMarca: %s", &cadastro[l].marca);
                        printf("\nModelo: %s ano %d", &cadastro[l].modelo, cadastro[l].ano);
                        printf("\nPlaca: %s\n", &cadastro[l].placa);
                    }else{
                        printf("Nao possuimos esse modelo listado");
                    }

                }else{
                    l = 20;
                }

            }

            break;
        
        case 0: exit(0); //Finaliza o loop e retorna 0;
            
            break;

        default:

            printf("Digite uma opcao valida, por favor");
            break;
        
        }

    }


    return 0;
}