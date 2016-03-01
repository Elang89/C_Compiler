#Mips Assembly
          .data
	  .globl main

	  .text
main: 

var: .word 3 
hola: .word 6 
h: .word 2 
li $t0, 2 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
li $t0, 4 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
lw $t1,var 
lw $t1,hola 
li $v0, 10 
syscall 
