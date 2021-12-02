#include <stdio.h>
#include <stdlib.h>
char *func(char c)
{
	char *s;
	static int i = 0;
	
	s = (char *)malloc(2);
	printf("%p", s);
	s[0] = c;
	s[1] = '\0';
	return (s);
}/*
int	main(){
	printf("%s\n", func('c'));	
	printf("%s\n", func('b'));	
	printf("%s\n", func('a'));	
}*/
