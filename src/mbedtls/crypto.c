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
