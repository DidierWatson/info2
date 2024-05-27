#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14

float areaCirculo(float radio){
    return PI * radio * radio;
}

float celsiusAFahrenheit(float celsius){
    return (celsius * 9/5.0) + 32;
}

bool esPar(int numero){
    return numero%2;
}

size_t numeroDigitos(int numero){
    size_t i = 0;
    while(numero != 0){
        i ++;
        numero/=10;
    }
    return i;
}

int revertir(int numero){
   
    int invertido = 0;
    while(numero != 0){
        invertido = invertido*10 + numero%10;
        numero /= 10;
    }
    return invertido;
}

int sumaNaturales(int numero){
    if (numero == 0)
        return numero;
    return numero + sumaNaturales(numero - 1);
   
}

float maximo(float a, float b, float c){
    float max = a;
    if (b > a)
        max = b;
    if (c > b || c > a)
        max = c;
    return max;
}

bool primo(int numero){
    return ((numero % 1) && (numero%numero));
}

int factorial(int numero){
    if(numero == 0)
        return 1;
    return numero * factorial(numero - 1);
}

size_t miStrlen(char *cadena){
    size_t i = 0;
    while(*cadena){
        i++;
        cadena++;
    }
    return i;
}

char *miConcat(char *s1, char *s2){
    size_t long_total = miStrlen(s1) + miStrlen(s2);
    char *concat = malloc((long_total + 1) * sizeof(char));
    if (!concat)
        return NULL;
    memcpy(concat,s1, miStrlen(s1) * sizeof(char));
    memcpy(&concat[miStrlen(s1)], s2, miStrlen(s2) * sizeof(char));
    concat[long_total] = '\0';

    return concat;   
}

bool miStrCmp(char *s1, char *s2){
    if (miStrlen(s1) != miStrlen(s2) || !s1 || !s2)
        return false;
    for(size_t i = 0; i < miStrlen(s1); i++){
        if (s1[i] != s2[i])
            return false;
    }
        return true;
}


char *revertirCadena(char *s){
    if (!s)
        return NULL;
    size_t len = strlen(s);
    char aux;
    for (size_t i = 0; i < len/2; ++i){
        aux = s[len - i - 1];
        s[i] = s[len - i - 1];
        s[i] = aux;
    }   
    return s;
}

size_t contadorVocales(char *s){
    if (!s)
        return 0;
    char vocales[] = {'a','e','i','o','u'};
    size_t vocal, i = 0;
    while(s[i] != '\0'){
        for (size_t j = 0; j < sizeof(vocales)/ sizeof(vocales[0]); j++){
            if (s[i] == vocales[j]){
                vocal++;
                break;
            }
        }
        i++;
    }    

    return vocal;
}

// int *ordenarArreglo(int *numeros){
//     if (!numeros)
//         return NULL;
//     while(*numeros){

//     }
// }


size_t sumarElementos(int *numeros){
    if(!numeros)
        return 0;
    size_t suma = 0;
    while(*numeros){
        suma += *numeros;
        numeros++;
    }
    return suma;
}

char *eliminarRepetidos(char *s){
    if (!s)
        return NULL;
    char *aux = malloc((strlen(s) + 1) * sizeof(char));
    if (!aux)
        return NULL;
    for (size_t i = 0; i < strlen(s); i++){
        for (size_t j = 0; j < i; j++){
            if (aux[j] == s[i])
                aux[j] = s[i+1];
        }
    }
    return aux;
}

void maximoYMinimo(int *numeros, int *maximo, int *minimo){
    *maximo = *numeros;
    *minimo = *numeros;

    while (*numeros){
        if (*numeros > *maximo)
            *maximo = *numeros;
        if (*numeros < *minimo)
            *minimo = *numeros;
        numeros++;    
    }

}

int buscarElemento(int *numeros, int buscado){
    if (!numeros)
        return -1;
    int posicion = 0;
    while(*numeros){
        if (*numeros == buscado)
            return posicion;
        numeros++;
        posicion++;
    }
        return -1;
}
int main()
{
    // printf("Hello World\n");
    int maximo = 0, minimo = 0;
    int numeros[] = {1,2,3,4,5};
    printf("%d\n",buscarElemento(numeros,0));
    return 0;
}