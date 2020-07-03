#include <stdio.h>

main(){

    FILE *arq;
    arq = fopen("dadosFuncionario.txt", "r");

    int i,j=0,flag = 0;
    char users[200], nome[100], senha[10];
    char login[100];

    while(fgets(users, 200, arq) != NULL){
        flag = 0;
        for(i = 0; i < sizeof(users); i++){

            if(users[i] == ','){
                i++;
                flag++;
                j=0;
            }
            if(flag == 0){
                login[j] = users[i];
                j++;
            }else if(flag == 1){
                nome[j] = users[i];
                j++;
            }
        }
        printf("Nome: %s\n", nome);
        printf("Registro: %s\n", login);
    }
}
