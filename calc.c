#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int powerFunc(int x,int n){
    int i;
    int number = 1;
    
    for (i = 0; i < n; ++i){
        number *= x;
    }
    return(number);
}



//CONVERSION FROM GIVEN TYPE TO DECIMAL

// Convert Decimal String to Actual String Number
int convertStringtoDecimal(char *number){
    
    //Created a character array of size 32 since each char is one bit
    //copy over the string to the array
    char p[32];
    strcpy(p, number);
    
    //Variables needed to iterate to through the string
    long index;
    int result;
    result = 0;
    long len=strlen(p);
    
    //check if first index is negative or letter start from 2
    
    if(p[0] == '-')
    { //number is negative
        //long neglength = strlen(p);
        for(index = 2; index < len; index++){
            result = result * 10 + (p[index] - '0');
        }
    }
    else if(p[0] == 'd'){ //number is possitive
        for(index = 1; index < len; index++){
            result = result * 10 + (p[index] - '0');
        }
        
    }
    
    return result;
}



// Conversion from Binary String to Decimal

int conversionfromBinarytoDecimal(char *number){
    
    char binary[50];
    
    strcpy(binary, number); //values are copied to new array called binary of the digits
    
    long index; //index for for loop
    int sum = 0;//initalized sum of array to be zero
    int exponent = 0;
    long stringlength = strlen(binary);
    
    if(binary[0] =='b'){ //Binary is a positive number
        for(index = stringlength - 1; index >= 1; index--){
            if(binary[index] == '1'){
                sum = sum + powerFunc(2, exponent);
            }
        exponent++;
        }
    }
    
    if(binary[0] == '-'){ //number is negative
       
        for(index = stringlength - 1; index >= 2; index--){
            if(binary[index] == '1'){
                sum = sum + powerFunc(2, exponent);
            }
            exponent++;
        }
        
    }
    
    return sum;
}






//Conversion from Hexadecimal to Decimal. Does not account for lowercase letters
int conversionfromHexadecimacltoDecimal(char * number){
    
    char hex[50];
    strcpy(hex, number);
    //  int a = 10, b =11, c = 12, d = 13, e = 14, f = 15;
    long index;
    int sum = 0;
    int exponent = 0;
    long stringLength = strlen(number);
    
    int j;
    char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
   
    if(hex[0] == 'x'){ //Number is positive
        for(index = stringLength-1; index >= 1; index--) {

            for(j=0; j<16; j++){
                if(hex[index] == hexDigits[j]){
                sum += j*powerFunc(16, exponent);
                }
            }
            exponent++;
        }
    }
    
    if(hex[0] == '-'){ //number is negative
        
        for(index = stringLength-1; index >= 2; index--) {
            
            for(j=0; j<16; j++){
                if(hex[index] == hexDigits[j]){
                    sum += j*powerFunc(16, exponent);
                }
            }
            exponent++;
        }
    }
    
    return sum;
}



//Conversion from Octal to Decimal.

int conversionfromOctaltoDecimal(char *number){
    
    char octal[40];
    strcpy(octal, number);
    long index;
    long stringlen = strlen(octal);
    int octalnum = 0;
    
    if(octal[0] == '-'){ //negative number
        
        for(index = 2; index < stringlen; index++){
            octalnum = octalnum * 10 + (octal[index] - '0');
        }
    }
    
    if(octal[0] == 'o'){ // positive number
        for(index = 1; index < stringlen; index++){
            octalnum = octalnum * 10 + (octal[index] - '0');
        }
    }
    
    int decimalnum =0, i =0;
    
    while(octalnum != 0){
        decimalnum += (octalnum % 10) * powerFunc(8,i);
        ++i;
        octalnum = octalnum / 10;
    }
    
    return decimalnum;
    
}



//CONVERSION FROM DECIMAL TO DIFFERENT TYPE



//DECIMAL TO BINARY
int conversionfromDecimaltoBinary(int number){
    
    int remainder;
    remainder = 0;
    int result = 0;
    long i = 1; // ones, tens, hundreds thousands etc
    
    while(number !=0){
        remainder = number % 2;
        number = number / 2;
        result = result + (remainder * i);
        i = i * 10;
    }
    
    return result;
}




//DECIMAL TO OCTAL
int conversionfromDecimaltoOctal(int number){
    
    int remainder = 0;
    int octal = 0;
    long index = 1;
    
    while(number !=0){
        
        remainder = number % 8;
        number = number / 8;
        octal = octal + (remainder * index);
        index = index * 10;
    }
    return octal;
    
}



