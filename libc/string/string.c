// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* DONE */
	char *ptr = destination;
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;

}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* DONE */
char *ptr = destination;
    size_t i;
    for (i = 0; i < len && *source != '\0'; i++)
    {
        *destination = *source;
        destination++;
        source++;
    }
    for (; i < len; i++)
    {
        *destination = '\0';
        destination++;
    }
    return ptr;
}

char *strcat(char *destination, const char *source)
{
	/* DONE */
	char *ptr = destination;
	while (*destination != '\0')
	{
		destination++;
	}
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return ptr;

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* DONE */
	char *ptr = destination;
    while (*destination != '\0')
    {
        destination++;
    }
    size_t i;
    for (i = 0; i < len && *source != '\0'; i++)
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}

int strcmp(const char *str1, const char *str2)
{
	/* DONE */
	while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            break;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* DONE */
	size_t i;
    for (i = 0; i < len && *str1 != '\0' && *str2 != '\0'; i++)
    {
        if (*str1 != *str2)
        {
            break;
        }
        str1++;
        str2++;
    }
    if (i == len)
    {
        return 0;
    }
    else
    {
        return *str1 - *str2;
    }
}

size_t strlen(const char *str)
{
	size_t i = 0;

	 size_t len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

char *strchr(const char *str, int c)
{
	/* DONE */
	while (*str != '\0')
    {
        if (*str == c)
        {
            return (char *) str;
        }
        str++;
    }
    if (c == '\0')
    {
        return (char *) str;
    }
}

char *strrchr(const char *str, int c)
{
	/* DONE */
	const char *last = NULL;
    while (*str != '\0')
    {
        if (*str == c)
        {
            last = str;
        }
        str++;
    }
    if (last != NULL)
    {
        return (char *) last;
    }
    if (c == '\0')
    {
        return (char *) str;
    }
}

char *strstr(const char *haystack, const char *needle)
{
	/* DONE */
	size_t needle_len = strlen(needle);
    if (!needle_len) return (char*) haystack;
    for (; (haystack = strchr(haystack, *needle)) != NULL; haystack++)
        if (!strncmp(haystack, needle, needle_len)) return (char*) haystack;
    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	//* DONE */
	size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);
    if (!needle_len) return (char*) haystack + haystack_len;
    if (needle_len > haystack_len) return NULL;
    const char *end = haystack + haystack_len - needle_len;
    for (; end >= haystack; end--)
        if (!strncmp(end, needle, needle_len)) return (char*) end;
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* DONE */
	char *dst = (char*) destination;
    const char *src = (const char*) source;
    while (num--) *dst++ = *src++;
    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* DONE */
	char *dst = (char *)destination;
    const char *src = (const char *)source;
    
    if (src < dst) {
        // If the source and destination memory areas overlap and
        // source starts before destination, then copy the data
        // in reverse order to avoid overwriting the data
        for (size_t i = num; i > 0; i--) {
            dst[i - 1] = src[i - 1];
        }
    } else {
        // Otherwise, copy the data in the normal order
        for (size_t i = 0; i < num; i++) {
            dst[i] = src[i];
        }
    }
    
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* DONE */
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;
    
    for (size_t i = 0; i < num; i++) {
        if (p1[i] != p2[i]) {
            // If the two memory blocks differ at this byte, return the difference
            return p1[i] - p2[i];
        }
    }
    
    // Otherwise, the memory blocks are equal
    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* DONE */
	unsigned char *p = (unsigned char *)source;
    unsigned char val = (unsigned char)value;
    
    for (size_t i = 0; i < num; i++) {
        p[i] = val;
    }
    
    return source;
}
