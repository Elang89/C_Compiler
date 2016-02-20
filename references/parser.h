void system_goal(void)
{
	/* <system goal> ::= <program> SCANEOF */
	program();
	match(SCANEOF); 
}

void program()
{
	/* <program> ::= BEGIN <statement list> END*/
	match(BEGIN);
	statement_list();
	match(END);

}