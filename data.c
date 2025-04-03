#include <stdint.h>
#include <stdlib.h>

/* Moves memory from source to destination safely */
uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length) {
    if (src == dst || length == 0) return dst;

    if (dst > src && dst < src + length) {  
        // Overlapping case: copy from end to start
        src += length - 1;
        dst += length - 1;
        while (length--) {
            *dst-- = *src--;
        }
    } else {  
        // Non-overlapping case: copy normally
        while (length--) {
            *dst++ = *src++;
        }
    }
    return dst;
}

/* Copies memory from source to destination */
uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length) {
    if (!src || !dst) return NULL;
    while (length--) {
        *dst++ = *src++;
    }
    return dst;
}

/* Sets memory locations to a given value */
uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value) {
    if (!src) return NULL;
    while (length--) {
        *src++ = value;
    }
    return src;
}

/* Zeros out memory locations */
uint8_t *my_memzero(uint8_t *src, size_t length) {
    return my_memset(src, length, 0);
}

/* Reverses the bytes in a given memory location */
uint8_t *my_reverse(uint8_t *src, size_t length) {
    if (!src || length <= 1) return src;

    uint8_t *start = src;
    uint8_t *end = src + length - 1;
    while (start < end) {
        uint8_t temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    return src;
}

/* Allocates memory dynamically */
int32_t *reserve_words(size_t length) {
    return (int32_t *)malloc(length * sizeof(int32_t));
}

/* Frees allocated memory */
void free_words(int32_t *src) {
    free(src);
}
