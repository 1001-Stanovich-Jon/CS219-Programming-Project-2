// CS219:  Programming Assignment 2
// File: main.cpp
// Author: Jon Stanovich-Rubalcava
// Date: 17 February 2022

//MOSTLY FROM ORIGINAL FILE, ADDED NEW FUNCTIONS FOR PROJECT 2

#define MAX_OPSIZE 25 //Maximum size of OPERATION specifier and OPERANDs - Operations should be three letters, and numbers 32-bit hex 0xXXXXXXXX
#define MESSAGE_PADDING 20 //Padding for output messages
#define MAX_RUN 100 //Maximum amount of operations to perform, used to prevent infinite loop.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PERFORM_OPERATION(FILE *, char[MAX_OPSIZE], _Bool);

void RUN_ADD(FILE *, _Bool);
void RUN_AND(FILE *, _Bool);
void RUN_ASR(FILE *, _Bool);
void RUN_LSR(FILE *, _Bool);
void RUN_LSL(FILE *, _Bool);
void RUN_NOT(FILE *, _Bool);
void RUN_ORR(FILE *, _Bool);
void RUN_SUB(FILE *, _Bool);
void RUN_XOR(FILE *, _Bool);

void ONE_OP_PRINT(char[3], u_int32_t, u_int32_t, _Bool);
void TWO_OP_PRINT(char[3], u_int32_t, u_int32_t, u_int32_t, _Bool);

int main(int argc, char *argv[])
{
    /*
    Builds on Project 1 by extending operations that can be performed.
    Project 2's Form:
            Expected Input: OPERATION HEX_NUMBER_1 HEX_NUMBER_2
            Output: Display the result of OPC in hex (32-bit).
            Possible options (OPERATION | # Args): (ADD | 2), (AND | 2), (ASR | 1), (LSR | 1), (LSL | 1), (NOT | 1), (ORR | 2), (SUB | 2), (XOR | 2).
    */

    //SETUP - Check for correct input and if file can be opened
    if (argc != 2)
        {
            printf("Correct usage: ./main <filename>\n");
            return 1;
        }

    FILE * input_file = NULL;
    input_file = fopen(argv[1], "r");

    if (input_file == NULL)
        {
            printf("Could not open %s \n",argv[1]);
            return 1;
        }

    char OPERATION[MAX_OPSIZE];
    unsigned int run_count = 0;
    _Bool print_hex = 1; //0 for decimal

    //Main Loop - Reads operation, calls appropriate function to run operation
    while (fscanf(input_file, "%s", OPERATION) != EOF && run_count < MAX_RUN)
        {
            printf("\n     _____________________ \n\n\n     INSTRUCTION %d\n\n", run_count);
            PERFORM_OPERATION(input_file, OPERATION, print_hex);
            run_count++;
        }

    if (fclose(input_file) == 0)
            printf("\n\n%20s", "----END----\n\n");

    return (0);
}




//####################################################################################################################
//Functions

void PERFORM_OPERATION(FILE * input_file, char OPERATION[MAX_OPSIZE], _Bool print_hex)
{
    //This is where all the checks happen to figure out what operation to run. 
    if (strcmp(OPERATION, "ADD")==0)
            RUN_ADD(input_file, print_hex);
        
   else if (strcmp(OPERATION, "AND")==0)
            RUN_AND(input_file, print_hex);
        
   else if (strcmp(OPERATION,"ASR")==0)
            RUN_ASR(input_file, print_hex);
        
   else if (strcmp(OPERATION,"LSR")==0)
            RUN_LSR(input_file, print_hex);

   else if (strcmp(OPERATION, "LSL")==0)
            RUN_LSL(input_file, print_hex);
   
   else if (strcmp(OPERATION, "NOT")==0)
            RUN_NOT(input_file, print_hex);
        
   else if (strcmp(OPERATION, "ORR")==0)
            RUN_ORR(input_file, print_hex);
        
   else if (strcmp(OPERATION, "SUB")==0)
            RUN_SUB(input_file, print_hex);
        
   else if (strcmp(OPERATION, "XOR")==0)
            RUN_XOR(input_file, print_hex);

    else 
        printf("\nUnknown Operation - check input file.\n");
}

//The main while loop has already checked to make sure we have a valid line to read, so we will not do any further checking here.

void RUN_ADD(FILE * input_file, _Bool print_hex)
{
    //Performs addition with OPERAND1 and OPERAND2, displays their sum.
    u_int32_t OPERAND1 = 0, OPERAND2 = 0; 

    fscanf(input_file, "%X %X", &OPERAND1, &OPERAND2);

    TWO_OP_PRINT("ADD", OPERAND1, OPERAND2, (OPERAND1+OPERAND2), print_hex);

    return;
}



void RUN_AND(FILE * input_file, _Bool print_hex)
{
    //Performs bitwise AND between OPERAND1 with OPERAND2 and displays the result.
    u_int32_t OPERAND1 = 0, OPERAND2 = 0; 

    fscanf(input_file, "%X %X", &OPERAND1, &OPERAND2);

    int message_space = 15; //Padding
    int message_length = 500;

    TWO_OP_PRINT("AND", OPERAND1, OPERAND2, (OPERAND1&OPERAND2), print_hex);

    return;
}



