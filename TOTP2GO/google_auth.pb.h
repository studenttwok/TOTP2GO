/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_GOOGLE_AUTH_PB_H_INCLUDED
#define PB_GOOGLE_AUTH_PB_H_INCLUDED
#include "pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _MigrationPayload_Algorithm {
    MigrationPayload_Algorithm_ALGO_INVALID = 0,
    MigrationPayload_Algorithm_ALGO_SHA1 = 1
} MigrationPayload_Algorithm;

typedef enum _MigrationPayload_OtpType {
    MigrationPayload_OtpType_OTP_INVALID = 0,
    MigrationPayload_OtpType_OTP_HOTP = 1,
    MigrationPayload_OtpType_OTP_TOTP = 2
} MigrationPayload_OtpType;

/* Struct definitions */
typedef struct _MigrationPayload {
    pb_callback_t otp_parameters;
    int32_t version;
    int32_t batch_size;
    int32_t batch_index;
    int32_t batch_id;
} MigrationPayload;

typedef struct _MigrationPayload_OtpParameters {
    pb_callback_t secret;
    pb_callback_t name;
    pb_callback_t issuer;
    MigrationPayload_Algorithm algorithm;
    int32_t digits;
    MigrationPayload_OtpType type;
    int64_t counter;
} MigrationPayload_OtpParameters;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _MigrationPayload_Algorithm_MIN MigrationPayload_Algorithm_ALGO_INVALID
#define _MigrationPayload_Algorithm_MAX MigrationPayload_Algorithm_ALGO_SHA1
#define _MigrationPayload_Algorithm_ARRAYSIZE ((MigrationPayload_Algorithm)(MigrationPayload_Algorithm_ALGO_SHA1+1))

#define _MigrationPayload_OtpType_MIN MigrationPayload_OtpType_OTP_INVALID
#define _MigrationPayload_OtpType_MAX MigrationPayload_OtpType_OTP_TOTP
#define _MigrationPayload_OtpType_ARRAYSIZE ((MigrationPayload_OtpType)(MigrationPayload_OtpType_OTP_TOTP+1))


#define MigrationPayload_OtpParameters_algorithm_ENUMTYPE MigrationPayload_Algorithm
#define MigrationPayload_OtpParameters_type_ENUMTYPE MigrationPayload_OtpType


/* Initializer values for message structs */
#define MigrationPayload_init_default            {{{NULL}, NULL}, 0, 0, 0, 0}
#define MigrationPayload_OtpParameters_init_default {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, _MigrationPayload_Algorithm_MIN, 0, _MigrationPayload_OtpType_MIN, 0}
#define MigrationPayload_init_zero               {{{NULL}, NULL}, 0, 0, 0, 0}
#define MigrationPayload_OtpParameters_init_zero {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, _MigrationPayload_Algorithm_MIN, 0, _MigrationPayload_OtpType_MIN, 0}

/* Field tags (for use in manual encoding/decoding) */
#define MigrationPayload_otp_parameters_tag      1
#define MigrationPayload_version_tag             2
#define MigrationPayload_batch_size_tag          3
#define MigrationPayload_batch_index_tag         4
#define MigrationPayload_batch_id_tag            5
#define MigrationPayload_OtpParameters_secret_tag 1
#define MigrationPayload_OtpParameters_name_tag  2
#define MigrationPayload_OtpParameters_issuer_tag 3
#define MigrationPayload_OtpParameters_algorithm_tag 4
#define MigrationPayload_OtpParameters_digits_tag 5
#define MigrationPayload_OtpParameters_type_tag  6
#define MigrationPayload_OtpParameters_counter_tag 7

/* Struct field encoding specification for nanopb */
#define MigrationPayload_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, MESSAGE,  otp_parameters,    1) \
X(a, STATIC,   SINGULAR, INT32,    version,           2) \
X(a, STATIC,   SINGULAR, INT32,    batch_size,        3) \
X(a, STATIC,   SINGULAR, INT32,    batch_index,       4) \
X(a, STATIC,   SINGULAR, INT32,    batch_id,          5)
#define MigrationPayload_CALLBACK pb_default_field_callback
#define MigrationPayload_DEFAULT NULL
#define MigrationPayload_otp_parameters_MSGTYPE MigrationPayload_OtpParameters

#define MigrationPayload_OtpParameters_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, BYTES,    secret,            1) \
X(a, CALLBACK, SINGULAR, STRING,   name,              2) \
X(a, CALLBACK, SINGULAR, STRING,   issuer,            3) \
X(a, STATIC,   SINGULAR, UENUM,    algorithm,         4) \
X(a, STATIC,   SINGULAR, INT32,    digits,            5) \
X(a, STATIC,   SINGULAR, UENUM,    type,              6) \
X(a, STATIC,   SINGULAR, INT64,    counter,           7)
#define MigrationPayload_OtpParameters_CALLBACK pb_default_field_callback
#define MigrationPayload_OtpParameters_DEFAULT NULL

extern const pb_msgdesc_t MigrationPayload_msg;
extern const pb_msgdesc_t MigrationPayload_OtpParameters_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define MigrationPayload_fields &MigrationPayload_msg
#define MigrationPayload_OtpParameters_fields &MigrationPayload_OtpParameters_msg

/* Maximum encoded size of messages (where known) */
/* MigrationPayload_size depends on runtime parameters */
/* MigrationPayload_OtpParameters_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif