#include <stdio.h>
char charkeys[10]={'D','B','D','C','C','D','A','E','A','D'};
int checkscore(char std[]);

int main() {
    int i,j;
    char ans[8][10]={
        	{'A','B','A','C','C','D','E','E','A','D'},//7
			{'D','B','A','B','C','A','E','E','A','D'},//6
			{'E','D','D','A','C','B','E','E','A','D'},//5
			{'C','B','A','E','D','C','E','E','A','D'},//4
			{'A','B','D','C','C','D','E','E','A','D'},//8
			{'B','B','E','C','C','D','E','E','A','D'},//7
			{'B','B','A','C','C','D','E','E','A','D'},//7
			{'E','B','E','C','C','D','E','E','A','D'}};//7

   	for(i=0;i<8;i++){
   		printf("std %d => %d\n", (i+1), checkscore(ans[i]));
	   }
	printf("Number of students correct in question 1 = %d\n",
       countCorrectQ1(ans, 8));
    printf("Hardest question is no = %d\n", hardestQuestion(ans, 8));
    return 0;
}

int checkscore(char std[]){
    int score=0;
    int i;

    for(i=0;i<10;i++){
        if(std[i] == charkeys[i])
            score++;

    }
    return score;
}
int countCorrectQ1(char ans[][10],int students){
    int count=0;
    int i;
    for(i=0; i<students;i++){
        if(ans[i][0]==charkeys[0])
            count++;
    }
    return count;
}
int hardestQuestion(char ans[][10],int students){
    int i,j;
    int minCorrect=students;
    int hardest=0;
    for(j=0;j<10;j++){
        int count=0;
        for(i=0;i<students; i++){
            if(ans[i][j]==charkeys[j])
                count++;
        }
        if(count<minCorrect){
            minCorrect=count;
            hardest=j;
        }
    }
    return hardest+1;
}
