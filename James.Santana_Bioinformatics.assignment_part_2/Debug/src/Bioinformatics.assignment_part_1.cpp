/*

Author: <James santana>
Course: {135}
Instructor: <Alexy>

>Assignment: <Qubi Model: Bioinformatics assignment part 1>

  //Write and test the following functions in a program using cin and cout.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;


bool isValidDNAchar(char x){//
    if( x=='a'or x=='c'or x=='g' or x== 't' )
        return 1;//returns true  if a char argument is one of 'a','c','g' or 't',
    else
        return 0;//otherwise the function returns false.
}

bool isValidDNAstring( string DNAstring){
    int d=0;

    while(d < DNAstring.size()){
    if( DNAstring[d]!='a'and DNAstring[d]!='c' and DNAstring[d]!='g'and DNAstring[d]!='t'){
        return 0;}//returns true  if a string is only made up of valid DNA characters.
    d++;
    }
    return 1;//If any other character exists in the string false is returned.
}

string transcribe( string DNAstring){//Takes a DNA string argument, and returns its RNA equivalent.
    int d=0;
        while(d < DNAstring.size()){
            if( DNAstring[d]=='t'){
                DNAstring[d]='u';
            }
            d++;
        }
        return DNAstring;
}

double gc(string DNAstring){	//return a double between 0 and 1 that is the GC content of a DNA sequence.
    double size=DNAstring.size();
    int d=0;
    int n=0;
    double gc=0;
    while(d < DNAstring.size()){
        if( DNAstring[d]=='g' or DNAstring[d]=='c'){
            n++;
        }
        d++;
    }
    gc=n/size;
    return gc;

}

char complementChar(char base){//returns the complement of the base character.
    if(isValidDNAchar(base)){
        if (base=='a') return 't';//If the argument is the base character 'a', then the character 't' is returned;
        if (base=='t') return 'a';
        if (base=='c') return 'g';// If the argument is the base character 'c', then 'g' is returned, etc.
        if (base=='g') return 'c';
    } else {
        cout<< "Unvalid" <<endl;
        return 'N';
    }
}

string complementStr(string DNAstring){

    int d=0;
    if ( isValidDNAstring(DNAstring)){//returns the complementary DNA string of a valid DNA string.
            while(d < DNAstring.size()){
                DNAstring[d]=complementChar(DNAstring[d]);//calls complementChar
                d++;
            }
    }
    return DNAstring;
}


vector<string> codons(string DNAstring){
    int size=DNAstring.size();
    vector<string>trio;
//returns a vector of codons contained in an RNA string where each codon is a string of three nucleotides.
    int i = 0;
    while(i < size ) {
         string temp;

         int j=i;
         while(j <i+3 and j < size){

             if(j<size){
                 temp=temp +DNAstring[j];}
             j++;
         }

          trio.push_back(temp);
          i=i+3;
       }
  return trio;
    }

int numCodon( vector<string> codons, string group){//takes a vector of codons (created by the function above),
    int counter=0;									// and a three character string as arguments
    for(int i=0;  i< codons.size(); i++){			//and returns the number of times the string exists in the vector.
        if(codons[i]==group ){
            counter++;
        }
    }
return counter;
}
int main() {

        cout<< "please enter a Character" <<endl;
        char a; cin>>a;
        cin.ignore();

        if ( isValidDNAchar(a)){
            cout << "the character true"<<endl;
            cout << "the complement for that character is "<< complementChar(a)<<endl;
        }else {cout<<" the character false"<<endl;}

        cout<< "please enter a String" <<endl;
        string s;

        getline(cin,s);
        vector<string> c=codons(s);
        if ( isValidDNAstring(s)){
            cout << "the string true"<<endl;
            cout<<"The RNA for that is "<< transcribe(s)<<endl;
            cout<<"The The GC content  is "<< gc(s)<<endl;
            cout<<"The The  complement is "<<  complementStr(s)<<endl;


            for(int i=0; i< c.size(); i++){
                cout<< "The Condons number "<<i+1<<" is "<<endl;
                cout<<c[i]<<endl;}

            }else{cout<<" the string false"<<endl;}

        string codon;
        do{
            cout<<"Please enter a Valid Codon to check the times it appears  "<<endl;
            getline(cin, codon);

        } while(codon.size() !=3 or !isValidDNAstring(codon));

        cout<<codon <<" it appears " <<numCodon(c,codon)<<" times "<<endl;


return 0;
}

