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

   
    vector<string>holder = split(temp,' ');

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

    

      vector<string>things;
      int pos =0;
      string sum ="";
      for(int i =0;i<7;++i){
          for(int j =0; j< 7;++j){
                sum = sum + temp4[pos] ;
                ++pos;

          }

          things.push_back(sum);
          sum="";

      }

for(int i=0;i<things.size();++i){

        things[i].erase(5,2);
        things[i].erase(things[i].begin()+0);
        things[i].erase(things[i].begin()+0);
    }


      string temp5 ="";

      for(int i=0; i< things.size();++i){

        temp5 = temp5 + things[i];
      }

    int index = 0;
    vector<vector<string>>board(7,vector<string>(3));

    for(int i=0; i< 7;++i){

        for(int j =0; j< 3;++j ){
        
          board[i][j]= temp5[index];
          ++index;

        }

    }



return board;
}

void printing_function(vector<vector<string>>board){

    for(int i =0;i<board.size();++i){

      for(int j =0 ; j< board[i].size();++j){

        cout<<board[i][j]<<" ";

      }

      cout<<endl;

    }


}




vector<vector<string>> lion_move(vector<vector<string>>board){

  vector<vector<string>>moves
  { 
    {"c7","d7","e7"},
    {"c6","d6","e6"},
    {"c5","d5","e5"},
    {"c4","d4","e4"},
    {"c3","d3","e3"},
    {"c2","d2","e2"},
    {"c1","d1","e1"} 
    
    };

    int b = 0;
    int a = 0;

    for(int i = 0; i < board.size();++i ){

          for(int j = 0;j < board[i].size();++j ){

              if(board[i][j] == "l"){
                  b = i;       
              } 

              if(board[i][j]=="L"){
                  a =i;

              }


          }


    }
  


    vector<string>storewhite;
    vector<string>storeblack;

    for(int i=0;i < board.size();++i){

      for(int j=0; j < board[i].size();++j){

          if(board[i][j]=="L"){

            storewhite.push_back(moves[i][j]);

            if( j-1>=0 and board[i][j-1]!="P" and board[i][j-1]!="E" and board[i][j-1]!="M" and board[i][j-1]!="Z" and board[i][j-1]!="C" and board[i][j-1]!="G"){
              storewhite.push_back(moves[i][j-1]);

            }

              if( j+1<3 and board[i][j+1]!="P" and board[i][j+1]!="E" and board[i][j+1]!="M" and board[i][j+1]!="Z" and board[i][j+1]!="C" and board[i][j+1]!="G"){
              storewhite.push_back(moves[i][j+1]);

            }

             if( i-1> 3 and board[i-1][j]!="P" and board[i-1][j]!="E" and board[i-1][j]!="M" and board[i-1][j]!="Z" and board[i-1][j]!="C" and board[i-1][j]!="G"){
              storewhite.push_back(moves[i-1][j]);

            }

            if( i+1 <7 and board[i+1][j]!="P" and board[i+1][j]!="E" and board[i+1][j]!="M" and board[i+1][j]!="Z" and board[i+1][j]!="C" and board[i+1][j]!="G"){
              storewhite.push_back(moves[i+1][j]);
            }

           if( i-1>3 and j-1>=0 and board[i-1][j-1]!="P" and board[i-1][j-1]!="E" and board[i-1][j-1]!="M" and board[i-1][j-1]!="Z" and board[i-1][j-1]!="C" and board[i-1][j]!="G"){
              storewhite.push_back(moves[i-1][j-1]);

           }


             if( i+1<7 and j+1<3 and board[i+1][j+1]!="P" and board[i+1][j+1]!="E" and board[i+1][j+1]!="M" and board[i+1][j+1]!="Z" and board[i+1][j+1]!="C" and board[i+1][j+1]!="G"){
              storewhite.push_back(moves[i+1][j+1]);

            }

            if( i-1>3 and j+1<3 and board[i-1][j+1]!="P" and board[i-1][j+1]!="E" and board[i-1][j+1]!="M" and board[i-1][j+1]!="Z" and board[i-1][j+1]!="C" and board[i-1][j+1]!="G"){
              storewhite.push_back(moves[i-1][j+1]);

            }

            if( i+1<7 and j-1>=0 and board[i+1][j-1]!="P" and board[i+1][j-1]!="E" and board[i+1][j-1]!="M" and board[i+1][j-1]!="Z" and board[i+1][j-1]!="C" and board[i+1][j-1]!="G"){
              storewhite.push_back(moves[i+1][j-1]);

            }


              vector<string>v;                
              for(int k = i-1; k < board.size();--k){

                  v.push_back(board[k][j]);
                 // cout<<board[k][j]<<endl;
                  if(board[k][j]=="l"){

                    break;
                  }

              }

            
              vector<string> vect2(v);
               v.erase(std::remove(v.begin(), v.end(), "0"), v.end());
                
                if(v.size()==1 and v[0]=="l"){

                    storewhite.push_back(moves[b][j]);

                }

                if( board[4][0]=="L" and board[2][2]=="l" and board[3][1]=="0"){
                  storewhite.push_back(moves[2][2]);

                 }

               if( board[4][2]=="L" and board[2][0]=="l" and board[3][1]=="0"){
                  storewhite.push_back(moves[2][0]);

                }


          
          }

        
      

           if(board[i][j]=="l"){

            storeblack.push_back(moves[i][j]);

            //move left
            if( j-1 >=0  and board[i][j-1]!="p" and board[i][j-1]!="e" and board[i][j-1]!="m" and board[i][j-1]!="z" and board[i][j-1]!="c" and board[i][j-1]!="g"){
             storeblack.push_back(moves[i][j-1]);

            }

            
             //    move right 
              if( j+1<3 and board[i][j+1]!="p" and board[i][j+1]!="e" and board[i][j+1]!="m" and board[i][j+1]!="z" and board[i][j+1]!="c" and board[i][j+1]!="g"){
              storeblack.push_back(moves[i][j+1]);

            }
            

            // move up
             if( i-1 >= 0 and board[i-1][j]!="p" and board[i-1][j]!="e" and board[i-1][j]!="m" and board[i-1][j]!="z" and board[i-1][j]!="c" and board[i-1][j]!="g"){
              storeblack.push_back(moves[i-1][j]);

            }

              // move down 
            if( i+1 <3 and board[i+1][j]!="p" and board[i+1][j]!="e" and board[i+1][j]!="m" and board[i+1][j]!="z" and board[i+1][j]!="c" and board[i+1][j]!="g"){
              storeblack.push_back(moves[i+1][j]);
            }
        
            // move north west 
           if( i-1 >= 0 and j-1>=0 and board[i-1][j-1]!="p" and board[i-1][j-1]!="e" and board[i-1][j-1]!="m" and board[i-1][j-1]!="z" and board[i-1][j-1]!="c" and board[i-1][j]!="g"){
              storeblack.push_back(moves[i-1][j-1]);

           }

            // move south east
             if( i+1<3 and j+1<3 and board[i+1][j+1]!="p" and board[i+1][j+1]!="e" and board[i+1][j+1]!="m" and board[i+1][j+1]!="z" and board[i+1][j+1]!="c" and board[i+1][j+1]!="g"){
              storeblack.push_back(moves[i+1][j+1]);

            }


            // move north east
            if( i-1 >= 0 and j+1<3 and board[i-1][j+1]!="p" and board[i-1][j+1]!="e" and board[i-1][j+1]!="m" and board[i-1][j+1]!="z" and board[i-1][j+1]!="c" and board[i-1][j+1]!="g"){
              storeblack.push_back(moves[i-1][j+1]);

            }

          // south west 
            if( i+1<3 and j-1>=0 and board[i+1][j-1]!="p" and board[i+1][j-1]!="e" and board[i+1][j-1]!="m" and board[i+1][j-1]!="z" and board[i+1][j-1]!="c" and board[i+1][j-1]!="g"){
              storeblack.push_back(moves[i+1][j-1]);

            }

           

              vector<string>v;
              for(int k = i+1; k < board.size();++k){

                  v.push_back(board[k][j]);
                 // cout<<board[k][j]<<endl;
                  if(board[k][j]=="L"){

                    break;
                  }

              }


            
              vector<string> vect2(v);
               v.erase(std::remove(v.begin(), v.end(), "0"), v.end());  
              // cout<<v[0]<<endl;

                if(v.size()==1 and v[0]=="L"){

                    storeblack.push_back(moves[a][j]);

                }




                if( board[4][0]=="L" and board[2][2]=="l" and board[3][1]=="0"){
                   storeblack.push_back(moves[4][0]);

                  }

                 if( board[4][2]=="L" and board[2][0]=="l" and board[3][1]=="0"){
                    storeblack.push_back(moves[4][2]);

                  }


          
          }

        

          
        
      }

      
    }

      vector<vector<string>>lp;

      lp.push_back(storewhite);
      lp.push_back(storeblack);

          return lp;


}
      

  
int main(){



int N;
 cin >> N;
 cin.ignore(); //NB!
 for (int k = 0; k < N; ++k) {
 string fen;
 getline(cin, fen);


 vector<string>l =split_fen(fen);

    vector<vector<string>> jn = lion_move(correcting_string(fen));

    vector<string>temp =  jn[0];
    vector<string>temp1 = jn[1];

    swap(temp[0], temp[temp.size()-1]);
    temp.pop_back();
    sort(temp.begin(),temp.end());

    swap(temp1[0], temp1[temp1.size()-1]);
    temp1.pop_back();
    sort(temp1.begin(),temp1.end());



        if(l[1]=="w"){

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



     
        if(l[1]=="b"){

            if(jn[1].empty()){

              cout<<endl;
            }

            else if(jn[1].size()==2){

              cout<<jn[1][0]+jn[1][1]<<endl;
            }

            else{

                for(int i =0; i < temp1.size() ; ++i){
                      cout<<jn[1][0]+temp1[i]<<" ";

                }

                cout<<endl;
            }
            

        }
    


 }

      


    return 0;
}