#include <iostream>
#include <sstream>
#include <string>
using namespace std;


int rolldie1();
int rolldie2();
int ability(string current,int playerNum);
int truespace(int space,int playerNum1);
int diceroll();
int coinspace(int playerturn);
string character[5];
int bananastop(int playerturn);
int abilityinfo();
int banana;

int bananaspaceValue[32];
int turnend;
int coinspaceValue[32];
int dice[6];
int spacecount[5]={1,1,1,1,1};
int playerbank[5]={10,10,10,10,10};
int roll1,roll2;
int main(){

for (int i=1; i<5;i++){
cout<<"Player "<<i<<" select character"<<endl;
cin>>character[i];

}

int race;
race=8;








while(race>0){

for (int j=1;j<5;j++){
system("CLS");

for (int bankstatuscount=1;bankstatuscount<5;bankstatuscount++){
cout<<character[bankstatuscount]<<" has "<<playerbank[bankstatuscount]<<" coins and is on space "<<spacecount[bankstatuscount]<<endl;
}
banana=spacecount[j];

cout<<character[j]<<" roll dice"<<endl;

	
	string greenshell,coin,lightning,blueshell,banana,powerroll;
    diceroll();
	cout << "You have rolled: " << dice[0] << endl;	   
	abilityinfo();
	int TurnStatus;
	
	


	cout<<"Press 1 to Move or Press 2 to Activate Ability"<<endl;
	cin>>TurnStatus;
	
	switch(TurnStatus){
		case 1:
		
			bananastop(j);
			if(turnend!=1){	   
				coinspace(j);	 
				spacecount[j]=spacecount[j]+dice[0];
				if (spacecount[j]>32){
					spacecount[j]=spacecount[j]-32;
				}
			}
			turnend=0;
				cout << "You have moved: " <<dice[0]<<" spaces."<< endl;			
				cout<<"You are now on space "<<spacecount[j]<<endl;
			
			truespace(spacecount[j],j);
			ability(character[j],j);
			system("pause");
			

			
			break;
			
		case 2:
			ability(character[j],j);
			bananastop(j);
			if(turnend!=1){	   
				coinspace(j);
				spacecount[j]=spacecount[j]+dice[0];
				if (spacecount[j]>32){
					spacecount[j]=spacecount[j]-32;
				}
			}
			turnend=0;
			cout << "You have moved: " << dice[0] <<  " spaces."<<endl;	   	   	   
			cout<<"You are now on space "<<spacecount[j]<<endl;
			truespace(spacecount[j],j);
			system("pause");
			 break;
	}
}
				
}	 

return 0;
}
int rolldie1(){
	return 1 + rand() % 6;
}


int rolldie2(){
	return 1 + rand() % 6;
}


