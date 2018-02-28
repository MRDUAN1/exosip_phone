#pragma once
#ifndef B_REGISTER__ALGORITHM_H_
 #define B_REGISTER__ALGORITHM_H_

#include <stdio.h>
 #include "osip_md5.h"

 #define HASHLEN 16
 typedef char HASH[HASHLEN];

 #define HASHHEXLEN 32
 typedef char HASHHEX[HASHHEXLEN + 1];

 char* cacluate_nonce();
 void DigestCalcHA1(const char *pszAlg, const char *pszUserName,
         const char *pszRealm, const char *pszPassword,
         const char *pszNonce, const char *pszCNonce,
         HASHHEX SessionKey);

 void DigestCalcResponse(HASHHEX HA1, const char *pszNonce,
        const char *pszNonceCount, const char *pszCNonce,
        const char *pszQop, int Aka, const char *pszMethod,
         const char *pszDigestUri, HASHHEX HEntity, HASHHEX Response);

#endif /* B_REGISTER__ALGORITHM_H_ */

