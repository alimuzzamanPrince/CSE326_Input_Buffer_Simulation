#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <stdbool.h>


bool isDelim(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}


bool validIdentifier(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || str[0] == '.'|| isDelim(str[0]) == true)
        return (false);
    return (true);
}

bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

bool isInteger(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}


int main(){
    char ch, Buffer[10], opps[] = "+-*/%=";
    FILE *fp;
    int i,j=0;

    fp = fopen("input.c","r");

    if(fp == NULL){
        printf("error opening the file\n");
        exit(0);
    }

    while((ch = fgetc(fp)) != EOF){

           for(i = 0; i < 6; ++i){
               if(ch == opps[i])
                   printf("Token Found!\t'%c'\t is an operator\n", ch);
           }

           if(isalnum(ch)){
               Buffer[j++] = ch;
           }
           else if((ch == ' ' || ch == '\n') && (j != 0)){
                   Buffer[j] = '\0';
                   j = 0;

                   if(isKeyword(Buffer) == true)
                       printf("Token Found!\t'%s'\tis a keyword\n", Buffer);
                   else if(isInteger(Buffer)==true)
                       printf("Token Found!\t'%s'\tis an integer\n", Buffer);
                   else if (validIdentifier(Buffer) == true)
                       printf("Token Found!\t'%s'\tis a valid identifier\n", Buffer);
               }
              else if(ch=='#'){
                       printf("Token Found!\t '%c' \t is a preprocessor command\n",ch);

           }

    }

    fclose(fp);

    return 0;
}
