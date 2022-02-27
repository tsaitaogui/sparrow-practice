#include "cli.h"
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "vm.h"
#include "core.h"

static void runFile(const char* path) {
   const char* lastSlash = strrchr(path, '/');
   if (lastSlash != NULL) {
      char* root = (char*)malloc(lastSlash - path + 2);
      memcpy(root, path, lastSlash - path + 1);
      root[lastSlash - path + 1] = '\0';
      rootDir = root;
      printf("%s is existed!\n", path);
   } else {
   	  printf("%s is not existed!\n", path);
   }


}

int main(int argc, char *argv[])
{
	printf("%s\n", "HelloWorld");
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);
	runFile(argv[1]);
	return 0;
}
