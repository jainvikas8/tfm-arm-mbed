/*
 * Copyright (c) 2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include "platform/include/tfm_plat_crypto_keys.h"
/**
 * \file tfm_rotpk.c
 *
 * This file contains the hash value (SHA256) of the public parts of the
 * firmware signing keys in bl2/ext/mcuboot folder (*.pem files).
 * This simulates when the hash of the Root of Trust Public Key is programmed
 * to an immutable device memory to be able to validate the image verification
 * key.
 *
 * \note These key-hash values must be provisioned to the SoC during the
 *       production, independently from firmware binaries. This solution
 *       (hard-coded key-hash values in firmware) is not suited for use in
 *       production!
 */

#if defined(BL2)
#if (MCUBOOT_SIGN_RSA_LEN == 2048)
/* Hash of public key: bl2/ext/mcuboot/root-rsa-2048.pem */
uint8_t rotpk_hash_0[ROTPK_HASH_LEN] = {
    0xfc, 0x57, 0x01, 0xdc, 0x61, 0x35, 0xe1, 0x32,
    0x38, 0x47, 0xbd, 0xc4, 0x0f, 0x04, 0xd2, 0xe5,
    0xbe, 0xe5, 0x83, 0x3b, 0x23, 0xc2, 0x9f, 0x93,
    0x59, 0x3d, 0x00, 0x01, 0x8c, 0xfa, 0x99, 0x94,
};

#elif (MCUBOOT_SIGN_RSA_LEN == 3072)
/* Hash of public key: bl2/ext/mcuboot/root-rsa-3072.pem */
uint8_t rotpk_hash_0[ROTPK_HASH_LEN] = {
    0xbf, 0xe6, 0xd8, 0x6f, 0x88, 0x26, 0xf4, 0xff,
    0x97, 0xfb, 0x96, 0xc4, 0xe6, 0xfb, 0xc4, 0x99,
    0x3e, 0x46, 0x19, 0xfc, 0x56, 0x5d, 0xa2, 0x6a,
    0xdf, 0x34, 0xc3, 0x29, 0x48, 0x9a, 0xdc, 0x38,
};

#else
#error "No public key available for given signing algorithm."
#endif

const struct tfm_plat_rotpk_t device_rotpk[] = {
    {
        .key_hash = rotpk_hash_0,
        .hash_len = ROTPK_HASH_LEN,
    },
};

const uint32_t rotpk_key_cnt = 1;
#endif /* BL2 */