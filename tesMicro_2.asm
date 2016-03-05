#Mips Assembly
          .data
	  .globl main

	  .text
main: 

variable_one: .word 11 
hola_mundo: .word 9 
h: .word 2 
li $t0, 2 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
li $t0, 4 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
li $t0, 7 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
li $t0, 8 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
lw $t1,variable_one 
lw $t1,h 
li $v0, 10 
syscall 
