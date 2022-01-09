#ifndef __XMLSEC_MBEDTLS_SYMBOLS_H__
#define __XMLSEC_MBEDTLS_SYMBOLS_H__

#if !defined(IN_XMLSEC) && defined(XMLSEC_CRYPTO_DYNAMIC_LOADING)
#error To disable dynamic loading of xmlsec-crypto libraries undefine XMLSEC_CRYPTO_DYNAMIC_LOADING
#endif /* !defined(IN_XMLSEC) && defined(XMLSEC_CRYPTO_DYNAMIC_LOADING) */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef XMLSEC_CRYPTO_MBEDTLS

/********************************************************************
 *
 * Crypto Init/shutdown
 *
 ********************************************************************/
#define xmlSecCryptoInit                        xmlSecMBedTLSInit
#define xmlSecCryptoShutdown                    xmlSecMBedTLSShutdown

  
#endif /* XMLSEC_CRYPTO_MBEDTLS */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __XMLSEC_MBEDTLS_SYMBOLS_H__ */

#define __XMLSEC_MBEDTLS_CRYPTO_H__
