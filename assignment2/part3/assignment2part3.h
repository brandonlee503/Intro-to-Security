#include <openssl/evp.h>
#include <string.h>

EVP_MD_CTX *EVP_MD_CTX_create(void);
int EVP_MD_CTX_reset(EVP_MD_CTX *ctx);
void EVP_MD_CTX_destroy(EVP_MD_CTX *ctx);

int EVP_DigestInit_ex(EVP_MD_CTX *ctx, const EVP_MD *type, ENGINE *impl);
int EVP_DigestUpdate(EVP_MD_CTX *ctx, const void *d, size_t cnt);
int EVP_DigestFinal_ex(EVP_MD_CTX *ctx, unsigned char *md,
    unsigned int *s);

// int EVP_MD_CTX_copy_ex(EVP_MD_CTX *out, const EVP_MD_CTX *in);

int EVP_DigestInit(EVP_MD_CTX *ctx, const EVP_MD *type);
int EVP_DigestFinal(EVP_MD_CTX *ctx, unsigned char *md,
    unsigned int *s);

int EVP_MD_CTX_copy1(EVP_MD_CTX *out, EVP_MD_CTX *in);

int EVP_MD_type(const EVP_MD *md);
int EVP_MD_pkey_type(const EVP_MD *md);
int EVP_MD_size(const EVP_MD *md);
int EVP_MD_block_size(const EVP_MD *md);

const EVP_MD *EVP_MD_CTX_md(const EVP_MD_CTX *ctx);
int EVP_MD_CTX_size1(const EVP_MD *ctx);
int EVP_MD_CTX_block_size1(const EVP_MD *ctx);
int EVP_MD_CTX_type1(const EVP_MD *ctx);

const EVP_MD *EVP_md_null(void);
const EVP_MD *EVP_md2(void);
const EVP_MD *EVP_md5(void);
const EVP_MD *EVP_sha1(void);
const EVP_MD *EVP_mdc2(void);
const EVP_MD *EVP_ripemd160(void);
const EVP_MD *EVP_blake2b_512(void);
const EVP_MD *EVP_blake2s_256(void);

const EVP_MD *EVP_sha224(void);
const EVP_MD *EVP_sha256(void);
const EVP_MD *EVP_sha384(void);
const EVP_MD *EVP_sha512(void);

const EVP_MD *EVP_get_digestbyname(const char *name);
const EVP_MD *EVP_get_digestbynid1(int type);
const EVP_MD *EVP_get_digestbyobj1(const ASN1_OBJECT *o);
