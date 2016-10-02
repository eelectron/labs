/*
Return: length of string.
*/
int stringlen(char *s){
	if(s == NULL){
		printf("Pls give a valid string.");
		return -1;
	}
	
	char *start=s;	
	
	while(*s != '\0')
		s++;
		
	return start - s;
}
