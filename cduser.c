#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
   char *s = getcwd(NULL,0);

   printf ("Current working directory: %s\n",s);
  
   printf("Enter a new directory: ");
   char new_dir[100];
   scanf("%s", new_dir);
   chdir(new_dir);

   free(s);
   s = getcwd(NULL,0);
   printf("Updated working directory: %s\n",s);
  
   free(s);
   return 0;
}
