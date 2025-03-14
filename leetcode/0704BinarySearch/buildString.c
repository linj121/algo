#include <stdio.h>

int main() {
    int i;
    printf("//Simple dynamic string builder:\n");
    char *strs[6] = {"I","am","an","array","of","strings"};
    
    char *buf = "["; // open bracket
    for (i=0;i<6;i++) {
        // Dynamically build and allocate memory
        asprintf(&buf,"%s%s",buf,strs[i]);
        if(i!=5) { // Add a comma , after each but skip the last
            asprintf(&buf,"%s,",buf);
        }
    }
    asprintf(&buf,"%s]",buf); // closing backet
printf("\"%s\"\n",buf);
}
