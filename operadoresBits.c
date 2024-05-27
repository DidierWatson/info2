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

int main(void)
{
	uchar prueba = 0x01;
	printf("%x\n", prueba);
	clear_bit(&prueba,0);
	printf("%i\n",bit_state(prueba,0));
	set_bit(&prueba,0);
	printf("%i\n",bit_state(prueba,0));

	return 0;
}

