#include<iostream>
#include<unistd.h>
using namespace std;

char table[9]={'1','2','3','4','5','6','7','8','9'};
string nplayer1 , nplayer2;
int playerround=1;

void getNamePlayer();
void printTable();
void getInput();
char nobat();
bool isNotEnd();
bool isWin();
bool isFull();
string getNameOfRound();
string whoIsWinner();
bool isTableFull(char );


//////////////////////////////////////////////////////////////////////////////

int main(){

getNamePlayer();
    while (isNotEnd()){

        printTable();
        getInput();
         
    }
    
cout<<whoIsWinner();	  

    
   
    
}

///////////////////////////////////////////////////////////////////////////////
void getNamePlayer(){
    cout<<"Enter player 1 name : "<<endl;
    getline(cin,nplayer1);
    cout<<"Enter player 2 name : "<<endl;
    getline(cin,nplayer2);

}

string getNameOfRound(){
    if(nobat()== 'X')
        return nplayer1;
    else
        return nplayer2;    
}

bool isNotEnd(){
     if( isFull() || isWin())
        return false;
     else
        return true;   

}
bool isWin(){

    
    
    if(table[0]== table[1] && table[1]== table[2])
		{
		
        return true;
		}
    else if(table[3]== table[4] && table[4]== table[5])
        {
		
        return true;
		}
    else if(table[6]== table[7] && table[7]== table[8])
        {
		
        return true;
		}
    else if(table[0]== table[3] && table[3]== table[6])
        {
	
        return true;
		}
    else if(table[1]== table[4] && table[4]== table[7])
        {
		
        return true;
		}
    else if(table[2]== table[5] && table[5]== table[8])
        {
		
        return true;
		}
    else if(table[0]== table[4] && table[4]== table[8])
        {
		
        return true;
		}
    else if(table[2]== table[4] && table[4]== table[6])
        {
		
        return true;
		}

    else{
        return false;
    }     
     

}

bool isFull(){
    for(int i=0; i<9; i++ ){
        if(table[i] !='X' && table[i] !='O')
        	return false;	
    }
	cout<<"Drow !";
	return true;
}

void printTable(){
    system("cls");
    cout<<"player 1 : "<< nplayer1<< "   player 2 : "<< nplayer2<<endl;
    cout<<"------------------------"<<endl;
    cout<<"|       |       |       |"<<endl;
    cout<<"|   "<<table[0]<<"   |   "<<table[1]<<"   |   "<<table[2]<<"   |"<<endl;
    cout<<"|       |       |       |"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"|       |       |       |"<<endl;
    cout<<"|   "<<table[3]<<"   |   "<<table[4]<<"   |   "<<table[5]<<"   |"<<endl;
    cout<<"|       |       |       |"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"|       |       |       |"<<endl;
    cout<<"|   "<<table[6]<<"   |   "<<table[7]<<"   |   "<<table[8]<<"   |"<<endl;
    cout<<"|       |       |       |"<<endl;
    cout<<"-------------------------"<<endl; 

}

char nobat(){
    if(playerround % 2 == 0)
        return 'X';
    else
        return 'O';    
}

bool isTableFull(char input){
	int x = (int)input - 48 ;
	if(table[x]=='X' || table[x]=='O'){
		return true;
	}
	else{
		return false;
	}
}

void getInput(){
    playerround++;
    char input;
    cout<<"Enter number between 1-9 player ( "<< getNameOfRound()<<"-> "<< nobat() << " ) :" <<endl;
    cin>>input;
    while(isTableFull(input)){
    	cout<<"Warning , table is not available. Try another one : ";
    	cin>> input;
	}

    switch (input)
    {
    case '1':
        table[0]= nobat();
        break;
    case '2':
        table[1]= nobat();
        break;
    case '3':
        table[2]= nobat();
        break;    
    case '4':
        table[3]= nobat();
        break;
    case '5':
        table[4]= nobat();
        break;
    case '6':
        table[5]= nobat();
        break;
    case '7':
        table[6]= nobat();
        break;
    case '8':
        table[7]= nobat();
        break;
    case '9':
        table[8]= nobat();
        break;
	default:
		cout<<"Error ---   just 1-9 numbert allowded.";
		sleep(4);
		break;	                    
    }

}

string whoIsWinner(){
	if(isFull()){
		return "Drow";
	}
	else{
	
		return "player "+ getNameOfRound() +" is winner .";
	}
}





