#include<iostream>
#include<vector>
#include<cctype>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<string>
#include<iterator>
using namespace std;

void SplitString(string s, vector<string>& v) {

	string temp = "";
	for (int i = 0; i < s.length(); ++i) {

		if (s[i] == ' ') {
			v.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(s[i]);
		}

	}
	v.push_back(temp);

}

void SplitString2(string s, vector<string>& v) {

	string temp = "";
	for (int i = 0; i < s.length(); ++i) {

		if (s[i] == '/') {
			v.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(s[i]);
		}

	}
	v.push_back(temp);

}

void PrintVector(vector<string> v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	cout << "\n";
}

int main() {
	vector<string> inputs;
	vector<string> inputs2;

	int N;
	cin >> N;
	cin.ignore(); //NB!
	for (int i = 0; i < N; ++i) {
		string fen;
		string MOVE;
		getline(cin, fen);
		getline(cin,MOVE);
		inputs.push_back(fen);
		inputs2.push_back(MOVE);
		}

	
	
	for(int b=0;b<N;b++){
	vector<string> v;
	
	string s =inputs[b];
	string p=inputs2[b];
	int j,i,k,m;
	//rank of the first move//
	if(p[0] == 'a'){
		i =0;
	}
	else if(p[0]=='b'){
		i=1;
	}
	else if(p[0]=='c'){
		i=2;
	}
	else if(p[0]=='d'){
		i=3;
	}
	else if(p[0]=='e'){
		i=4;
	}
	else if(p[0]=='f'){
		i=5;
	}
	else if(p[0]=='g'){
		i=6;
	}
	//column of the first move//
	if(p[1]=='7'){
		j=0;
	}
	else if(p[1]=='6'){
		j=1;
	}
	else if(p[1]=='5'){
		j=2;
	}
	else if(p[1]=='4'){
		j=3;
	}
	else if(p[1]=='3'){
		j=4;
	}
	else if(p[1]=='2'){
		j=5;
	}
	else if(p[1]=='1'){
		j=6;
	}
	//row of the second move//
	if(p[2] == 'a'){
		k =0;
	}
	else if(p[2]=='b'){
		k=1;
	}
	else if(p[2]=='c'){
		k=2;
	}
	else if(p[2]=='d'){
		k=3;
	}
	else if(p[2]=='e'){
		k=4;
	}
	else if(p[2]=='f'){
		k=5;
	}
	else if(p[2]=='g'){
		k=6;
	}
	//column of the second move//
	if(p[3]=='7'){
		m=0;
	}
	else if(p[3]=='6'){
		m=1;
	}
	else if(p[3]=='5'){
		m=2;
	}
	else if(p[3]=='4'){
		m=3;
	}
	else if(p[3]=='3'){
		m=4;
	}
	else if(p[3]=='2'){
		m=5;
	}
	else if(p[3]=='1'){
		m=6;
	}
	
	SplitString(s, v);
    string OUT=v[1];
	vector<string> v2;
	string first = v[0];
	SplitString2(first, v2);
	
	//second board//
	vector<vector<string>> matrix ={{"a7","b7","c7","d7","e7","f7","g7"},
									{"a6","b6","c6","d6","e6","f6","g6"},
									{"a5","b5","c5","d5","e5","f5","g5"},
									{"a4","b4","c4","d4","e4","f4","g4"},
									{"a3","b3","c3","d3","e3","f3","g3"},
									{"a2","b2","c2","d2","e2","f2","g2"},
									{"a1","b1","c1","d1","e1","f1","g1"}
									};
	
	//input the FEN in the matrix2//
	vector<vector<char>> matrix2;
	for(int i=0;i<7;i++){
		string str = v2[i];
		vector<char> keep;
 			int check;

 			for (int k= 0; k< str.size(); k++)  {

    		check = isdigit(str[k]);
    		if (check){
    	
    			int x=str[k]-48;
    			for(int j=0;j<x;j++){
    				keep.push_back('#');
      					}
      				}
     			else{
					keep.push_back(str[k]);
						}
  			}
  					matrix2.push_back(keep);
	}
			
			//vector<string> moves;
 
			//making the move//
			char HOLD=matrix2[j][i];
			matrix2[j][i]='#';
			

			
			//increment the number of moves if black is playing//
			if(v[1]=="b"){
				string 	NUM=v[2];
				int num=stoi(NUM)+1;
                //int one=num+1;
				string STR=to_string(num);
				v[2]=STR;
				v[1]="w";
				
					for(int a=0;a<7;a++){
					
						 
						if(j!=3 && m==3){
							if( matrix2[3][a]=='e' || matrix2[3][a]=='z' || matrix2[3][a]=='p'	||  matrix2[3][a]=='l'){
								matrix2[3][a]='#';
							}
							matrix2[m][k]=HOLD;
						}
						else if(j==3 && m!=3){
							matrix2[m][k]=HOLD;
							if(matrix2[3][a]=='e' || matrix2[3][a]=='z' || matrix2[3][a]=='p'	||  matrix2[3][a]=='l'){
								matrix2[3][a]='#';
							}
						}
                        
						else if(j!=3 && m!=3){
							matrix2[m][k]=HOLD;
							if(matrix2[3][a]=='e' || matrix2[3][a]=='z' || matrix2[3][a]=='p'  ||  matrix2[3][a]=='l'){
								matrix2[3][a]='#';
							}
							
						}
						
						 else if(j==3 && m==3){
						matrix2[m][k]=HOLD;
						if(matrix2[m][k]=='e' || matrix2[m][k]=='z' || matrix2[m][k]=='p'  ||  matrix2[m][k]=='l'){
								matrix2[m][k]='#';
							}
							
						}

					}
				
			}
			else{
				v[1]="b";
					for(int a=0;a<7;a++){
					
						
						if(j!=3 && m==3){
							if( matrix2[3][a]=='E' || matrix2[3][a]=='Z' || matrix2[3][a]=='P' || matrix2[3][a]=='L'){
								matrix2[3][a]='#';
							}
							matrix2[m][k]=HOLD;
						}
						else if(j==3 && m!=3){
							matrix2[m][k]=HOLD;
							if(matrix2[3][a]=='E' || matrix2[3][a]=='Z' || matrix2[3][a]=='P'	|| matrix2[3][a]=='L'){
								matrix2[3][a]='#';
							}
						}
                        
						else if(j!=3 && m!=3){
							
							matrix2[m][k]=HOLD;
							if(matrix2[3][a]=='E' || matrix2[3][a]=='Z' || matrix2[3][a]=='P'	|| matrix2[3][a]=='L'){
								matrix2[3][a]='#';
							}
							
						}
						
						 else if(j==3 && m==3){
						matrix2[m][k]=HOLD;
						if(matrix2[m][k]=='E' || matrix2[m][k]=='Z' || matrix2[m][k]=='P'  ||  matrix2[m][k]=='L'){
								matrix2[m][k]='#';
							}
							
						}
					}
				}
		

			
	//outputs the board//
 /*for(int i=0;i<7;i++){
 	for(int j=0;j<7;j++){
 		cout<<matrix2[i][j]<<" ";
 	}
 	cout<<endl;
 }
 cout<<endl;*/
 
 //outputs the resulting moves//
 string fen2="";
  for(int i=0;i<7;i++){
	  for(int j=0;j<7;j++){
		  if(matrix2[i][j] == '#'){
			  if(matrix2[i][j+1]=='#' && matrix2[i][j+2]=='#' && matrix2[i][j+3]=='#' && matrix2[i][j+4]=='#' &&matrix2[i][j+5]=='#' && matrix2[i][j+6]=='#'){
				  fen2.push_back('7');
                  j=7;
			  }
			  else if(matrix2[i][j+1]=='#' && matrix2[i][j+2]=='#' && matrix2[i][j+3]=='#' && matrix2[i][j+4]=='#' &&matrix2[i][j+5]=='#'){
				  fen2.push_back('6');
                  j=j+5;
			  }
			  else if(matrix2[i][j+1]=='#' && matrix2[i][j+2]=='#' && matrix2[i][j+3]=='#' && matrix2[i][j+4]=='#' ){
				  fen2.push_back('5');
                  j=j+4;
			  }
			  else if(matrix2[i][j+1]=='#' && matrix2[i][j+2]=='#' && matrix2[i][j+3]=='#'){
				  fen2.push_back('4');
                  j=j+3;
			  }
			  else if(matrix2[i][j+1]=='#' && matrix2[i][j+2]=='#'){
				  fen2.push_back('3');
                  j=j+2;
			  }
			  else if(matrix2[i][j+1]=='#'){
				  fen2.push_back('2');
                  j=j+1;
			  }
			  else {
				  fen2.push_back('1');
			  }

		  }
		  else{
			  fen2.push_back(matrix2[i][j]);
		  	}
		
	  	}
		  if(i<=5){
			fen2.push_back('/');
		  }
  }

  bool chance=false;
  //string out="Continue";
  for(int i=0;i<7;i++){
      for(int j=0;j<7;j++){
          if(OUT == "b"){
              if(matrix2[i][j]=='L'){
                  chance=true;
              }
          }
          else if(OUT=="w"){
              if(matrix2[i][j]=='l'){
                  chance=true;
              }
          }
      }
  }


	//fen2.push_back(v[1]);
	//fen2.push_back(v[2]);

	cout<<fen2<<" "<<v[1]<<" "<<v[2]<<endl;
    if(chance){
        cout<<"Continue"<<endl;
    }
    else{
        if(OUT=="b"){
            cout<<"Black wins"<<endl;
        }
        else{
            cout<<"White wins"<<endl;
        }
    }

   
 	
 }
 
  
  

 /*
 if(v[1]=="w"){
 	for(int i=0;i<7;i++){
 			for(int j=0;j<7;j++){
 					if(matrix2[i][j]=='E'){
 							
 								if(i-2>=0){
									 
 									if(matrix2[i-2][j] == 'G' || matrix2[i-2][j] == 'M' || matrix2[i-2][j] == 'E' || matrix2[i-2][j] == 'L' || matrix2[i-2][j] == 'C' || matrix2[i-2][j] == 'Z' || matrix2[i-2][j] == 'P'){
 											int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i-2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 
									 }
 										}
 								if(i-1>=0){
									 
 									 if(matrix2[i-1][j] == 'G' || matrix2[i-1][j] =='M' || matrix2[i-1][j] =='E' || matrix2[i-1][j] =='L' || matrix2[i-1][j] =='C' || matrix2[i-1][j] =='Z' || matrix2[i-1][j] =='P'){
										  	int j;
 										}
										 else{
											  string thanks = matrix[i][j]+matrix[i-1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
									 
 										}
 									
 								 if(i+2<=6){
 									if(matrix2[i+2][j] == 'G' ||  matrix2[i+2][j] =='M' || matrix2[i+2][j] =='E' || matrix2[i+2][j] =='L' || matrix2[i+2][j] =='C' || matrix2[i+2][j] =='Z' || matrix2[i+2][j] =='P'){
 										int j;
 										}
										 else{
											 	string thanks = matrix[i][j]+matrix[i+2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(i+1<=6){
 									 if(matrix2[i+1][j] == 'G' || matrix2[i+1][j] =='M' || matrix2[i+1][j] =='E' || matrix2[i+1][j] =='L' || matrix2[i+1][j] =='C' || matrix2[i+1][j] =='Z' || matrix2[i+1][j] =='P'){
										  int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i+1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j-2>=0){
 									if(matrix2[i][j-2] == 'G' || matrix2[i][j-2] =='M' || matrix2[i][j-2] =='E' || matrix2[i][j-2] =='L' || matrix2[i][j-2] =='C' || matrix2[i][j-2] =='Z' || matrix2[i][j-2] =='P'){
 											int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j-2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j-1>=0){
 									 if(matrix2[i][j-1] ==  'G' || matrix2[i][j-1] == 'M' || matrix2[i][j-1] == 'E' || matrix2[i][j-1] == 'L' || matrix2[i][j-1] == 'C' || matrix2[i][j-1] == 'Z' || matrix2[i][j-1] == 'P'){
 										int j;
 										}else{
											 string thanks = matrix[i][j]+matrix[i][j-1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j+1<=6){
 									if(matrix2[i][j+1] == 'G' || matrix2[i][j+1] =='M' || matrix2[i][j+1] =='E' || matrix2[i][j+1] =='L' || matrix2[i][j+1] =='C' || matrix2[i][j+1] =='Z' || matrix2[i][j+1] =='P'){
 										int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j+1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j+2<=6){
 									 if(matrix2[i][j+2] == 'G' || matrix2[i][j+2] =='M' || matrix2[i][j+2] =='E' || matrix2[i][j+2] =='L' || matrix2[i][j+2] =='C' || matrix2[i][j+2] =='Z' || matrix2[i][j+2] =='P'){
 										int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j+2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								
 						}
 				}
 		}
 		
 }
 else{
 
 	for(int i=0;i<7;i++){
 			for(int j=0;j<7;j++){
 					if(matrix2[i][j]=='e'){
 							
 								if(i-2>=0){
									 
 									if(matrix2[i-2][j] == 'g' || matrix2[i-2][j] == 'm' || matrix2[i-2][j] == 'e' || matrix2[i-2][j] == 'l' || matrix2[i-2][j] == 'c' || matrix2[i-2][j] == 'z' || matrix2[i-2][j] == 'p'){
 											int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i-2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 
									 }
 										}
 								if(i-1>=0){
									 
 									 if(matrix2[i-1][j] == 'g' || matrix2[i-1][j] =='m' || matrix2[i-1][j] =='e' || matrix2[i-1][j] =='l' || matrix2[i-1][j] =='c' || matrix2[i-1][j] =='z' || matrix2[i-1][j] =='p'){
										  	int j;
 										}
										 else{
											  string thanks = matrix[i][j]+matrix[i-1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
									 
 										}
 									
 								 if(i+2<=6){
 									if(matrix2[i+2][j] == 'g' ||  matrix2[i+2][j] =='m' || matrix2[i+2][j] =='e' || matrix2[i+2][j] =='l' || matrix2[i+2][j] =='c' || matrix2[i+2][j] =='z' || matrix2[i+2][j] =='p'){
 										int j;
 										}
										 else{
											 	string thanks = matrix[i][j]+matrix[i+2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(i+1<=6){
 									 if(matrix2[i+1][j] == 'g' || matrix2[i+1][j] =='m' || matrix2[i+1][j] =='e' || matrix2[i+1][j] =='l' || matrix2[i+1][j] =='c' || matrix2[i+1][j] =='z' || matrix2[i+1][j] =='p'){
										  int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i+1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j-2>=0){
 									if(matrix2[i][j-2] == 'g' || matrix2[i][j-2] =='m' || matrix2[i][j-2] =='e' || matrix2[i][j-2] =='l' || matrix2[i][j-2] =='c' || matrix2[i][j-2] =='z' || matrix2[i][j-2] =='p'){
 											int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j-2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j-1>=0){
 									 if(matrix2[i][j-1] ==  'g' || matrix2[i][j-1] == 'm' || matrix2[i][j-1] == 'e' || matrix2[i][j-1] == 'l' || matrix2[i][j-1] == 'c' || matrix2[i][j-1] == 'z' || matrix2[i][j-1] == 'p'){
 										int j;
 										}else{
											 string thanks = matrix[i][j]+matrix[i][j-1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j+1<=6){
 									if(matrix2[i][j+1] == 'g' || matrix2[i][j+1] =='m' || matrix2[i][j+1] =='e' || matrix2[i][j+1] =='l' || matrix2[i][j+1] =='c' || matrix2[i][j+1] =='z' || matrix2[i][j+1] =='p'){
 										int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j+1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j+2<=6){
 									 if(matrix2[i][j+2] == 'g' || matrix2[i][j+2] =='m' || matrix2[i][j+2] =='e' || matrix2[i][j+2] =='l' || matrix2[i][j+2] =='z' || matrix2[i][j+2] =='z' || matrix2[i][j+2] =='p'){
 										int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j+2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								
 						}
 				}
 		}
 		
 }
 */

  /*vector<string> white_pawn;
  vector<string> black_pawn;
  vector<string> white_superpawn;
  vector<string> black_superpawn;
  vector<string> white_giraffe;
  vector<string> black_giraffe;
  vector<string> white_monkey;
  vector<string> black_monkey;
  vector<string> white_elephant;
  vector<string> black_elephant;
  vector<string> white_lion;
  vector<string> black_lion;
  vector<string> white_crocodile;
  vector<string> black_crocodile;
  vector<string> white_zebra;
  vector<string> black_zebra;
  
  for(int i=0;i<7;i++){
 	for(int j=0;j<7;j++){
 		if(matrix2[i][j] =='P'){
 			white_pawn.push_back(matrix[i][j]);
 		}	
 		if(matrix2[i][j] =='p'){
 			black_pawn.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='S'){
 			white_superpawn.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='s'){
 			black_superpawn.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='G'){
 			white_giraffe.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='g'){
 			black_giraffe.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='M'){
 			white_monkey.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='m'){
 			black_monkey.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='E'){
 			white_elephant.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='e'){
 			black_elephant.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='L'){
 			white_lion.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='l'){
 			black_lion.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='C'){
 			white_crocodile.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='c'){
 			black_crocodile.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='Z'){
 			white_zebra.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='z'){
 			black_zebra.push_back(matrix[i][j]);
 		}
 		
 	}
 }
 
  sort(white_pawn.begin(),white_pawn.end());
  sort(black_pawn.begin(),black_pawn.end());
  sort(white_superpawn.begin(),white_superpawn.end());
  sort(black_superpawn.begin(),black_superpawn.end());
  sort(white_giraffe.begin(),white_giraffe.end());
  sort(black_giraffe.begin(),black_giraffe.end());
  sort(white_monkey.begin(),white_monkey.end());
  sort(black_monkey.begin(),black_monkey.end());
  sort(white_elephant.begin(),white_elephant.end());
  sort(black_elephant.begin(),black_elephant.end());
  sort(white_lion.begin(),white_lion.end());
  sort(black_lion.begin(),black_lion.end());
  sort(white_crocodile.begin(),white_crocodile.end());
  sort(black_crocodile.begin(),black_crocodile.end());
  sort(white_zebra.begin(),white_zebra.end());
  sort(black_zebra.begin(),black_zebra.end());
  
		if(white_pawn.size() > 0){
			cout<<"white pawn: ";
 			for(string x:white_pawn){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white pawn: "<<endl;
 			}
 			
 		if(black_pawn.size() > 0){
			cout<<"black pawn: ";
 			for(string x:black_pawn){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black pawn: "<<endl;
 			}
 			
 		if(white_superpawn.size() > 0){
			cout<<"white superpawn: ";
 			for(string x:white_superpawn){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white superpawn: "<<endl;
 			}
 			
 		if(black_superpawn.size() > 0){
			cout<<"black superpawn: ";
 			for(string x:black_superpawn){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black superpawn: "<<endl;
 			}
 		
 		if(white_giraffe.size() > 0){
			cout<<"white giraffe: ";
 			for(string x:white_giraffe){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white giraffe: "<<endl;
 			}
 			
 		if(black_giraffe.size() > 0){
			cout<<"black giraffe: ";
 			for(string x:black_giraffe){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black giraffe: "<<endl;
 			}
 			
 		if(white_monkey.size() > 0){
			cout<<"white monkey: ";
 			for(string x:white_monkey){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white monkey: "<<endl;
 			}
 			
 		if(black_monkey.size() > 0){
			cout<<"black monkey: ";
 			for(string x:black_monkey){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black monkey: "<<endl;
 			}
 			
 		if(white_elephant.size() > 0){
			cout<<"white elephant: ";
 			for(string x:white_elephant){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white elephant: "<<endl;
 			}
 			
 		if(black_elephant.size() > 0){
			cout<<"black elephant: ";
 			for(string x:black_elephant){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black elephant: "<<endl;
 			}
 			
 		if(white_lion.size() > 0){
			cout<<"white lion: ";
 			for(string x:white_lion){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white lion: "<<endl;
 			}
 			
 		if(black_lion.size() > 0){
			cout<<"black lion: ";
 			for(string x:black_lion){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black lion: "<<endl;
 			}
 			
 		if(white_crocodile.size() > 0){
			cout<<"white crocodile: ";
 			for(string x:white_crocodile){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white crocodile: "<<endl;
 			}
 			
 		if(black_crocodile.size() > 0){
			cout<<"black crocodile: ";
 			for(string x:black_crocodile){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black crocodile: "<<endl;
 			}
 			
 		if(white_zebra.size() > 0){
			cout<<"white zebra: ";
 			for(string x:white_zebra){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white zebra: "<<endl;
 			}
 			
 		if(black_zebra.size() > 0){
			cout<<"black zebra: ";
 			for(string x:black_zebra){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black zebra: "<<endl;
 			}
 			
 		cout<<"side to play: ";
 		if(v[1]=="b"){
 			cout<<"black"<<endl;
 			}
 			else{
 				cout<<"white"<<endl;
 				}
 				cout<<endl;*/
 				
 		

	
	
	
	
	return 0;
}
