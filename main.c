#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int opcao = 1, y = 0, a = -1, b = -1, c = -1;

carregamento(){

    int i, j;

    printf("\n\n\n\n\t\t\tCarregando  Sistema de Estoque\n\n\t\t\t");
    for(i = 0; i < 10; i++){
        for(j = 0; j < 3; j++){
            printf("%c", 219);
            Sleep(90);
        }
    }
}

voltar_menu(){
    system("cls");
    printf("\n\n\t       Digite: 0 para finalizar o programa \n\t\t\t     ou \n\t\tQualquer Botão P/ Voltar ao Menu \n\n\n\t  root@Escolha>>> ");
    scanf("%i", &opcao);

    if(opcao == 0){
        printf("\n\t");
        return 0;
    }
}

opcao_invalida(){
    system("cls");
    printf("\n\n\t       Digite: 1. Tentar Novamente \n\t\t\t     ou \n\tQualquer Botão Diferente de 1 p/ Voltar ao Menu \n\n\n\t  root@Escolha>>> ");
    scanf("%i", &opcao);
    return 0;
}

pesquisa(char argumento[100]){

    FILE *arq;
    arq = fopen("dadosProdutos.txt", "r");

    char valor[200], nome[100] = " ", cor[100] = " ", valorPr[100] = " ", ano[100] = " ";
    char nome_p[100] = " ", cor_p[100] = " ", valor_p[100] = " ", ano_p[100] = " ";
    int x, i = 0, j = 0, flag = 0, a, b = 0, cont = 1;
    system("cls");
    while(fgets(valor, 200, arq) != NULL){
        flag = 0;
        for(x = 0; x <= sizeof(valor); x++){
            if(valor[x] == ','){
                flag++;
                x++;
                j=0;
            }
            if(flag == 0){
                nome[j] = valor[x];
                j++;
            }
            if(flag == 1){
                ano[j] = valor[x];
                j++;
            }
            if(flag == 3){
                cor[j] = valor[x];
                j++;
            }
            if(flag == 4){
                valorPr[j] = valor[x];
                j++;
            }
        }

        a = strlen(argumento);

        for(x = 0; x <= a+5; x++){
            nome_p[x] = nome[x];
            nome[x] = 0;

            ano_p[x] = ano[x];
            ano[x] = 0;

            cor_p[x] = cor[x];
            cor[x] = 0;

            valor_p[x] = valorPr[x];
            valorPr[x] = 0;
        };

        printf("\n\t\tProduto: %i", cont++);
        if(strcmp(argumento, cor_p) == 0){
            printf("\n\t\tNome: %s\n", nome_p);
            printf("\t\tAno: %s\n", ano_p);
            printf("\t\tCor: %s\n", cor_p);
            printf("\t\tValor: %s\n", valor_p);
        }
        if(strcmp(argumento, ano_p) == 0){
            printf("\n\t\tNome: %s\n", nome_p);
            printf("\t\tAno: %s\n", ano_p);
            printf("\t\tCor: %s\n", cor_p);
            printf("\t\tValor: %s\n", valor_p);
        }
        if(strcmp(argumento, valor_p) == 0){
            printf("\n\t\tNome: %s\n", nome_p);
            printf("\t\tAno: %s\n", ano_p);
            printf("\t\tCor: %s\n", cor_p);
            printf("\t\tValor: %s\n", valor_p);
        }
        if(strcmp(argumento,"tudo")==0){
            printf("\n\t\tNome: %s\n", nome_p);
            printf("\t\tAno: %s\n", ano_p);
            printf("\t\tCor: %s\n", cor_p);
            printf("\t\tValor: %s\n", valor_p);
        };
    }
    fclose(arq);
    printf("\n");
    system("pause");
}


