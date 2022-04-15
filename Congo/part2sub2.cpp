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

void printing(vector<vector<string>> temp){

  for(int i=0;i < temp.size();++i){
    for(int j =0 ;j < temp[0].size();++j){
        cout<<temp[i][j]<<" ";

    }
    cout<<endl;

  }




}


vector<vector<string>> zebra_moves(vector<vector<string>>board, string fen){

      vector<string> temp = split_fen(fen);
      vector<string>storewhite;
      vector<vector<string>>storage;

       vector<vector<string>>moves
    {
      {"a7","b7","c7","d7","e7","f7","g7"},
      {"a6","b6","c6","d6","e6","f6","g6"},
      {"a5","b5","c5","d5","e5","f5","g5"},
      {"a4","b4","c4","d4","e4","f4","g4"},
      {"a3","b3","c3","d3","e3","f3","g3"},
      {"a2","b2","c2","d2","e2","f2","g2"},
      {"a1","b1","c1","d1","e1","f1","g1"}
      
      }; 




      if(temp[1]=="w"){
        
          for(int i=0 ; i < board.size();++i ){
              for(int j = 0; j < board[0].size();++j){

                if(board[i][j]=="Z"){

                  storewhite.push_back(moves[i][j]);

                 if( j-2 >=0 and i+1 < 7 and board[i+1][j-2]!="P" and board[i+1][j-2]!="E" and board[i+1][j-2]!="M" and board[i+1][j-2]!="L" and board[i+1][j-2]!="C" and board[i+1][j-2]!="G"){
                      storewhite.push_back(moves[i+1][j-2]);

                }
                


                if( j+2 < 7 and i+1 < 7 and board[i+1][j+2]!="P" and board[i+1][j+2]!="E" and board[i+1][j+2]!="M" and board[i+1][j+2]!="L" and board[i+1][j+2]!="C" and board[i+1][j+2]!="G"){
                       storewhite.push_back(moves[i+1][j+2]);

                }
             

                if( i-1 >= 0 and j+2 < 7 and board[i-1][j+2]!="P" and board[i-1][j+2]!="E" and board[i-1][j+2]!="M" and board[i-1][j+2]!="L" and board[i-1][j+2]!="C" and board[i-1][j+2]!="G"){
                    storewhite.push_back(moves[i-1][j+2]);

                }
           

                if( i-1 >= 0 and j-2 >= 0 and board[i-1][j-2]!="P" and board[i-1][j-2]!="E" and board[i-1][j-2]!="M" and board[i-1][j-2]!="L" and board[i-1][j-2]!="C" and board[i-1][j-2]!="G"){
                    storewhite.push_back(moves[i-1][j-2]);
               }
            
             

                if( i-2 >=0  and j+1 < 7 and board[i-2][j+1]!="P" and board[i-2][j+1]!="E" and board[i-2][j+1]!="M" and board[i-2][j+1]!="L" and board[i-2][j+1]!="C" and board[i-2][j+1]!="G"){
                    storewhite.push_back(moves[i-2][j+1]);

              }
              


             if( i-2 >= 0 and j-1 >= 0 and board[i-2][j-1]!="P" and board[i-2][j-1]!="E" and board[i-2][j-1]!="M" and board[i-2][j-1]!="L" and board[i-2][j-1]!="C" and board[i-2][j-1]!="G"){
                storewhite.push_back(moves[i-2][j-1]); 

             }

             if( i+2 < 7 and j+1 < 7 and board[i+2][j+1]!="P" and board[i+2][j+1]!="E" and board[i+2][j+1]!="M" and board[i+2][j+1]!="L" and board[i+2][j+1]!="C" and board[i+2][j+1]!="G"){
                storewhite.push_back(moves[i+2][j+1]); 

             }
           


             if( i+2 < 7 and j-1 >= 0 and board[i+2][j-1]!="P" and board[i+2][j-1]!="E" and board[i+2][j-1]!="M" and board[i+2][j-1]!="L" and board[i+2][j-1]!="C" and board[i+2][j-1]!="G"){
                storewhite.push_back(moves[i+2][j-1]); 

             }

         
      

          }
          


              }


          }

         
      }


    


    //  black moves 


 if(temp[1]=="b"){
        
          for(int i=0 ; i < board.size();++i ){
              for(int j = 0; j < board[0].size();++j){

                if(board[i][j]=="z"){

                  storewhite.push_back(moves[i][j]);

                 if( j-2 >=0 and i+1 < 7 and board[i+1][j-2]!="p" and board[i+1][j-2]!="e" and board[i+1][j-2]!="m" and board[i+1][j-2]!="l" and board[i+1][j-2]!="c" and board[i+1][j-2]!="g" ){
                      storewhite.push_back(moves[i+1][j-2]);

                }

                if( j+2 < 7 and i+1 < 7 and board[i+1][j+2]!="p" and board[i+1][j+2]!="e" and board[i+1][j+2]!="m" and board[i+1][j+2]!="l" and board[i+1][j+2]!="c" and board[i+1][j+2]!="g"){
                       storewhite.push_back(moves[i+1][j+2]);

                }

                if( i-1 >= 0 and j+2 < 7 and board[i-1][j+2]!="p" and board[i-1][j+2]!="e" and board[i-1][j+2]!="m" and board[i-1][j+2]!="l" and board[i-1][j+2]!="c" and board[i-1][j+2]!="g"){
                    storewhite.push_back(moves[i-1][j+2]);

                }

                if( i-1 >= 0 and j-2 >= 0 and board[i-1][j-2]!="p" and board[i-1][j-2]!="e" and board[i-1][j-2]!="m" and board[i-1][j-2]!="l" and board[i-1][j-2]!="c" and board[i-1][j-2]!="g"){
                    storewhite.push_back(moves[i-1][j-2]);
               }

                if( i-2 >=0  and j+1 < 7 and board[i-2][j+1]!="p" and board[i-2][j+1]!="e" and board[i-2][j+1]!="m" and board[i-2][j+1]!="l" and board[i-2][j+1]!="c" and board[i-2][j+1]!="g"){
                    storewhite.push_back(moves[i-2][j+1]);

              }


             if( i-2 >= 0 and j-1 >= 0 and board[i-2][j-1]!="p" and board[i-2][j-1]!="e" and board[i-2][j-1]!="m" and board[i-2][j-1]!="l" and board[i-2][j-1]!="c" and board[i-2][j-1]!="g"){
                storewhite.push_back(moves[i-2][j-1]); 

             }

             if( i+2 < 7 and j+1 < 7 and board[i+2][j+1]!="p" and board[i+2][j+1]!="e" and board[i+2][j+1]!="m" and board[i+2][j+1]!="l" and board[i+2][j+1]!="c" and board[i+2][j+1]!="g"){
                storewhite.push_back(moves[i+2][j+1]); 

             }


             if( i+2 < 7 and j-1 >= 0 and board[i+2][j-1]!="p" and board[i+2][j-1]!="e" and board[i+2][j-1]!="m" and board[i+2][j-1]!="l" and board[i+2][j-1]!="c" and board[i+2][j-1]!="g"){
                storewhite.push_back(moves[i+2][j-1]); 

             }


          }


              }


          }

         
      }


      
     storage.push_back(storewhite);
    return storage;

} 


main(){


      int N;
     cin >> N;
     cin.ignore(); //NB!
    for (int k = 0; k < N; ++k) {

      string fen;
      getline(cin, fen);
      vector<vector<string>> jn =  zebra_moves(correcting_string(fen),fen);
      vector<string>temp =  jn[0];

    swap(temp[0], temp[temp.size()-1]);
    temp.pop_back();
    sort(temp.begin(),temp.end());


            if(jn[0].empty()){

              cout<<endl;
            }

            else if(jn[0].size()==2){

              cout<<jn[0][0]+jn[0][1]<<endl;
            }

            else{

                for(int i =0; i < temp.size() ; ++i){
                      cout<<jn[0][0]+temp[i]<<" ";

                }

                cout<<endl;
            }
    }
              
return 0;

}