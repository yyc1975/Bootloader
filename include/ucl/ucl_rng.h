/*===========================================================================
 *
 * ucl_rng.h
 *
 *==========================================================================*/
/*===========================================================================
 *
 * Copyright © 2009 Innova Card. All Rights Reserved. Do not disclose.
 *
 * This software is the confidential and proprietary information of
 * Innova Card ("Confidential Information"). You shall not
 * disclose such Confidential Information and shall use it only in
 * accordance with the terms of the license agreement you entered
 * into with Innova Card.
 *
 * Innova Card makes no representations or warranties about the suitability of
 * the software, either express or implied, including but not limited to
 * the implied warranties of merchantability, fitness for a particular purpose,
 * or non-infrigement. Innova Card shall not be liable for any damages suffered
 * by licensee as the result of using, modifying or distributing this software
 * or its derivatives.
 *
 *==========================================================================*/
/*===========================================================================
 *
 * Purpose: Random Number Generator Interface
 *
 *==========================================================================*/
#ifndef UCL_RNG_H_
#define UCL_RNG_H_

/** @file ucl_rng.h
 * @defgroup UCL_RNG RNG Interface
 * Interface for Random Number Generator.
 *
 * This interface allows to attach any RNG for all random needs of the UCL.
 * The default RNG is the hardware USIP&reg; TRNG.
 *
 * @par Header:
 * @link ucl_rng.h ucl_rng.h @endlink
 *
 *
 * @ingroup UCL_RAND
 */


#include "ucl/ucl_trng.h"

