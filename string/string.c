// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>


char *strcpy(char *destination, const char *source)
{
    char *tmp = destination;

    while ((*destination++ = *source++) != '\0')
    {
        ;
    }

    return tmp;
}


char *strncpy(char *destination, const char *source, size_t len)
{
    char *tmp = destination;

    while (len)
    {
        if ((*tmp = *source) != 0)
        {
            source++;
        }
        tmp++;
        len--;
    }

    return destination;
}


char *strcat(char *destination, const char *source)
{
    char *tmp = destination;

    while (*destination)
    {
        destination++;
    }

    while ((*destination++ = *source++) != '\0')
    {
        ;
    }

    return tmp;
}


char *strncat(char *destination, const char *source, size_t len)
{
    char *tmp = destination;

    if (len)
    {
        while (*destination)
        {
            destination++;
        }

        while ((*destination++ = *source++) != 0)
        {
            if (--len == 0)
            {
                *destination = '\0';
                break;
            }
        }
    }

    return tmp;
}


int strcmp(const char *str1, const char *str2)
{
    unsigned char c1, c2;

    while (1)
    {
        c1 = *str1++;
        c2 = *str2++;

        if (c1 != c2)
        {
            return c1 < c2 ? -1 : 1;
        }

        if (!c1)
        {
            break;
        }
    }

    return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
    unsigned char c1, c2;

    while (len)
    {
        c1 = *str1++;
        c2 = *str2++;

        if (c1 != c2)
        {
            return c1 < c2 ? -1 : 1;
        }

        if (!c1)
        {
            break;
        }

        len--;
    }

    return 0;
}


size_t strlen(const char *str)
{
    const char *sc;

    for (sc = str; *sc != '\0'; ++sc)
    {
        ;
    }

    return sc - str;
}


char *strchr(const char *str, int c)
{
    for (; *str != (char)c; ++str)
    {
        if (*str == '\0')
        {
            return NULL;
        }
    }

    return (char *)str;
}


char *strrchr(const char *str, int c)
{
    const char *last = NULL;

    do {
        if (*str == (char)c)
        {
            last = str;
        }
    } while (*str++);

    return (char *)last;
}


char *strstr(const char *haystack, const char *needle)
{
	size_t l1, l2;

	l2 = strlen(needle);
	if (!l2) {
		return (char *)haystack;
	}

	l1 = strlen(haystack);

	while (l1 >= l2) 
    {
		l1--;

		if (!memcmp(haystack, needle, l2)) 
        {
			return (char *)haystack;
		}

		haystack++;
	}

	return NULL;
}


char* strrstr(const char* haystack, const char* needle)
{
    char* result = NULL;

    if (needle[0] == '\0') 
    {
        return (char*) haystack + strlen(haystack);
    }

    while (1) 
    {
        char* p = strstr(haystack, needle);
        if (!p) 
        {
            return result;
        }

        result = p;
        haystack = p + 1;
    }
}


void *memcpy(void *destination, const void *source, size_t num)
{
	char *tmp = destination;
	const char *s = source;

	while (num--)
    {
        *tmp++ = *s++;
    }
		
	return destination;
}


void *memmove(void *destination, const void *source, size_t num)
{
	char *tmp;
	const char *s;

	if (destination<= source) 
    {
        tmp = destination;
		s = source;
		while (num--)
        {
            *tmp++ = *s++;
        }
	} 
    else 
    {
		tmp = destination;
		tmp += num;
		s = source;
		s += num;

		while (num--)
        {
            *--tmp = *--s;
        }
			
	}
	return destination;
}


int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char *su1, *su2;
	int res = 0;

    #ifdef CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS

        if (num >= sizeof(unsigned long)) 
        {
            const unsigned long *u1 = ptr1;
            const unsigned long *u2 = ptr2;

            do {
                if (get_unaligned(u1) != get_unaligned(u2))
                {
                    break;
                }
                u1++;
                u2++;
                num -= sizeof(unsigned long);

            } while (num >= sizeof(unsigned long));

            ptr1 = u1;
            ptr2 = u2;
        }

    #endif

	for (su1 = ptr1, su2 = ptr2; 0 < num; ++su1, ++su2, num--)
    {
        if ((res = *su1 - *su2) != 0)
        {
            break;
        }

    }

	return res;
}


void *memset(void *source, int value, size_t num)
{
	char *xs = source;

	while (num--)
    {
        *xs++ = value;
    }
		
	return source;
}
