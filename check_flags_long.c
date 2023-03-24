int check_flags(const char *str, int i)
{
    int index = i + 1;
    if (str[i] == '0')
    {
        g_bonus.is_zero = 1;
        index++;
    }
    while (str[index])
    {
        if (ft_strchr("cspdiuxX%", str[index]))
            break;
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
        index++;
    }
    return (index - 1);
}
