/**
 * SECTION:crypto
 * @Short_description: Crypto transforms implementation for mbedtls.
 * @Stability: Instable
 *
 */

#include "globals.h"

#include <string.h>

#include <xmlsec/xmlsec.h>
#include <xmlsec/errors.h>
#include <xmlsec/dl.h>
#include <xmlsec/private.h>

#include <xmlsec/mbedtls/app.h>
#include <xmlsec/mbedtls/crypto.h>
#include <xmlsec/mbedtls/x509.h>

static xmlSecCryptoDLFunctionsPtr gXmlSecMBedTLSFunctions = NULL;

/**
 * xmlSecCryptoGetFunctions_mbedtls:
 *
 * Gets the pointer to xmlsec-mbedtls functions table.
 *
 * Returns: the xmlsec-mbedtls functions table or NULL if an error occurs.
 */
xmlSecCryptoDLFunctionsPtr
xmlSecCryptoGetFunctions_mbedtls(void) {
    static xmlSecCryptoDLFunctions functions;

    if (gXmlSecMBedTLSFunctions != NULL) {
      return(gXmlSecMBedTLSFunctions);
    }

    memset(&functions, 0, sizeof(functions));
    gXmlSecMBedTLSFunctions = &functions;

    /********************************************************************
     *
     * Crypto Init/shutdown
     *
     ********************************************************************/
    gXmlSecMBedTLSFunctions->cryptoInit                  = xmlSecMBedTLSInit;
    gXmlSecMBedTLSFunctions->cryptoShutdown              = xmlSecMBedTLSShutdown;
    gXmlSecMBedTLSFunctions->cryptoKeysMngrInit = xmlSecMBedTLSKeysMngrInit;

        /********************************************************************
     *
     * High level routines form xmlsec command line utility
     *
     ********************************************************************/
    gXmlSecMBedTLSFunctions->cryptoAppInit                       = xmlSecMBedTLSAppInit;
    gXmlSecMBedTLSFunctions->cryptoAppShutdown                   = xmlSecMBedTLSAppShutdown;

    return(gXmlSecMBedTLSFunctions);
}


/**
 * xmlSecMBedTLSInit:
 *
 * XMLSec library specific crypto engine initialization.
 *
 * Returns: 0 on success or a negative value otherwise.
 */
int
xmlSecMBedTLSInit (void)  {
    /* Check loaded xmlsec library version */
    if(xmlSecCheckVersionExact() != 1) {
        xmlSecInternalError("xmlSecCheckVersionExact", NULL);
        return(-1);
    }

    /* register our klasses */
    if(xmlSecCryptoDLFunctionsRegisterKeyDataAndTransforms(xmlSecCryptoGetFunctions_mbedtls()) < 0) {
        xmlSecInternalError("xmlSecCryptoDLFunctionsRegisterKeyDataAndTransforms", NULL);
        return(-1);
    }

    return(0);
}

/**
 * xmlSecMBedTLSShutdown:
 *
 * XMLSec library specific crypto engine shutdown.
 *
 * Returns: 0 on success or a negative value otherwise.
 */
int
xmlSecMBedTLSShutdown(void) {
    return(0);
}


/**
 * xmlSecMBedTLSKeysMngrInit:
 * @mngr:               the pointer to keys manager.
 *
 * Adds MBedTLS specific key data stores in keys manager.
 *
 * Returns: 0 on success or a negative value otherwise.
 */
int
xmlSecMBedTLSKeysMngrInit(xmlSecKeysMngrPtr mngr) {
    int ret;

    xmlSecAssert2(mngr != NULL, -1);

#ifndef XMLSEC_NO_X509
    /* create x509 store if needed */
    if(xmlSecKeysMngrGetDataStore(mngr, xmlSecMBedTLSX509StoreId) == NULL) {
        xmlSecKeyDataStorePtr x509Store;

        x509Store = xmlSecKeyDataStoreCreate(xmlSecMBedTLSX509StoreId);
        if(x509Store == NULL) {
            xmlSecInternalError("xmlSecKeyDataStoreCreate(xmlSecOpenSSLX509StoreId)", NULL);
            return(-1);
        }

        ret = xmlSecKeysMngrAdoptDataStore(mngr, x509Store);
        if(ret < 0) {
            xmlSecInternalError("xmlSecKeysMngrAdoptDataStore", NULL);
            xmlSecKeyDataStoreDestroy(x509Store);
            return(-1);
        }
    }
#endif /* XMLSEC_NO_X509 */
    return(0);
}
