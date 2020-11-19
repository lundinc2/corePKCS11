# Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0

HARNESS_ENTRY = harness
HARNESS_FILE = C_CreateObject_harness

# This should be a unique identifier for this proof, and will appear on the
# Litani dashboard. It can be human-readable and contain spaces if you wish.
PROOF_UID = C_CreateObject

CERT_TEMPLATE_SIZE=6
DEFINES += -DCERT_TEMPLATE_SIZE=$(CERT_TEMPLATE_SIZE)
INCLUDES += -I$(SRCDIR)/3rdparty/mbedtls/include
INCLUDES += -I$(SRCDIR)/3rdparty/mbedtls_utils

REMOVE_FUNCTION_BODY +=
UNWINDSET += prvCreateCertificate.0:$(CERT_TEMPLATE_SIZE)

# Stopped error'ing
#UNWINDSET += prvGetKeyType.0:$(CERT_TEMPLATE_SIZE)
#UNWINDSET += prvGetObjectClass.0:$(CERT_TEMPLATE_SIZE)

PROOF_SOURCES += $(PROOFDIR)/$(HARNESS_FILE).c
PROOF_SOURCES += $(SRCDIR)/test/cbmc/stubs/mbedtls_stubs.c
PROOF_SOURCES += $(SRCDIR)/test/cbmc/stubs/core_pkcs11_pal_stubs.c
PROJECT_SOURCES += $(SRCDIR)/source/portable/mbedtls/core_pkcs11_mbedtls.c

include ../Makefile.common
