#include "parse_asn1.h"
#include "handle_bits.h"

void parase_asn1(Info *info, unsigned char *bitstream)
{
	BitsIter bits_iter = { 0 };
	unsigned char bits_width = 0;

	info->a = Get_bits(bitstream, 2, &bits_iter) + 5;
	info->b = Get_bits(bitstream, 5, &bits_iter);
}
