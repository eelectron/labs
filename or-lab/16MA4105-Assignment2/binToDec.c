/*
binary: 111.11
dec: 7.75
*/

#include<string.h>
#include<math.h>

float binToDec(char *str){
	float dec = 0;			//store decimal value here and finally return it
	int n  = strlen(str);		//length of binary no. input ex 1111.11

	int dotIndex = -1;
	
	char *pd = strchr(str, '.');	//ptr to dot
	int integralInd = -1;		//this index depends on presence of dot 	
	if(pd){
		dotIndex = pd - str;
		integralInd = dotIndex -1;
	}
	else{
		integralInd = n -1;
		dotIndex = n;
	}
		

	//cal integral part
	for(int i=0; i<dotIndex; i++){
		dec = dec + (str[i] - '0')*pow(2, integralInd);
		integralInd--;
	}
		
	//return dec value if there is no fractional part
	if(!pd)
		return dec;
	
	//otherwise also cal frac. part	
	int fracIndex = 1;
	for(int i=dotIndex+1; i<n; i++){
		dec = dec + (str[i] - '0')*pow(2, -1*fracIndex);
		fracIndex++;
	}
	
	return dec;
}

