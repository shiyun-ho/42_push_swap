// Helper function to validate a single number string
static int is_valid_number(const char *str)
{
    long long num;
    char *endptr;

    if (!str || !*str)
        return (0);
    // Check for single '-' or '+'
    if ((*str == '-' || *str == '+') && !*(str + 1))
        return (0);
    num = strtoll(str, &endptr, 10);
    // Check if conversion was successful and within INT range
    if (*endptr != '\0' || num > INT_MAX || num < INT_MIN)
        return (0);
    return (1);
}

// Helper function to check for duplicates in array
static int has_duplicates(char **numbers, int count)
{
    int i;
    int j;
    long a;
    long b;

    i = 0;
    while (i < count)
    {
        j = i + 1;
        while (j < count)
        {
            a = strtol(numbers[i], NULL, 10);
            b = strtol(numbers[j], NULL, 10);
            if (a == b)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

// Main validation function
static int validate_quoted_input(char *input)
{
    char **numbers;
    int i;
    int valid;

    numbers = ft_split(input, ' ');
    if (!numbers)
        return (0);
    
    // Count numbers and validate each one
    i = 0;
    valid = 1;
    while (numbers[i])
    {
        if (!is_valid_number(numbers[i]))
        {
            valid = 0;
            break;
        }
        i++;
    }

    // Check for duplicates if numbers are valid
    if (valid && has_duplicates(numbers, i))
        valid = 0;

    free_split_args(numbers);
    return (valid);
}