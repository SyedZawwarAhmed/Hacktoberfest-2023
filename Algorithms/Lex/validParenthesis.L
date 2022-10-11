%{
int i, top = 0;
char arr[20];
%}
%%
(.)* {
	if (yyleng % 2 != 0)
		printf("Invalid Parenthesis\n");
	else{
		for (i=0; i<yyleng; i++){
			arr[top] = yytext[i];
			if (i != 0){
				if (arr[top-1] == '(' && yytext[i] == ')')
					top -= 1;
				else if (arr[top-1] == '[' && yytext[i] == ']')
					top -= 1;
				else if (arr[top-1] == '{' && yytext[i] == '}')
					top -= 1;
				else
					top ++;

			}
			else
				top ++;
		}
	if (top == 0)
		printf("Valid Parenthesis\n");
	else
		printf("Invalid Parenthesis\n");
	}
	top = 0;
}
%%
int main(){
	yylex();
	return 0;
}
int yywrap(){
	return 1;
}
