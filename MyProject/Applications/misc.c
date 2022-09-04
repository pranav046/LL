/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#if 0
#include <stdio.h>
//common elements of an array
int main()
{
    int A[10] = {10,5,36,56,10,20,36,59,11,52};
    int B[8] = {11,6,23,89,20,10,10,36};
    int result[50] = {0,};
    
    int i =0, j = 0, k =0, x = 0, flag = 0;
    printf("Common elements are:");
    for(i = 0; i < sizeof(A)/sizeof(int); i++)
    {
        for(j = 0; j < sizeof(B)/sizeof(int); j++)
        {
            if(A[i] == B[j])
            {
                flag = 0; // reset flag;
                
                for(k = 0; k < x; k++)
                {
                    if(result[k] == A[i])
                    {flag++;}
                }
            
                if(flag == 0)
                {
                    result[x] = A[i];
                    printf(" %d",result[x]);
                    x++;
                }
            }
        }
    }

    return 0;
}



/*---------------------------------memcopy---------------------------------*/

#include <stdio.h>
#include <string.h>

void * memcopy(const void * src, void * dest, unsigned int n)
{
    const char * psrc = (const char*)(src);
    char * pdest = (char*)(dest);
  
    if((psrc != NULL) && (pdest != NULL))
    {
        while(n)
        {
            *(pdest++) = *(psrc++);
            --n;
        }
    }
 
    return dest;
}


void print(int * storage, int n)
{

    for(int i = 0; i< n; i++)
    {
         printf("%d ",(storage[i]));   
    }

}
int main()
{
    int src[20] = {10,20,30,40,50,60,70}; //Source String
    int dst[20] = {0}; //dst buffer
    //copy source buffer int dst
    
    memcopy(src, dst, sizeof(src));
    print(&dst[0],7 );

    return 0;
}

#endif
