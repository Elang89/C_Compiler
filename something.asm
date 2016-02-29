#Mips Assembly
          .data
	  .globl main

	  .text
main: 

var: .word 3 
h: .word 2 
li $t0, 2 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
li $t0, 4 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
li $v0 , 10 
syscall 

