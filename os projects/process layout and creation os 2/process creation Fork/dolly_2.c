#include <stdio.h>
#include <unistd.h>
int main ( ) {
int pid = fork ( ) ;
if ( pid == 0 ) {
printf ( " I 'm the c h i l d %d\n" , getpid ( ) ) ;
} else {
printf ( "My c h i l d i s c a l l e d %d\n" , pid ) ;
}
printf ( "That ' s i t %d\n" , getpid ( ) ) ;
return 0 ;
}

