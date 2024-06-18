#include <stdio.h>
#include <conio.h>
#define  processNum 5  //进程数
#define resourceNum 4   //资源种类数目

int max[processNum][resourceNum] = {{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};   
       //M个进程对N类资源的最大需求量
int allocation[processNum][resourceNum] = {{0,0,0,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
                                     //M个进程已经得到N类资源的资源量
int need[processNum][resourceNum] = {{0,0,1,0},{0,7,5,0},{1,0,0,2},{0,0,2,0},{0,6,4,2}};  
//M个进程执行完毕仍需的N类资源的资源量
int available[resourceNum]={1,2,2,0};      //系统可用资源数
int isSatisfied( int need_[resourceNum], int available_[resourceNum])  /*用于安全性检查时判断某个进程执行完毕仍需的N类资源的资源量是否小于当前系统可用的N类资源的资源量，若是返回1，否则返回0*/
{
    int i,success=1 ;
    for(i=0;i<resourceNum;i++)    
	if(need_[i]>available_[i])
    {
        success=0 ;
        break ;
    }	
    if(success==1)
    return 1;
    else return 0;    
}

void forward(int pro,int work_[resourceNum],int fini[processNum])     
 //找安全序列时，若某进程符合条件进入安全序列，修改工作向量work=work+allocation；finish[M]=true；
{                                                        
    int i;
    fini[pro]=1 ;
    for(i=0;i<resourceNum;i++)
    work_[i]+=allocation[pro][i];
}

void backward(int pro,int work_[resourceNum],int fini[processNum])   
/*由于找安全序列采用的算法是回溯法，即采用深度优先遍历整棵全解树，当按某条路径走最后不能找到安全序列，于是要回溯上去，回溯的过程中要恢复工作向量，即work=work-allocation；finish[M]=false；*/
{                                                                                           
    int i;
    fini[pro]=0 ;
    for(i=0;i<resourceNum;i++)
    work_[i]-=allocation[pro][i];
}

int isSafe()                  //安全性检查算法，采用的是回溯法
{
    int i,p,discard,s ,c;    
    int finish[processNum];  //工作向量finish[]存放各进程的状态,如执行完毕存1,否则存0
    int safeList[processNum],a=0 ; 	//safeList[]存放安全序列，存放的是各进程的序号， a为数组safeList[]的下标     
    int stack[50],b=0,pre_b;      
  /*当出现2个或者2个以上分支的时候，则要把这些分支节点压入栈stack[]中，被选择的分支节点最后入栈，以便后面若按照该分支节点走却找不到安全序列时回溯回来所用，b为数组stack[]的下标*/                                      
    int work[resourceNum];        //工作向量work，对work进行初始化，使work=available
	for( i = 0; i < resourceNum; i++)
    work[i]=available[i];    
    do 
    {
        pre_b=b ;                  
        for(i=0;i<processNum;i++)  //扫描所有进程,若有进程符合need<available的，入栈
        {
            if(finish[i]==1)continue ;
            else if(isSatisfied(need[i],work)==1)         
            stack[b++]=i;		
        }
        if(b>pre_b)           //表示存在符合条件need<available的进程
        {
            c=b-pre_b;
			if(c==1)          //如果只有一个进程符合条件need<available，该进程出栈
			{	b--;         
                p=stack[b];
                safeList[a++]=p;         //将该进程暂时添加到安全序列里面
                forward(p,work,finish);   //修改工作向量work=work+allocation,finish[M]=true
			}
		    if(c>1)      //如果有2个或以上的进程符合条件need<available，则不用出栈 
			{
                p=stack[b-1];
                safeList[a++]=p ;
                forward(p,work,finish);
			}
        }
        else 
        {
			if(b==0)               //若一开始就没找到
            {
                printf("找不到安全序列\n");
                return 0;
            }
                p=stack[--b];           //p为最后一次分支选择所选择的分支节点(进程的序号)
                if(b==0)               //b==0表示到了栈底,即找不到安全序列,返回0
            {
                printf("找不到安全序列\n");
                return 0;
            }
            a=a-1 ;                 
            while(safeList[a]!=p)  
 //回溯,直到安全序列的指针a指向最后一次分支选择所选择的分支节点(进程的序号)
            {
                discard=safeList[a];
                backward(discard,work,finish);   
//恢复工作向量，即work=work-allocation；finish[M]=false；
                a--;
            }
			backward(p,work,finish);
			while(safeList[a-1]==stack[b-1])     //很关键的一步,但很难表达 
			{
                backward(safeList[a-1],work,finish);
			    a--;
			    b--;}
			if(b==0)
            {
                printf("找不到安全序列\n");
                return 0;
            }
			

			safeList[a++]=stack[b-1];  
//从最后一次分支的所有分支节点中选择还没被选过的分支节点继续深度优先遍历
            s=stack[b-1];
		    forward(s,work,finish);
		}
    }while( a < processNum);                      //当安全序列还没填完
   
    if( a == processNum)                         //如果找到安全序列
	{
        printf("找到安全序列");
        for(i=0;i<processNum;i++)
        printf("%d ",safeList[i]);
        printf(",");
		return 1;
	}
    return 1;
}

int isValid(int pro,int req[resourceNum])  
//判断某进程的请求向量是否同时满足条件Request<=Need 和Request<=Available, 若是返回1，否则返回0 
{                                      
    int i,success1=1,success2=1 ;
    
    for(i=0;i<resourceNum;i++)       //判断某进程的请求向量是否满足条件1:Request<=Need 
    if(req[i]>need[pro][i])
    {
        success1=0 ;
        printf("不满足条件1 Request<=Need\n");
        break ;
    }
    if(success1==1)                //若符合条件1,接着继续判断是否满足条件2:Request<=Available
    {
        printf("满足条件1 Request<=Need\n");
        for(i=0;i<resourceNum;i++)           
        if(req[i]>available[i])
        {
            success2=0 ;
            printf("不满足条件2 Request<=Available\n");
            break ;
        }
        if(success2==1)
        printf("满足条件2 Request<=Available\n");
    }
    if(success1==1&&success2==1)    //只有同时满足才返回1
    return 1 ;
    else return 0 ;
    
}

void tryAllocate(int pro,int req[resourceNum])      
/*试着把资源分配给该请求进程，即该进程的allocation+=request；need-=request；系统当前资源可用数available-=request*/
{                                       
  int i;
  for(i=0;i<resourceNum;i++)
  {
	  allocation[pro][i]+=req[i];
	  need[pro][i]-=req[i];
	  available[i]-=req[i];
  }
}

void resume(int pro,int req[resourceNum])         /*由于试着把资源分配给该请求进程时修改了该进程allocation，need以及系统当前资源可用数available，当试着把资源分配给该请求进程后系统进入不安全状态，则应当恢复该进程allocation，need以及系统当前资源可用数available*/
{
  int i;
  for(i=0;i<resourceNum;i++)
  {
	  allocation[pro][i]-=req[i];
	  need[pro][i]+=req[i];
	  available[i]+=req[i];
  } 
}
void printList()        //输出资源分配表
{
    int i,j ;
	printf("\n                          资源分配表\n");
    printf("-----------------------------------------------------------------------\n");    
    printf("进程        Max         Allocation         Need         Available\n");
	printf("-----------------------------------------------------------------------\n");
    for(i=0;i<processNum;i++)
    {
        printf("%d  ",i);
        printf("\t");
        for(j=0;j<resourceNum;j++)
        printf("%d  ",max[i][j]);
        printf("\t");
        for(j=0;j<resourceNum;j++)
        printf("%d  ",allocation[i][j]);
        printf("\t");
        for(j=0;j<resourceNum;j++)
        printf("%d  ",need[i][j]);
        
        if(i==0)
        {
            printf("\t");
            for(j=0;j<resourceNum;j++)
            printf("%d  ",available[j]);
        }   
		printf("\n");
    }
	 printf("-----------------------------------------------------------------------\n");
}

int main()                                      //主函数
{
	int c;
    int request[resourceNum];                  //request[]用于存放请求进程的请求向量
    int prosess,i,j,finish;     
    printList();                              //首先输出T0时刻的资源分配表
	printf("首先进行T0时刻的安全性检查,");
    if(isSafe()==1)                           //进行T0时刻的安全性检查
	{printf("故T0时刻系统是安全的\n");
    do  
	{
	printf("\n---------------------------------------------------\n");
    printf("请求资源的进程: ");
    scanf("%d",&prosess);                              
    //输入请求进程的序号，本次测试总共有5个进程，序号分别为：0、1、2、3、4
    printf("请求向量(示例:1 0 0 0): ");
        for(i=0;i<resourceNum;i++)
        scanf("%d",&request[i]);     //输入请求向量，即输入进程所请求的各类资源数目
        if(isValid(prosess,request)==1)                  
/*判断请求向量的合法性，要同时满足两个条件：Request<=Need 和Request<=Available。该条件语句表示如果请求向量合法*/
		{
			tryAllocate(prosess,request);               //试着把资源分配给该请求进程
			printf("试探把资源分配给该进程\n");
		    if(isSafe()==0)  
 //判断若把资源分给请求进程，系统是否安全。该条件语句表示如果不安全
			{printf("试探性分配作废，系统恢复原状，进程等待\n");
				resume(prosess,request);  
//恢复请求进程的allocation，need以及系统当前资源可用数available
			}
			else 
			{
				printf("可以将资源分配给该请求进程\n");
                for(finish=1,j=0;j<resourceNum;j++)  
 			//该循环用于判断请求进程的请求得到满足后是否能执行完毕，即其need为0				  			if(need[prosess][j]!=0)                 
				{
					finish=0;
					break;
				}
				if(finish==1)  
{//若执行完毕，该进程释放资源，系统当前资源可用数available+=(该进程的allocation)
                for(j=0;j<resourceNum;j++)               
                    available[j]+=allocation[prosess][j];
for(j=0;j<resourceNum;j++)               
                   allocation[prosess][j]=0;
}
				printf("分配完后的资源分配表如下\n");
				printf("---------------------------------------------------\n");
				printList();                             //输出资源分配表
			}
		}
	printf("是否继续(1/0): ");                           
    scanf("%d",&c);}
	while(c==1);                   //是否继续，若是则再次执行循环体，否则退出	
	}
	else printf("T0时刻系统是不安全的");  
	getche();   
    return 0;
}