menu_pesquisa(){
    char argumento[100], tudo[10] = "tudo";
    int argVal;

    do{
        system("cls");
        printf("\n\t\t--------------------------------------\n\t\t|         OPÇÕES DE PESQUISA\t     |\n\t\t|------------------------------------|\n\t\t|\t\t\t\t     |\n\t\t|\t\t\t\t     |\n\t\t| 1. Pesquisa por Modelo; \t     |\n\t\t| 2. Exibir todos os Produtos; \t     |\n\t\t| 3. Pesquisa por Cor;\t\t     |\n\t\t| 4. Pesquisa por Valor;\t     |\n\t\t|\t\t\t\t     |\n\t\t| 5. Voltar;\t\t\t     |\n\t\t|\t\t\t\t     |\n\t\t|------------------------------------|\n\t\t|\t\t\t\t     |\n\t\t--------------------------------------\n\n\t\troot@Escolha>>> ");
        scanf("%i", &opcao);

        if(opcao == 1){
            printf("\n\t\tDigite o modelo: ");
            fflush(stdin);
            gets(argumento);
            pesquisa(argumento);
        }else if(opcao == 2){
            pesquisa(tudo);
        }else if(opcao == 3){
            printf("\n\t\tDigite a cor: ");
            fflush(stdin);
            gets(argumento);
            pesquisa(argumento);
        }else if(opcao == 4){
            printf("Digite o valor: ");
            fflush(stdin);
            gets(argumento);
            pesquisa(argumento);
        }else if(opcao == 5){
            printf("\n\t");
        }else{
            system("cls");
            printf("\n\n\t\t   -----------  INFORMAÇÃO INVÁLIDA!  -----------\n\n\t\t    ");
            system("pause");
            system("cls");
            fflush(stdin);
        }
    }while(opcao != 5);
}

struct dadosProdutos{

    int registro, ano;
    char nome[100], cor[20], modelo[50], valor[10];

}produtos;

Pesquisa_Associado(char nome_Associado[100]){

    FILE *arq;
    arq = fopen("dadosCadastrados.txt", "r");
    system("cls");
    printf("\n\t\t---------------------------------\n\t\t|\t     DADOS   \t\t|\n\t\t---------------------------------\n");
    char user[300], nome[100], idade[100] = " ", endereco[100], login[100], telefone[100], registro[100];
    char nome_A[100] = " ", idade_A[100] = " ", login_A[50] = " ", endereco_A[10] = " ", telefone_A[100], registro_A[100] = " ";
    int x, i = 0, j = 0, flag = 0, a, b = 0, cont = 1;
    while(fgets(user, 300, arq) != NULL){
        flag = 0;
        for(x = 0; x <= sizeof(user); x++){
            if(user[x] == ','){
                flag++;
                x++;
                j=0;
            }
            if(flag == 0){
                registro[j] = user[x];
                j++;
            }
            if(flag == 1){
                nome[j] = user[x];
                j++;
            }
            if(flag == 2){
                idade[j] = user[x];
                j++;
            }
            if(flag == 3){
                endereco[j] = user[x];
                j++;
            }
            if(flag == 4){
                telefone[j] = user[x];
                j++;
            }
            if(flag == 5){
                login[j] = user[x];
                j++;
            }
        }

        a = strlen(nome_Associado);

        for(x = -1; x <= a; x++){
            nome_A[x] = nome[x];
            nome[x] = 0;

            registro_A[x] = registro[x];
            registro[x] = 0;

            idade_A[x] = idade[x];
            idade[x] = 0;

            endereco_A[x] = endereco[x];
            endereco[x] = 0;

            login_A[x] = login[x];
            login[x] = 0;

            telefone_A[x] = telefone[x];
            telefone[x] = 0;

        };

        if(strcmp(nome_A, nome_Associado) == 0){
            printf("\n\n\t\tNome: %s.",nome_A);
            printf("\n\t\tRegistro: %i", atoi(registro_A));
            printf("\n\t\tIdade: %s", idade_A);
            printf("\n\t\tEndereço: %s", endereco_A);
            printf("\n\t\tTelefone %s\n", telefone_A);
        }
    }
    fclose(arq);
    printf("\n");
    system("pause");
}

