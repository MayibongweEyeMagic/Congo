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





string ReplaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}


vector<string> AddToString(string FEN ){

  vector<string> temp = split(FEN,'/');

  for(int i=0;i< temp.size();++i){

    for(int j=0;j<temp[i].length();++j){

      string thing = temp[i];

       if(thing[j]=='1'){
        string holder =  ReplaceAll(thing,"7","0");

        temp[i]= holder;
        }


        else if(thing[j]=='2'){
        string holder =  ReplaceAll(thing,"2","00");

        temp[i]= holder;
        }


        else if(thing[j]=='3'){
          string holder =  ReplaceAll(thing,"3","000");

           temp[i]= holder;
        }


        else if(thing[j]=='4'){
        string holder =  ReplaceAll(thing,"4","0000");

        temp[i]= holder;
        }



        else if(thing[j]=='5'){
        string holder =  ReplaceAll(thing,"5","00000");

        temp[i]= holder;
        }


       else if(thing[j]=='6'){

        string holder =  ReplaceAll(thing,"6","000000");
        temp[i]= holder;

        }


       else if(thing[j]=='7'){
        string holder =  ReplaceAll(thing,"7","0000000");

        temp[i]= holder;
        }

    }


  }


  return temp;
}


 
vector<vector<char>> settingboard(string fen_string){

    vector<string>FenVector = AddToString(fen_string);

    vector<vector<char>> board(7,vector<char>(7));

    for(int i=0;i<FenVector.size();++i){

        for(int j = 0; j< FenVector[i].length();++j){

          string temp = FenVector[i];

          if(temp[j]=='g'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='e'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='m'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='l'){
            
            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='c'){

            char thing = temp[j];
            board[i][j]= thing;


          }

          else if(temp[j]=='z'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='p'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='P'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='G'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='M'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='E'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='C'){

            char thing = temp[j];
            board[i][j]= thing;

          }


          else if(temp[j]=='L'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='Z'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='0'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='S'){

            char thing = temp[j];
            board[i][j]= thing;

          }

          else if(temp[j]=='s'){

            char thing = temp[j];
            board[i][j]= thing;

          }


        
        }

    }     


return board;
}


