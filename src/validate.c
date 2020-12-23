#include "validate.h"

#define error_print(...) fprintf(stderr, __VA_ARGS__)

int error(char *error_text)
{
    error_print("%s\n", error_text);
    return UNSUCCESSFUL_EXIT_CODE;
}

bool check_existence_input_file(file_name_t file_name)
{
    FILE* input_file = fopen(file_name, "r");
    if(input_file == NULL)
    {
        return false;
    }
    fclose(input_file);
    return true;
}

bool check_count_of_parameters(parameters_count_t parameters_count)
{
    if(parameters_count == PARAMETERS_COUNT)
    {
        return true;
    }
    return false;
}

int check_parameters(parameters_count_t parameters_count, parameters_t parameters)
{
    if(!check_count_of_parameters(parameters_count))
    {
        return error("Input correct count of parameters.");
    }
    if(!check_existence_input_file(parameters[ARG_INPUT_FILE_NAME]))
    {
        return error("Input correct file name.");
    }
    return SUCCESSFUL_EXIT_CODE;
}