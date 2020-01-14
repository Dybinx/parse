#ifndef _HANDLE_BITS_H_
#define _HANDLE_BITS_H_


typedef struct
{
	unsigned int octet_iter; //index start from 0.
	unsigned int bit_iter;   //index start from 0 to 7. 0��ʾ�����һλ��Ҳ���������Чλ��
}BitsIter;


/* for the field with bits_width <= 32*/
extern __int64 Get_bits(unsigned char *buff, unsigned char bits_width, BitsIter *bits_iter);


#endif // _HANDLE_BITS_H_




