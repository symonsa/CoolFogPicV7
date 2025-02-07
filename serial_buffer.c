#include <xc.h>
#include "serial_buffer.h"

/**
 * push - pushes the char to the end of the array if
 * we are not full
 */

void
push(SerialBuffer_t * buff, unsigned char d) {


    // disable interupts so that we don't over write 
    GIE = 0;
    buff->data[(buff->start + buff->length) % BUFFER_SIZE_OUT] = d;
    buff->length++;
    GIE = 1;
}


/**
 * pop off the start of the array if we are not empty
 */


unsigned char
pop(SerialBuffer_t * buff) {
    unsigned char d;



    if (buff->length == 0) {
        // empty
        return 0;
    }
    // disable interupts so that we don't over write 
    GIE = 0;
    d = buff->data[buff->start];
    buff->length--;
    buff->start = (buff->start + 1) % BUFFER_SIZE_OUT;
    GIE = 1;

    return d;
}

uint8_t
is_empty(SerialBuffer_t * buff) {
    return !buff->length;
}
uint8_t
has_data(SerialBuffer_t * buff) {
    return buff->length;
}

uint8_t
is_full(SerialBuffer_t * buff) {
    return buff->length >= BUFFER_SIZE_OUT;
}
uint8_t
not_full(SerialBuffer_t * buff) {
    return buff->length < BUFFER_SIZE_OUT;
}



