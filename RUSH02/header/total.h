// 작성후 쪼개기

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define DEFAULT_DIC "dictionary.dict"

#define CANNOT_DIC "Can't open dic file.\n"
#define AC_ERR_MSG "Error\n"
#define DICT_ERR "Dict Error\n"

typedef struct dict_{
    char *key;
    char *val;
    struct dict_ *next;
    
}dict;

// rush
void rush(int ac, char **ag);

// util
int ut_is_space(char ch);
int ut_is_num(char ch);

void ut_strcpy(char *dest, char *begin, char *end);
int ut_get_len(char *str);

void ut_write(char *str, int len);
void ut_word_print(char *str);
void ut_err_print(char *str);

// dictionary
int dic_valid_key(char *str);
void dic_insert_value(char *str);
char *dic_get_line(int fd);
int dic_make_dic(char *newfile);