#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

const char	*ft_write_text(const char *letrucaprint)
{
	int 	i;
	char	*s;
	
	i = 0;
	s = (char *)letrucaprint;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '%')
	{
		ft_putchar(s[i]);
		i++;
	}
	return ((const char *) s + i);
}

// ft_search_data_type()


int	ft_printf(const char *letrucaprint, ...)
{
	
	va_list args;
	int		i;
	
	va_start(args, type);
	i = 0;
	while (*letrucaprint)
	{
		if(*letrucaprint == '%')
			// ft_search_data_type();
		else if(*letrucaprint != '%')
			letrucaprint = ft_write_text(letrucaprint);
		else
		{
			write (1, "(null)", 6);
			va_end (args);
		}
	}
}