int ability(string current,int playerNum){
		int q=0;
		int b=0;
		
		if (dice[1]==1){
		cout<<"Rolled: green shell"<<endl;
		cout<<"Select character"<<endl;
		string playerSelect;
		
		cin>>playerSelect;
				while(playerSelect==current){
					cin>>playerSelect;
				}
		
					for (q=1; q<5;q++){
						if (playerSelect==character[q]){
						b=5;
						playerbank[q]=playerbank[q]-3;
						
						coinspaceValue[spacecount[q]]=coinspaceValue[spacecount[q]]+3;
						cout<<character[q]<<" dropped 3 coins"<<endl;
						
						}
						
					}
					
				
		
		
				
		}
		if (dice[1]==2){
				
				
				if(current=="Mario"){
					string choiceMario;
					cout<<"Power-Up Boost: Collect 3 Coins, or add up to 3 spaces to your roll. [Collect/Add]"<<endl;
					cin>>choiceMario;
				 			if(choiceMario=="Collect"){
								cout << "Rolled: coin " << endl;
								playerbank[playerNum]=playerbank[playerNum]+3;
								cout<<character[playerNum]<<" collects 3 coins. "<<endl;
							}
							if(choiceMario=="Add"){
								spacecount[playerNum]=spacecount[playerNum]+3;
							    if (spacecount[playerNum]>32){
									spacecount[playerNum]=spacecount[playerNum]-32;
								}
								cout<<"You are now on space "<<spacecount[playerNum]<<endl;
								truespace(spacecount[playerNum],playerNum);	   	   
								
							}
					
				}	 
						
						
						
						
						
				if(current!="Mario"){	 	 
				cout << "Rolled: coin " << endl;
				playerbank[playerNum]=playerbank[playerNum]+3;
				cout<<character[playerNum]<<" collects 3 coins. "<<endl;
				}
			}
				if (dice[1]==3){
				cout << "Rolled: lightning " << endl;
					if(current=="Toad"){
						for (q=1;q<5;q++){
							if(current!=character[q]){
							playerbank[q]=playerbank[q]-2;
							coinspaceValue[spacecount[q]]=coinspaceValue[spacecount[q]]+1;
							playerbank[playerNum]=playerbank[playerNum]+1;
							cout<<character[q]<<" dropped 2 coin."<<endl;
							cout<<current<<" collects 1 coin."<<endl;
							}
						}
					}
					
					
					
					
					if(current!="Toad"){
					
						for (q=1;q<5;q++){
							if(current!=character[q]){
							playerbank[q]=playerbank[q]-1;
							coinspaceValue[spacecount[q]]=coinspaceValue[spacecount[q]]+1;
							cout<<character[q]<<" dropped 1 coin."<<endl;
							}
						}
					}
		
						
				
				
			}
				if (dice[1]==4){
				cout << "Rolled: blue shell " << endl;
						if(current=="Peach"){
							cout<<"Power-Up Boost: Choose any two players to drop 3 coins [Collect/Add]"<<endl;
								for(int peachBoost=1;peachBoost<3;peachBoost++){
									cout<<"Select character "<<peachBoost<<endl;
									string playerSelect;
									cin>>playerSelect;
										while(playerSelect==current){
											cin>>playerSelect;
				
										}
										for (q=1; q<5;q++){
											if (playerSelect==character[q]){
											playerbank[q]=playerbank[q]-3;
											coinspaceValue[spacecount[q]]=coinspaceValue[spacecount[q]]+3;
											cout<<character[q]<<" dropped 3 coins"<<endl;
											}
						
										}
							
								}
						}
					
						
				
				
				
						if(current!="Peach"){
							cout<<"Select character"<<endl;
							string playerSelect;
							cin>>playerSelect;
								while(playerSelect==current){
								cin>>playerSelect;
								}
									for (q=1; q<5;q++){
										if (playerSelect==character[q]){
											playerbank[q]=playerbank[q]-3;
											coinspaceValue[spacecount[q]]=coinspaceValue[spacecount[q]]+3;
											cout<<character[q]<<" dropped 3 coins"<<endl;
						
										}
						
									}
						}
					
				   	   	   	   
				
				
			}
				if (dice[1]==5){
				int number;
			
				cout << "Rolled: banana" << endl;
				cout<<"You may drop a banana on the following spaces "<<endl;
				int bananadice=dice[0]+1;
				int bananaplace;
				for(int v=0; v<bananadice;v++){
				cout<<v<<", ";
				}
				cout<<endl;
				cin>>number;
				bananaplace=banana+number;
				if(bananaplace>32){
				bananaplace=bananaplace-32;
				}
				bananaspaceValue[bananaplace]=1;
				cout<<"Banana is placed on space "<<bananaplace<<endl;
				
				
				
				
				
			}	 
				if (dice[1]==6){
							if(current=="Mario"){
							string choiceMario;
							cout<<"Power-Up Boost: Collect 3 Coins, or add up to 3 spaces to your roll. [Collect/Add]"<<endl;
							cin>>choiceMario;
				 					if(choiceMario=="Collect"){
										cout << "Rolled: coin " << endl;
										playerbank[playerNum]=playerbank[playerNum]+3;
										cout<<character[playerNum]<<" collects 3 coins. "<<endl;
									}
									if(choiceMario=="Add"){
									spacecount[playerNum]=spacecount[playerNum]+3;
							   			 if (spacecount[playerNum]>32){
											spacecount[playerNum]=spacecount[playerNum]-32;	   	   	   	   	   	   	   	   	   
										}
									cout<<"You are now on space "<<spacecount[playerNum]<<endl;
									truespace(spacecount[playerNum],playerNum);
									}
									
							}	 
										
						
						
						
						
							if(current!="Mario"){	 	 
								cout << "Rolled: coin " << endl;
								playerbank[playerNum]=playerbank[playerNum]+3;
								cout<<character[playerNum]<<" collects 3 coins. "<<endl;
							}
			
			
			
				}
}
int truespace(int space,int playerNum1){
switch(space){

case 1:
cout<<"Collect 2  coins"<<endl;
break;
case 2:
cout<<"You have landed on Mario Kart Stadium"<<endl;
break;
case 3:
	cout<<"You have landed on a Boost Pad"<<endl;
	cout<<"You have rolled " <<dice[3]<<endl;
		spacecount[playerNum1]=spacecount[playerNum1]+dice[3];
			if (spacecount[playerNum1]>32){
				spacecount[playerNum1]=spacecount[playerNum1]-32;	 	 	 	 	 	 	 	 	 
			}
			coinspace(playerNum1);
			cout<<"You are now on space "<<spacecount[playerNum1]<<endl;
			truespace(spacecount[playerNum1],playerNum1);
break;
case 4:
cout<<"You have landed on Water Park"<<endl;
break;
case 5:
	cout<<"You have landed on a Coin Block"<<endl;
	cout<<"You have rolled "<<dice[3]<<endl;
		playerbank[playerNum1]=playerbank[playerNum1]+dice[3];
		cout<<character[playerNum1]<<" has "<< playerbank[playerNum1]<<" coins."<<endl;
		
break;
case 6:
cout<<"You have landed on Sweet Sweet Canyon"<<endl;
break;
case 7:
cout<<"You have landed on a Super Star"<<endl;
break;
case 8:
cout<<"You have landed on Thwomp ruins"<<endl;
break;
case 9:
cout<<"You are now visiting jail"<<endl;
break;
case 10:
cout<<"You have landed on Mario Circuit"<<endl;
break;
case 11:
cout<<"You have landed on a Boost Pad"<<endl;
	cout<<"You have rolled " <<dice[3]<<endl;
		spacecount[playerNum1]=spacecount[playerNum1]+dice[3];
			if (spacecount[playerNum1]>32){
				spacecount[playerNum1]=spacecount[playerNum1]-32;	 	 	 	 	 	 	 	 	 
			}
			coinspace(playerNum1);
			cout<<"You are now on space "<<spacecount[playerNum1]<<endl;
			truespace(spacecount[playerNum1],playerNum1);
break;
case 12:
cout<<"You have landed on Toad Harbor"<<endl;
break;
case 13:
cout<<"You have landed on a Thwomp"<<endl;
break;
case 14:
cout<<"You have landed on Twisted Manson"<<endl;
break;
case 15:
cout<<"You have landed on a Super Star"<<endl;
break;
case 16:
cout<<"You have landed on Shy Guy Falls"<<endl;
break;
case 17:
cout<<"You have landed on Free Parking"<<endl;
break;
case 18:
cout<<"You have landed on Sunshine Airport"<<endl;
break;
case 19:
cout<<"You have landed on a Boost Pad"<<endl;
	cout<<"You have rolled " <<dice[3]<<endl;
		spacecount[playerNum1]=spacecount[playerNum1]+dice[3];
			if (spacecount[playerNum1]>32){
				spacecount[playerNum1]=spacecount[playerNum1]-32;	 	 	 	 	 	 	 	 	 
			}
			coinspace(playerNum1);
			cout<<"You are now on space "<<spacecount[playerNum1]<<endl;
			truespace(spacecount[playerNum1],playerNum1);
break;
case 20:
cout<<"You have landed on Dolphin Shoals"<<endl;
break;
case 21:
cout<<"You have landed on a Coin Block"<<endl;
	cout<<"You have rolled "<<dice[3]<<endl;
		playerbank[playerNum1]=playerbank[playerNum1]+dice[3];
		cout<<character[playerNum1]<<" has "<< playerbank[playerNum1]<<" coins."<<endl;
break;
case 22:
cout<<"You have landed on Electrodome"<<endl;
break;
case 23:
cout<<"You have landed on a Super Star"<<endl;
break;
case 24:
cout<<"You have landed on Mount Wario"<<endl;
break;
case 25:
cout<<"You have landed on: \"Go to Jail\""<<endl;
break;
case 26:
cout<<"You have landed on Cloud Top Cruise"<<endl;
break;
case 27:
cout<<"You have landed on a Boost Pad"<<endl;
	cout<<"You have rolled " <<dice[3]<<endl;
		spacecount[playerNum1]=spacecount[playerNum1]+dice[3];
			if (spacecount[playerNum1]>32){
				spacecount[playerNum1]=spacecount[playerNum1]-32;	 	 	 	 	 	 	 	 	 
			}
			coinspace(playerNum1);
			cout<<"You are now on space "<<spacecount[playerNum1]<<endl;
			truespace(spacecount[playerNum1],playerNum1);
break;
case 28:
cout<<"You have landed on Bone Dry Dunes"<<endl;
break;
case 29:
cout<<"You have landed on Thwomp"<<endl;
break;
case 30:
cout<<"You have landed on Bowser Castle"<<endl;
break;
case 31:
cout<<"You have landed on a Super Star"<<endl;
break;
case 32:
cout<<"You have landed on Rainbow Road"<<endl;
break;

}
}


