#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCUVINTE 10000
#define MAXLITERE 1000

void swap(char *a, char *b);
void sortare(char * cuvant, int lenght);
int amestecareCuvant(char* cuvant);

int main(){
    int NumarCuvinte;
    char cuvant[MAXLITERE];
    FILE *inputFile;
	FILE *outputFile;

	inputFile = fopen("ams.in","r");
	outputFile = fopen("ams.out","w");

    fscanf(inputFile,"%d",&NumarCuvinte);
    if (NumarCuvinte > MAXCUVINTE)
        return 0;
        
    
    for (int i = 0; i < NumarCuvinte; i++){
        fscanf(inputFile,"%s",cuvant);
        cuvant[strcspn(cuvant,"\n")] = 0;
        
        if(amestecareCuvant(cuvant) == 1)
            fprintf(outputFile, "%s\n", cuvant);  
        else 
            fprintf(outputFile, "-1\n"); 
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void sortare(char *cuvant ,int length){
     for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (cuvant[j] > cuvant[j + 1]) {
                swap(&cuvant[j], &cuvant[j + 1]);
            }
        }
    }
}

int amestecareCuvant(char* word) {
    int len = strlen(word);

    int i, j;
    for (i = len - 2; i >= 0; i--) {
        if (word[i] < word[i + 1]) {
            break;
        }
    }

    if (i < 0) {
        return 0;  
    }

    for (j = len - 1; j > i; j--) {
        if (word[j] > word[i]) {
            break;
        }
    }

    swap(&word[i], &word[j]);
    sortare(word + i + 1, len - i - 1);  

    return 1;  
}
