#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LINE 256
#define WORD 30

// char* getline1(char s[]) {
// 	char* t [LINE];
// 	int i = 0;
// 	while (s[i++] != '\n'&&i<LINE)
// 		t[i]=s[i];
// 	return t;
// }

char* getword(char w[]) {
	char* t = malloc(sizeof(char)*WORD+1);
	int i = 0;
	while (w[i] != '\n' && w[i] != ',' && w[i] != '\t' && w[i] != ' ' && w[i] != '\0' && i < WORD && (int)w[i] != 13){
		t[i]=w[i];
		i++;
	}
	t[i] = '\0';
	return t;
}

int substring(char* str1, char* str2) {
	int i = 0;
	int j = 0;
	while (*(str2 + i) != '\0'  && *(str1 + j) != '\0')
	{
		if (*(str2 + i) == *(str1 + j)) {
			i++;
			j++;
		}
		else
		{
			i = 0;
			j++;
		}
	}
	if (*(str2 + i) == '\0')
		return 1;
	return 0;
}

int similar(char* s, char* t, int n) {
	int i = 0;
	int j = 0;
	int sizeT = strlen(t);
	int sizeS = strlen(s);
	if (sizeT > sizeS)
		return 0;
	while (s[i] != '\0' && t[j] != '\0' && n>=0)
	{
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			i++;
			n--;
		}
	}
	if ((j == sizeT && i == sizeS && n >= 0) || ( j == sizeT && sizeS-i <= n)) //almog homo לפחות או בידיוק (הומו בטוח הלפחות או בידיוק קשור ל n)
		return 1;
	return 0;

}

int contain(char* s, char* t) {
	int i = 0;
	int j = 0;
	int sizeT = strlen(t);
	int sizeS = strlen(s);
	if (sizeT > sizeS)
		return 0;
	while (s[i] != '\0' && t[j] != '\0' )
	{
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else{
			i=0;
			j++;
		}
	}
	if (i == sizeT)
		return 1;
	return 0;

}

void print_lines(char* str) {

	int count=0;
   	char buff[LINE];
   	char* word;
	fgets(buff, LINE, (stdin));

   while (fgets(buff, LINE, (stdin))!=NULL)
   {  	count = 0;
		while(count < strlen(buff)){
   			word = getword(buff+count);
			int sum = contain(word,str);
			if(sum==1){
				printf("%s",buff);
				break;
			}
			count += strlen(word) + 1;
		}
   }
}


void print_similar_words(char* str) {
	int count=0;
   	char buff[255];
   	char* word;
	fgets(buff, LINE, (stdin));
   while (fgets(buff, 255, stdin)!=NULL)
   {  	count = 0;
		while(count < strlen(buff)){
   			word = getword(buff+count);
			int sum = similar(word,str,1);
			if(sum==1){
				printf("%s\n",word);
			}
			count += strlen(word) + 1;
		}
   }
}

int main() {
    char line[LINE];
	char w[WORD];
	fgets(line, LINE ,stdin);
	int j = 0;
	int i = 0;
	for(i = 0 ; i < LINE ; i++){
		if(line[i] == ' ' || line[i] == '\t' ){
			break;
		}
		else{
			w[j] = line[i];
			j++;
		}
	}
	w[j] = '\0';
	i++;
	if(line[i] == 'a'){
		print_lines(w);
	}
	if(line[i] == 'b'){
		print_similar_words(w);
	}
	return 0;
}