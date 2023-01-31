#include <stdio.h>
#include <s21_string.h>
#include <string.h>

int func2(char *str1, char *str2);

int main () {
char a[1000] = "Helbo";
char b[1000] = "Helaoo";
func2(a, b);
return 0;
}

int func2(char *str1, char *str2) { 
    
    for(int i=0; str1[i] != '\0'; i++) {
        if(str1[i] != str2[i]) {
        printf("%d", str1[i]-str2[i]);
        }
        if(str2[i] == '\0') {
        break;
        }
    }
    return 0;
}



// int main () {
// char* a = "MARTINI";
// char* b = "olives";
// size_t c = 6;
// s21_memcpy(a, b, c); 
// return 0;
// }