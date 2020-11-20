# Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0

HARNESS_ENTRY = harness
HARNESS_FILE = C_CreateObject_harness

# This should be a unique identifier for this proof, and will appear on the
# Litani dashboard. It can be human-readable and contain spaces if you wish.
PROOF_UID = C_CreateObject

# CERT_TEMPLATE_SIZE is bounded to reduce proof run time. A user can have an
# arbitrarily large template size, but our library uses only 6. Memory safety
# can be proven within a reasonable bound past what our stack cares about. It
# adds no value to the proof to input the largest possible template of the
# maximum CK_ULONG size.
CERT_TEMPLATE_SIZE=10
DEFINES += -DCERT_TEMPLATE_SIZE=$(CERT_TEMPLATE_SIZE)
INCLUDES += -I$(SRCDIR)/3rdparty/mbedtls/include
INCLUDES += -I$(SRCDIR)/3rdparty/mbedtls_utils

REMOVE_FUNCTION_BODY +=
UNWINDSET += prvCreateCertificate.0:$(CERT_TEMPLATE_SIZE)
UNWINDSET += prvGetKeyType.0:$(CERT_TEMPLATE_SIZE)
UNWINDSET += prvGetObjectClass.0:$(CERT_TEMPLATE_SIZE)

PROOF_SOURCES += $(PROOFDIR)/$(HARNESS_FILE).c
PROOF_SOURCES += $(SRCDIR)/test/cbmc/stubs/mbedtls_stubs.c
PROOF_SOURCES += $(SRCDIR)/test/cbmc/stubs/core_pkcs11_pal_stubs.c
PROJECT_SOURCES += $(SRCDIR)/source/portable/mbedtls/core_pkcs11_mbedtls.c

include ../Makefile.common