int diceroll(){
    srand(time(0));	

        dice[0] = rand() % 6 + 1;
        dice[1] = rand() % 6 + 1;
		dice[3] = rand() % 6 + 1;
     
    
}

int coinspace(int playerturn){

int tempcount=spacecount[playerturn];
int tempcount1=spacecount[playerturn];
int tempdice=tempcount+dice[0];
int l=0;
	for(tempcount;   tempcount<tempdice;  tempcount++){
   		l=l+1;
	 
	 	if(coinspaceValue[tempcount+1]>0){
	 		cout<<"There are "<<coinspaceValue[tempcount+1]<<" coins on "<<tempcount1+l<<endl;
	 		playerbank[playerturn]=playerbank[playerturn]+ coinspaceValue[tempcount+1];
	 	}
 	}
}
	 

/*
int bananastop(int turnnumber){

		int pew;
		int s=dice[0]+1;
		
		for(int h=1; h<s; h++){
			pew=banana+h;
				if(bananaspaceValue[pew]=1){
				cout<<"You have slipped on a banana at space "<<pew<<endl;	  	  	  
				dice[0]=h;
				coinspace(turnnumber);	  	  	  
				spacecount[turnnumber]=spacecount[turnnumber]+dice[0];
					if (spacecount[turnnumber]>32){
						spacecount[turnnumber]=spacecount[turnnumber]-32;
					}
				turnend=1;
				}
		}




}
*/
	
