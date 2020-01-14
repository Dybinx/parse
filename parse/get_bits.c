
#include <assert.h>
#include "handle_bits.h"


/* bits_iter指向最低字节最低位。*/
__int64 ShiftToLeftForGet(unsigned char bits_width, unsigned char *buff, BitsIter *bits_iter)
{ 
	unsigned int one_bit = 0; 
	unsigned int count = 0; 
	__int64 value = 0;
	unsigned int octet_iter = bits_iter->octet_iter;
	unsigned int bit_iter = bits_iter->bit_iter;

	while(count < bits_width) 
	{ 
		one_bit = ((buff[octet_iter] << bit_iter) & 0xff) >> 7; 
		value = (value << 1) | one_bit; 
		bit_iter++; 
		octet_iter += bit_iter / 8; 
		bit_iter = bit_iter % 8; 
		count++; 
	} 

	bits_iter->bit_iter = bit_iter;
	bits_iter->octet_iter = octet_iter;

	return value;
}

/* for the field with bits_width <= 64 */
__int64 Get_bits(unsigned char *buff, unsigned char bits_width, BitsIter *bits_iter)
{
	assert(bits_width <= 64);

	return ShiftToLeftForGet(bits_width, buff, bits_iter);
}

