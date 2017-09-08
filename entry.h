
#ifndef TEN_INT_T
#	define TEN_INT_T int
#endif
#ifndef TEN_STR_T
#	define TEN_STR_T const char*
#endif
#ifndef TEN_FLT_T
#	define TEN_FLT_T float
#endif


/* Can be defined however you want */
struct TenEnv;
struct TenValue;

/* Allocate a new environment */
TenEnv* ten_init();

/*
	Compile the source `code` within `env`, and return a executable version of code.
	to be run with `ten_execute`
 */
TenValue* ten_compile(TenEnv* env, const char* src);

/* Execute `code`, return a result, if any */
TenValue* ten_execute(TenValue* code);

/* Free an environment, and anything it allocated */
void ten_free(TenEnv* env);


/* return_value = new TenValue(type=TEN_INT_T, value=value) */
TenValue* ten_make_int(TenEnv* env, TEN_INT_T value);

/* return_value = new TenValue(type=TEN_STR_T, value=value) */
TenValue* ten_make_str(TenEnv* env, TEN_STR_T value);

/* return_value = new TenValue(type=TEN_FLT_T, value=value) */
TenValue* ten_make_flt(TenEnv* env, TEN_FLT_T value);

/* return_value = new TenValue(type=OBJ) */
TenValue* ten_make_obj(TenEnv* env);

/* return_value = new TenValue(type=LIST) */
TenValue* ten_make_lst(TenEnv* env);

/* return_value = ConvertTenValueToInt(value) */
TEN_INT_T ten_unwrap_int(TenValue* value);

/* return_value = ConvertTenValueToStr(value) */
TEN_STR_T value ten_unwrap_str(TenValue* value);

/* return_value = ConvertTenValueToFlt(value) */
TEN_FLT_T ten_unwrap_flt(TenValue* value);

/* return_value = obj[key] */
TenValue* ten_obj_get(TenValue* obj, TenValue* key);
/* return_value = (obj[key] = value) */
TenValue* ten_obj_set(TenValue* obj, TenValue* key, TenValue* value);

/* return_value = lst[idx] */
TenValue* ten_lst_get(TenValue* lst, TenValue* idx);

/* return_value = (lst[idx] = value) */
TenValue* ten_lst_set(TenValue* lst, TenValue* idx, TenValue* value);

/* push value to the end of list, return value */
TenValue* ten_lst_push(TenValue* lst, TenValue* value);

/* push value to the beginning of list, return value */
TenValue* ten_lst_unshift(TenValue* lst, TenValue* value);

/* remove the first item from list, and return it */
TenValue* ten_lst_shift(TenValue* lst);
/* remove the last item from list and return it */
TenValue* ten_lst_pop(TenValue* lst);


/*
Any other public functions are for you to define but must be callable from C 
*/