int bananastop(int playerturn){

int tempcount=spacecount[playerturn];
int tempcount1=spacecount[playerturn];
int tempdice=tempcount+dice[0];
int l=0;
	for(tempcount;   tempcount<tempdice;  tempcount++){
   		l=l+1;
	 
	 	if(bananaspaceValue[tempcount+1]>0){
	 		cout<<"There is  "<<bananaspaceValue[tempcount+1]<<" banana on "<<tempcount1+l<<endl;
	 		bananaspaceValue[tempcount+1]=bananaspaceValue[tempcount1-1];
			dice[0]=l;
			break;
			coinspace(playerturn);	  	  	  
			spacecount[playerturn]=spacecount[playerturn]+dice[0];
			if (spacecount[playerturn]>32){
				spacecount[playerturn]=spacecount[playerturn]-32;
			}
			turnend=1;
	 	}
 	}
}	   
	
	
	
	
	
	
	
	
	
int abilityinfo(){
		int q=0;
		int b=0;
		
		if (dice[1]==1){
		cout<<"Rolled: green shell"<<endl;	  	  	  	  	  	  	  
		}
		if (dice[1]==2){
		cout << "Rolled: coin " << endl;
		}
		if (dice[1]==3){
		cout << "Rolled: lightning " << endl;
		}
		if (dice[1]==4){
		cout << "Rolled: blue shell " << endl;
		}
		if (dice[1]==5){
		cout << "Rolled: banana" << endl;
		}	 
		if (dice[1]==6){
		cout << "Rolled: coin " << endl;
		}
}



 








 

