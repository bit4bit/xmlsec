NULL =

EXTRA_DIST = \
	README \
	$(NULL)

lib_LTLIBRARIES = \
	libxmlsec1-mbedtls.la \
	$(NULL)

libxmlsec1_mbedtls_la_CPPFLAGS = \
	-DPACKAGE=\"@PACKAGE@\" \
	-I../../include \
	-I$(top_srcdir)/include \
	$(XMLSEC_DEFINES) \
	$(MBEDTLS_CFLAGS) \
	$(LIBXSLT_CFLAGS) \
	$(LIBXML_CFLAGS) \
	$(NULL)

libxmlsec1_mbedtls_la_SOURCES =\
	globals.h \
	crypto.c \
	app.c \
	x509.c \
	$(NULL)

# xmlsec-mbedtls library requires xmlsec-gcrypt
libxmlsec1_mbedtls_la_LIBADD = \
	$(MBEDTLS_LIBS) \
	$(LIBXSLT_LIBS) \
	$(LIBXML_LIBS) \
	../libxmlsec1.la \
	$(NULL)

libxmlsec1_mbedtls_la_DEPENDENCIES = \
	$(NULL)

libxmlsec1_mbedtls_la_LDFLAGS = \
	@XMLSEC_CRYPTO_EXTRA_LDFLAGS@ \
	-version-info @XMLSEC_VERSION_INFO@ \
	$(NULL)
