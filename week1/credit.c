#include <stdio.h>
#include <math.h>
#include "cs50.h"
#include <cs50.h>

bool is_valid(long cc);

int main(void){
    long cc = get_long("Enter credit > ");
    if (!is_valid(cc)){
        printf("INVALID\n");
        return 0;
    }
    int nDigits = floor(log10(cc)) + 1;   
    long cstart = cc;
    while (cstart > 100){
        cstart /= 10;
    }
    if ((cstart >= 40 && cstart < 50) && (nDigits == 13 || nDigits == 16)){
        printf("VISA\n");
        return 0;
    } 
    else if ((cstart >= 50 && cstart <=55) && nDigits == 16){
        printf("MASTERCARD\n");
        return 0;
    }
    else if ((cstart == 34 || cstart == 37) && nDigits == 15){
        printf("AMEX\n");
        return 0;
    }
    else { printf("INVALID\n");
        return 0;
    }
} 

bool is_valid(long cc){
    int sum = 0;
    bool EVEN = true;

    while(cc > 0){
        int n = cc % 10;
        cc /= 10;
        if (EVEN){
            sum += n;
        }
        else{
            int dob = n*2;
            while(dob > 9){
                sum += dob%10;
                dob /= 10; 
            }
            sum += dob; 
        }
        EVEN = !EVEN;
    }
    return sum % 10 == 0;
}

