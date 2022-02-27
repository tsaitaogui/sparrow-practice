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
   }

VM* vm = newVM();
   const char* sourceCode = readFile(path);

   struct parser parser;
   initParser(vm, &parser, path, sourceCode);

   #include "tokenlist.c"
   
   while (parser.curToken.type != TOKEN_EOF) {
      getNextToken(&parser);
      printf("%dL-tokenArray[%d]: %s [", parser.curToken.lineNo, \
      	parser.curToken.type,tokenArray[parser.curToken.type]);
      uint32_t idx = 0;
      while (idx < parser.curToken.length) {
	 	printf("%c", *(parser.curToken.start+idx++));
      }
      printf("]\n");
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
