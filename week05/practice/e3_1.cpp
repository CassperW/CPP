    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char *argv[]) {
        int A = 0x11223344;
        unsigned char *byte_ptr = (unsigned char *)&A;

        printf("Data A_addr: %p, A_data: 0x%x, ", (void *)&A, A);
        *byte_ptr == 0x44 ? printf("This is LE\n") : printf("This is BE\n");

        if (argc == 2) {
            if (argv[1][0] == 'H') {
                // 堆模式分配
                int *B = (int *)malloc(sizeof(int));
                if (B != NULL) {
                    unsigned char *b_ptr = (unsigned char *)B;
                    for (int i = 0; i < 4; i++)
                        b_ptr[i] = byte_ptr[3 - i]; 
                    printf("Data B_addr: %p, B_data: 0x%x\n", (void *)B, *B);
                    free(B);  
                }
            } else if (argv[1][0] == 'S') {
                int B_stack;
                unsigned char *b_ptr = (unsigned char *)&B_stack;
                for (int i = 0; i < 4; i++)
                    b_ptr[i] = byte_ptr[3 - i]; 
                printf("Data B_addr: %p, B_data: 0x%x\n", (void *)&B_stack, B_stack);
            } else {
                return 1;  
            }
            return 0;
        }
        return 1; 
    }