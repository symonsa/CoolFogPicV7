/* 
 * File:   serial_buffer.h
 * Author: antho
 *
 * Created on 3 September 2023, 6:33 AM
 */

#ifndef SERIAL_BUFFER_H
#define	SERIAL_BUFFER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>


#define BUFFER_SIZE_IN 32
#define BUFFER_SIZE_OUT 32

//    typedef struct {
//        unsigned char data[BUFFER_SIZE_IN];
//        unsigned int start;
//        unsigned int length;
//    } SerialBuffer_t_in;

    typedef struct {
        unsigned char data[BUFFER_SIZE_OUT];
        unsigned int start;
        unsigned int length;
    } SerialBuffer_t;

    extern SerialBuffer_t inbound;
    extern SerialBuffer_t outbound;


//    void push_in(SerialBuffer_t_in * buff, unsigned char d);
//    unsigned char pop_in(SerialBuffer_t_in * buff);

    void push(SerialBuffer_t * buff, unsigned char d);
    unsigned char pop(SerialBuffer_t * buff);

    uint8_t is_empty(SerialBuffer_t * buff);

    uint8_t is_full(SerialBuffer_t * buff);
    uint8_t has_data(SerialBuffer_t * buff);
    uint8_t not_full(SerialBuffer_t * buff);


void serial_process_loop(void);
    void ser_int(void);



#ifdef	__cplusplus
}
#endif

#endif	/* SERIAL_BUFFER_H */

