#ifndef SORTER_HANDLER_H
#define SORTER_HANDLER_H

#include "validate.h"

static const char SEPARATORS[] = {'.', ',', ';', ':', '!', '?'};
static const int MAX_STRING_LENGTH = 1000, MAX_STINGS_COUNT = 100, SEPARATORS_COUNT = sizeof(SEPARATORS) / sizeof(char);

typedef char** strings_array_t;
typedef size_t array_size_t;

int count_strings(file_name_t);

void input_array(file_name_t, array_size_t, strings_array_t);

void bubble_sort(strings_array_t, array_size_t);

void take_off_separators(strings_array_t, array_size_t);

#endif //SORTER_HANDLER_H
