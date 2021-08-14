#include <stdio.h>
#include <string.h>
#define  MAX_INPUT 30
char *password = "TUNEcoNNAISpas";

int main(int argc, char *argv[]){
   int n;
   char input[MAX_INPUT];
   do{
       printf("Pouvez vous deviner le mot de passe secret?\n:");
       scanf("%s", input);
       printf("\nTexte entré: (%s)\n", input);
   }while(strncmp(input, password, MAX_INPUT ));
   
   printf("Félicitation, vous avez trouvé le mot de passe (%s)\n", password);

}