Incluir_Produto(){
    a++;
    system("cls");

    FILE *arq;
    arq = fopen("dadosProdutos.txt", "a+");

    printf("\n\t\t---------------------------------\n\t\t|\t     CADASTRO   \t|\n\t\t|   \t\tDE\t\t|\n\t\t|\t     PRODUTOS\t\t|\n\t\t---------------------------------\n");

    printf("\n\n\t\tNome do Carro>> ");
    fflush(stdin);
    gets(produtos.nome);

    printf("\n\t\tAno>> ");
    fflush(stdin);
    scanf("%i", &produtos.ano);

    printf("\n\t\tModelo>> ");
    fflush(stdin);
    gets(produtos.modelo);

    printf("\n\t\tCor do Carro>> ");
    fflush(stdin);
    gets(produtos.cor);

    printf("\n\t\tValor do Carro>> ");
    scanf("%s", &produtos.valor);

    printf("\n\n\t Deseja Cadastrar um novo Produto 1. Sim ou 2. Não>>> ");
    scanf("%i", &y);

    fprintf(arq, " %s ,", produtos.nome, 1);
    fprintf(arq, " %i,", produtos.ano, 1);
    fprintf(arq, " %s ,", produtos.modelo, 1);
    fprintf(arq, "%s,", produtos.cor, 1);
    fprintf(arq, "%s,\n", produtos.valor, 1);

    fclose(arq);
    if(y == 1){
        Incluir_Produto();
    }else if(y == 2){
        printf("\n\t");
    }else{
        system("cls");
        printf("\n\n\t\t      INFORMAÇÃO INVÁLIDA!\n\t    -----------------------------------");
        voltar_menu();
    }
}

menu_Proprietario(char root[100]){
    do{
        setlocale(LC_ALL, "Portuguese");
        system("cls");
        printf("\n\t\t--------------------------------------\n\t\t|  SISTEMA DE ESTOQUE DE AUTOMÓVEIS  |\n\t\t|\t\t  DO\t\t     |     \n\t\t|\t     PROPRIETÁRIO\t     |\n\t\t|------------------------------------|\n\t\t|\t\t\t\t     |\n\t\t|\t\t\t\t     |\n\t\t| 1. Incluir novo Produto; \t     |\n\t\t| 2. Excluir Produto; \t\t     |\n\t\t| 3. Pesquisar Funcionário; \t     |\n\t\t| 4. Pesquisar Produto; \t     | \n\t\t| 5. Pesquisar Cliente; \t     |\n\t\t| 6. Sair;\t\t\t     |\n\t\t|\t\t\t\t     |\n\t\t|------------------------------------|\n\t\t|\t\t\t\t     |\n\t\t--------------------------------------\n\n\t\t%s@Escolha>>> ", root);
        scanf("%i", &opcao);
        char associado[100];
        if(opcao == 1){
            Incluir_Produto();
        }else if(opcao == 2){
            /*Excluir Produto*/
        }else if(opcao == 3){
            printf("\n\t\tDigite o nome do Associado: ");
            fflush(stdin);
            gets(associado);
            Pesquisa_Associado(associado);
        }else if(opcao == 4){
            menu_pesquisa();
        }else if(opcao == 5){
            printf("\n\t\tDigite o nome do Associado: ");
            fflush(stdin);
            gets(associado);
            Pesquisa_Associado(associado);
        }else if(opcao == 6){
            printf("\n\t");
        }
    }while(opcao != 6);
}

menu_Funcionario(char root[100]){
    do{
        system("cls");
        printf("\n\n\t       SISTEMA DE ESTOQUE DE AUTOMÓVEIS \n\t\t\t    DOS \n\t\t       FUNCIONARIOS\n\t   ------------------------------------\n\n\t1. Pesquisar por Produto; \n\t2. Pesquisar por clientes; \n\t3. Realizar compra; \n\t4. Sair;\n\n\t%s@Escolha>>> ", root);
        scanf("%i", &opcao);
        char associado[100];
        if(opcao == 1){
            menu_pesquisa();
        }else if(opcao == 2){
            printf("\n\t\tDigite o nome do Associado: ");
            fflush(stdin);
            gets(associado);
            Pesquisa_Associado(associado);
        }else if(opcao == 3){
            /*Realizar compra*/
        }else if(opcao == 4){
            printf("\n\t");
        }else{
            system("cls");
            printf("\n\n\t\t   -----------  INFORMAÇÃO INVÁLIDA!  -----------\n\n\t\t    ");
            system("pause");
            system("cls");
            fflush(stdin);
        }
    }while(opcao != 4);
}

