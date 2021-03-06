ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ORNG_XorShift128Plus___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, seed, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ORNG_XorShift128Plus_next, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_ORNG_XorShift128Plus_next64 arginfo_class_ORNG_XorShift128Plus_next

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ORNG_XorShift128Plus_range, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, min, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ORNG_XorShift128Plus_shuffle, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(1, array, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_ORNG_XorShift128Plus_arrayRand, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ORNG_XorShift128Plus_strShuffle, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, string, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ORNG_XorShift128Plus_serialize, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_ORNG_XorShift128Plus_unserialize, 0, 1, IS_VOID, 0)
	ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()


ZEND_METHOD(ORNG_XorShift128Plus, __construct);
ZEND_METHOD(ORNG_XorShift128Plus, next);
ZEND_METHOD(ORNG_XorShift128Plus, next64);
ZEND_METHOD(ORNG_XorShift128Plus, range);
ZEND_METHOD(ORNG_XorShift128Plus, shuffle);
ZEND_METHOD(ORNG_XorShift128Plus, arrayRand);
ZEND_METHOD(ORNG_XorShift128Plus, strShuffle);
ZEND_METHOD(ORNG_XorShift128Plus, serialize);
ZEND_METHOD(ORNG_XorShift128Plus, unserialize);


static const zend_function_entry class_ORNG_XorShift128Plus_methods[] = {
	ZEND_ME(ORNG_XorShift128Plus, __construct, arginfo_class_ORNG_XorShift128Plus___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(ORNG_XorShift128Plus, next, arginfo_class_ORNG_XorShift128Plus_next, ZEND_ACC_PUBLIC)
	ZEND_ME(ORNG_XorShift128Plus, next64, arginfo_class_ORNG_XorShift128Plus_next64, ZEND_ACC_PUBLIC)
	ZEND_ME(ORNG_XorShift128Plus, range, arginfo_class_ORNG_XorShift128Plus_range, ZEND_ACC_PUBLIC)
	ZEND_ME(ORNG_XorShift128Plus, shuffle, arginfo_class_ORNG_XorShift128Plus_shuffle, ZEND_ACC_PUBLIC)
	ZEND_ME(ORNG_XorShift128Plus, arrayRand, arginfo_class_ORNG_XorShift128Plus_arrayRand, ZEND_ACC_PUBLIC)
	ZEND_ME(ORNG_XorShift128Plus, strShuffle, arginfo_class_ORNG_XorShift128Plus_strShuffle, ZEND_ACC_PUBLIC)
	ZEND_ME(ORNG_XorShift128Plus, serialize, arginfo_class_ORNG_XorShift128Plus_serialize, ZEND_ACC_PUBLIC)
	ZEND_ME(ORNG_XorShift128Plus, unserialize, arginfo_class_ORNG_XorShift128Plus_unserialize, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
