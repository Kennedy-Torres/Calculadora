#include <stdio.h>
#include <stdlib.h>

// prototipagem
void cabecalho();
void rodape();
int le_valida_n1();
int le_valida_n2();
char le_valida_op();
int soma(int n1, int n2);
int subtracao(int n1, int n2);
int mult(int n1, int n2);
int divisao(int n1, int n2);
void resultado(int n1, char op, int n2);


int main()
{

    int n1 = 0, n2 = 0, retorno = -1;
    char op,inicio;

    do{
        cabecalho();
        n1 = le_valida_n1();
        op = le_valida_op();
        n2 = le_valida_n2();
        resultado(n1, op, n2);

        printf("|     Deseja continuar (S/N): ");
        scanf("%c",&inicio);
        printf("+-----------------------------------+\n");
    }while(inicio=='s' || inicio=='S');
    return 0;
}

// declarao
void cabecalho()
{
    system("cls");
    printf("+-----------------------------------+\n");
    printf("|            SUPER CALC             |\n");
    printf("+-----------------------------------+\n");
}

void rodape()
{
    printf("+-----------------------------------+\n");
    printf("|          Copyright 2023           |\n");
    printf("+-----------------------------------+\n");
}

int le_valida_n1()
{
    int n1 = 0, retorno = -1;
    char letra;

    do
    {
        printf("|    Informe o primeiro numero:");
        retorno = scanf(" %d", &n1); //'t'enter
        if (retorno == 0)
        {
            printf("|     Isto nao e um numero          |\n");
            printf("+-----------------------------------+\n");
        }

        do
        {
            letra = getchar();
        } while (letra != '\n'); // limpar o buffer do teclado para impedir o looping infinito
    } while (retorno == 0);      // retorno == 0.R.:letra , retorno == 1.R.:numero

    return n1;
}

int le_valida_n2()
{
    int n2 = 0, retorno = -1;
    char letra;

    do
    {
        printf("|     Informe o segundo numero:");
        retorno = scanf("%d", &n2);
        if (retorno == 0)
        {
            printf("|     Isto nao e um numero          |\n");
            printf("+-----------------------------------+\n");
        }

        do
        {
            letra = getchar();
        } while (letra != '\n');
    } while (retorno == 0);

    return n2;
}

char le_valida_op()
{

    char operador;

    do{
        printf("|      Informe o operador:");
        scanf(" %c",&operador);
    } while (operador != '+' && operador != '-' && operador != '*' && operador != '/');

    return operador;
}

int soma(int n1, int n2)
{
    cabecalho();

    printf("|          O resultado da           |\n");
    printf("|          soma %d+%d eh            |\n", n1, n2);
    printf("|                %d                 |\n", n1 + n2);

    rodape();
    return 0;
}

int subtracao(int n1, int n2)
{
    cabecalho();

    printf("|          O resultado da           |\n");
    printf("|          subtracao %d-%d eh       |\n", n1, n2);
    printf("|                %d                 |\n", n1 - n2);

    rodape();
    return 0;
}

int mult(int n1, int n2)
{
    cabecalho();

    printf("|          O resultado da           |\n");
    printf("|      multiplicacao %d*%d eh       |\n", n1, n2);
    printf("|                %d                 |\n", n1 * n2);

    rodape();
    return 0;
}

int divisao(int n1, int n2)
{
    cabecalho();
    
    if(n2==0){
        printf("| Nao eh possivel dividir por zero! |\n");
    }
    else{
        printf("|          O resultado da           |\n");
        printf("|    divisao inteira de %d/%d eh    |\n", n1, n2);
        printf("|                %d                 |\n", n1 / n2);
    }

    rodape();
    return 0;
}

void resultado(int n1, char op, int n2){
    switch(op){
        case '+':
            soma(n1,n2);
            break;
        case '-':
            subtracao(n1,n2);
            break;
        case '*':
            mult(n1,n2);
            break;
        case '/':
             divisao(n1,n2);
        break;
    }       


}