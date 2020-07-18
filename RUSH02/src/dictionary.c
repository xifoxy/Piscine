#include "total.h"

dict *dic_make_elem(char *key, char *val){
    dict *ret;

    ret = (dict *)malloc(sizeof(dict));
    ret->next = 0;
    ret->key = key;
    ret->val = val;
    return ret;
}

void push_back(char *key, char *val){
    dict *temp;

    // 판별부분, 리스트를 글로벌로 둘거냐 아니면 인자로 계속 넘길꺼냐..?
    
}

int dic_valid_key(char *str){
    int colon;
    int key;
    int val;
    int ret;

    colon = 0;
    key = 0;
    val = 0;
    while(*str){
        if(*str == ':') colon++;
        if(ut_is_space(*str)){
            if(colon) ++val;
            else ++key;
        }
        ++str;
    }
    ret = (colon == 1 && key && val) ? 1 : 0;
    return ret;
}

int g_is_eof;
char *dic_get_line(int fd){
    char *ret;
    char buff[2048];
    int idx;
    int len;

    // EOF를 어떻게 판별할꺼지?
    // 라인 하나씩 받을껀데... 생각좀 해보자.
    // EOF의 경우 read의 반환값이 0이 된단다.
    // 글로벌 변수 하나 만들자.
    g_is_eof = 1;
    g_is_eof = read(fd, buff, 2048);
    if(!g_is_eof)
        return 0;
    len = ut_get_len(buff);
    ret = (char *)malloc(len + 1);
    idx = 0;
    while(g_is_eof && idx < len){
        if(ret[idx] == '\n'){
            ret[idx] = 0;
            break;
        }
        ++idx;
    }
    return (ret);
}

void dic_insert_value(char *str){
    char *base;
    char *key;
    char *val;
    char *cur;


    // 동적할당 FREE하기
    base = str;
    
    // 인덱스 가지고 놀면 카피가 불편하다(결론)
    // while(key[idx] != ':')
    //     ++idx;
    
    // key = (char *)malloc(idx + 1);
    // ut_strcpy(key, str, )

    // 키값 얻어오기
    cur = str;
    while(*cur != ':')
        ++cur;
    key = (char *)malloc(cur - str + 1);
    ut_strcpy(key, str, cur - 1);

    // 키 부분 사이드 공백을 처리해야된다
    /* 여기서 호출하기 */
    // key = stringScissors(key);
    ////////////////////////////

    // 콜론 다음부분부터 value받기
    str = ++cur;
    while (*cur)
        ++cur;
    val = (char *)malloc(cur - str + 1);
    ut_strcpy(val, str, cur -  1);

    // value도 똑같이 공백처리.
    // val = stringScissors(val);
    free(base);
    

    // 값 정리했으면 리스트에 푸시하기
    push_back(key, val);
}

int dic_make_dic(char *newfile){
    int fd;
    int ret;
    char *line;

    ret = 0;
    // 정상반환 0
    // 오류반환 -1
    // 파일 못읽으면 오류 반환
    fd = open(newfile, O_RDONLY);
    if(fd == -1)
        return -1;


    // 
    while(line = dic_get_line(fd)){
        // EOF
        if(!g_is_eof)
            break;
        // 문제에서 말한 딕셔너리에 공백이 있을수 있다.
        if (!*line)
            continue;
        // 딕셔너리 값이 규격에 맞는지 1차 검사
        if(!dic_valid_key(line)){
            ret = -1;
            break;
        }
        dic_insert_value(line);
    }

    close(fd);

    return ret;
}