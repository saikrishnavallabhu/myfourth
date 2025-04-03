#include <stdint.h>

/* Integer to ASCII conversion */
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
    if (base < 2 || base > 16) return 0;  

    uint8_t *start = ptr;
    int is_negative = (data < 0 && base == 10);
    if (is_negative) data = -data;

    do {
        uint8_t remainder = data % base;
        *ptr++ = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        data /= base;
    } while (data);

    if (is_negative) *ptr++ = '-';
    *ptr = '\0';  

    my_reverse(start, ptr - start);
    return ptr - start + 1;  
}

/* ASCII to Integer conversion */
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base) {
    if (!ptr || base < 2 || base > 16) return 0;

    int32_t result = 0;
    int is_negative = (*ptr == '-') ? 1 : 0;
    if (is_negative) ptr++;

    for (uint8_t i = 0; i < digits - is_negative - 1; i++) {
        result *= base;
        if (*ptr >= '0' && *ptr <= '9')
            result += *ptr - '0';
        else if (*ptr >= 'A' && *ptr <= 'F')
            result += *ptr - 'A' + 10;
        ptr++;
    }

    return is_negative ? -result : result;
}
