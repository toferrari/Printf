#include <stdio.h>
#include "libft.h"
int main()
{
	printf("%lx", 4294967296);
	printf("%s\n", ft_itoa_base64(4294967296, 16));
}
