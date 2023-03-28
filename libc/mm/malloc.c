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
	/* TODO: Implement malloc(). */
	if (size == 0) {
		errno = EINVAL;
		return NULL;
}
void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

/* Check if mmap failed */
if (ptr == MAP_FAILED) {
    errno = ENOMEM;
    return NULL;
}

/* Add the allocated memory to the memory list */
if (mem_list_add(ptr, size) != 0) {
    munmap(ptr, size);
    errno = ENOMEM;
    return NULL;
}

/* Return the allocated memory */
return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size) {
		errno = EINVAL;
		return NULL;
	void *ptr = malloc(total_size);

/* Clear the allocated memory */
if (ptr != NULL) {
    memset(ptr, 0, total_size);
}

/* Return the allocated memory */
return ptr;
}
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
	return;
}
	if (mem_list_del(ptr) != 0) {
    /* Error occurred */
    errno = EINVAL;
    return;
}

/* Free the memory */
munmap(ptr, mem_list_find(ptr)->len);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0) {
		free(ptr);
		return NULL;
	}

	if (ptr == NULL) {
    return malloc(size);
}

	/* Get the current size of the memory block */
	size_t curr_size = mem_list_find(ptr)->len;

	/* Check if the new size is smaller than the current size */
	if (size <= curr_size) {
		return ptr;
	}

	/* Allocate memory for the new block */
	void *new_ptr = malloc(size);

	/* Check if malloc failed */
	if (new_ptr == NULL) {
		return NULL;
	}

	/* Copy the contents of the old block to the new block */
	memcpy(new_ptr, ptr, curr_size);

	/* Free the old block */
	free(ptr);

	/* Return the new block */
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size) {
		errno = EINVAL;
		return NULL;
	}

	return realloc(ptr, total_size);
}
