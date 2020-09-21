/*
 * FreeRTOS PKCS #11 V1.1.0
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/* This is a dummy file that contains mutex stubs. This is needed in order to use
 * CMock to generate the necessary mocks for the mutexes used by the PKCS #11
 * mbed TLS implementation.
 */
#ifndef DUMMY_MUTEX_H_H
#define DUMMY_MUTEX_H_H

//typedef struct mbedtls_threading_mutex_t
//{
//    int empty;
//} mbedtls_threading_mutex_t;


//void mbedtls_mutex_init( mbedtls_threading_mutex_t * mutex ); 
//void mbedtls_mutex_free( mbedtls_threading_mutex_t * mutex ); 
//int mbedtls_mutex_lock( mbedtls_threading_mutex_t * mutex ); 
//int mbedtls_mutex_unlock( mbedtls_threading_mutex_t * mutex ); 
void *fake_malloc(size_t size);
void *fake_calloc(size_t nitems, size_t size);
void fake_free(void *ptr);

//void mutex_init( mbedtls_threading_mutex_t * mutex ); 
//void mutex_free( mbedtls_threading_mutex_t * mutex ); 
//int mutex_lock( mbedtls_threading_mutex_t * mutex ); 
//int mutex_unlock( mbedtls_threading_mutex_t * mutex ); 
//
//mbedtls_mutex_init = &mutex_init;
//mbedtls_mutex_free = &mutex_free;
//mbedtls_mutex_lock = &mutex_lock;
//mbedtls_mutex_unlock = &mutex_unlock;

#endif

