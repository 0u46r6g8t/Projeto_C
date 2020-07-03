#include <stdio.h>
#include <locale.h>
#include <windows.h>
excluirProduto(){
	int op,op2,numReg,lei,var, veri=0;
    FILE *arq , *temp;
    //arq = fopen("dadosProdutos.txt", "a+");
    
    printf("\n\t-------------------------------------\n");
    printf("");
    printf("\t\t*Excluir Produtos:*\n");
    printf("");
    printf("\t\t     Opcoes:\n\t\tExcluir Produto: 1\n\t\t    Voltar: 2\n\n\t\t  Opcao desejada:\n\t\t\t");
    scanf("%d",&op);
    if (op==1){
    		printf("");
    		printf("\n\t   Informe o numero do registro:\n\t\t\t");
    		fflush(stdin);
    		scanf("%d", &numReg);
    		
    		struct excluirProdutos{
    			int registro, ano;
       			char nome[100], cor[20], modelo[50];
       			float valor;
			};
			struct excluirProdutos excluir;
			
			arq = fopen("dadosProdutos.txt", "a+");
			if(arq != NULL){
				system("pause");
				temp=fopen("temp.txt", "a+");
				fread(&excluir , 1 , sizeof(struct excluirProdutos) , arq);
				while(!feof(arq)){
					if(excluir.registro == numReg){
						veri=1;
					}else{
						fwrite(&excluir, sizeof(struct excluirProdutos) , 1, temp);
						fread(&excluir , 1 , sizeof(struct excluirProdutos) , arq);	
					}
					
						
				}
				
			}	
			
			fclose(temp);
			fclose(arq);
			
			if(veri == 1){
				remove("dadosProdutos.txt");
				rename("temp.txt" , "dadosProdutos.txt");				
				printf("excluido com sucesso...\n");
				system("pause");
			}else{
				printf("Erro ao apagar...\n");
				system("pause");
			}
			
			/*lei =fread(&excluir, 1 , sizeof(struct excluirProdutos), arq);
			if (lei!=0){
				temp=fopen("temp.txt", "a+");
				while(!feof(arq)){
					if(excluir.registro<numreg || excluir.registro>numreg){
						fwrite(excluir.registro,sizeof(), temp);
						fwrite(excluir.nome, sizeof(), temp);
						fwrite(excluir.ano,sizeof(), temp);
						fwrite(excluir.modelo,sizeof(), temp);
						fwrite(excluir.cor,sizeof(), temp);
						fwrite(excluir.valor,sizeof(), temp);
						fread(&excluir,1, sizeof (struct excluirProdutos),arq);
					}
				}
				fclose(arq);
				fclose(temp);
				remove("dadosProdutos.txt");
				rename("temp.txt","dadosProdutos.txt");
				*/
				/*system("cls");
				printf("\n\t\tDeseja realmente excluir o produto?\n\n\tSim(1)\tNao(2)\n\n");
				scanf("%d",&op2);
				
				if (op2==1){
					system("cls");
					printf("\n\t\tRegistro Excluido!");
					printf("");
					excluirProduto();
				}else{
					system("cls");
					printf("Registro nao excluido!");
					printf("");
					excluirProduto();
				}*/
			}
		
    	else if(op==2){
			//voltar_menu();
	}else{
			system("cls");
			printf("\n     Erro! Verifique se sua opcao esta correta.\n");
			printf("");
			excluirProduto();
		}
	}

int main(){
	excluirProduto();
}

