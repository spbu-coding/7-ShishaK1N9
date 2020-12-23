#include "handler.h"

int count_strings(file_name_t file_name)
{
    FILE *input_file = fopen(file_name, "r");
    int count_of_input_strings = 0;
    char *input_string = malloc(sizeof(char) * MAX_STRING_LENGTH);
    while(!feof(input_file))
    {
        if(fgets(input_string, MAX_STRING_LENGTH, input_file) != NULL)
        {
            count_of_input_strings++;
        }
    }
    free(input_string);
    fclose(input_file);
    return count_of_input_strings;
}

void input_array(file_name_t file_name, array_size_t array_size, strings_array_t strings_array)
{
    FILE* input_file = fopen(file_name, "r");
    for(array_size_t i = 0; i < array_size; i++)
    {
        fgets(strings_array[i], MAX_STRING_LENGTH, input_file);
    }
    fclose(input_file);
}

void bubble_sort(strings_array_t strings_array, array_size_t array_size)
{
    for(array_size_t i = 0; i < array_size; i++)
        for(array_size_t j = i + 1; j < array_size; j++)
            if(strcmp(strings_array[i], strings_array[j]) < 0)
            {
                char* swapper = strings_array[i];
                strings_array[i] = strings_array[j];
                strings_array[j] = swapper;
            }
}

bool is_symbol_in_array(char symbol, const char char_array[], int array_size)
{
    for(int i = 0; i < array_size; i++)
    {
        if(symbol == char_array[i])
        {
            return true;
        }
    }
    return false;
}

void take_off_separators(strings_array_t strings_array, array_size_t array_size)
{
    strings_array_t buffer = malloc(sizeof(char*) * array_size);
    for(int i = 0; i < array_size; i++)
    {
        buffer[i] = malloc(sizeof(char) * MAX_STRING_LENGTH);
    }

    for(int i = 0; i < array_size; i++)
    {
        char* string = malloc(sizeof(char) * MAX_STRING_LENGTH);
        int position = 0;
        for(int j = 0; j < strlen(strings_array[i]); j++)
        {
            if(!is_symbol_in_array(strings_array[i][j], SEPARATORS, SEPARATORS_COUNT))
            {
                string[position++] = strings_array[i][j];
            }
        }
        strcpy(buffer[i], string);
    }

    for(int i = 0; i < array_size; i++)
    {
        strcpy(strings_array[i], buffer[i]);
    }
    for(int i = 0; i < array_size; i++)
    {
        free(buffer[i]);
    }
    free(buffer);
}
