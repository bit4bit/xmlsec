#ifndef __XMLSEC_MBEDTLS_CRYPTO_H__
#define __XMLSEC_MBEDTLS_CRYPTO_H__


#include <xmlsec/dl.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

XMLSEC_CRYPTO_EXPORT xmlSecCryptoDLFunctionsPtr xmlSecCryptoGetFunctions_mbedtls(void);

/********************************************************************
 *
 * Init shutdown
 *
 ********************************************************************/
XMLSEC_CRYPTO_EXPORT int                xmlSecMBedTLSInit                (void);
XMLSEC_CRYPTO_EXPORT int                xmlSecMBedTLSShutdown            (void);

  
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __XMLSEC_MBEDTLS_CRYPTO_H__ */

#define __XMLSEC_MBEDTLS_CRYPTO_H__
