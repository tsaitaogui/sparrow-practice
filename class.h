#ifndef _OBJECT_CLASS_H
#define _OBJECT_CLASS_H
#include "common.h"
#include "utils.h"
#include "header_obj.h"

struct Class {
   ObjHeader objHeader;
   struct Class* superClass; //��?
   uint32_t fieldNum;	   //��?���r�q?,�]�A��?���r�q?
   //MethodBuffer methods;   //��?����k
   //ObjString* name;   //?�W
};

#define CAPACITY_GROW_FACTOR 4 
#define MIN_CAPACITY 64
#endif

