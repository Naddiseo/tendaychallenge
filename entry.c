/*
EXAMPLE: Not intended to work
*/
#include <stdio.h>
#include "entry.h"

/*
All these functions/types are custom define, 
but can be part of your public interface
*/

struct TenEnv {
	/* TODO: fill in */
	HASHMAP globals;
}
enum ValueTp  { INT = 1, LONG = 2, FLOAT = 3, STRING = 4, OBJ = 5, FUNC = 6 };
struct TenValue {
	union data {
		int i;
		long l;
		float f;
		void* data;
	};
	ValueTp tp;
}

int ten_value_get_int(TenValue v) { return v.data.i; }

void ten_set_value(TenEnv* env, const char* name, TenValue* value) {
	env.globals[name] = value;
}

int
external_function(char* input) {
	return 0;
}



int main() {
	const char* src = "const noop = () => null; const ret = external_function(\"hello\");";
	
	
	TenEnv* env = ten_init();
	
	TenValue global_external_function;
	global_external_function.data.data = &external_function;
	external_function.tp = FUNC;
	
	ten_set_value(env, "external_function", &global_external_function);
	
	int res = ten_value_get_int(ten_runscript(env, src));
	
	printf("res=%i\n", res);

	ten_free(env);
}
