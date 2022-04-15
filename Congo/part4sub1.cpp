#include <bits/stdc++.h>
#include<iostream>
#include <string>
#include<cstring>
#include <cstdlib>
#include <algorithm> 
#include <cmath>

using namespace std;


vector<string> split(string str,char separator){

       string temp = "";
       vector<string>holder;
   
      for(int i=0; i<str.length(); i++){
        
         if(str[i] != separator){
            temp += str[i];
        }

          else{
            holder.push_back(temp);
              temp = "";
        }
    }
       
      holder.push_back(temp);

        return holder;
}




vector<string> split_fen(string temp){

    vector<string>thing = split(temp,' ');

  return thing;
}



vector<vector<string>> correcting_string(string temp){
 
    vector<string>holder = split_fen(temp);

    string temp2 = holder[0];
    vector<string>holder1;
    holder1 = split(temp2,'/');

    string temp3 ="";

    for(int i=0;i< holder1.size();++i){

       temp3 = temp3 + holder1[i]; 
    }

    vector<string>holder2;
    for(int i=0;i<temp3.length();++i){

        string s(1,temp3[i]);
        holder2.push_back(s);
    
    }

    for(int i=0; i< holder2.size();++i ){

        if(holder2[i]=="7"){
            holder2[i]="0000000";
        }

        else if(holder2[i]=="6"){
                holder2[i]="000000";

        }

        else if(holder2[i]=="5"){
                holder2[i]="00000";
        }

        else if(holder2[i]=="4"){
                holder2[i]="0000";
        }


        else if(holder2[i]=="3"){
                holder2[i]="000";
        }


        else if(holder2[i]=="2"){
                holder2[i]="00";
        }

        else if(holder2[i]=="1"){
                holder2[i]="0";

        }
        
    }


    string temp4 ="";

    for(int i=0;i< holder2.size();++i){

       temp4 = temp4 + holder2[i]; 
    }

    

    int index =0;

    vector<vector<string>>board(7,vector<string>(7));

    for(int i=0; i< 7;++i){
        for(int j =0; j < 7;++j ){
        
          board[i][j]= temp4[index];
          ++index;
        }
    }

  return board;
}


void score_function(vector<vector<string>>board,string fen){


vector<string> temp = split_fen(fen);
	
	int sumotherpw = 0;
	int sumLw = 0 ;
	
	int sumotherpb = 0;
	int sumLb = 0 ;
      
        
          for(int i=0 ; i < board.size();++i ){
              for(int j = 0; j < board[0].size();++j){


                 if( board[i][j] == "L"){
                 	
                     sumLw = 10000;

                }
                


                if( board[i][j] =="P" ){
                
                      sumotherpw = sumotherpw + 100;
                }
                
             

                if(  board[i][j] == "E"){
                    
                   sumotherpw = sumotherpw + 200;

                }
           
              


             	if(board[i][j] == "Z"){
                
                sumotherpw = sumotherpw + 300;

             	}
           

          // black moves

                 if( board[i][j] == "l"){
                 
                     sumLb = -10000;

                }
                


                if( board[i][j] == "p" ){
                
                      sumotherpb = sumotherpb + 100;
                }
                
             

                if(  board[i][j] == "e"){
                    
                   sumotherpb = sumotherpb + 200;

                }
           
              


             	if(board[i][j] == "z"){
                
                sumotherpb = sumotherpb + 300;

             	}
           

          
     	
     	 }
     	 
      }    
      
      
    //  if(sumotherpw==0 and sumotherpb == 0 and sumLw ==10000 and sumLb==-10000){
          
      //    	cout<<0<<endl;		
      //    }
         
     


          if(temp[1]=="b"){   
          
          
          
         
           
          if( sumLw==0 and sumLb==-10000 ){
          	cout<<10000<<endl;
          	
          }
          	
          	
         else if(sumLw==10000 and sumLb==0){
          		
          	cout<<-10000<<endl;
          	
          }
          
          
         else{
          
          	int temp2 = sumotherpb - sumotherpw;
          	cout<<temp2<<endl;
          	
          } 
          
          
          }
          
          
          if(temp[1]=="w"){   
         
           
          if( sumLw==0 and sumLb==-10000 ){
          
          	cout<<-10000<<endl;
          	}
          	
           else if(sumLw==10000 and sumLb==0){
          
          		
          	cout<<10000<<endl;
          	
          }
          
          
          else{
          	
          	int temp2 = sumotherpw -sumotherpb;
          	cout<<temp2<<endl;
          } 
          
          
          }
         
          
          
          

 }


int main(){

	
      int N;
     cin >> N;
    cin.ignore(); 
    
    
   for (int k = 0; k < N; ++k) {

      string fen;
      getline(cin, fen); 
	vector<vector<string>> bo = correcting_string(fen);	
	score_function(bo,fen);
	
	}
	
	
	
		

return 0;
}
