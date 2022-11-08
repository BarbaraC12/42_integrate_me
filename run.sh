#!/bin/bash

ret=0
tst=0

printf '%b\n' "$(cat pimp.txt)"

bash run_tests.sh
tst=$?

if [ $tst -ne 0 ]; then

    ret=1

fi

norminette -R CheckForbiddenSourceHeader srcs/ | grep -v "Warning: Not a valid file"
ret=$?

if [ $tst -ne 0 ]; then

    ret=1

fi

exit $ret