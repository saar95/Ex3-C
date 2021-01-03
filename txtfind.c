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
	while (w[i] != '\n' && w[i] != ',' && w[i] != '\t' && w[i] != ' ' && i < WORD){
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
	if (i == sizeT) //almog homo לפחות או בידיוק (הומו בטוח הלפחות או בידיוק קשור ל n)
		return 1;
	return 0;

}

void print_lines(char* str) {

	int count=0;
	FILE *fp;
   	char buff[255];
   	char* word;
  	fp = fopen("test.txt", "r");
   while (fgets(buff, 255, (FILE*)fp)!=NULL)
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
   fclose(fp);
}


void print_similar_words(char* str) {
	int count=0;
	FILE *fp;
   	char buff[255];
   	char* word;
  	fp = fopen("test.txt", "r");
   while (fgets(buff, 255, (FILE*)fp)!=NULL)
   {  	count = 0;
		while(count < strlen(buff)){
   			word = getword(buff+count);
			int sum = similar(word,str,1);
			if(sum==1){
				printf("%s \n",word);
			}
			count += strlen(word) + 1;
		}
   }
   fclose(fp);

}

int main(int argc, char** argv) {
	char w[] = "cat";
	print_lines(w);
	print_similar_words(w);
	return 0;
}