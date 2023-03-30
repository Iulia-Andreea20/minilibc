// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
	if (size == 0) 
	{
		errno = EINVAL;
		return NULL;
	}

	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	if (ptr == MAP_FAILED) 
	{
		errno = ENOMEM;
		return NULL;
	}

	if (mem_list_add(ptr, size) != 0) 
	{
		munmap(ptr, size);
		errno = ENOMEM;
		return NULL;
	}

	return ptr;
}


void *calloc(size_t nmemb, size_t size)
{

	size_t total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size) 
	{
		errno = EINVAL;
		return NULL;
		void *ptr = malloc(total_size);

		if (ptr != NULL) 
		{
			memset(ptr, 0, total_size);
		}

		return (void*) ptr;
	}
	return (void*) -1;
}


void free(void *ptr) 
{
    struct mem_list *mem = mem_list_find(ptr);

	if (ptr == NULL) 
	{
		return;
	}
    size_t size = mem->len;

    munmap(ptr, size);

    mem_list_del(ptr); 
}


void *realloc(void *ptr, size_t size)
{

	if (size == 0) 
	{
		free(ptr);
		return NULL;
	}

	if (ptr == NULL) 
	{
    	return malloc(size);
	}

	size_t curr_size = mem_list_find(ptr)->len;

	if (size <= curr_size) 
	{
		return ptr;
	}

	void *new_ptr = malloc(size);


	if (new_ptr == NULL) 
	{
		return NULL;
	}


	memcpy(new_ptr, ptr, curr_size);

	free(ptr);

	return new_ptr;
}


void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size) 
	{
		errno = EINVAL;
		return NULL;
	}

	return realloc(ptr, total_size);
}
