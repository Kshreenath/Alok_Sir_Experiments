#ifndef __TIC_TAC_TOE_H__
#define __TIC_TAC_TOE_H__s

void set_position(int &row,int & coloumn);
void print_layout(int m ,int n,int sd);
/////////////////////////////////////////////////////////////////////////////
void set_position(int &row,int & coloumn)
{
    printf("\n/////////It is your Turn Now//////////");
    printf("\nEnter Row and Coloumn(<ROW> <COLOUMN>):");
    scanf("%d %d",&row,& coloumn);
    printf("\nEntered Value: [%d,%d]",row,coloumn);
}
/////////////////////////////////////////////////////////////////////////////
void print_layout(int m ,int n,int sd){
    for (int j = 0; j < n; j++){
    
       /* code */
    if(j==0){    
    for (int i = 0; i < m; i++)
    {
        if(i==0){
            printf("+--+");
        }
        else{
        printf("--+");
        }
        
    }
    
    printf("\n");
    for (int i=0;i<m;i++){
        if(i==0){
        
            printf("| %c|",sd);
        }        
        else{       
            printf(" %c|",sd);
        }
    
    }
    printf("\n"); 
     for (int i = 0; i < m; i++)
    {
        if(i==0){
            printf("+--+");
        }
        else{
        printf("--+");
        }

    }
     printf("\n");
    }
    else
    {  
    for (int i=0;i<m;i++){
        if(i==0){
        
            printf("| %c|",sd);
        }        
        else{       
            printf(" %c|",sd);
        }
    
    }
    printf("\n"); 
     for (int i = 0; i < m; i++)
    {
        if(i==0){
            printf("+--+");
        }
        else{
        printf("--+");
        }

    }
     printf("\n");       /* code */
    }
     
    }   
}
//////////////////////////////////////////////////////////////////

#endif /* __STATS_H__ */