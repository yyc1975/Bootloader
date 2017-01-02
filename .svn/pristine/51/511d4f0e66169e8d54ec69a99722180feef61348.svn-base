#define UCL_SP800_90A_SHA256_SEEDLENGTH 55
#define UCL_SP800_90A_SHA512_SEEDLENGTH 111

struct ucl_sp80090a_internal_state
{
u8 v[UCL_SP800_90A_SHA512_SEEDLENGTH];
u8 c[UCL_SP800_90A_SHA512_SEEDLENGTH];
u32 reseed_counter;
};

typedef struct ucl_sp80090a_internal_state ucl_sp80090a_internal_state_t;

int ucl_sp80090a_hash_df_sha256(u8 *requested_bits,u8 *input_string,u32 input_string_bytelen,u32 nb_of_bits_to_return);
int ucl_sp80090a_reseeding_sha256(ucl_sp80090a_internal_state_t *internal_state,u8 *entropy_input,u32 entropy_input_len,u8 *additional_input,u32 additional_input_len);
int ucl_sp80090a_instantiate_sha256(ucl_sp80090a_internal_state_t *internal_state,u8 *entropy_input,u32 entropy_input_len,u8 *nonce,u32 nonce_len,u8 *personalization_string,u32 personalization_string_len);


int ucl_sp80090a_hash_df_sha512(u8 *requested_bits,u8 *input_string,u32 input_string_bytelen,u32 nb_of_bits_to_return);
int ucl_sp80090a_reseeding_sha512(ucl_sp80090a_internal_state_t *internal_state,u8 *entropy_input,u32 entropy_input_len,u8 *additional_input,u32 additional_input_len);
int ucl_sp80090a_instantiate_sha512(ucl_sp80090a_internal_state_t *internal_state,u8 *entropy_input,u32 entropy_input_len,u8 *nonce,u32 nonce_len,u8 *personalization_string,u32 personalization_string_len);
