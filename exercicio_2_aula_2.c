
#include <stdio.h>

float calculo_triangulo(float altura, float largura);

int main()
{
    float altura, largura, resultado;
    
    printf("\nPor favor, Digite a Altura do Triangulo: ");
    scanf("%f", &altura);
    
    printf("\nPor favor, Digite a Largura do Triangulo: ");
    scanf("%f", &largura);
    
    resultado = calculo_triangulo(altura, largura);
    
    printf("\n\nA Área do Triangulo fornecido é %0.2f", resultado);

    return 0;
}

float  calculo_triangulo(float altura, float largura) {
    
    float resultado;
    resultado = altura * largura / 2;
    return (resultado);
}