void RUN_ASR(FILE * input_file, _Bool print_hex)
{
    //Performs an arithmetic shift right on OPERAND1 and displays the result.
    //I chose to divide by 2 since the >> can vary depending on compiler from what I remember hearing in lecture,
    //this should solve that problem though it asks more from the computer, but for our purposes I don't imagine it will matter.

    u_int32_t OPERAND1 = 0, OPERAND2 = 0;
    u_int32_t RESULT = 0;    

    fscanf(input_file, "%X %X", &OPERAND1, &OPERAND2);

    if (OPERAND1 > 0x7FFFFFFF)
        {
            //If the value is negative then we need to keep the sign bit
            //This is as simple as removing the left-most 1, dividing by 2, 
            //then adding the left most 1 again (i.e. add 0x80000000)
            RESULT =  OPERAND1 - 0x80000000;
            RESULT = RESULT / 2;
            RESULT += 0x80000000;
        }
    else
        RESULT = OPERAND1 / 2; //If the value is positive ASR is same as dividing by 2.

    ONE_OP_PRINT("ASR", OPERAND1, RESULT, print_hex);

    return;
}



void RUN_LSR(FILE * input_file, _Bool print_hex)
{
    //Performs logical shift right on OPERAND1 and displays the result.
    //This is the same as dividing by 2
    //I chose to divide by 2 since the >> can vary depending on compiler from what I remember hearing in lecture,
    //this should solve that problem though it asks more from the computer, but for our purposes I don't imagine it will matter.

    u_int32_t OPERAND1 = 0, OPERAND2 = 0;
    u_int32_t RESULT = 0;    

    fscanf(input_file, "%X %X", &OPERAND1, &OPERAND2);

    ONE_OP_PRINT("LSR", OPERAND1, (OPERAND1 / 2), print_hex);

    return;
}



void RUN_LSL(FILE * input_file, _Bool print_hex)
{
    //Performs logical shift left on OPERAND1 and displays the result.
    u_int32_t OPERAND1 = 0, OPERAND2 = 0;
    u_int32_t RESULT = 0;    

    fscanf(input_file, "%X %X", &OPERAND1, &OPERAND2);

    ONE_OP_PRINT("LSL", OPERAND1, (OPERAND1 << 1), print_hex);

    return;
}



void RUN_NOT(FILE * input_file, _Bool print_hex)
{
    //Performs bitwise NOT on OPERAND1, displays the result.
    u_int32_t OPERAND1 = 0, OPERAND2 = 0;
    u_int32_t RESULT = 0;    

    fscanf(input_file, "%X %X", &OPERAND1, &OPERAND2);

    ONE_OP_PRINT("NOT", OPERAND1, ~OPERAND1, print_hex);
}



void RUN_ORR(FILE * input_file, _Bool print_hex)
{
    //Performs bitwise OR betwee OPERAND1 and OPERAND2, displays the result.
    u_int32_t OPERAND1 = 0, OPERAND2 = 0;
    u_int32_t RESULT = 0;    

    fscanf(input_file, "%X %X", &OPERAND1, &OPERAND2);

    TWO_OP_PRINT("ORR", OPERAND1, OPERAND2, (OPERAND1 | OPERAND2), print_hex);
}



void RUN_SUB(FILE * input_file, _Bool print_hex)
{
    //Performs subtraction of OPERAND2 from OPERAND1, displays the result.
    u_int32_t OPERAND1 = 0, OPERAND2 = 0;
    u_int32_t RESULT = 0;    

    fscanf(input_file, "%X %X", &OPERAND1, &OPERAND2);

    RESULT = OPERAND1 + ((~OPERAND2)+1); //I wanted to do two's complement, looks cooler than using -

    TWO_OP_PRINT("SUB", OPERAND1, OPERAND2, RESULT, print_hex);
}



void RUN_XOR(FILE * input_file, _Bool print_hex)
{
    //Performs bitwise XOR betwee OPERAND1 and OPERAND2, displays the result.
    u_int32_t OPERAND1 = 0, OPERAND2 = 0;
    u_int32_t RESULT = 0;    

    fscanf(input_file, "%X %X", &OPERAND1, &OPERAND2);


    TWO_OP_PRINT("XOR", OPERAND1, OPERAND2, OPERAND1 ^ OPERAND2, print_hex);
}


//####################################################################################################################
//Printing Functions

void ONE_OP_PRINT(char OPERATION[3], u_int32_t OP1, u_int32_t RESULT, _Bool print_hex)
{
    //Used for printing information about operations involving one operand.


    int message_space = 15; //Whitespace Padding
    int message_length = 500; //Max Message Length

    char * output_format = "%*s: 0x%08X\n%*s: %10s\n%*s: 0x%08X\n\n";
    char output_message[message_length];

    if (!print_hex)
        output_format = "%*s: %12lu\n%*s: %12lu\n%*s: %12s\n%*s: %12lu\n\n";

    snprintf(output_message, (message_length-1), output_format,
    message_space, "Operand 1 ", OP1,
    message_space, "Operation ", OPERATION,
    message_space, "Result ", RESULT);

    printf("%s", output_message);
}



void TWO_OP_PRINT(char OPERATION[3], u_int32_t OP1, u_int32_t OP2, u_int32_t RESULT, _Bool print_hex)
{
    //Used for printing information about operations involving two operands.

    int message_space = 15; //Whitespace Padding
    int message_length = 500; //Max Message Length

    char * output_format = "%*s: 0x%08X\n%*s: 0x%08X\n%*s: %10s\n%*s: 0x%08X\n\n";
    char output_message[message_length];

    if (!print_hex)
        output_format = "%*s: %12lu\n%*s: %12lu\n%*s: %12s\n%*s: %12lu\n\n";

    snprintf(output_message, (message_length-1), output_format,
    message_space, "Operand 1 ", OP1,
    message_space, "Operand 2 ", OP2,
    message_space, "Operation ", OPERATION,
    message_space, "Result ", RESULT);

    printf("%s", output_message);
}