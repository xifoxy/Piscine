////////////////////////////////////////// Valid Area
int ut_is_space(char ch){
    return (ch == ' ' || (ch >= 9 && ch <= 13));
}

int ut_is_num(char ch){
    return (ch >= '0' && ch <= '9');
}



////////////////////////////////////////// string util
void ut_strcpy(char *dest, char *begin, char *end){
    while(begin <= end)
        *dest++ = *begin++;
    *dest = 0;
}

int ut_get_len(char *str){
    int idx;

    idx = 0;
    while(str[idx])
        ++idx;
    return (idx);
}



////////////////////////////////////////// Print Area
void ut_write(char *str, int len){
    write(1, str, len);
}

void ut_word_print(char *str){
    int len;

    len = ut_get_len(str);
    ut_write(str, len);
}

void ut_err_print(char *str){
    int len;
    
    len = ut_get_len(str);
    ut_write("Error: ", 7);
    ut_write(str, len);
    ut_write("\n", 1);
}