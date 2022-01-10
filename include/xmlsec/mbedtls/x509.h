#ifndef __XMLSEC_MBEDTLS_X509_H__
#define __XMLSEC_MBEDTLS_X509_H__

#ifndef XMLSEC_NO_X509

#include <xmlsec/xmlsec.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * xmlSecMBedTLSX509StoreId:
 *
 * The mbedtls X509 store klass.
 */
#define xmlSecMBedTLSX509StoreId \
        xmlSecMBedTLSX509StoreGetKlass()
XMLSEC_CRYPTO_EXPORT xmlSecKeyDataStoreId xmlSecMBedTLSX509StoreGetKlass(void);
  
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* XMLSEC_NO_X509 */

#endif /* __XMLSEC_MBEDTLS_X509_H__ */
