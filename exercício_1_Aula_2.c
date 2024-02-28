
#include <stdio.h>

float calculo_media(float nota1, float nota2) {
    
    float media;
    media = nota1 + nota2 / 2;
    return (media);
}

int main()
{
    float nota1, nota2, media;
    
    printf("\nPor favor, Digite a Primeiro Nota: ");
    scanf("%f", &nota1);
    
    printf("\nPor favor, Digite a Segunda Nota: ");
    scanf("%f", &nota2);
    
    media = calculo_media(nota1, nota2);
    
    printf("\n\nA Média das 2 Notas fornecidas é %0.2f", media);

    return 0;
}
