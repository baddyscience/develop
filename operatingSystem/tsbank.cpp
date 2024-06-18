#include <stdio.h>
#include <conio.h>
#define  processNum 5  //������
#define resourceNum 4   //��Դ������Ŀ

int max[processNum][resourceNum] = {{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};   
       //M�����̶�N����Դ�����������
int allocation[processNum][resourceNum] = {{0,0,0,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
                                     //M�������Ѿ��õ�N����Դ����Դ��
int need[processNum][resourceNum] = {{0,0,1,0},{0,7,5,0},{1,0,0,2},{0,0,2,0},{0,6,4,2}};  
//M������ִ����������N����Դ����Դ��
int available[resourceNum]={1,2,2,0};      //ϵͳ������Դ��
int isSatisfied( int need_[resourceNum], int available_[resourceNum])  /*���ڰ�ȫ�Լ��ʱ�ж�ĳ������ִ����������N����Դ����Դ���Ƿ�С�ڵ�ǰϵͳ���õ�N����Դ����Դ�������Ƿ���1�����򷵻�0*/
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
 //�Ұ�ȫ����ʱ����ĳ���̷����������밲ȫ���У��޸Ĺ�������work=work+allocation��finish[M]=true��
{                                                        
    int i;
    fini[pro]=1 ;
    for(i=0;i<resourceNum;i++)
    work_[i]+=allocation[pro][i];
}

void backward(int pro,int work_[resourceNum],int fini[processNum])   
/*�����Ұ�ȫ���в��õ��㷨�ǻ��ݷ���������������ȱ�������ȫ����������ĳ��·����������ҵ���ȫ���У�����Ҫ������ȥ�����ݵĹ�����Ҫ�ָ�������������work=work-allocation��finish[M]=false��*/
{                                                                                           
    int i;
    fini[pro]=0 ;
    for(i=0;i<resourceNum;i++)
    work_[i]-=allocation[pro][i];
}

int isSafe()                  //��ȫ�Լ���㷨�����õ��ǻ��ݷ�
{
    int i,p,discard,s ,c;    
    int finish[processNum];  //��������finish[]��Ÿ����̵�״̬,��ִ����ϴ�1,�����0
    int safeList[processNum],a=0 ; 	//safeList[]��Ű�ȫ���У���ŵ��Ǹ����̵���ţ� aΪ����safeList[]���±�     
    int stack[50],b=0,pre_b;      
  /*������2������2�����Ϸ�֧��ʱ����Ҫ����Щ��֧�ڵ�ѹ��ջstack[]�У���ѡ��ķ�֧�ڵ������ջ���Ա���������ո÷�֧�ڵ���ȴ�Ҳ�����ȫ����ʱ���ݻ������ã�bΪ����stack[]���±�*/                                      
    int work[resourceNum];        //��������work����work���г�ʼ����ʹwork=available
	for( i = 0; i < resourceNum; i++)
    work[i]=available[i];    
    do 
    {
        pre_b=b ;                  
        for(i=0;i<processNum;i++)  //ɨ�����н���,���н��̷���need<available�ģ���ջ
        {
            if(finish[i]==1)continue ;
            else if(isSatisfied(need[i],work)==1)         
            stack[b++]=i;		
        }
        if(b>pre_b)           //��ʾ���ڷ�������need<available�Ľ���
        {
            c=b-pre_b;
			if(c==1)          //���ֻ��һ�����̷�������need<available���ý��̳�ջ
			{	b--;         
                p=stack[b];
                safeList[a++]=p;         //���ý�����ʱ��ӵ���ȫ��������
                forward(p,work,finish);   //�޸Ĺ�������work=work+allocation,finish[M]=true
			}
		    if(c>1)      //�����2�������ϵĽ��̷�������need<available�����ó�ջ 
			{
                p=stack[b-1];
                safeList[a++]=p ;
                forward(p,work,finish);
			}
        }
        else 
        {
			if(b==0)               //��һ��ʼ��û�ҵ�
            {
                printf("�Ҳ�����ȫ����\n");
                return 0;
            }
                p=stack[--b];           //pΪ���һ�η�֧ѡ����ѡ��ķ�֧�ڵ�(���̵����)
                if(b==0)               //b==0��ʾ����ջ��,���Ҳ�����ȫ����,����0
            {
                printf("�Ҳ�����ȫ����\n");
                return 0;
            }
            a=a-1 ;                 
            while(safeList[a]!=p)  
 //����,ֱ����ȫ���е�ָ��aָ�����һ�η�֧ѡ����ѡ��ķ�֧�ڵ�(���̵����)
            {
                discard=safeList[a];
                backward(discard,work,finish);   
//�ָ�������������work=work-allocation��finish[M]=false��
                a--;
            }
			backward(p,work,finish);
			while(safeList[a-1]==stack[b-1])     //�ܹؼ���һ��,�����ѱ�� 
			{
                backward(safeList[a-1],work,finish);
			    a--;
			    b--;}
			if(b==0)
            {
                printf("�Ҳ�����ȫ����\n");
                return 0;
            }
			

			safeList[a++]=stack[b-1];  
//�����һ�η�֧�����з�֧�ڵ���ѡ��û��ѡ���ķ�֧�ڵ����������ȱ���
            s=stack[b-1];
		    forward(s,work,finish);
		}
    }while( a < processNum);                      //����ȫ���л�û����
   
    if( a == processNum)                         //����ҵ���ȫ����
	{
        printf("�ҵ���ȫ����");
        for(i=0;i<processNum;i++)
        printf("%d ",safeList[i]);
        printf(",");
		return 1;
	}
    return 1;
}

int isValid(int pro,int req[resourceNum])  
//�ж�ĳ���̵����������Ƿ�ͬʱ��������Request<=Need ��Request<=Available, ���Ƿ���1�����򷵻�0 
{                                      
    int i,success1=1,success2=1 ;
    
    for(i=0;i<resourceNum;i++)       //�ж�ĳ���̵����������Ƿ���������1:Request<=Need 
    if(req[i]>need[pro][i])
    {
        success1=0 ;
        printf("����������1 Request<=Need\n");
        break ;
    }
    if(success1==1)                //����������1,���ż����ж��Ƿ���������2:Request<=Available
    {
        printf("��������1 Request<=Need\n");
        for(i=0;i<resourceNum;i++)           
        if(req[i]>available[i])
        {
            success2=0 ;
            printf("����������2 Request<=Available\n");
            break ;
        }
        if(success2==1)
        printf("��������2 Request<=Available\n");
    }
    if(success1==1&&success2==1)    //ֻ��ͬʱ����ŷ���1
    return 1 ;
    else return 0 ;
    
}

void tryAllocate(int pro,int req[resourceNum])      
/*���Ű���Դ�������������̣����ý��̵�allocation+=request��need-=request��ϵͳ��ǰ��Դ������available-=request*/
{                                       
  int i;
  for(i=0;i<resourceNum;i++)
  {
	  allocation[pro][i]+=req[i];
	  need[pro][i]-=req[i];
	  available[i]-=req[i];
  }
}

void resume(int pro,int req[resourceNum])         /*�������Ű���Դ��������������ʱ�޸��˸ý���allocation��need�Լ�ϵͳ��ǰ��Դ������available�������Ű���Դ�������������̺�ϵͳ���벻��ȫ״̬����Ӧ���ָ��ý���allocation��need�Լ�ϵͳ��ǰ��Դ������available*/
{
  int i;
  for(i=0;i<resourceNum;i++)
  {
	  allocation[pro][i]-=req[i];
	  need[pro][i]+=req[i];
	  available[i]+=req[i];
  } 
}
void printList()        //�����Դ�����
{
    int i,j ;
	printf("\n                          ��Դ�����\n");
    printf("-----------------------------------------------------------------------\n");    
    printf("����        Max         Allocation         Need         Available\n");
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

int main()                                      //������
{
	int c;
    int request[resourceNum];                  //request[]���ڴ��������̵���������
    int prosess,i,j,finish;     
    printList();                              //�������T0ʱ�̵���Դ�����
	printf("���Ƚ���T0ʱ�̵İ�ȫ�Լ��,");
    if(isSafe()==1)                           //����T0ʱ�̵İ�ȫ�Լ��
	{printf("��T0ʱ��ϵͳ�ǰ�ȫ��\n");
    do  
	{
	printf("\n---------------------------------------------------\n");
    printf("������Դ�Ľ���: ");
    scanf("%d",&prosess);                              
    //����������̵���ţ����β����ܹ���5�����̣���ŷֱ�Ϊ��0��1��2��3��4
    printf("��������(ʾ��:1 0 0 0): ");
        for(i=0;i<resourceNum;i++)
        scanf("%d",&request[i]);     //�����������������������������ĸ�����Դ��Ŀ
        if(isValid(prosess,request)==1)                  
/*�ж����������ĺϷ��ԣ�Ҫͬʱ��������������Request<=Need ��Request<=Available������������ʾ������������Ϸ�*/
		{
			tryAllocate(prosess,request);               //���Ű���Դ��������������
			printf("��̽����Դ������ý���\n");
		    if(isSafe()==0)  
 //�ж�������Դ�ָ�������̣�ϵͳ�Ƿ�ȫ������������ʾ�������ȫ
			{printf("��̽�Է������ϣ�ϵͳ�ָ�ԭ״�����̵ȴ�\n");
				resume(prosess,request);  
//�ָ�������̵�allocation��need�Լ�ϵͳ��ǰ��Դ������available
			}
			else 
			{
				printf("���Խ���Դ��������������\n");
                for(finish=1,j=0;j<resourceNum;j++)  
 			//��ѭ�������ж�������̵�����õ�������Ƿ���ִ����ϣ�����needΪ0				  			if(need[prosess][j]!=0)                 
				{
					finish=0;
					break;
				}
				if(finish==1)  
{//��ִ����ϣ��ý����ͷ���Դ��ϵͳ��ǰ��Դ������available+=(�ý��̵�allocation)
                for(j=0;j<resourceNum;j++)               
                    available[j]+=allocation[prosess][j];
for(j=0;j<resourceNum;j++)               
                   allocation[prosess][j]=0;
}
				printf("����������Դ���������\n");
				printf("---------------------------------------------------\n");
				printList();                             //�����Դ�����
			}
		}
	printf("�Ƿ����(1/0): ");                           
    scanf("%d",&c);}
	while(c==1);                   //�Ƿ�������������ٴ�ִ��ѭ���壬�����˳�	
	}
	else printf("T0ʱ��ϵͳ�ǲ���ȫ��");  
	getche();   
    return 0;
}
