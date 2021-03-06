/*
  +----------------------------------------------------------------------+
  | ORNG - PHP Objective RNG                                             |
  +----------------------------------------------------------------------+
  | Copyright (c) The PHP Group                                          |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Go Kudo <zeriyoshi@gmail.com>                                |
  +----------------------------------------------------------------------+
*/

#ifndef ORNG_COMPAT
# define ORNG_COMPAT

# include "php.h"

/* For compatibility with older PHP versions */
# ifndef ZEND_PARSE_PARAMETERS_NONE
#  define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
# endif

# define ORNG_COMPAT_RNG_CLONE(__cn) orng_ORNG_clone_autodefined_##__cn

# if PHP_VERSION_ID >= 80000
#  define ORNG_COMPAT_RNG_CLONE_FUNCTION(__cn) \
	static zend_object *orng_ORNG_clone_autodefined_##__cn(zend_object *__old)
#  define ORNG_COMPAT_RNG_CLONE_GET_OBJ() __old
#  define ORNG_COMPAT_RETURN_ERROR_OR_THROW_RANGE() \
	zend_argument_value_error(2, "must be greater than or equal to argument #1 ($min)"); \
	RETURN_THROWS();
#  define ORNG_COMPAT_RETURN_ERROR_OR_THROW_ARRAY_RAND_EMPTY() \
	zend_argument_value_error(1, "cannot be empty"); \
	RETURN_THROWS();
#  define ORNG_COMPAT_RETURN_ERROR_OR_THROW_ARRAY_RAND_AVAIL() \
	zend_argument_value_error(2, "must be between 1 and the number of elements in argument #1 ($array)"); \
	RETURN_THROWS();
#  define ORNG_COMPAT_RETURN_ERROR_OR_NOTHING_SERIALIZE() RETURN_THROWS();
#  define ORNG_COMPAT_ZVAL_GETTHIS() Z_OBJ_P(getThis())
# else
#  define ORNG_COMPAT_RNG_CLONE_FUNCTION(__cn) \
	static zend_object *orng_ORNG_clone_autodefined_##__cn(zval *__old)
#  define ORNG_COMPAT_RNG_CLONE_GET_OBJ() Z_OBJ_P(__old)
#  define ORNG_COMPAT_RETURN_ERROR_OR_THROW_RANGE() \
	php_error_docref(NULL, E_WARNING, "max(" ZEND_LONG_FMT ") is smaller than min(" ZEND_LONG_FMT ")", max, min); \
	RETURN_FALSE;
#  define ORNG_COMPAT_RETURN_ERROR_OR_THROW_ARRAY_RAND_EMPTY() \
	php_error_docref(NULL, E_WARNING, "Array is empty"); \
	return;
#  define ORNG_COMPAT_RETURN_ERROR_OR_THROW_ARRAY_RAND_AVAIL() \
	php_error_docref(NULL, E_WARNING, "Second argument has to be between 1 and the number of elements in the array"); \
	return;
#  define ORNG_COMPAT_RETURN_ERROR_OR_NOTHING_SERIALIZE() return;
#  define ORNG_COMPAT_ZVAL_GETTHIS() getThis()
#  ifndef ZEND_ABSTRACT_ME_WITH_FLAGS
#   define ZEND_ABSTRACT_ME_WITH_FLAGS(classname, name, arg_info, flags) ZEND_RAW_FENTRY(#name, NULL, arg_info, flags)
#  endif
# endif

#endif