menu_Gerente(char root[100]){
    do{
        system("cls");
        printf("\n\t\t--------------------------------------\n\t\t|  SISTEMA DE ESTOQUE DE AUTOMÓVEIS  |\n\t\t|\t\t  DOS\t\t     |     \n\t\t|\t       GERENTES\t\t     |\n\t\t|------------------------------------|\n\t\t|\t\t\t\t     |\n\t\t|\t\t\t\t     |\n\t\t| 1. Incluir novo Produto; \t     |\n\t\t| 2. Pesquisar por funcionário(a);   |\n\t\t| 3. Pesquisar por Clientes; \t     |\n\t\t| 4. Pesquisar por Produto; \t     | \n\t\t|\t\t\t\t     |\n\t\t| 5. Sair;\t\t\t     |\n\t\t|\t\t\t\t     |\n\t\t|------------------------------------|\n\t\t|\t\t\t\t     |\n\t\t--------------------------------------\n\n\t\t%s@Escolha>>> ", root);
        scanf("%i", &opcao);
        char associado[100];
        if(opcao == 1){
            Incluir_Produto();
        }else if(opcao == 2){
            printf("\n\t\tDigite o nome do Associado: ");
            fflush(stdin);
            gets(associado);
            Pesquisa_Associado(associado);
        }else if(opcao == 3){
            printf("\n\t\tDigite o nome do Associado: ");
            fflush(stdin);
            gets(associado);
            Pesquisa_Associado(associado);
        }else if(opcao == 4){
            menu_pesquisa();
        }else if(opcao == 5){
            printf("\n\t");
        }
    }while(opcao != 5);
}

menu_Cliente(char root[100]){
    setlocale(LC_ALL, "Portuguese");
    do{
        opcao = 0;
        system("cls");
        printf("\n\t\t--------------------------------------\n\t\t|  SISTEMA DE ESTOQUE DE AUTOMÓVEIS  |\n\t\t|\t\t  DOS\t\t     |     \n\t\t|\t       CLIENTES\t\t     |\n\t\t|------------------------------------|\n\t\t|\t\t\t\t     |\n\t\t|\t\t\t\t     |\n\t\t| 1. Pesquisar por Produto; \t     |\n\t\t| 2. Sair; \t\t\t     |\n\t\t|\t\t\t\t     |\n\t\t|------------------------------------|\n\t\t|\t\t\t\t     |\n\t\t--------------------------------------\n\n\t\t%s@Escolha>>>  ", root);
        scanf("%i", &opcao);

        if(opcao == 1){
            menu_pesquisa();
        }else if(opcao == 2){
            printf("\n\t");
        }else{
            system("cls");
            printf("\n\n\t\t   -----------  INFORMAÇÃO INVÁLIDA!  -----------\n\n\t\t    ");
            system("pause");
            system("cls");
            fflush(stdin);
        }
    }while(opcao != 2);
}


struct fichadado_cliente{

    char nome[100], login[100], endereco[100], senha[100], telefone[100], cpf[100], rg[100];
    int idade, registro;

}cliente;

Cadastro_Cliente(){
    b++;

    cliente;
    FILE *arq;
    arq = fopen("dadosCadastrados.txt", "a+");

    system("cls");

    printf("\n\t\t---------------------------------\n\t\t|\t     CADASTRO   \t|\n\t\t|   \t\tDE\t\t|\n\t\t|\t     CLIENTES\t\t|\n\t\t---------------------------------\n");
    printf("\n\n\t\tNome>>> ");
    fflush(stdin);
    gets(cliente.nome);

    printf("\n\t\tIdade>>> ");
    scanf("%i", &cliente.idade);

    printf("\n\t\tEndereco>>> ");
    fflush(stdin);
    gets(cliente.endereco);

    printf("\n\t\tTelefone>>> ");
    fflush(stdin);
    gets(cliente.telefone);

    printf("\n\t\tSenha>>> ");
    fflush(stdin);
    gets(cliente.senha);

    printf("\n\t\tCPF>>> ");
    fflush(stdin);
    gets(cliente.cpf);

    printf("\n\t\tRG>>> ");
    fflush(stdin);
    gets(cliente.rg);

    printf("\n\t\tLogin>>> ");
    fflush(stdin);
    gets(cliente.login);

    cliente.registro = 4;

    fprintf(arq, " %i  ,", cliente.registro, 1);
    fprintf(arq, "%s,", cliente.nome, 1);
    fprintf(arq, "%i,", cliente.idade, 1);
    fprintf(arq, "%s,", cliente.endereco, 1);
    fprintf(arq, "%s,", cliente.telefone, 1);
    fprintf(arq, "%s,", cliente.login, 1);
    fprintf(arq, "%s,", cliente.senha, 1);
    fprintf(arq, " %s ,", cliente.cpf, 1);
    fprintf(arq, " %s , \n", cliente.rg, 1);

    printf("\n\n\t Deseja Cadastrar um novo cliente 1. Sim ou 2. Não>>> ");
    scanf("%i", &y);

    // fwrite(&cliente, 1,sizeof(struct fichadados),  arq); Dando problema de escrita;;;;;

    if(y == 1){
        Cadastro_Cliente(cliente);
    }else if(y == 2){
        printf("\n\t");
    }else{
        system("cls");
        printf("\n\n\t\t      INFORMAÇÃO INVÁLIDA!\n\t    -----------------------------------");
        voltar_menu();
    }
}

