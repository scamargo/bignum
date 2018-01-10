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

char *add_bignum(char *num1, int len1, char *num2, int len2)
{
	char	*result;
	t_array *char_arr;
	int		carry;
	int		fac1;
	int		fac2;
	int		i;

	if (!(char_arr = init_bignum("", len1)))
		return (0);
	carry = 0;
	i = 0;
	len1--;
	len2--;
	while (len1 >= 0 || len2 >= 0 || carry > 0)
	{
		fac1 = (len1 < 0) ? 0 : num1[len1] - '0';
		fac2 = (len2 < 0) ? 0 : num2[len2] - '0';
		fac1 += fac2 + carry;
		arr_insert(char_arr, (fac1 % 10) + '0');
		carry = fac1 / 10;
		i++;
		len1--;
		len2--;
	}
	arr_insert(char_arr, '\0');
	ft_strrev(char_arr->str);
	result = char_arr->str;
	free(char_arr);
	return (result);
}

// TODO: pytong tuodr this bitch
int main()
{
   	char *result;
	char *str1 = "3333333333333333";
	char *str2 = "6555555555555555555";
	int len1 = ft_strlen(str1);
	int len2 = ft_strlen(str2);

	result = add_bignum(str1, len1, str2, len2);
	ft_putendl(result);
	
	return 0;
}
