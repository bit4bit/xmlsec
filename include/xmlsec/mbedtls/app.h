#ifndef __XMLSEC_MBEDTLS_APP_H__
#define __XMLSEC_MBEDTLS_APP_H__

#include <xmlsec/xmlsec.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

  /********************************************************************
 *
 * Init/shutdown
 *
 ********************************************************************/
XMLSEC_CRYPTO_EXPORT int        xmlSecMBedTLSAppInit                     (const char* config);
XMLSEC_CRYPTO_EXPORT int        xmlSecMBedTLSAppShutdown                 (void);
  
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __XMLSEC_MBEDTLS_APP_H__ */
