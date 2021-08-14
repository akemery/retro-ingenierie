#include <stdio.h>
// x est maintenant une variable globale
int x ;
int main(){
	printf ("Enter X :\n") ;
	scanf ("%d", &x) ;
	printf ("You entered %d...\n", x) ;
	return 0;
};
