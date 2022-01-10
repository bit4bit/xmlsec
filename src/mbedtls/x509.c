/**
 * SECTION:x509
 * @Short_description: X509 certificates implementation for OpenSSL.
 * @Stability: Instable
 *
 */


#include "globals.h"

#ifndef XMLSEC_NO_X509

#include <xmlsec/xmlsec.h>
#include <xmlsec/keys.h>
#include <xmlsec/errors.h>

#include <xmlsec/mbedtls/crypto.h>
#include <xmlsec/mbedtls/x509.h>

typedef struct _xmlSecMBedTLSX509StoreCtx xmlSecMBedTLSX509StoreCtx, *xmlSecMBedTLSX509StoreCtxPtr;
struct _xmlSecMBedTLSX509StoreCtx {
    /* TODO(bit4bit) implement */
};


#define xmlSecMBedTLSX509StoreGetCtx(store) \
    ((xmlSecMBedTLSX509StoreCtxPtr)(((xmlSecByte*)(store)) + sizeof(xmlSecKeyDataStoreKlass)))
#define xmlSecMBedTLSX509StoreSize \
    (sizeof(xmlSecKeyDataStoreKlass) + sizeof(xmlSecMBedTLSX509StoreCtx))

static int              xmlSecMBedTLSX509StoreInitialize        (xmlSecKeyDataStorePtr store);
static void             xmlSecMBedTLSX509StoreFinalize          (xmlSecKeyDataStorePtr store);

static xmlSecKeyDataStoreKlass xmlSecMBedTLSX509StoreKlass = {
    sizeof(xmlSecKeyDataStoreKlass),
    xmlSecMBedTLSX509StoreSize,

    /* data */
    xmlSecNameX509Store,                        /* const xmlChar* name; */

    /* constructors/destructor */
    xmlSecMBedTLSX509StoreInitialize,           /* xmlSecKeyDataStoreInitializeMethod initialize; */
    xmlSecMBedTLSX509StoreFinalize,             /* xmlSecKeyDataStoreFinalizeMethod finalize; */

    /* reserved for the future */
    NULL,                                       /* void* reserved0; */
    NULL,                                       /* void* reserved1; */
};

xmlSecKeyDataStoreId
xmlSecMBedTLSX509StoreGetKlass(void) {
    return(&xmlSecMBedTLSX509StoreKlass);
}

static int
xmlSecMBedTLSX509StoreInitialize(xmlSecKeyDataStorePtr store) {
    // assert con return
    xmlSecAssert2(xmlSecKeyDataStoreCheckId(store, xmlSecMBedTLSX509StoreId), -1);

    return(0);
}

static void
xmlSecMBedTLSX509StoreFinalize(xmlSecKeyDataStorePtr store) {
    xmlSecAssert(xmlSecKeyDataStoreCheckId(store, xmlSecMBedTLSX509StoreId));
}

#endif /* XMLSEC_NO_X509 */
