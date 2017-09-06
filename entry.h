
/* Can be defined however you want */
struct TenEnv;
struct TenValue;

/* Allocate a new environment */
TenEnv* ten_init();

/* Run the source `code` within `env`, and return any result, if any. */
TenValue* ten_runscript(TenEnv* env, const char* code);

/* Free an environment, and anything it allocated */
void ten_free(TenEnv* env);

/*
Any other public functions are for you to define but must be callable from C 
*/


