#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random1to100();
void best3_by_select(int score[],int best3[]);
void best3_by_sort(int score[],int best3[]);

int main(){
    int score1[4]={65, 80, 75, 90};
    int score2[4]={65, 80, 75, 90};
    int best3[3];
    int i;

    best3_by_select(score1,best3);
    printf("Best 3 (select):");
    for (i=0;i<3;i++)
        printf(" %d ", best3[i]);

    printf("\n");

    best3_by_sort(score2,best3);
    printf("Best 3 (sort):");
    for(i=0;i<3;i++)
        printf(" %d ", best3[i]);

    return 0;
}
void printAr(int numAr[],int numArSize){
    int i;
    for (i=0;i<numArSize;i++)
        printf("%d ",numAr[i]);
}

int checkNum(int numAr[],int numArSize){
    int rnum;
    rnum=random1to100();
    while (searchNum(numAr,numArSize,rnum)){
        rnum=random1to100();
    }
    return rnum;
}
void best3_by_select(int score[], int best3[]){
    int i,j,max,idx;
    for (i=0;i<3;i++){
        max=score[0];
        idx=0;
        for (j=1;j<4;j++){
            if (score[j]>max){
                max=score[j];
                idx=j;
            }
        }
        best3[i]=max;
        score[idx]=-1;
    }
}
void best3_by_sort(int score[],int best3[]){
    int i,j,temp;
    for (i=0;i<3;i++){
        for (j=0;j<3-i;j++) {
            if (score[j]>score[j+1]){
                temp=score[j];
                score[j]=score[j+1];
                score[j+1]=temp;
            }
        }
    }
    for (i=0;i<3;i++)
        best3[i]=score[i+1];
}

int searchNum(int numAr[],int numArSize,int target){
    int i,found=0;
    for (i=0;i<numArSize;i++){
        if (numAr[i]==target){
        	found=1;
        	break;
		}
    }
    return found;
}
int random1to100(){
    int random_num = (rand() % 100) + 1;
    printf("%d", random_num);
    return random_num;
}
