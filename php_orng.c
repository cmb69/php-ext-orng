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

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "orng_compat.h"
#include "php_orng.h"

#include "orng_util.h"

#include "rng/rnginterface.h"
#include "rng/glibcrand.h"
#include "rng/xorshift128plus.h"
#include "rng/mt19937.h"

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(orng)
{
#if defined(ZTS) && defined(COMPILE_DL_ORNG)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RSHUTDOWN_FUNCTION */
PHP_RSHUTDOWN_FUNCTION(orng)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(orng)
{
	PHP_MINIT(orng_rng_rnginterface)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(orng_glibcrand)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(orng_rng_xorshift128plus)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(orng_rng_mt19937)(INIT_FUNC_ARGS_PASSTHRU);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(orng)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(orng)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "orng support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ orng_module_entry */
zend_module_entry orng_module_entry = {
	STANDARD_MODULE_HEADER,
	"orng",
	NULL,
	PHP_MINIT(orng),
	PHP_MSHUTDOWN(orng),
	PHP_RINIT(orng),
	PHP_RSHUTDOWN(orng),
	PHP_MINFO(orng),
	PHP_ORNG_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ORNG
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(orng)
#endif