#ifdef __cplusplus
extern "C"
{
#endif /* _ cplusplus  */


/** <b>Attach</b>.
 * Attach a RNG.
 *
 * @param[in] rng The pointer to the RNG
 *
 * @return Error code
 *
 * @retval #UCL_OK No error occurred
 *
 * @ingroup UCL_RNG
 */
int ucl_rng_attach(int (*rng)(u8* rand, u32 rand_byteLen, int option));


/** <b>Detach</b>.
 * Detach the previously attached RNG.
 *
 * @return Error code
 *
 * @retval #UCL_OK No error occurred
 *
 * @ingroup UCL_RNG
 */
int ucl_rng_detach(void);


/** <b>Get pointer</b>.
 * Get the pointer of the current RNG.
 *
 * @return A function pointer
 *
 * @ingroup UCL_RNG
 */
  void * ucl_rng_getpt(void);


  /** <b>RNG Read</b>.
   * Read random octet string using the attached RNG.
   *
 * @param[out] rand         Random octet string
 * @param[in]  rand_byteLen Random byte length
 * @param[in]  option       A value between:
 *                              @li #UCL_RAND_DEFAULT
 *                              @li #UCL_RAND_NO_NULL
 *
 * @return Error code or a positive value equal to @p the generated byte number
 *
 * @retval #UCL_ERROR    in case of erro
 *
 * @ingroup UCL_RNG
 */
  int ucl_rng_read(u8* rand, u32 rand_byteLen, int option);

  /** <b>RNG Read</b>.
   * Read random octet string using the attached RNG postprocessed with SHA-256
   *
 * @param[out] rand         Random octet string
 * @param[in]  rand_byteLen Random byte length
 *
 * @return Error code
 *
 * @retval #UCL_OK No error occurred
 * @retval #UCL_INVALID_OUTPUT    If @p rand is the pointer #NULL
 * @retval #UCL_NOP               If @p rand_byteLen = 0
 * @retval #UCL_ERROR if there is no interface to the TRNG
 *
 * @ingroup UCL_RNG
 */
  int ucl_sha256_whitening_rng_read(u8 *rand,u32 rand_byteLen);
  int ucl_sha256_whitening_rng_read_non_zero(u8 *rand,u32 rand_byteLen);
  int ucl_sha256_whitening_rng_read_leading_non_zero(u8 *rand,u32 rand_byteLen);

  /** <b>RNG Read</b>.
   * EMV Unpredictable Number generation power down function
   * see EMV bulletin no144 (june-2014)
 * @param[out] q         persistent variant of P, 32 bytes
 * @param[in]  p         pre-image of UN, 32 bytes
 *
 * @return Error code
 *
 * @retval #UCL_OK No error occurred
 * @retval #UCL_INVALID_OUTPUT    If @p q is the pointer #NULL
 * @retval #UCL_INVALID_INPUT    If @p p  is the pointer #NULL
 *
 * @ingroup UCL_RNG
 */

//EMV specification bulletin no144, june 2014

#define EMV_TVP_BYTESIZE 8
#define EMV_TID_BYTESIZE 8
#define EMV_IFDSN_BYTESIZE 8
#define EMV_RAND_BYTESIZE 8
#define EMV_AC_BYTESIZE 8
#define EMV_P_BYTESIZE UCL_SHA256_HASHSIZE
#define EMV_Q_BYTESIZE UCL_SHA256_HASHSIZE
#define EMV_UN_BYTESIZE 4

  int ucl_emv_unpredictable_number_power_down(u8 *q,u8 *p);

  /** <b>RNG Read</b>.
   * EMV Unpredictable Number generation per transaction P refresh
   * see EMV bulletin no144 (june-2014)
   *
 * @param[in,out] p         pre-image of UN, 32 bytes
 * @param[in]  tvp          time-varying parameter, 8 bytes
 * @param[in]  rand         value from external RNG, 8 bytes, optional (shall be #NULL if not available)
 * @param[in]  ac           application cryptogram, 8 bytes
 *
 * @return Error code
 *
 * @retval #UCL_OK No error occurred
 * @retval #UCL_INVALID_OUTPUT    If @p p is the pointer #NULL
 * @retval #UCL_INVALID_INPUT    If @p tvp  is the pointer #NULL
 * @retval #UCL_INVALID_INPUT    If @p ac  is the pointer #NULL
 *
 * @ingroup UCL_RNG
 */
  int ucl_emv_unpredictable_number_transaction_p_refresh(u8 *p,u8 *tvp,u8 *rand,u8 *ac);

  /** <b>RNG Read</b>.
   * EMV Unpredictable Number generation
   * see EMV bulletin no144 (june-2014)
   *
   * @param[out] un           unpredictable number, 4 bytes
   * @param[in] rand        value from external RNG, 8 bytes, optional (shall be #NULL if not available)
   * @param[in]  p         pre-image of UN, 32 bytes
 *
 * @return Error code
 *
 * @retval #UCL_OK No error occurred
 * @retval #UCL_INVALID_OUTPUT    If @p un is the pointer #NULL
 * @retval #UCL_INVALID_INPUT     If @p p is the pointer #NULL
 *
 * @ingroup UCL_RNG
 */
  int ucl_emv_unpredictable_number_transaction_un_generation(u8 *un,u8 *rand,u8 *p);

  /** <b>RNG Read</b>.
  * EMV Unpredictable Number generation power down function
   * see EMV bulletin no144 (june-2014)
   *
 * @param[in,out] q         persistent variant of P, 32 bytes
   * @param[in]  tid         Terminal ID, 8 bytes
   * @param[in]  ifdsn       IFD Serial, 8 bytes
   * @param[in]  tvp          time-varying parameter, 8 bytes
   * @param[in]  rand         value from external RNG, 8 bytes, optional (shall be #NULL if not available)
   * @param[in]  p         pre-image of UN, 32 bytes
 *
 * @return Error code
 *
 * @retval #UCL_OK No error occurred
 * @retval #UCL_INVALID_OUTPUT    If @p q is the pointer #NULL
 * @retval #UCL_INVALID_INPUT     If @p tid is the pointer #NULL
 * @retval #UCL_INVALID_INPUT     If @p ifdsn is the pointer #NULL
 * @retval #UCL_INVALID_INPUT     If @p tvp is the pointer #NULL
 * @retval #UCL_INVALID_INPUT     If @p p is the pointer #NULL
 *
 * @ingroup UCL_RNG
 */
  int ucl_emv_unpredictable_number_power_up(u8 *q,u8 *tid,u8 *ifdsn,u8 *tvp,u8 *rand,u8 *p);

#ifdef __cplusplus
}
#endif /* _ cplusplus  */


#endif /*UCL_RNG_H_*/
