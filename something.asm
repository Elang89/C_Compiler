#Mips Assembly
          .data
	  .globl main

	  .text
main: 

li $t0, 20 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
li $v0 , 10 
syscall 
