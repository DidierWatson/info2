#include <stdio.h>

typedef unsigned char uchar;

void set_bit(uchar *numero, uchar bit_posicion)
{
	(*numero)|=1<<bit_posicion;
}

void clear_bit(uchar *numero, uchar bit_posicion)
{
	(*numero)&=~(1<<bit_posicion);
}

int bit_state(const uchar numero, uchar bit_posicion)
{
	return (numero & (1 << bit_posicion)) >> bit_posicion;
}

int ones_quantity (uchar numero){
	int suma=0;
	for(int n=0;n<8;n++){
		suma += bit_state(numero, n);
	}
	return suma;
}

int main(void)
{
	uchar prueba = 0xc3;
	printf("Nuestro numero es: %x", prueba);
	printf("\nEn binario es: %i%i%i%i %i%i%i%i",bit_state(prueba,7),bit_state(prueba,6),bit_state(prueba,5),bit_state(prueba,4),bit_state(prueba,3),bit_state(prueba,2),bit_state(prueba,1),bit_state(prueba,0));
	
	printf("\nEl bit N°%i esta en %i\n",5,bit_state(prueba,5));
	
	printf("\nLa cantidad de bits en uno en el numero %x es de %d\n", prueba, ones_quantity(prueba));
	
	return 0;
}
