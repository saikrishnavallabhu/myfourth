#include <stdint.h>
#include <stdio.h>

int8_t test_data1() {
    uint8_t buffer[12];
    int32_t num = -12345;
    uint8_t length = my_itoa(num, buffer, 10);
    int32_t result = my_atoi(buffer, length, 10);

    return (result == num) ? 0 : -1;
}

int8_t test_data2() {
    uint8_t buffer[12];
    int32_t num = 0xFF;
    uint8_t length = my_itoa(num, buffer, 16);
    int32_t result = my_atoi(buffer, length, 16);

    return (result == num) ? 0 : -1;
}

int8_t test_memmove1() {
    uint8_t src[10] = "abcdefghi";
    uint8_t dst[10];
    my_memmove(src, dst, 9);
    return (dst[0] == 'a' && dst[8] == 'i') ? 0 : -1;
}

int8_t test_memmove2() {
    uint8_t buffer[] = "HelloWorld";
    my_memmove(buffer, buffer + 2, 8);
    return (buffer[2] == 'H' && buffer[3] == 'e') ? 0 : -1;
}

int8_t test_memmove3() {
    uint8_t buffer[] = "HelloWorld";
    my_memmove(buffer + 2, buffer, 8);
    return (buffer[0] == 'l' && buffer[1] == 'o') ? 0 : -1;
}

int8_t test_memcopy() {
    uint8_t src[10] = "ABCDEFGHI";
    uint8_t dst[10];
    my_memcopy(src, dst, 9);
    return (dst[0] == 'A' && dst[8] == 'I') ? 0 : -1;
}

int8_t test_memset() {
    uint8_t buffer[10];
    my_memset(buffer, 10, 'X');
    return (buffer[0] == 'X' && buffer[9] == 'X') ? 0 : -1;
}

int8_t test_reverse() {
    uint8_t buffer[] = "12345";
    my_reverse(buffer, 5);
    return (buffer[0] == '5' && buffer[4] == '1') ? 0 : -1;
}

int8_t course1() {
    return test_data1() + test_data2() + test_memmove1() +
           test_memmove2() + test_memmove3() + test_memcopy() +
           test_memset() + test_reverse();
}
