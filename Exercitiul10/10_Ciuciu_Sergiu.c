#include <stdio.h>
int StringLenght(char *String);
void PunereParanteze(char * string_in, char * string_out);

int main(){
	char S_in[1000];
	char S_out[1000];
	FILE *inputFile;
	FILE *outputFile;

	inputFile = fopen("cor.in","r");
	outputFile = fopen("cor.out","a");

	// verifica ca fisierele sa fie deschise corect
	if (inputFile == NULL || outputFile == NULL)
	{
		printf("eroare la deschiderea fisierelor !!!!");
		return 0;
	}

	//loop pentru a aplica algoritmul pe fiecare string din fisier
	while (fscanf(inputFile,"%s",S_in) != EOF){
		PunereParanteze(S_in,S_out);
		fprintf(outputFile,"%s\n",S_out);
	}
	
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}

//lungimea unui string
int StringLenght(char *String){
	int i = 0;
	while (String[i] != '\0')
		i++;
	return i;
	
}


void PunereParanteze(char *String_in, char *String_out) {
    int i, openParentheses = 0;
     
    for (i = 0; i < String_in[0] - '0'; i++)
        String_out[i] = '(';

    openParentheses += String_in[0] - '0';
     
    for (i = 0; i < StringLenght(String_in) - 1; i++) {
        int diff = String_in[i] - String_in[i + 1];
        if (diff < 0) {
             
            for (int j = 0; j < -diff; j++) {
                String_out[openParentheses++] = '(';
            }
        } else {
            
            for (int j = 0; j < diff; j++) {
                String_out[openParentheses++] = ')';
            }
        }
         
        String_out[openParentheses++] = String_in[i];
    }
     
    String_out[openParentheses++] = String_in[strlen(String_in) - 1];

    for (i = 0; i < String_in[strlen(String_in) - 1] - '0'; i++) {
        String_out[openParentheses++] = ')';
    }

    String_out[openParentheses] = '\0';
}