//DECIMAL TO HEXADECIMAL

char *integerToHexadecimalASCII(int number){
    
    int remainder, decimal;
    char hexArray[100];
    
    decimal = number;
  //  printf("The decimal number is %d \n", decimal);
    
    char hexLetter[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char intArr[100];
    
    
    while(decimal != 0){
        
        remainder = decimal % 16;
    //    printf("THE REMINDER IS: %d \n", remainder);
        
        if(remainder >= 10){
            remainder = remainder - 10;
            intArr[0] = hexLetter[remainder];
        }else{
            intArr[0] = remainder + '0';
        }
        
        strcat(hexArray, intArr);
        decimal = decimal /16;
    }
    
    char flip[100];
    int hexArrLength = strlen(hexArray)-1;
    int flipIndex;
    int increment = 0;
    
    for(flipIndex = hexArrLength; flipIndex >=0; flipIndex--){
       flip[increment] = hexArray[flipIndex];
       increment++;
    }
    
    char *stringofHex = malloc((sizeof(char)*32) +1);
    
    strcpy(stringofHex, flip);
    
    return stringofHex;

}


char *integerToDecimalASCII(int number){
    
   // printf("THIS IS INPUT NUMBER %d \n", number);
    char stringnum[32];
    char stringArr[32] = "";
    
    
    
    if(number < 0){
        number = number * -1; //convert negative number to positive.
    }
    
    int remainder;
    
    while(number != 0){
        remainder = number % 10; //I get the last digit of the input number
        number = number / 10; //I can then divide by 10 to get rid of the last digit
        
        stringnum[0]=remainder + '0'; //copy character to the pointer at its first index.
        
        //copy the character array consisting of the converted ASCII to the array consisting of all chars.
        strcat(stringArr, stringnum);
        
    }
    
    int stringLength = strlen(stringArr);
    
    int index;
    int indexofFlip = 0;
    
    char flip[32];
    
    for(index = stringLength - 1; index >=0; index--){
        
        flip[indexofFlip]= stringArr[index];
        indexofFlip++;
    }
    
    
  //  printf("The character array is: %s\n",&flip[0]);
    
    char *stringofNum = malloc((sizeof(char)*32) +1);
    
    strcpy(stringofNum, flip);
    
    return stringofNum;
}



char *integerToOctalASCII(int number){
    
  //  printf("THIS IS INPUT NUMBER %d \n", number);
    char stringnum[32];
    char stringArr[32] = "";
    
    
    
    if(number < 0){
        number = number * -1; //convert negative number to positive.
    }
    
    int remainder;
    
    while(number != 0){
        remainder = number % 8; //I get the last digit of the input number
        number = number / 8; //I can then divide by 10 to get rid of the last digit
        
        stringnum[0]=remainder + '0'; //copy character to the pointer at its first index.
        
        //copy the character array consisting of the converted ASCII to the array consisting of all chars.
        strcat(stringArr, stringnum);
        
    }
    
    int stringLength = strlen(stringArr);
    
    int index;
    int indexofFlip = 0;
    
    char flip[32];
    
    for(index = stringLength - 1; index >=0; index--){
        
        flip[indexofFlip]= stringArr[index];
        indexofFlip++;
    }
    
    
   // printf("The character array is: %s\n",&flip[0]);
    
    char *stringofNum = malloc((sizeof(char)*32)+1);
    
    strcpy(stringofNum, flip);
    
    return stringofNum;
}


char *integerToBinaryASCII(int number){
    
    //printf("THIS IS INPUT NUMBER %d \n", number);
    char stringnum[32];
    char stringArr[32] = "";
    
    
    
    if(number < 0){
        number = number * -1; //convert negative number to positive.
    }
    
    int remainder;
    
    while(number != 0){
        remainder = number % 2; //I get the last digit of the input number
        number = number / 2; //I can then divide by 10 to get rid of the last digit
        
        stringnum[0]=remainder + '0'; //copy character to the pointer at its first index.
        
        //copy the character array consisting of the converted ASCII to the array consisting of all chars.
        strcat(stringArr, stringnum);
        
    }
    
    int stringLength = strlen(stringArr);
    
    int index;
    int indexofFlip = 0;
    
    char flip[32];
    
    for(index = stringLength - 1; index >=0; index--){
        
        flip[indexofFlip]= stringArr[index];
        indexofFlip++;
    }
    
    
  //  printf("The character array is: %s\n",&flip[0]);
    
    char *stringofNum = malloc((sizeof(char)*32)+1);
    
    strcpy(stringofNum, flip);
    
    return stringofNum;
}







//MAIN PROGRAM


int main(int argc, char ** argv) {
    
    /*First the program checks if any of the agruments are left empty. The program will return the necessary information for which parameter was left empty.
     */
    if(argv[1] == NULL){
        printf("Error: The operator was not indicated \n");
    }else if(argv[1] == NULL){
        printf("Error: The first number was not indicated \n");
    }else if(argv[2] == NULL){
        printf("Error: The second number was not indicated \n");
    }else if(argv[3] == NULL){
        printf("Error: The third number was not indicated \n");
    }else if(argv[4] == NULL){
        printf("Error: The fourth number was not indicated \n");
    }
    
    /*Created pointers to each argument. The order will be important for te program to work successfully. 
     */
    
    char *operator = argv[1];
    char *number1 = argv[2];
    char *number2 = argv[3];
    char *outputType = argv[4];

    //Tester
    
    /*printf("This is the operator: %s \n", operator);
    printf("This is num 1: %s \n ", number1);
    printf("This is num 2: %s \n ", number2);
    printf("This is the output type: %s \n", outputType);
    */
    
    
    // Created variables, which will be assigned to each parameter depending on the conversion needed.
    int integerValue1 =0;
    int integerValue2 =0;
    int total =0;
    
        //Check what type number 1 is.
    
        if(number1[1] == 'x' && number1[0] == '-'){
            integerValue1 = conversionfromHexadecimacltoDecimal(number1);
          //  printf("This is the converted number1 to decimal from hexadecimal: %d \n", integerValue1);
            
        }else if(number1[0] == 'x'){
            integerValue1 = conversionfromHexadecimacltoDecimal(number1);
        //    printf("This is the converted number1 to decimal from hexadecimal: %d \n", integerValue1);
        }else if(number1[1] == 'b' && number1[0] == '-'){
            integerValue1 = conversionfromBinarytoDecimal(number1);
          //  printf("This is the converted number1 to decimal from binary: %d \n", integerValue1);
        }else if(number1[0] == 'b'){
            integerValue1 = conversionfromBinarytoDecimal(number1);
           // printf("This is the converted number1 to decimal from binary: %d \n", integerValue1);
        }else if(number1[1] == 'd' && number1[0] == '-'){
            integerValue1 = convertStringtoDecimal(number1);
          //  printf("This is the converted number1 to decimal from string: %d \n", integerValue1);
        }else if(number1[0] == 'd'){
            integerValue1 = convertStringtoDecimal(number1);
         //   printf("This is the converted number1 to decimal from string: %d \n", integerValue1);
        }
        else if(number1[1] == 'o' && number1[0] == '-'){
            integerValue1 = conversionfromOctaltoDecimal(number1);
           // printf("This is the converted number1 to decimal from octal: %d \n", integerValue1);
        }else if(number1[0] == 'o'){
            integerValue1 = conversionfromOctaltoDecimal(number1);
           // printf("This is the converted number1 to decimal from octal: %d \n", integerValue1);
        }else{
            printf("Error: Invalid number type, please enter hexadecimal, binary, octal, or binary number \n");
        }
        
        //Check what type number 2 is
        
        if(number2[1] == 'x' && number2[0] == '-'){
            integerValue2 = conversionfromHexadecimacltoDecimal(number2);
          //  printf("This is the converted number2 to decimal from hexadecimal: %d \n", integerValue2);
        
        }else if(number2[0] == 'x'){
            integerValue2 = conversionfromHexadecimacltoDecimal(number2);
          //  printf("This is the converted number2 to decimal from hexadecimal: %d \n", integerValue2);
        }else if(number2[1] == 'b' && number2[0] == '-'){
            integerValue2 = conversionfromBinarytoDecimal(number2);
          //  printf("This is the converted number2 to decimal from binary: %d \n", integerValue2);
        }else if(number2[0] == 'b'){
            integerValue2 = conversionfromBinarytoDecimal(number2);
         //   printf("This is the converted number2 to decimal from binary: %d \n", integerValue2);
        }else if(number2[1] == 'd' && number2[0] == '-'){
            integerValue2 = convertStringtoDecimal(number2);
           // printf("This is the converted number2 to decimal from string: %d \n", integerValue2);
        }else if(number2[0] == 'd'){
            integerValue2 = convertStringtoDecimal(number2);
          //  printf("This is the converted number2 to decimal from string: %d \n", integerValue2);
        }
        else if(number2[1] == 'o' && number2[0] == '-'){
            integerValue2 = conversionfromOctaltoDecimal(number2);
           // printf("This is the converted number2 to decimal from octal: %d \n", integerValue2);
        }else if(number2[0] == 'o'){
            integerValue2 = conversionfromOctaltoDecimal(number2);
           // printf("This is the converted number2 to decimal from octal: %d \n", integerValue2);
        }else{
            printf("Error: Invalid number type, please enter hexadecimal, binary, octal, or binary number \n");
        }
    
    
    //Check if the operator is addition
    if(operator[0] == '+'){
        
        if(number1[0] == '-'){
            integerValue1 = integerValue1 * -1;
        }
        
        if(number2[0] == '-'){
            integerValue2 = integerValue2 * -1;
        }
        //Calculate the total in decimal
        total = integerValue1 + integerValue2;
      //  printf("THIS IS TOTAL FOR ADDITION: %d \n", total);
    }else if(operator[0] == '-'){ //checks if the operator is subtraction and subtracts
        
        if(number1[0] == '-'){
            integerValue1 = integerValue1 * -1;
        }
        
        if(number2[0] == '-'){
            integerValue2 = integerValue2 * -1;
        }
        
        total = integerValue1 - integerValue2;
       // printf("THIS IS TOTAL FOR SUBTRACTION: %d \n", total);
    }else if(operator[0] == '*'){
        
        if(number1[0] == '-'){
            integerValue1 = integerValue1 * -1;
        }
        
        if(number2[0] == '-'){
            integerValue2 = integerValue2 * -1;
        }
        
        total = integerValue1 * integerValue2;
       // printf("THIS IS TOTAL FOR Multiplication: %d \n", total);
        
    }else{
        printf("Error: Incorrect Operator \n");
    }
    
    //Updated total in designated output type.
    
    int tot;
    
    if(outputType[0] == 'd'){
        
        if(total >0){
            char *p = malloc((sizeof(char)*32)+1);
            p = integerToDecimalASCII(total);
            printf("This is the ASCII Value for Decimal: %s \n", p);
        }else if(total < 0){
            total = total * -1;
            char *p = malloc((sizeof(char)*32)+1);
            p = integerToDecimalASCII(total);
            printf("This is the ASCII Value for Decimal: -%s \n", p);
        }
    
      //  printf("The output in Decimal: %d \n", total);
    }
    
    else if(outputType[0] == 'x'){
        if(total > 0){
           
            char *p = malloc((sizeof(char)*32)+1);
            p = integerToHexadecimalASCII(total);
            printf("This is the ASCII Value for Hexadecimal: %s \n", p);
            
           // printf("The output in hexadecimal: %d \n", tot);
        }else if (total < 0){
            total = total * -1;
           // tot = conversionfromDecimaltoHexadecimal(total);
            
            char *p = malloc((sizeof(char)*32)+1);
            p = integerToHexadecimalASCII(total);
            printf("This is the ASCII Value for Hexadecimal: -%s \n", p);
            
           // printf("The output in hexadecimal: - %d \n", tot);
        }
        
    }
    
    else if(outputType[0] == 'o'){
        
        if(total > 0){
            tot = conversionfromDecimaltoOctal(total);
            char *p = malloc((sizeof(char)*32)+1);
            p = integerToOctalASCII(total);
            printf("This is the ASCII Value for Octal: %s \n", p);
            // printf("The output in octal: %d \n", tot);
        }else if (total < 0){
            total = total * -1;
            tot = conversionfromDecimaltoOctal(total);
           
            char *p = malloc((sizeof(char)*32)+1);
            p = integerToOctalASCII(total);
            printf("This is the ASCII Value for Octal: -%s \n", p);

          //  printf("The output in octal: - %d \n", tot);
        }
    }
    
    else if(outputType[0] == 'b'){
        
        if(total > 0){
            tot = conversionfromDecimaltoBinary(total);
            
            char *p = malloc((sizeof(char)*32)+1);
            p = integerToBinaryASCII(total);
        
            printf("This is the ASCII Value for Binary: %s \n", p);
           // printf("The output in binary: %d \n", tot);
            
        }else if (total < 0){
            total = total * -1;  //convert negative total to positive and convert
            tot = conversionfromDecimaltoBinary(total);
            
            char *p = malloc((sizeof(char)*32)+1);
            p = integerToBinaryASCII(total);
            printf("This is the ASCII Value for Binary: -%s \n", p);
            
           // printf("The output in binary: - %d \n", tot);
        }
        
    }else{
        printf("Error: Incorrect output type given \n");
    }
    

    
}
