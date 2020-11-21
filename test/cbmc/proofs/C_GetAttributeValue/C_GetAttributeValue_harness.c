/*
 * corePKCS11 V2.0.0
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

/**
 * @file C_GetAttributeValue_harness.c
 * @brief Implements the proof harness for C_GetAttributeValue function.
 */

#include <stddef.h>
#include "mbedtls/ecp.h"
#include "mbedtls/oid.h"
#include "core_pkcs11.h"

#define EC_D_LENGTH 32
#define EC_PARAMS_LENGTH 10

#define EC_PRIV_KEY_INITIALIZER                                                            \
    {                                                                                      \
        { CKA_CLASS, &xPrivateKeyClass, sizeof( CK_OBJECT_CLASS ) },                       \
        { CKA_KEY_TYPE, &xPrivateKeyType, sizeof( CK_KEY_TYPE ) },                         \
        { CKA_LABEL, pucPrivLabel, ( CK_ULONG ) sizeof( pucPrivLabel ) }, \
        { CKA_TOKEN, &xTrue, sizeof( CK_BBOOL ) },                                         \
        { CKA_SIGN, &xTrue, sizeof( CK_BBOOL ) },                                          \
        { CKA_EC_PARAMS, pxEcPrivParams, EC_PARAMS_LENGTH },                               \
        { CKA_VALUE, pxD, EC_D_LENGTH }                                                    \
    }

void harness()
{
    
    CK_SESSION_HANDLE hSession;
    CK_OBJECT_HANDLE xObject;
    CK_ULONG ulCount;
    CK_KEY_TYPE xPrivateKeyType = CKK_EC;
    CK_OBJECT_CLASS xPrivateKeyClass = CKO_PRIVATE_KEY;
    CK_BBOOL xTrue = CK_TRUE;
    CK_FLAGS xFlags;
    char * pucPrivLabel = "Priv key label";
    /* DER-encoding of an ANSI X9.62 Parameters value */
    CK_BYTE * pxEcPrivParams = ( CK_BYTE * ) ( "\x06\x08" MBEDTLS_OID_EC_GRP_SECP256R1 );
    CK_RV xResult;

    /* Private value D. */
    CK_BYTE pxD[ EC_D_LENGTH ] = { 0 };

    CK_ATTRIBUTE xPrivateKeyTemplate[] = EC_PRIV_KEY_INITIALIZER;
    xResult = C_Initialize( NULL );
    __CPROVER_assume( xResult == CKR_OK );

    xResult = C_OpenSession( 0, xFlags, NULL, 0, &hSession );
    __CPROVER_assume( xResult == CKR_OK );

    xResult = C_CreateObject( hSession,
                                  ( CK_ATTRIBUTE_PTR ) &xPrivateKeyTemplate,
                                  sizeof( xPrivateKeyTemplate ) / sizeof( CK_ATTRIBUTE ),
                                  &xObject );
    __CPROVER_assume( xResult == CKR_OK );

    __CPROVER_assume( ulCount < 10 );
    CK_ATTRIBUTE_PTR pTemplate = malloc( sizeof( CK_ATTRIBUTE ) * ulCount );

  ( void ) C_GetAttributeValue( hSession, xObject, pTemplate, ulCount );
}
