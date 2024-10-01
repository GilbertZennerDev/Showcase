#include <stdio.h>

// Without packing
struct NormalStruct {
    char a;
    int b;
    char c;
};

struct MyNormalStruct {
	char a;
	int b;
	char c;
};

// With packing
#pragma pack(push, 1)
struct PackedStruct {
    char a;
    int b;
    char c;
};

struct MyPackedStruct {
	char a;
	int b;
	char c;
};
#pragma pack(pop)



int main() {
    printf("Size of NormalStruct: %zu\n", sizeof(struct NormalStruct));
    printf("Size of MyNormalStruct: %zu\n", sizeof(struct MyNormalStruct));
    printf("Size of PackedStruct: %zu\n", sizeof(struct PackedStruct));
    printf("Size of MyPackedStruct: %zu\n", sizeof(struct MyPackedStruct));
    return 0;
}
