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

t_array *add_bignum(t_array *num1, int len1, t_array *num2, int len2, int *result_size)
{
	t_array *result;
	int		carry;
	int		fac1;
	int		fac2;
	int		i;

	if (!(result = init_bignum("", len1)))
		return (0);
	carry = 0;
	i = 0;
	len1--;
	len2--;
	while (len1 >= 0 || len2 >= 0 || carry > 0)
	{
		fac1 = (len1 < 0) ? 0 : num1->str[i] - '0';
		fac2 = (len2 < 0) ? 0 : num2->str[i] - '0';
		fac1 += fac2 + carry;
		//arr_insert(num1, (fac1 % 10) + '0');
		arr_insert(result, (fac1 % 10) + '0');
		//print_bignum(num1, i);
		print_bignum(result, i);
		carry = fac1 / 10;
		i++;
		len1--;
		len2--;
	}
	print_bignum(result, i);
	*result_size = i;
	return (result);
}

// TODO: pytong tuodr this bitch
int main()
{
   	t_array *result;
	int 	result_size;
	char *str1 = "3333333333333333";
	char *str2 = "6555555555555555555";
	int len1 = ft_strlen(str1);
	int len2 = ft_strlen(str2);
	//char result[200];
	int carry = 0;
	int fac1;
	int fac2;
	int i = 0;

	// TEST BIGNUM FUNCS
	// TODO: protect these init calls
	t_array *num1 = init_bignum(str1, len1);
	printf("num1->str: %s\n", num1->str);
	//print_bignum(num1, len1);
	t_array *num2 = init_bignum(str2, len2);
	printf("num2->str: %s\n", num2->str);
	//print_bignum(num2, len2);
	// modifies num1
	/*if (!(result = add_bignum(num1, len1, num2, len2, &result_size)))
	{
		ft_putendl("malloc error");
		return (1);
	}*/
	
	add_bignum(num1, len1, num2, len2, &result_size);
	//print_bignum(num1, result_size);
	
	/*len1--;
	len2--;
	while (len1 >= 0 || len2 >= 0 || carry > 0)
	{
		fac1 = (len1 < 0) ? 0 : str1[len1] - '0';
		fac2 = (len2 < 0) ? 0 : str2[len2] - '0';
		fac1 += fac2 + carry;
		result[i] = (fac1 % 10) + '0';
		carry = fac1 / 10;
		i++;
		len1--;
		len2--;
	}
	while (--i >= 0)
	{
		printf("%c", result[i]);
	}
	printf("\n");*/
	return 0;
}
