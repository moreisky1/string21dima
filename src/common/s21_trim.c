#include "../s21_string.h"

int contain_list(char c, const char *list);
size_t s21_strespn(const char *str1, const char *str2);
char * whiteSpase(char * src, char * trim_chars, int flag);

void* s21_trim(const char *src, const char *trim_chars) {
    char* result = NULL;
    if (src == NULL && trim_chars == NULL) {
        result = NULL;
    } else if (trim_chars == NULL) {
        result = whiteSpase(src, trim_chars, 1);
        // int j = 0;
        // while (src[j] != '\0') {
        //     result[j] = src[j];
        //     j++;
        // }
        // result[j] = '\0';
    } else if (src != NULL) {
        if (!s21_strlen(trim_chars)) {
            result = whiteSpase(src, trim_chars, 1);
        } else {
            result = whiteSpase(src, trim_chars, 0);
        }
        
        
        // int start = 0, end = 0, i = s21_strlen(src) - 1, len = 0;
        // // check start
        // while (contain_list(src[start], trim_chars)) {
        //     start++;
        // }
        // // check end
        // while (contain_list(src[i], trim_chars)) {
        //     end++;
        //     i--;
        // }
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
        // len = s21_strlen(src) - start - end;

        // if (start + end < s21_strlen(src) && start + end > 0) {
        //     result = (char*) malloc((len + 1) * sizeof (char));
        //     int j = 0;
        //     while (j < len) {
        //         result[j] = src[start + j];
        //         j++;
        //     }
        //     result[j] = '\0';
        // } else if (start + end == 0) {
        //     result = (char *) malloc((s21_strlen(src) + 1) * sizeof(char));
        //     int j = 0;
        //     while (src[j] != '\0') {
        //         result[j] = src[j];
        //         j++;
        //     }
        //     result[j] = '\0';
        // }
    }
    return result;
}

char * whiteSpase(char * src, char * trim_chars, int flag) {
    size_t size = s21_strlen(src), start_step = 0, end_step = 0;
    char * result = (char *) malloc((size + 1) * sizeof(char));
    if (flag) {
        char whitespase[] = {9, 10, 11, 12, 13, 32, '\0'};
        start_step = s21_strspn(src, whitespase);
        end_step = s21_strespn(src + start_step, whitespase);
        s21_strncpy(result, src + start_step, size - start_step - end_step);
    } else {
        start_step = s21_strspn(src, trim_chars);
        end_step = s21_strespn(src + start_step, trim_chars);
        s21_strncpy(result, src + start_step, size - start_step - end_step);
    }
    result[size - start_step - end_step] = 0;
    return result;
}


int contain_list(char c, const char *list) {
    int result = 0;
    int i = 0;
    while (list[i] != '\0') {
        if (c == list[i]) {
            result = 1;
            break;
        }
        i++;
    }
    return result;
}

size_t s21_strespn(const char *str1, const char *str2) {
    size_t size = s21_strlen(str1);
    char * buf = (char *)malloc((size + 1) * sizeof(char));
    for (size_t i = 0; i < size; i++) {
        buf[i] = str1[size - 1 - i];
    }
    buf[size] = 0;
    free(buf);
    size = 0;
    size = s21_strspn(buf, str2);
    return size;
}