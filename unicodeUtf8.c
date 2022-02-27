#include "unicodeUtf8.h"
#include "common.h"

//��^value����utf8??�Z���r??
uint32_t getByteNumOfEncodeUtf8(int value) {
   ASSERT(value > 0, "Can`t encode negative value!");

   // ??ascii�r�Żݭn1�r?
   if (value <= 0x7f) {
      return 1;
   }

   //���S???��???utf8�ݭn2�r?
   if (value <= 0x7ff) {
      return 2;
   }

   //���S???��???utf8�ݭn3�r?
   if (value <= 0xffff) {
      return 3;
   }

   //���S???��???utf8�ݭn4�r?
   if (value <= 0x10ffff) {
      return 4;
   } 

   return 0;  //�W?�S?��^0
}

//��value???utf8�Z?�J???buf,��^?�J���r??
uint8_t encodeUtf8(uint8_t* buf, int value) {
   ASSERT(value > 0, "Can`t encode negative value!");

//���Ӥj�ݦr?��?�J??? 
   if (value <= 0x7f) {   // ??ascii�r�Żݭn1�r?
      *buf = value & 0x7f;
      return 1;
   } else if (value <= 0x7ff) {  //���S???��???utf8�ݭn2�r?
      //��?�J���r?
      *buf++ = 0xc0 | ((value & 0x7c0) >> 6);
      // �A?�J�C�r?
      *buf = 0x80 | (value & 0x3f);
      return 2;
   } else if (value <= 0xffff) { //���S???��???utf8�ݭn3�r?
      // ��?�J���r? 
      *buf++ = 0xe0 | ((value & 0xf000) >> 12);
      //�A?�J��?�r?
      *buf++ = 0x80 | ((value & 0xfc0) >> 6);
       //�̦Z?�J�C�r?
      *buf = 0x80 | (value & 0x3f);
      return 3;
   } else if (value <= 0x10ffff) { //���S???��???utf8�ݭn4�r?
      *buf++ = 0xf0 | ((value & 0x1c0000) >> 18);
      *buf++ = 0x80 | ((value & 0x3f000) >> 12);
      *buf++ = 0x80 | ((value & 0xfc0) >> 6);
      *buf = 0x80 | (value & 0x3f);
      return 4;
   }

   NOT_REACHED();
   return 0;
}

//��^��?utf8���r??
uint32_t getByteNumOfDecodeUtf8(uint8_t byte) {
   //byte??�Outf8���̰�1�r?,�p�G���V�Futf8??�Z�����C�r?����?��^0
   if ((byte & 0xc0) == 0x80) {
      return 0;
   }

   if ((byte & 0xf8) == 0xf0) {
      return 4;
   }

   if ((byte & 0xf0) == 0xe0) {
      return 3;
   }

   if ((byte & 0xe0) == 0xc0) {
      return 2;
   }

   return 1;   //ascii?
} 

//��?�HbytePtr?�_�l�a�}��UTF-8�ǦC ��̤j?��?length �Y���OUTF-8�ǦC�N��^-1
int decodeUtf8(const uint8_t* bytePtr, uint32_t length) {
   //�Y�O1�r?��ascii:  0xxxxxxx
   if (*bytePtr <= 0x7f) {
      return *bytePtr;
   }

   int value;
   uint32_t remainingBytes;

   //��?����1�r?
   //���u���r?����n��P?��?�r??��utf8??
   if ((*bytePtr & 0xe0) == 0xc0) {
      //�Y�O2�r?��utf8
      value = *bytePtr & 0x1f; 
      remainingBytes = 1;
   } else if ((*bytePtr & 0xf0) == 0xe0) {
      //�Y�O3�r?��utf8
      value = *bytePtr & 0x0f; 
      remainingBytes = 2;
   } else if ((*bytePtr & 0xf8) == 0xf0) {
      //�Y�O4�r?��utf8
      value = *bytePtr & 0x07; 
      remainingBytes = 3;
   } else {   //�D�k??
      return -1;
   }

   //�p�Gutf8�Q??�F�N���A??�h�F
   if (remainingBytes > length - 1) {
      return -1;
   }

   //�A?���C�r?����?�u
   while (remainingBytes > 0) {
      bytePtr++;  
      remainingBytes--;
      //��2�쥲?�O10
      if ((*bytePtr & 0xc0) != 0x80) {
	 return -1;
      }

      //?�����r?���C�r?,��?�֥[�U�r?���C6��
      value = value << 6 | (*bytePtr & 0x3f);
   }
   return value;
}
