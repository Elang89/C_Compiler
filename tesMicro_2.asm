#Mips Assembly
          .data
	  .globl main

	  .text
main: 

something: .word 10 
hola: .word 6 
li $t0, 2 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
li $t0, 4 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
li $t0, 20 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
li $t0, 40 
li $v0, 1 
add $a0, $t0, $zero 
syscall 
h: .word 2 
lw $t1,something 
lw $t1,hola 
li $v0, 10 
syscall 
