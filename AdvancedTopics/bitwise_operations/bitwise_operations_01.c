#include <stdio.h>

int main() {
    // Initialize an unsigned integer with binary value (64 in decimal)
    unsigned int num = 0b01000000;
    unsigned int num2 = 0b01100000;
    
    printf("Original number: %u\n", num);
    
    //Set the 1rst bit to 1
    num |= (1 << 0); // Setting the first bit to 1, making num 65 
 
    printf("After setting 1rst bit: %u\n", num);
    //Set the 2nd bit to 1
    num |= (1 << 1); // Setting the second bit to 1, making num 67 

    printf("After setting 2nd bit: %u\n", num);
    //Set the 3nd bit to 1
    num |= (1 << 2); // Setting the third bit to 1, making num 71
		     
    printf("After setting 3rd bit: %u\n", num);
	//Set the 4nd bit to 1
    num |= (1 << 3); // Setting the second bit to 1

    printf("After setting 4th bit: %u\n", num);

    printf("num & num2: only those bits=1 remain that are in both: %d\n", num & num2);
    printf("num or num2: only those bits=1 remain that are in at least one of the two: %d\n", num | num2);
    printf("num ^ num2: only those bits=1 remain that are in only one of the two %d\n", num ^ num2);
    printf("~num: inverts every bit %d\n.", (unsigned int)~num);
    printf("num << 1 : shifts all bits one position to the left: %d\n", num << 1 );
    printf("num >> 1 : shifts all bits one position to the right: %d\n", num >> 1 );
  
    return 0;
}
