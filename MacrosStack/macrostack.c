#include <stdio.h>
#include <stdlib.h>

#define STACK_DECL(name, type) 			\
	struct {							\
		type* 	bottom;					\
		type* 	top;					\
		size_t 	size;					\
	} stack_##name = {NULL, NULL, 0};

#define STACK_CHUNK_SIZE (size_t)(16)

#define STACK_PUSH(name, elem) {															\
		if (stack_##name.bottom == NULL) {													\
			stack_##name.size = STACK_CHUNK_SIZE;											\
			stack_##name.bottom = 															\
				malloc(stack_##name.size * sizeof(*stack_##name.bottom)); 					\
			stack_##name.top = stack_##name.bottom;											\
		}																					\
		if (stack_##name.top - stack_##name.bottom == stack_##name.size) {					\
			stack_##name.bottom = realloc(stack_##name.bottom, 								\
				(stack_##name.size + STACK_CHUNK_SIZE) * sizeof(*stack_##name.bottom));		\
			stack_##name.top = stack_##name.bottom + stack_##name.size;						\
			stack_##name.size += STACK_CHUNK_SIZE;											\
		}																					\
		*stack_##name.top = elem;															\
		++stack_##name.top;																	\
	}
	
#define STACK_POP(name, elem) elem = *(--stack_##name.top);

#define STACK_EMPTY(name) (stack_##name.bottom == stack_##name.top)

#define STACK_FREE(name) {							\
	free(stack_##name.bottom);						\
	stack_##name.bottom = stack_##name.top = NULL;	\
	stack_##name.size = 0;							\
}
	

STACK_DECL(qsort, int)

int main() {
	for (int i = 0; i < 50; ++i)
		STACK_PUSH(qsort, i)
		
	for (int i = 0; i < 50; ++i) {
		int x;
		STACK_POP(qsort, x)
		printf("%d ", x);
	}
	
	STACK_FREE(qsort)
}
