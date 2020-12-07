/*
  +----------------------------------------------------------------------+
  | ORNG - PHP Objective RNG                                             |
  +----------------------------------------------------------------------+
  | Copyright (c) The PHP Group                                          |
  | Copyright (c) Go Kudo                                                |
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

# if PHP_VERSION_ID >= 80000
#  define ORNG_COMPAT_RETURN_ERROR_OR_THROW_MAX_SMALLER_THAN_MIN() \
	zend_argument_value_error(2, "must be greater than or equal to argument #1 ($min)"); \
	RETURN_THROWS();
# else
#  define ORNG_COMPAT_RETURN_ERROR_OR_THROW_MAX_SMALLER_THAN_MIN() \
	php_error_docref(NULL, E_WARNING, "max(" ZEND_LONG_FMT ") is smaller than min(" ZEND_LONG_FMT ")", max, min); \
	RETURN_FALSE;
#  ifndef ZEND_ABSTRACT_ME_WITH_FLAGS
#   define ZEND_ABSTRACT_ME_WITH_FLAGS(classname, name, arg_info, flags) ZEND_RAW_FENTRY(#name, NULL, arg_info, flags)
#  endif
# endif

#endif