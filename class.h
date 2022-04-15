#ifndef _OBJECT_CLASS_H
#define _OBJECT_CLASS_H
#include "common.h"
#include "utils.h"
#include "header_obj.h"

struct Class {
   ObjHeader objHeader;
   struct Class* superClass; //父?
   uint32_t fieldNum;	   //本?的字段?,包括基?的字段?
   //MethodBuffer methods;   //本?的方法
   //ObjString* name;   //?名
};

#define CAPACITY_GROW_FACTOR 4 
#define MIN_CAPACITY 64
#endif