vector<string> printing_function2(vector<vector<char>>board){

  vector<string>key(16,"");

    vector<vector<string>>temp
    {
      {"a7","b7","c7","d7","e7","f7","g7"},
      {"a6","b6","c6","d6","e6","f6","g6"},
      {"a5","b5","c5","d5","e5","f5","g5"},
      {"a4","b4","c4","d4","e4","f4","g4"},
      {"a3","b3","c3","d3","e3","f3","g3"},
      {"a2","b2","c2","d2","e2","f2","g2"},
      {"a1","b1","c1","d1","e1","f1","g1"}
      
      }; 

      

    for(int i=0; i<board.size();++i){

      for(int j=0; j<board[i].size();++j){


          if(board[i][j]=='P'){
            
                key[0]= key[0]+ temp[i][j]+" ";
         
            
          }


          else if(board[i][j]=='p'){

           key[1]= key[1]+ temp[i][j]+" ";
            

          }

          else if(board[i][j]=='S'){
            
             key[2]= key[2]+ temp[i][j]+" ";

          }

          else if(board[i][j]=='s'){

             key[3]= key[3]+ temp[i][j]+" ";


          }

          else if(board[i][j]=='G'){

            key[4]= key[4] + temp[i][j]+" ";
            

          }

          else if(board[i][j]=='g'){

             key[5]= key[5] + temp[i][j] + " ";
           

          }


          else if(board[i][j]=='M'){

             key[6] = key[6] + temp[i][j]+" ";

          }

          else if(board[i][j]=='m'){
            
            key[7] = key[7] + temp[i][j] + " ";
            

          }

          else if(board[i][j]=='E'){

           key[8]= key[8]+ temp[i][j]+" ";

          

          }


          else if(board[i][j]=='e'){

           key[9]= key[9]+ temp[i][j]+" ";

          }

          else if(board[i][j]=='L'){
            
             key[10] = key[10] + temp[i][j] + " ";

          }


          else if(board[i][j]=='l'){

             key[11] = key[11]+ temp[i][j] + " ";
        
          }

          else if(board[i][j]=='C'){

             key[12] = key[12] + temp[i][j] + " ";
            

          }

          else if(board[i][j]=='c'){

             key[13] = key[13] + temp[i][j] + " ";
            
          }


          else if(board[i][j]=='Z'){

             key[14] = key[14] + temp[i][j] + " ";
            
          }


          else if(board[i][j]=='z'){
            
            key[15]= key[15] + temp[i][j] + " ";

          }




      }

    }

    vector<string>V;
    vector<string>V1;
    vector<string>V2;
    vector<string>V3;

    if(key[0]!="" and key[0].length() > 3){

      V =split(key[0],' ') ;
      sort(V.begin(),V.end());
      key[0]="";

      for(int i=0;i< V.size();++i){
        key[0]=key[0] + V[i] + " ";

      }   
      
      
      }

      if(key[1]!="" and key[1].length() > 3){

      V1 =split(key[1],' ') ;
      sort(V1.begin(),V1.end());
      key[1]="";

      for(int i=0;i< V1.size();++i){
        key[1]=key[1] + V1[i] + " ";

      }   
      
      }

      if(key[8]!="" and key[8].length() >3 ){

      V2 =split(key[8],' ') ;
      sort(V2.begin(),V2.end());
      key[8]="";

      for(int i=0;i< V2.size();++i){
        key[8]=key[8] + V2[i] + " ";

      }   
      
      }

      if(key[9]!="" and key[9].length() > 3){

      V3 =split(key[9],' ') ;
      sort(V3.begin(),V3.end());
      key[9] = "";
      
      for(int i=0;i< V3.size();++i){
        key[9]=key[9] + V3[i] + " ";

      }   
      
      }


    return key;

}

void output(vector<string>out){

  cout<<"white pawn:"<<" "<<out[0]<<endl;
  cout<<"black pawn:"<<" "<<out[1]<<endl;
  cout<<"white superpawn:"<<" "<<out[2]<<endl;
  cout<<"black superpawn:"<<" "<<out[3]<<endl;
  cout<<"white giraffe:"<<" "<<out[4]<<endl;
  cout<<"black giraffe:"<<" "<<out[5]<<endl;
  cout<<"white monkey:"<<" "<<out[6]<<endl;
  cout<<"black monkey:"<<" "<<out[7]<<endl;
  cout<<"white elephant:"<<" "<<out[8]<<endl;
  cout<<"black elephant:"<<" "<<out[9]<<endl;
  cout<<"white lion:"<<" "<<out[10]<<endl;
  cout<<"black lion:"<<" "<<out[11]<<endl;
  cout<<"white crocodile:"<<" "<<out[12]<<endl;
  cout<<"black crocodile:"<<" "<<out[13]<<endl;
  cout<<"white zebra:"<<" "<<out[14]<<endl;
  cout<<"black zebra:"<<" "<<out[15]<<endl;


}

void dofunction(string FEN){

vector<vector<char>>temp = settingboard(FEN);
  vector<string> tim = printing_function2(temp);
   output(tim);

}

int main(){


int N;
 cin >> N;
 cin.ignore();

 vector<string>str;

 for (int i = 0; i < N; ++i) {
 string fen;
 getline(cin, fen);
  str = split(fen,' '); 
 
    dofunction(str[0]);
    if(str[1]=="w"){

      cout<<"side to play:"<<" "<<"white"<<endl;
      
    }

   else if(str[1]=="b"){

      cout<<"side to play:"<<" "<<"black"<<endl;
      
    }

    
 }

 



    return 0;
}