struct fichadado_funcionario{

    char nome[100], endereco[100], senha[100], telefone[100], cpf[20], rg[20], login[100];
    int idade, registro, verificaR;

}dados;

Cadastro_Funcionario(){

    FILE *arq;
    arq = fopen("dadosCadastrados.txt", "a+");

    dados;
    system("cls");
    printf("\n\t\t---------------------------------\n\t\t|\t     CADASTRO   \t|\n\t\t|   \t\tDE\t\t|\n\t\t|\t   FUNCIONÁRIOS\t\t|\n\t\t---------------------------------\n");
    printf("\n\n\t\tN° do Registro>>> ");
    fflush(stdin);
    scanf("%i", &dados.registro);
    while((dados.registro < 1) || (dados.registro > 3)){
        if((dados.registro < 1) || (dados.registro > 3)){
            printf("\n\t\tDigite o N° do registro novamente: ");
            scanf("%i", &dados.verificaR);
            if(dados.verificaR == 1){
                 dados.registro = 1;
            }else if(dados.verificaR == 2){
                dados.registro = 2;
            }else if(dados.verificaR == 3){
                dados.registro = 3;
            }
        }
    }
    printf("%i", dados.registro);

    printf("\n\t\tNome>>> ");
    fflush(stdin);
    gets(dados.nome);

    printf("\n\t\tIdade>>> ");
    scanf("%i", &dados.idade);

    printf("\n\t\tEndereco>>> ");
    fflush(stdin);
    gets(dados.endereco);

    printf("\n\t\tTelefone>>> ");
    fflush(stdin);
    gets(dados.telefone);

    printf("\n\t\tSenha>>> ");
    fflush(stdin);
    gets(dados.senha);

    printf("\n\t\tCPF>>> ");
    fflush(stdin);
    gets(dados.cpf);

    printf("\n\t\tRG>>> ");
    fflush(stdin);
    gets(dados.rg);

    printf("\n\t\tLogin>>> ");
    fflush(stdin);
    gets(dados.login);

    fprintf(arq, " %i  ,", dados.registro, 1);
    fprintf(arq, "%s,", dados.nome, 1);
    fprintf(arq, "%i,", dados.idade, 1);
    fprintf(arq, "%s,", dados.endereco, 1);
    fprintf(arq, "%s,", dados.telefone, 1);
    fprintf(arq, "%s,", dados.login, 1);
    fprintf(arq, "%s,", dados.senha, 1);
    fprintf(arq, " %s ,", dados.cpf, 1);
    fprintf(arq, " %s ,\n", dados.rg, 1);

    printf("\n\n\t Deseja Cadastrar um novo Funcionário 1. Sim ou 2. Não>>> ");
    scanf("%i", &y);

    if(y == 1){
        Cadastro_Funcionario(dados);
    }else if(y == 2){
        printf("\n\t");
    }else{
        system("cls");
        printf("\n\n\t\t      INFORMAÇÃO INVÁLIDA!\n\t    -----------------------------------");
        voltar_menu();
    }
    fclose(arq);
}

Cadastro(){

    system("cls");
    printf("\n\t\t---------------------------------\n\t\t|       OPÇÕES DE CADASTRO  \t|\n\t\t|-------------------------------|\n\t\t|\t\t\t\t|\n\t\t| 1. Novo Funcionário; \t\t|\n\t\t| 2. Novo Cliente; \t\t|\n\t\t|\t\t\t\t|\n\t\t| 3. Voltar para o Menu;  \t|\n\t\t|\t\t\t\t|\n\t\t---------------------------------\n\n\t\troot@Escolha>>> ");
    scanf("%i", &opcao);

    if(opcao == 1){
        Cadastro_Funcionario();
    }else if(opcao == 2){
        Cadastro_Cliente();
    }else if(opcao > 3){
        system("cls");
        opcao_invalida();
        Cadastro();
    }
}

