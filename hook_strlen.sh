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

norminette srcs/ft_strlen.c 2>/dev/null 1>/dev/null
tst=$?
if [ $tst -ne 0 ]; then

    ret=1

fi

if [ $ret -eq 1 ]; then

	printf "\033[0;31m You failed the test, try again!\n \033[0m\n"

else

	date
	printf "\033[0;32m Congratz! Please take a picture to keep a proof of your success\n\033[0m"


fi

exit $ret