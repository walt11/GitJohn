/*
##################################################################
	Name:		John Walter 
	Date:		9/20/2016
	Class:		ECE 3220
	Assignment:	Lab 2 part 2 - Arithmetic and bitwise conversions
				from decimal to binary
##################################################################
*/ 

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int choice = 0, i=0, bit = 0, location = 0, length = sizeof(unsigned short); //gets the number of BYTES of an unsigned short
	length = length*8; //gets number of BITS of an unsigned short
	unsigned short number;
	
	//while user does not exit program
	while(1){
		int bArray[64] = {0};	//an array to store the binary values in
		location = 63;			//The location in the array to start at
		
		//menu
		printf("Select:\n\t(1) Arithmetic\n\t(2) Bitwise\n\t(0) Quit\n> ");
		scanf("%d",&choice);
		while((choice<0) || (choice>2)){
			printf("Invalid choice. Enter again> ");
			scanf("%d",&choice);
		}
		//if user selects 0 then exit the program
		if(choice == 0){
			puts("Exiting.");
			return 0;
		}
		
		//get decimal value
		printf("Enter a decimal: ");
		scanf("%hu",&number);
		//do conversion based on user selection
		switch(choice){
			// arithmetic method
			case 1:
				for(i=0;i<length;i++){			// looks at the remainders to determine if the bit is a 1 or 0
												//if remainder is 1 then insert 1 into the array
					if(number%2 == 1){
						bArray[location] = 1;
												//otherwise insert a 0
					}else{
						bArray[location] = 0;
					}
					number = number/2;			// changes the number to the division of the number by 2 for the next remainder
					location--;					// steps through the array in the reverse order
				}
				break;
			// bitwise method
			case 2:
				for(i=0;i<length;i++){
					bit = number >> i; 			// look at the least significant bit by shifting bits to the right
					if(bit & 1){ 				// and it with 1
						bArray[location] = 1;	//if it is a 1 insert 1 into array
					}else{
						bArray[location] = 0;	//otherwise it is a 0
					}
					location--;					//step through the array in the reverse order
				}
				break;
		}
		
		//print out the binary representation from the array
		printf("The binary representation is: ");
		for(i=0;i<length;i++){
			printf("%d",bArray[64-length+i]);
		}
		puts("\n");
	}
}
//here is another comment at the end of the file
