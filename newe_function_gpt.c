/**
 * check_flags - function to check both sign flags and formatting flags in a format string
 * @str: pointer to the format string
 * @i: index of the character in the format string
 *
 * Return: the index of the last character before the conversion specifier
 */
int check_flags(const char *str, int i)
{
    int index = i + 1;

    // Check if the first character is '0'
    if (str[i] == '0')
    {
        g_bonus.is_zero = 1;
        index++;
    }

    // Loop through the string to find flags
    while (str[index])
    {
        // If a conversion specifier is found, exit the loop
        if (ft_strchr("cspdiuxX%", str[index]))
            break;

        // Check for sign flags
        if (str[index] == '+')
        {
            g_bonus.is_plus = 1;
            index++;
        }
        else if (str[index] == '-')
        {
            g_bonus.is_minus = 1;
            index++;
        }
        else if (str[index] == ' ' && !g_bonus.is_minus)
        {
            g_bonus.is_minus = 2;
            index++;
        }

        // Check for formatting flags
        if (ft_isdigit(str[index]))
        {
            if (!has_precision && !has_width)
                has_width = 1;
            if (has_precision)
            {
                g_bonus.precision = 0;
                has_precision = 0;
            }
            g_bonus.width = g_bonus.width * 10 + (str[index] - '0');
        }
        else if (str[index] == '.')
        {
            has_precision = 1;
            has_width = 0;
            index++;
            if (ft_isdigit(str[index]))
            {
                g_bonus.precision = ft_atoi(str + index);
                while (ft_isdigit(str[index]))
                    index++;
            }
            else
            {
                g_bonus.precision = 0;
            }
        }

        // Move to the next character
        index++;
    }

    // Return the index of the last character before the conversion specifier
    return index - 1;
}

