char* tokenArray[] = {
   "UNKNOWN",
   "NUM",		   
   "STRING",     	   
   "ID",	     	   
   "INTERPOLATION",
   "VAR",		   
   "FUN",		   
   "IF",		   
   "ELSE",	     	   
   "TRUE",	     	   
   "FALSE",	     	   
   "WHILE",	     	   
   "FOR",	     	   
   "BREAK",	     	   
   "CONTINUE"
   "RETURN",     	   
   "NULL",	     	   
   "CLASS",	     	   
   "THIS",	     	   
   "STATIC",     	   
   "IS",     	   
   "SUPER",	     	   
   "IMPORT",     	   
   "COMMA",		   
   "COLON",		   
   "LEFT_PAREN",	   
   "RIGHT_PAREN",	   
   "LEFT_BRACKET",	   
   "RIGHT_BRACKET",	   
   "LEFT_BRACE",	   
   "RIGHT_BRACE",	   
   "DOT",		   
   "DOT_DOT",	   
   "ADD",		   
   "SUB",		   
   "MUL",		   
   "DIV",		   
   "MOD",		   
   "ASSIGN",	   
   "BIT_AND",	   
   "BIT_OR",	   
   "BIT_NOT",	   
   "BIT_SHIFT_RIGHT",  
   "BIT_SHIFT_LEFT",   
   "LOGIC_AND",	   
   "LOGIC_OR",	   
   "LOGIC_NOT",	   
   "EQUAL",		   
   "NOT_EQUAL",	   
   "GREATE",	   
   "GREATE_EQUAL",	   
   "LESS",		   
   "LESS_EQUAL",	   
   "QUESTION",	   
   "EOF"
};

/*
typedef enum {
   TOKEN_UNKNOWN,
   // ?�u?��
   TOKEN_NUM,		   //?�r
   TOKEN_STRING,     	   //�r�Ŧ�
   TOKEN_ID,	     	   //?�q�W 
   TOKEN_INTERPOLATION,     //?�O��?��

   // ??�r(�t?�O�d�r)
   TOKEN_VAR,		   //'var'
   TOKEN_FUN,		   //'fun'
   TOKEN_IF,		   //'if'
   TOKEN_ELSE,	     	   //'else'	
   TOKEN_TRUE,	     	   //'true'
   TOKEN_FALSE,	     	   //'false'
   TOKEN_WHILE,	     	   //'while'
   TOKEN_FOR,	     	   //'for'
   TOKEN_BREAK,	     	   //'break'
   TOKEN_CONTINUE,         //'continue'
   TOKEN_RETURN,     	   //'return'
   TOKEN_NULL,	     	   //'null'

   //�H�U�O?�_?�M��??�J��token
   TOKEN_CLASS,	     	   //'class'
   TOKEN_THIS,	     	   //'this'
   TOKEN_STATIC,     	   //'static'
   TOKEN_IS,		   // 'is'
   TOKEN_SUPER,	     	   //'super'
   TOKEN_IMPORT,     	   //'import'

   //���j��
   TOKEN_COMMA,		   //','
   TOKEN_COLON,		   //':'
   TOKEN_LEFT_PAREN,	   //'('
   TOKEN_RIGHT_PAREN,	   //')'
   TOKEN_LEFT_BRACKET,	   //'['
   TOKEN_RIGHT_BRACKET,	   //']'
   TOKEN_LEFT_BRACE,	   //'{'
   TOKEN_RIGHT_BRACE,	   //'}'
   TOKEN_DOT,		   //'.'
   TOKEN_DOT_DOT,	   //'..'
   
   //???��?���
   TOKEN_ADD,		   //'+'
   TOKEN_SUB,		   //'-'
   TOKEN_MUL,		   //'*' 
   TOKEN_DIV,		   //'/' 
   TOKEN_MOD,		   //'%'

   //?��?���
   TOKEN_ASSIGN,	   //'='

   // ��?���
   TOKEN_BIT_AND,	   //'&'
   TOKEN_BIT_OR,	   //'|'
   TOKEN_BIT_NOT,	   //'~'
   TOKEN_BIT_SHIFT_RIGHT,  //'>>'
   TOKEN_BIT_SHIFT_LEFT,   //'<<'

   // ???���
   TOKEN_LOGIC_AND,	   //'&&'
   TOKEN_LOGIC_OR,	   //'||'
   TOKEN_LOGIC_NOT,	   //'!'

   //?�t�ާ@��
   TOKEN_EQUAL,		   //'=='
   TOKEN_NOT_EQUAL,	   //'!='
   TOKEN_GREATE,	   //'>'
   TOKEN_GREATE_EQUAL,	   //'>='
   TOKEN_LESS,		   //'<'
   TOKEN_LESS_EQUAL,	   //'<='

   TOKEN_QUESTION,	   //'?'

   //���?��??,??�k���R?�ϥ�
   TOKEN_EOF		   //'EOF'
} TokenType;

*/
