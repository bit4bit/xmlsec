/**
 * SECTION:app
 * @Short_description: Application support functions for GCrypt.
 * @Stability: Instable
 *
 */
#include "globals.h"


#include <xmlsec/xmlsec.h>

/**
 * xmlSecMBedTLSAppInit:
 * @config:             the path to GCrypt configuration (unused).
 *
 * General crypto engine initialization. This function is used
 * by XMLSec command line utility and called before
 * @xmlSecInit function.
 *
 * Returns: 0 on success or a negative value otherwise.
 */
int
xmlSecMBedTLSAppInit(const char* config ATTRIBUTE_UNUSED) {
  /* TODO(bit4bit) check features and version */
  return(0);
}

/**
 * xmlSecMBedTLSAppShutdown:
 *
 * General crypto engine shutdown. This function is used
 * by XMLSec command line utility and called after
 * @xmlSecShutdown function.
 *
 * Returns: 0 on success or a negative value otherwise.
 */
int
xmlSecMBedTLSAppShutdown(void) {
  return(0);
}
