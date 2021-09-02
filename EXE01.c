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

    int opcao, i, j;

    for (i = 1; i <= 20;){
            printf("\nDigite uma opcao: \n");
            printf("1- Cadastrar um novo veiculo: \n");
            printf("2- Listar os veiculos cadastrados: \n");
            printf("3- Listar os veiculos filtrando-se por ano de fabricacao: \n");
            printf("4- Listar os veiculos com o ano de fabricacao acima de um certo valor especificado pelo usuário: \n");
            printf("5- Listar os veiculos filtrando-se pelo modelo: \n\n");

            scanf("%d", &opcao);

            switch(opcao){
                case 1:

                    fflush(stdin);
                    printf ("\n Marca:");
                    scanf ("%s", &cadastro[i].marca);
    
                    fflush(stdin);
                    printf ("\n Modelo:");
                    scanf ("%s", &cadastro[i].modelo);
    
                    fflush(stdin);
                    printf ("\n Placa: ");
                    scanf ("%s", &cadastro[i].placa);
    
                    fflush(stdin);
                    printf ("\n Ano: ");
                    scanf ("%d", &cadastro[i].ano);

                    fflush(stdin);
                    i++;
                    
                break;

                case 2:
                    for(j=1; j<=20; j++){
                        if(j < i){
                            printf("\n\nMarca: %s", &cadastro[j].marca);
                            printf("\nModelo: %s ano %d", &cadastro[j].modelo, cadastro[j].ano);
                            printf("\nPlaca: %s \n", &cadastro[j].placa);
                        }else{
                            j = 20;
                        }
                        break;
                    }
            }
    }
    
    

    return 0;
}