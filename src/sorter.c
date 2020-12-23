#include "validate.h"
#include "handler.h"

int main(int argc, char* argv[])
{
    int exit_code = check_parameters(argc - 1, argv);
    if(exit_code == UNSUCCESSFUL_EXIT_CODE)
    {
        return exit_code;
    }
    int count_of_strings = count_strings(argv[ARG_INPUT_FILE_NAME]);
    char** strings_array = malloc(sizeof(char*) * count_of_strings);
    for(int i = 0; i < count_of_strings; i++)
    {
        strings_array[i] = malloc(sizeof(char) * MAX_STRING_LENGTH);
    }
    input_array(argv[ARG_INPUT_FILE_NAME], count_of_strings, strings_array);
    take_off_separators(strings_array, count_of_strings);
    bubble_sort(strings_array, count_of_strings);
    int cnt = count_of_strings > 100 ? 100: count_of_strings;
    for(int i = 0; i < cnt; i++)
    {
        printf("%s", strings_array[i]);
        free(strings_array[i]);
    }
    free(strings_array);
    return exit_code;
}