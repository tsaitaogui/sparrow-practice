#include "unicodeUtf8.h"
#include "common.h"

//返回value按照utf8??后的字??
uint32_t getByteNumOfEncodeUtf8(int value) {
   ASSERT(value > 0, "Can`t encode negative value!");

   // ??ascii字符需要1字?
   if (value <= 0x7f) {
      return 1;
   }

   //此范???值???utf8需要2字?
   if (value <= 0x7ff) {
      return 2;
   }

   //此范???值???utf8需要3字?
   if (value <= 0xffff) {
      return 3;
   }

   //此范???值???utf8需要4字?
   if (value <= 0x10ffff) {
      return 4;
   } 

   return 0;  //超?范?返回0
}

//把value???utf8后?入???buf,返回?入的字??
uint8_t encodeUtf8(uint8_t* buf, int value) {
   ASSERT(value > 0, "Can`t encode negative value!");

//按照大端字?序?入??? 
   if (value <= 0x7f) {   // ??ascii字符需要1字?
      *buf = value & 0x7f;
      return 1;
   } else if (value <= 0x7ff) {  //此范???值???utf8需要2字?
      //先?入高字?
      *buf++ = 0xc0 | ((value & 0x7c0) >> 6);
      // 再?入低字?
      *buf = 0x80 | (value & 0x3f);
      return 2;
   } else if (value <= 0xffff) { //此范???值???utf8需要3字?
      // 先?入高字? 
      *buf++ = 0xe0 | ((value & 0xf000) >> 12);
      //再?入中?字?
      *buf++ = 0x80 | ((value & 0xfc0) >> 6);
       //最后?入低字?
      *buf = 0x80 | (value & 0x3f);
      return 3;
   } else if (value <= 0x10ffff) { //此范???值???utf8需要4字?
      *buf++ = 0xf0 | ((value & 0x1c0000) >> 18);
      *buf++ = 0x80 | ((value & 0x3f000) >> 12);
      *buf++ = 0x80 | ((value & 0xfc0) >> 6);
      *buf = 0x80 | (value & 0x3f);
      return 4;
   }

   NOT_REACHED();
   return 0;
}

//返回解?utf8的字??
uint32_t getByteNumOfDecodeUtf8(uint8_t byte) {
   //byte??是utf8的最高1字?,如果指向了utf8??后面的低字?部分?返回0
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

//解?以bytePtr?起始地址的UTF-8序列 其最大?度?length 若不是UTF-8序列就返回-1
int decodeUtf8(const uint8_t* bytePtr, uint32_t length) {
   //若是1字?的ascii:  0xxxxxxx
   if (*bytePtr <= 0x7f) {
      return *bytePtr;
   }

   int value;
   uint32_t remainingBytes;

   //先?取高1字?
   //根据高字?的高n位判?相?字??的utf8??
   if ((*bytePtr & 0xe0) == 0xc0) {
      //若是2字?的utf8
      value = *bytePtr & 0x1f; 
      remainingBytes = 1;
   } else if ((*bytePtr & 0xf0) == 0xe0) {
      //若是3字?的utf8
      value = *bytePtr & 0x0f; 
      remainingBytes = 2;
   } else if ((*bytePtr & 0xf8) == 0xf0) {
      //若是4字?的utf8
      value = *bytePtr & 0x07; 
      remainingBytes = 3;
   } else {   //非法??
      return -1;
   }

   //如果utf8被??了就不再??去了
   if (remainingBytes > length - 1) {
      return -1;
   }

   //再?取低字?中的?据
   while (remainingBytes > 0) {
      bytePtr++;  
      remainingBytes--;
      //高2位必?是10
      if ((*bytePtr & 0xc0) != 0x80) {
	 return -1;
      }

      //?次高字?往低字?,不?累加各字?的低6位
      value = value << 6 | (*bytePtr & 0x3f);
   }
   return value;
}
