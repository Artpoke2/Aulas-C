#include <stdio.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    long matricula;
    float nota;
}Aluno;

void print_dados(char Nome[50], long Matricula, float Nota){
    printf("O(a) Aluno(a) %s, com a Matricula %ld, teve uma nota de %0.2f",Nome, Matricula, Nota);
}

int main()
{
    Aluno Aluno;
    
    printf("\nPor favor, Digite seu Nome:\n");
    scanf("%50s", Aluno.nome);
    
    printf("\nPor favor, Digite sua Matricula:\n");
    scanf("%ld", &Aluno.matricula);

    printf("\nPor favor, Digite sua Nota:\n");
    scanf("%f", &Aluno.nota);
    
    print_dados(Aluno.nome, Aluno.matricula, Aluno.nota);

    return 0;
}
