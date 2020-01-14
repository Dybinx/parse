#include <stdio.h>
#include "parse_asn1.h"

int main(int agc, char *agv[])
{
	unsigned char bits[] = { 0x9a }; //‭10011010‬	
	Info info = { 0 };

	parase_asn1(&info, bits);

	printf("info.a = %d, info.b = %d\n", info.a, info.b);

	return 1;
}