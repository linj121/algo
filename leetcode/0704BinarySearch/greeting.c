#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main( void )
{
	char greeting[]   = "hello";  // greeting contains a *copy* of the string "hello";
	                              // size is taken from the length of the string plus the
	                              // 0 terminator
	
	char *greetingPtr = "hello";  // greetingPtr contains the *address* of the 
	                              // string literal "hello"
	
	printf( "size of greeting array:              %zu\n", sizeof greeting );
	printf( "length of greeting string:           %zu\n", strlen( greeting ) );
	printf( "size of greetingPtr variable:        %zu\n", sizeof greetingPtr );
	
	printf( "address of string literal \"hello\":   %p\n", (void * ) "hello" );
	printf( "address of greeting array:           %p\n", (void * ) greeting );
	printf( "address of greetingPtr:              %p\n", (void * ) &greetingPtr );
	printf( "content of greetingPtr:              %p\n", (void * ) greetingPtr );
	
	printf( "greeting:                            %s\n", greeting );
	printf( "greetingPtr:                         %s\n", greetingPtr );
	
	return 0;
}
