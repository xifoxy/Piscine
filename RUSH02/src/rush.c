#include "total.h"

void rush(int ac, char **ag){
    // 기본 DICT를 가져와야한다.
    int run;
    if(3 < ac){
        ut_err_print(AC_ERR_MSG);
        return ;
    } else if(ac == 2)
        run = make_dic(DEFAULT_DIC);
    else
        run = make_dic(ag[1]);

    
    if(run == -1){
        ut_err_print(CANNOT_DIC);
        return ;
    }


    if(ac == 2)
    ;
    else
    ;


}