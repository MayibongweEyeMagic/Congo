#include <bits/stdc++.h>
#include<iostream>
#include <string>
#include<cstring>
#include <cstdlib>
#include <algorithm> 
#include <cmath>

using namespace std;

struct congo{

string fen; 
vector<string> postion{"a","b","c","d","e","f","g"};

public:

congo(string F){
    fen =F;

}

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



vector<string> split_fen(){

    string temp = "";
    temp =fen;

    vector<string>thing = split(temp,' ');

  return thing;
}


void turn(){

    vector<string>holder = split_fen();

    if(holder[1]=="w"){

        cout<<"side to play:"<<" "<<"white"<<endl;
    }

    else if(holder[1]=="b"){

        cout<<"side to play:"<<" "<<"black"<<endl;
    }

}

string  correcting_string(){

   
    vector<string>holder = split_fen();

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



return temp4;
}

void current_state()
{

    string temp = correcting_string();
 vector<string>postion
    {"a7","b7","c7","d7","e7","f7","g7","a6","b6","c6","d6","e6","f6","g6","a5","b5","c5","d5","e5","f5","g5","a4","b4","c4","d4","e4","f4","g4","a3","b3","c3","d3","e3","f3","g3","a2","b2","c2","d2","e2","f2","g2","a1","b1","c1","d1","e1","f1","g1"}; 

    vector<string>whitepawns;
    vector<string>blackpawns;
    vector<string>whiteelephate;
    vector<string>blackelephate;
    vector<string>blackspawn;
    vector<string> whitspawn;
    vector<string>other(10,"");

    for(int i=0; i < temp.length();++i){

        if(temp[i]=='P'){
            
            whitepawns.push_back(postion[i]);
                     
          }


          else if(temp[i]=='p'){
           blackpawns.push_back(postion[i]);
            
          }

          else if(temp[i]=='S'){
            
             whitspawn.push_back(postion[i]);

          }

          else if(temp[i]=='s'){

             blackspawn.push_back(postion[i]);

          }

          else if(temp[i]=='G'){

            other[0]=postion[i];
            

          }

          else if(temp[i]=='g'){

             other[1]=postion[i];
           

          }


          else if(temp[i]=='M'){
 
            other[2]=postion[i];
          }

          else if(temp[i]=='m'){
            
            other[3]=postion[i];
            

          }

          else if(temp[i]=='E'){

           whiteelephate.push_back(postion[i]);

          }


          else if(temp[i]=='e'){

           blackelephate.push_back(postion[i]);

          }

          else if(temp[i]=='L'){
            
             other[4]=postion[i];

          }


          else if(temp[i]=='l'){

             other[5]=postion[i];
        
          }

          else if(temp[i]=='C'){

             other[6]=postion[i];
            
          }

          else if(temp[i]=='c'){

             other[7]=postion[i];
          }


          else if(temp[i]=='Z'){

             
            other[8]=postion[i];
          }


          else if(temp[i]=='z'){
            
            other[9]=postion[i];
          }



    }
    if(!whitepawns.empty()){
        sort(whitepawns.begin(),whitepawns.end());
          string temp6 = "";
        for(int i=0;i<whitepawns.size();++i){

                temp6 = temp6 + whitepawns[i]+" ";
              
        }

         cout<<"white pawn:"<<" "<<temp6<<endl;
        

    }

    else{

            cout<<"white pawn:"<<endl;

    }


    if(!blackpawns.empty()){
        sort(blackpawns.begin(),blackpawns.end());
         string temp6 = "";
        for(int i=0;i<blackpawns.size();++i){
              temp6 = temp6 + blackpawns[i] +" ";
             
        }

         cout<<"black pawn:"<<" "<<temp6<<endl; 
        

    }

    else{

          cout<<"black pawn:"<<endl;

    }

 if(!whitspawn.empty()){
        sort(whitspawn.begin(),whitspawn.end());
        string temp6= "";
        for(int i=0;i<whitspawn.size();++i){
            temp6 = temp6 + whitspawn[i]+" ";
              
        }

        cout<<"white superpawn:"<<" "<<temp6<<endl;
    
    }

    else{

         cout<<"white superpawn:"<<endl;

    }


    if(!blackspawn.empty()){
        sort(blackspawn.begin(),blackspawn.end());
          string temp6 ="";
        for(int i=0;i<blackspawn.size();++i){
              temp6 = temp6 + blackspawn[i]+" ";
              
        }
        cout<<"black superpawn:"<<" "<<temp6<<endl;

    }

    else{

         cout<<"black superpawn:"<<endl;

    }



  cout<<"white giraffe:"<<" "<<other[0]<<endl;
  cout<<"black giraffe:"<<" "<<other[1]<<endl;
  cout<<"white monkey:"<<" "<<other[2]<<endl;
  cout<<"black monkey:"<<" "<<other[3]<<endl;


     if(!whiteelephate.empty()){
        sort(whiteelephate.begin(),whiteelephate.end());
        string temp6="";
        for(int i=0;i<whiteelephate.size();++i){

        temp6 = temp6 + whiteelephate[i] +" ";
             
        }

        cout<<"white elephant:"<<" "<<temp6<<endl; 
        
    }

    else{

         cout<<"white elephant:"<<endl;

    }


 if(!blackelephate.empty()){
        sort(blackelephate.begin(),blackelephate.end());

        string temp6 ="";
        for(int i=0;i<blackelephate.size();++i){

          temp6 = temp6 + blackelephate[i] +" ";

        }
        
      cout<<"black elephant:"<<" "<<temp6<<endl; 
    }

    else{

         cout<<"black elephant:"<<endl;

    }

  cout<<"white lion:"<<" "<<other[4]<<endl;
  cout<<"black lion:"<<" "<<other[5]<<endl;
  cout<<"white crocodile:"<<" "<<other[6]<<endl;
  cout<<"black crocodile:"<<" "<<other[7]<<endl;
  cout<<"white zebra:"<<" "<<other[8]<<endl;
  cout<<"black zebra:"<<" "<<other[9]<<endl;



}


};


int main(){

  int N;
  cin >> N;
  cin.ignore();

  for (int i = 0; i < N; ++i) {

      string fen;
      getline(cin, fen);
      congo test(fen);
      test.current_state();
      test.turn();
     
  }
    

    return 0;
}