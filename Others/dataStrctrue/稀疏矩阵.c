#include<stdio.h>
#include<stdlib.h>
#define MaxSize 2000
typedef struct Triple{  //三元组基本数据
    int i,j;    //下标
    int member;
}Triple;
typedef struct Matrix{  //定义为矩阵
    Triple data[MaxSize+1]; //弃用data[0]
    int InitRow, InitCol, num;
}Matrix,*pMatrix;
pMatrix InitMatrix( pMatrix mat){           //应该返回一个头指针,类似于单链表
    mat = (pMatrix)malloc(sizeof(Matrix));
    printf("请输入矩阵规模m * n\n");
    scanf("%d*%d",&(mat->InitRow),&(mat->InitCol));
    printf("请输入含值的数目num:\n");
    scanf("%d",&(mat->num));
    int i = 1;
    printf("请逐个输入具体的坐标(i,j)和值member:\n");
    while( i-1 < mat->num ){
        scanf("%d,%d,%d",&(mat->data[i].i),&(mat->data[i].j),&(mat->data[i].member));
        i++;
    }
    // 判断
    //printf("%d\n",mat->InitRow );
    return mat;
}
pMatrix MatrixPlus( pMatrix sumM, pMatrix m1, pMatrix m2){
    if( m1->InitRow != m2->InitRow || m1->InitCol != m2->InitCol)
        exit( 0 );
    sumM = (pMatrix)malloc(sizeof(Matrix));
    sumM->InitRow = m1->InitRow;
    sumM->InitCol = m1->InitCol;
    //初始化sumM
    int num = 1;
    while( num-1 < m1->num ){
        sumM->data[num].i = m1->data[num].i;
        sumM->data[num].j = m1->data[num].j;
        sumM->data[num].member = m1->data[num].member;
        num++;
    }       //第一个全赋值
    //判断
    //printf("%d\n",sumM->data[1].member );
    int count = 0;
    for( count = 1; count < m2->num ; num++,count++){
        if( sumM->data[num].i == m2->data[num].i && sumM->data[num].j == m2->data[num].j)
            //判断ij坐标位置
            sumM->data[num].member += m2->data[num].member;
        else{
            sumM->data[num].i = m2->data[num].i;
            sumM->data[num].j = m2->data[num].j;
            sumM->data[num].member = m2->data[num].member;
        }
    }
    return sumM;
}
int main(){
    pMatrix m1,m2,sumM;
    m1 = InitMatrix( m1 );
    printf("%d\n",m1->InitRow );
    m2 = InitMatrix( m2 );
    sumM = MatrixPlus( sumM,m1,m2);
    int i;
    for( i = 0 ; i < sumM->num ; i++){
        printf("i:%d,j:%d,value:%d\n",sumM->data[i+1].i,sumM->data[i+1].j,sumM->data[i+1].member );
    }
    return 0;
}
