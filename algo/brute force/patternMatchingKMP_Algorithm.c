#include<stdio.h>
#include<string.h>

// String matching using KMP

void pi_table(char str[],int pi[]){
	
	int i=0,j=1,len=strlen(str);
	pi[0] = 0;
	while(j<len){
		if(str[i]==str[j]){
			pi[j] = i+1;
			i++;
			j++;
		}
		else if(i==0){
			pi[j] = 0;
			j++;
		}
		else{
			i = pi[i-1];
		}
	}
	
}

void KMPSearch(char text[],char pat[],int pi[]){
	int patLen = strlen(pat),textLen = strlen(text);
	int i=0,j=0;
	while(i<=textLen){
		if(j==patLen){
			printf("Pattern Found at index: %d\n",i-j);
			j = pi[j-1];
		}
		else if(text[i]==pat[j]){
			i++;
			j++;
		}
		else if(j>0){
			j = pi[j-1];
		}
		else if(j==0){
			i++;
		}
	}
}

int main(){
	char txt[] = "AAAAABAAABA";
    char pat[] = "AAAA";
    int patLen = strlen(pat);
	int pi[patLen];
	pi_table(pat,pi);
	KMPSearch(txt,pat,pi);
}