Verifica_Login(char VeriLogin[100], char VeriSenha[100]){
    setlocale(LC_ALL, "Portuguese");
    FILE *arq;
    arq = fopen("dadosCadastrados.txt", "r");
    system("cls");
    int i,j=0,flag = 0,x, a = 0, b = 0, y ;

    char users[200], login[100], senha[100], result[100], senhar[100];
    char r[100], ver_r[100], confirm[100];

    while(fgets(users, 200, arq) != NULL){
        flag = 0;
        for(i = 0; i < sizeof(users); i++){

            if(users[i] == ','){
                i++;
                flag++;
                j=0;
            }
            if(flag == 0){
                r[j] = users[i];
                j++;
            }
            if(flag == 5){
                login[j] = users[i];
                j++;
            }
            if(flag == 6){
                senha[j] = users[i];
                j++;
            }
        }
        a= strlen(login);
        for(x = -1; x <= a;x++){
            result[x] = login[x];
            login[x] = 0;

            senhar[x] = senha[x];
            senha[x] = 0;

            ver_r[x] = r[x];
            r[x] = 0;
        }

        if(strcmp(result, VeriLogin)==0){
            if(strcmp(senhar, VeriSenha)==0){
                printf("\n\t\tVoce logou com>> %s\n\t\tSenha>> %s\n\t\tRegistro %s", result, senhar, ver_r);
                Sleep(1000);
                return(atoi(ver_r));
            }
        }
    }
    fclose(arq);
}

Login(){

    char senha[100], login[100];
    int valor;

    do{
        system("cls");
        printf("\n\t\t---------------------------------\n\t\t|\tPagina de Acesso      \t|\n\t\t---------------------------------\n\n\n\t\tLogin: ");
        fflush(stdin);
        gets(login);

        printf("\n\t\tSenha: ");
        fflush(stdin);
        gets(senha);
        valor = Verifica_Login(login, senha);
        if(valor > 0){
            if(valor == 1){
                menu_Proprietario(login);
                return 0;
            }else if(valor == 2){
                menu_Gerente(login);
                return 0;
            }else if(valor == 3){
                menu_Funcionario(login);
                return 0;
            }else if(valor == 4){
                menu_Cliente(login);
                return 0;
            }else{
                printf("\n\n\t\t");
                voltar_menu();
            }
        }
    }while(opcao != 0);
}

main(){
    opcao = -1;
    do{
        setlocale(LC_ALL, "Portuguese");
        system("cls");
        printf("\n\t\t---------------------------------\n\t\t|        SEJA BEM VINDO         |\n\t\t|-------------------------------|\n\t\t|\t\t\t\t|\n\t\t|   [+]OPÇÕES DISPONÍVEIS[+]    |\n\t\t|\t\t\t\t|\n\t\t|\t\t\t\t|\n\t\t| 1. Realizar Login;\t\t| \n\t\t| 2. Novo Cadastro; \t\t|\n\t\t| 3. Sobre;\t\t\t|\n\t\t|\t\t\t\t|\n\t\t| 0. Finalizar Sistema;\t\t|\n\t\t|\t\t\t\t|\n\t\t|-------------------------------|\n\t\t|\t      v2.0\t\t|\n\t\t---------------------------------\n\n\t\troot@Escolha>>> ");
        scanf("%i", &opcao);
        if(opcao == 1){
            Login();
        }
        if(opcao == 2){
            Cadastro();
        }else if(opcao == 3){
            system("cls");
            printf("\n\n\t\t\t\t      SOBRE NÓS!\n\t  ----------------------------------------------------------------\n\n\t  DESENVOLVEDORES: Elvis, Gabriel, Gustavo, Lucas, Mariana, Nelsi. \n\t  CURSO: Ciência Da Computação. \n\t  FACULDADE: UTFPR - Universidade Técnologica Federal do Paraná. \n\t  CAMPUS: Santa Helena - PR.\n\n\n\t  ");
            system("pause");
        }
    }while(opcao != 0);
}
