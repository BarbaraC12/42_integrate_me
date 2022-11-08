#!/bin/bash

ret=0
tst=0

<<<<<<< HEAD:run.sh
printf '%b\n' "$(cat pimp.txt)"

bash run_tests.sh
=======
bash run_tests.sh strlen
>>>>>>> 4a26504 (ADD HOOK STRLEN:):hook_strlen.sh
tst=$?

if [ $tst -ne 0 ]; then

    ret=1

fi

norminette srcs/ft_strlen.c 2>/dev/null
tst=$?
if [ $tst -ne 0 ]; then

    ret=1

fi

exit $ret