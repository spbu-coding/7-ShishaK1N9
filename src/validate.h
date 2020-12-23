#ifndef INC_7_SHISHAK1N9_VALIDATE_H
#define INC_7_SHISHAK1N9_VALIDATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static const int PARAMETERS_COUNT = 1, SUCCESSFUL_EXIT_CODE = 0, UNSUCCESSFUL_EXIT_CODE = -1;
static const int ARG_INPUT_FILE_NAME = 1;

typedef size_t count_of_strings_t;
typedef int parameters_count_t;
typedef char *string_t, *file_name_t;
typedef char** parameters_t;

int check_parameters(parameters_count_t, parameters_t);

#endif //INC_7_SHISHAK1N9_VALIDATE_H
