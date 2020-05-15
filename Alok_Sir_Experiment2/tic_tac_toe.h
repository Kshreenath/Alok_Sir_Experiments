#ifndef __TIC_TAC_TOE_H__
#define __TIC_TAC_TOE_H__s
#define MSIZE 12
#define MWIDTH 20
using namespace std;
////////GLOBAL VARIABLES////////////
int M,N,K; //// M x N : SIZE , K IN A LINE 
char matrix[MWIDTH][MSIZE];// GMAE MATRIX
int cpu_win[20],p1_win[20];
int MAXDEPTH;
char s_cpu='X';
char s_p1='0';
char sd=' ';
char minimiser=s_cpu;
char maximiser=s_p1;
/////////////////////////DECLARATIONS////////////////////////////
void set_position(int &row,int & coloumn,int m,int n);
void print_layout();
void board_init(int &m,int &n,int &k);
void matrix_init(char matrix[][MSIZE],int m,int n,char sb);
bool nomovesleft();
bool wins(char c);
void Insert(int row ,int col, char c);
void Remove(int row,int col);
int count2s(char c);
int count3s(char c);
int minimax(int depth, char c, int alpha, int beta);
void findmove(int &y,int&x);
void score_init();
void print_arr(int a[],int n);
/////////////#############################################################################################################################################


void print_arr(int a[],int n){
	for (int i = 0; i < n; i++)
	{
		printf("[%d]",a[i]);
	}
	printf("\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void score_init(){
    for(int i=0;i<K-1;i++){
        cpu_win[i]=0;
        p1_win[i]=0;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mangat(char &ch){
    printf("\n Select coin(X or O):");
    scanf("%c",&ch);
    if(!(ch=='X'|ch=='O')){
        printf("\n Invalid Choice,please re-enter:");
        mangat(ch);
    }
}
///////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void board_init(int &m,int &n,int &k){
    printf("\n///////WELCOME//////////");
    printf("\nEnter Board Size(MxN):");
    scanf("%dx%d",&m,&n);
    printf("\nEnter Coins To Win:");
    scanf("%d",&k); 

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void set_position(int &row,int & coloumn,int m,int n)
{
    printf("\n/////////It is your Turn Now//////////");
    printf("\nEnter Row and Coloumn(<ROW> <COLOUMN>):");
    scanf("%d %d",&row,& coloumn);
    printf("\nEntered Value: [%d,%d]",row,coloumn);
    if((row<0|row>m)|(coloumn<0 |coloumn>n)){
        printf("\n !!!!!!!!!Position out of Bound!!!!!!!!!\nPlese Enter Again=>");
        set_position(row,coloumn,m,n);    
    }
    
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void matrix_init(char matrix[][MSIZE],int m,int n,char sb)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j]=sb;
        }
        
    }
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_layout(){
   printf("\n");
   for(int i=0;i<M;i++){
		printf("|");
		for(int j=0;j<N;j++){
			printf(" %c |", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n"); 
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool nomovesleft(){
	for(int i=0;i<M;i++){
        for (int j = 0; j <N; j++)
            {                 
             if(matrix[i][j]==' '){
                return false;
            }
        }
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool wins(char c){
	// Horizontal
    int count=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(matrix[i][j]==c){
                count++;
            }
            else{
                count=0;
            }    
        
        if(count==K){
            return true;
        }}
        
    }

	// Vertical
	count=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(matrix[j][i]==c){
                count++;
            }
            else{
                count=0;
            }
            
        if(count==K){
            return true;
        }}
        
    }
	// Diagonal
	count=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<K ;k++){
                if (matrix[i+k][j+k]==c){
                count++;
                }
                else{
                    count=0;
                }
                if(count==K){
                    return true;
                }
            }
        }
    }
	
    //Cross diagonal
    count=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<K ;k++){
                if (matrix[i+k][j-k]==c){
                count++;
                }
                else{
                    count=0;
                }
                if(count==K){
                    return true;
                }
            }
        }
    }
    return false;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Insert(int row ,int col, char c){
	
    	if(matrix[row][col]==' '){
		matrix[row][col]=c;}
        else{

            printf("\nINVALID INDEX OR PLACE IS NOT VACANT!");
            return;
            
        }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Remove(int row,int col){
	
		if(matrix[row][col]!=' '){
			matrix[row][col]=' ';
			return;
		}
		
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void score_keeper(int a[],int i1,char c)
{   int count=0;
    // Horizontal
      for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(matrix[i][j]==c){
                count++;
            }
            else{
                count=0;
            }    
        }       
    }
    a[count]+=count;    
	//print_arr(a,20);

    // Vertical
	count=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(matrix[j][i]==c){
                count++;
            }
            else{
                count=0;
            }
        }
    }
	a[count]+=count;    
	//print_arr(a,20);
    
    // Diagonal
	count=0;
    for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<K ;k++){
                    if (matrix[i+k][j+k]==c){
                    count++;
                    }
                    else{
                        count=0;
                    }
                }
            }
    }
        
	a[count]+=count;    
	//print_arr(a,20);

    //Cross diagonal
    count=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<K ;k++){
                if (matrix[i+k][j-k]==c){
                count++;
                }
                else{
                    count=0;
                }
                
            }
        }
    }
    a[count]+=count;    
	//print_arr(a,20);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int minimax(int depth, char ch, int alpha, int beta){
	
    int sum=0;
    if(wins(maximiser)){
		return 100-depth;
	}
	else if(wins(minimiser)){
		return -100+depth;
	}
	else if(nomovesleft()){
		return 0;
	}
    ///////////initialise score matrix
    score_keeper(cpu_win,1,minimiser);
    score_keeper(p1_win,2,maximiser);

	if(depth>=MAXDEPTH){
		for(int i=2;i<=K-1;i++){
        sum+=5*i*(p1_win[i]-cpu_win[i]);
        }
        //return 5*(count2s(maximiser)-count2s(minimiser))+10*(count3s(maximiser)-count3s(minimiser));
        return sum;
    }

	int curbest, value;
	if(ch==maximiser){
		curbest=-100;
		for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){	
                if(matrix[i][j]==' '){
                    Insert(i,j, maximiser);
                    curbest=max(curbest, minimax(depth+1, minimiser, alpha, beta));
                    Remove(i,j);
                    alpha=max(alpha, curbest);
                    if(alpha>=beta){
                        break;
                    }
                }
            }
        }
		return curbest;
	}
	else{
		curbest=100;
		for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(matrix[i][j]==' '){
                    Insert(i,j, minimiser);
                    curbest=min(curbest, minimax(depth+1, maximiser, alpha, beta));
                    Remove(i,j);
                    beta=min(beta, curbest);
                    if(alpha>=beta){
                        break;
                    }
                }	
            }
        }
		return curbest;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void findmove(int &y, int &x){
	int curmove_x,curmove_y;
	int curbest=-100, value;
	for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(matrix[i][j]==' '){
                Insert(i,j, maximiser);
                value=minimax(0, minimiser, -1000, 1000);
                if(value>curbest){
                    curbest=value;
                    curmove_x=j;
                    curmove_y=i;
                }
                Remove(i,j);
            }
        }
    }
	x=curmove_x;
    y=curmove_y;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif 