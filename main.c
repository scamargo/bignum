#include <stdio.h>
#include "libft.h"

void	print_bignum(t_array *num, int size)
{
	while (--size >= 0)
	{
		ft_putchar(num->str[size]);
	}
	ft_putchar('\n');
}


t_array	*init_bignum(char *str, int size)
{
	t_array *num;
	int		i;
	
	if (!(num = arr_init(size)))
		return (NULL);
	i = 0;
	while (--size >= 0)
	{
		num->str[size] = str[i++];
	}
	return (num);
}

int	second_is_bigger(char *num1, int len1, char *num2, int len2)
{
	if (len1 != len2)
		return (len1 > len2);
	while (--len1 >= 0)
	{
		if (num1[len1] != num2[len1])
			return (num1[len1] > num2[len1]);
	}
	return (0);
}

void	trim_trailing_zeroes(char *num)
{
	int len;
	int is_neg;

	len = ft_strlen(num);
	is_neg = (num[len - 1] == '-') ? 1 : 0;
	while (--len >= 0)
	{
		if (num[len] != '0' && num[len] != '-')
		{
			if (is_neg)
				num[++len] = '-';
			break;
		}
	}
	if (len < 0)
		++len;
	num[++len] = '\0';
}
	
char *subtract_bignum(char *num1, int len1, char *num2, int len2)
{
	char	*result;
	t_array *char_arr;
	char	*temp;
	int		is_second_bigger;
	int		fac1;
	int		fac2;
	
	if (!(char_arr = init_bignum("", len1)))
		return (0);
	if ((is_second_bigger = second_is_bigger(num2, len2, num1, len1)))
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
		fac1 = len1;
		len1 = len2;
		len2 = fac1;
	}
	//SUBTRACT
	len1--;
	len2--;
	while (len1 >= 0 || len2 >= 0)
	{
		fac1 = (len1 < 0) ? 0 : num1[len1] - '0';
		//printf("fac1: %d\n", fac1);
		fac2 = (len2 < 0) ? 0 : num2[len2] - '0';
		//printf("fac2: %d\n", fac2);
		fac1 -= fac2;
		arr_insert(char_arr, fac1 + '0');
		len1--;
		len2--;
	}
	//END SUBTRACT
	if (is_second_bigger)
		arr_insert(char_arr, '-');
	arr_insert(char_arr, '\0');
	// TODO: trim trailing zeroes
	trim_trailing_zeroes(char_arr->str);
	ft_strrev(char_arr->str);
	result = char_arr->str;
	free(char_arr);
	return (result);
}

char *add_bignum(char *num1, int len1, char *num2, int len2)
{
	char	*result;
	t_array *char_arr;
	int		carry;
	int		fac1;
	int		fac2;

	if (!(char_arr = init_bignum("", len1)))
		return (0);
	carry = 0;
	len1--;
	len2--;
	while (len1 >= 0 || len2 >= 0 || carry > 0)
	{
		fac1 = (len1 < 0) ? 0 : num1[len1] - '0';
		fac2 = (len2 < 0) ? 0 : num2[len2] - '0';
		fac1 += fac2 + carry;
		arr_insert(char_arr, (fac1 % 10) + '0');
		carry = fac1 / 10;
		len1--;
		len2--;
	}
	arr_insert(char_arr, '\0');
	ft_strrev(char_arr->str);
	result = char_arr->str;
	free(char_arr);
	return (result);
}

int main(int ac, char **av)
{
   	char *result;
	char *str1 = av[1];
	char *str2 = av[2];
	int len1 = ft_strlen(str1);
	int len2 = ft_strlen(str2);

	result = subtract_bignum(str1, len1, str2, len2);
	ft_putendl(result);
	
	return 0;
}
