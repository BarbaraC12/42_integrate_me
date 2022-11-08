#!/bin/bash

TEST_NAMES='
strlen
strcpy
strcat
putchar
putstr
'

# Commands
CC='cc -c -Wall -Wextra -Werror'
LD='cc'

# Directories
OBJ_DIR=objs
FUNC_DIR=srcs
TEST_DIR=tests
INCLUDE_DIR=include
EXECUTABLE_DIR=bin
LOG_DIR=logs

# Colors
FG_BLACK='\033[38;2;0;0;0m'
FG_RED='\033[38;2;255;0;0m'
FG_GREEN='\033[38;2;0;255;0m'
FG_BLUE='\033[38;2;0;0;255m'
FG_YELLOW='\033[38;2;255;255;0m'
FG_MAGENTA='\033[38;2;255;0;255m'
FG_CYAN='\033[38;2;0;255;255m'
FG_WHITE='\033[38;2;255;255;255m'

BG_BLACK='\033[48;2;0;0;0m'
BG_RED='\033[48;2;255;0;0m'
BG_GREEN='\033[48;2;0;255;0m'
BG_BLUE='\033[48;2;0;0;255m'
BG_YELLOW='\033[48;2;255;255;0m'
BG_MAGENTA='\033[48;2;255;0;255m'
BG_CYAN='\033[48;2;0;255;255m'
BG_WHITE='\033[48;2;255;255;255m'

# Visual effects
BOLD='\033[1m'
BLINK='\033[5m'

RESET='\033[0m'

# Miscellaneous

unit_test() {

	local func_file_c="$FUNC_DIR/ft_$1.c"
	local func_file_o="$OBJ_DIR/ft_$1.o"
	local test_file_c="$TEST_DIR/test_ft_$1.c"
	local test_file_o="$OBJ_DIR/test_ft_$1.o"
	local executable_file="$EXECUTABLE_DIR/test_ft_$1.out"
	local compilation_logs_file="$LOG_DIR/test_ft_$1.compilation.log"
	local linkage_logs_file="$LOG_DIR/test_ft$1.linkage.log"
	local forbidden_functions_logs_file="$LOG_DIR/test_ft$1.forbidden_functions.log"
	local running_logs_file="$LOG_DIR/test_ft_$1.running.log"
	local padded_title='  %-19s: '
	local sleep_time=1
	local score=0

	printf "$FG_MAGENTA$BOLD"'Testing '"$1$RESET"'\n'
	/bin/sleep $sleep_time
	# Check compilation
	printf "$padded_title" 'Compilation'
	$CC -I $INCLUDE_DIR -o $test_file_o $test_file_c
	$CC -I $INCLUDE_DIR -o $func_file_o $func_file_c 2>$compilation_logs_file
	if [ $? -ne 0 ]; then

		printf $FG_RED'KO'$RESET'\n'

	else

		printf $FG_GREEN'OK'$RESET'\n'
		rm $compilation_logs_file
		((score++))

	fi

	# Check linkage
	printf "$padded_title" 'Linkage'
	$LD -o $executable_file $test_file_o $func_file_o 2>$linkage_logs_file
	if [ $? -ne 0 ]; then

		printf $FG_RED'KO'$RESET'\n'

	else

		printf $FG_GREEN'OK'$RESET'\n'
		rm $linkage_logs_file
		((score++))

	fi

	# Check forbidden functions
	printf "$padded_title" 'Forbidden functions'
	nm -u $func_file_o 2>/dev/null | grep "$1" >>$forbidden_functions_logs_file
	if [ $? -eq 0 ]; then

		printf $FG_RED'KO'$RESET'\n'

	else

		printf $FG_GREEN'OK'$RESET'\n'
		rm $forbidden_functions_logs_file
		((score++))

	fi

	# Check running behavior
	printf "$padded_title" 'Running'
	./$executable_file >$running_logs_file 2>&1
	if [ $? -ne 0 ]; then

		printf $FG_RED'KO'$RESET'\n'

	else

		printf $FG_GREEN'OK'$RESET'\n'
		rm $running_logs_file
		((score++))

	fi

	printf '\n'
	if [ $score -eq 4 ]; then

		return 0
	
	else 
	
		return 1

	fi
}

# Beginning of the script
# printf '%b\n' "$(cat pimp.txt)"

# Create directories that may not exist yet
mkdir -p $OBJ_DIR $LOG_DIR $EXECUTABLE_DIR

ret=0

# Check if some arguments have been sent
if [ $# -ne 0 ]; then

	# Browse arguments
	while [ $# -ne 0 ]; do

		for NAME in $TEST_NAMES ; do

			if [ "$NAME" = "$1" ]; then

				unit_test $NAME
				ret=$?
				# Check if all tests have been passed
				if [ $ret -ne 4 ]; then

					printf $FG_RED$BOLD'Not all tests passed!'"$RESET$BOLD"' You should check your work.'"$RESET$BOLD"'\n\n'"$RESET"

				fi

				break

			fi

		done

		shift 1

	done

else

	# Do all tests
	for NAME in $TEST_NAMES ; do

		unit_test $NAME
		ret+=$?

	done

	# Check if all tests have been passed
	if [ $ret -ne 0 ]; then

			printf $FG_RED$BOLD'Not all tests passed!'"$RESET$BOLD"' You should check your work.'"$RESET$BOLD"'\n\n'"$RESET"
			ret=1

	fi
	
fi

exit $ret
