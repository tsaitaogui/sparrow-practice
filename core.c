#include "core.h"
#include <string.h>
#include <sys/stat.h>
#include "utils.h"
#include "vm.h"

char* rootDir = NULL;   //�ڥ�?

//?�����N?���
char* readFile(const char* path) {
	
   FILE* file = fopen(path, "rb");
   if (file == NULL) {
      IO_ERROR("Could`t open file \"%s\".\n", path);
   }
   struct stat fileStat;
   stat(path, &fileStat);
   size_t fileSize = fileStat.st_size;
   char* fileContent = (char*)malloc(fileSize + 1);
   if (fileContent == NULL) {
      MEM_ERROR("Could`t allocate memory for reading file \"%s\".\n", path);
   }

   size_t numRead = fread(fileContent, sizeof(char), fileSize, file);
   printf("numRead=%d, fileSize=%d \n", numRead, fileSize);

   if (numRead < fileSize) {
      IO_ERROR("111Could`t read file \"%s\".\n", path);
   }

   fileContent[fileSize] = '\0';
   fclose(file);
   return fileContent;
}
