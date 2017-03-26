/*

Author: <James santana>
Course: {135}
Instructor: <Alexy>

>Assignment: <Qubi Model: Bioinformatics assignment part 2>

  reads dna.txt and fill up an array of struct objects of a user defined type . Each DNA object is going to have the following data members:

•	A vector of strings that holds the header lines
•	The actual DNA string
•	The gc content of the DNA string which should be a double

*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAX_DNA_SIZE=1000;

struct DNA{
	vector <string> headers;
	string dnastring;
	double gc;};

DNA GoodDNA[MAX_DNA_SIZE]; // holds the valid DNA objects
int number_of_strings(DNA antaray[MAX_DNA_SIZE]){
	//Returns the number of DNA objects in the array
	int count=0;
	for(int t=0; t< MAX_DNA_SIZE; t++){
			if(antaray[t].dnastring.size()>0){
				count++;
			}
		}
	return count;
}
/*-----------------------------------------------------------------*/
bool isValidDNAchar(char x){
	//returns true  if a char argument is one of 'a','c','g' or 't', otherwise the function returns false.
	if( x=='a'or x=='c'or x=='g' or x== 't' )
		return 1;
	else
		return 0;
}
/*-----------------------------------------------------------------*/
bool isValidDNAstring( string DNAstring){
//returns true  if a string is only made up of valid DNA characters. If any other character exists in the string false is returned.
	int d=0;
	while(d < DNAstring.size()){
	if( DNAstring[d]!='a'and DNAstring[d]!='c' and DNAstring[d]!='g'and DNAstring[d]!='t'){
		return 0;}
	d++;
	}
	return 1;
}
/*-----------------------------------------------------------------*/
string transcribe( string DNAstring){
	//Takes a DNA string argument, and returns its RNA equivalent.
	int d=0;
		while(d < DNAstring.size()){
			if( DNAstring[d]=='t'){
				DNAstring[d]='u';
			}
			d++;
		}
		return DNAstring;
}
/*-----------------------------------------------------------------*/
double gc(string DNAstring){
	//return a double between 0 and 1 that is the GC content of a DNA sequence.
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
/*-----------------------------------------------------------------*/
char complementChar(char base){
	//returns the complement of the base character.
	if(isValidDNAchar(base)){
		if (base=='a') return 't';
		if (base=='t') return 'a';
		if (base=='c') return 'g';
		if (base=='g') return 'c';
	} else {
		cout<< "Unvalid" <<endl;
		return 'N';
	}
}
/*-----------------------------------------------------------------*/
string complementStr(string DNAstring){
	//returns the RNA complementary DNA string of a valid DNA string.
	int d=0;
	if ( isValidDNAstring(DNAstring)){
			while(d < DNAstring.size()){
				DNAstring[d]=complementChar(DNAstring[d]);
				d++;
			}
	}
	return DNAstring;
}
/*-----------------------------------------------------------------*/
vector<string> codons(string DNAstring){
	//returns a vector of codons contained in an RNA string where each codon is a string of three nucleotides.
	int size=DNAstring.size();
	vector<string>trio;

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
/*-----------------------------------------------------------------*/
int numCodon( vector<string> codons, string group){
	//takes a vector of codons (created by the function above), and a three character string as arguments
	//and returns the number of times the string exists in the vector.
	int counter=0;
	for(int i=0;  i< codons.size(); i++){
		if(codons[i]==group ){
			counter++;
		}
	}
return counter;
}

/*-----------------------------------------------------------------*/

void createlist( DNA list[MAX_DNA_SIZE]){
	//fills up an array of DNA objects with data from a file called dna.txt
		ifstream fs;
		  fs.open("dna.txt");

		  if (fs.fail()) {
		    cerr << "Failed to open the data file." << endl;
		    exit(1);
		  }
		  while(fs.peek() != EOF) {
			  string s;
			  int j=0;//index for dna string
				 while ( getline(fs,s) ){
					 if(s[0]=='>') {
						 list[j].headers.push_back(s);

					 }else if (s[0]!='>'){
						 list[j].dnastring=s;
						 list[j].gc=gc(s);// insert the gc number of the dna string into the DNA object

					 	 j++;
					 }

				 }
		  }
}
/*-----------------------------------------------------------------*/
void WriteBadDNA(DNA badDNA[MAX_DNA_SIZE]){
	//Outputs an array of DNA object into a file called badDNA.txt
	ofstream arrayData("badDNA.txt"); // File Creation(on C drive)
			    for(int k=0;k<number_of_strings(badDNA);k++)
			    {
			    	for(int z=0; z<badDNA[k].headers.size(); z++){
			        arrayData<<badDNA[k].headers[z]<<endl;}
			        arrayData<< badDNA[k].dnastring<< endl; //Outputs array to txtFile
			    }
}

/*-----------------------------------------------------------------*/

void Write_headerLinesFreq(DNA temp_aray[MAX_DNA_SIZE]){
	//Create an output file called headerLinesFreq.txt that contains the frequency of the number of header lines.
	vector<int> frequency;
		int p=0;
		for(int f=0; f<number_of_strings(temp_aray); f++){
			while(temp_aray[f].headers.size()> p){
				frequency.push_back(0);
				p++;
			}
		}
		int fsz=frequency.size();

		for (int y=0; y< number_of_strings(temp_aray); y++){
			int n=temp_aray[y].headers.size();

			frequency[n-1]++;
		}
		ofstream headerLinesFreq("headerLinesFreq.txt "); // File Creation
		for(int w=0; w<fsz; w++){
			headerLinesFreq<<w+1<<"\t"<<frequency[w]<<endl;
		}
}

/*-----------------------------------------------------------------*/

void swap(int one, int two){
// swaps two positions of an array of DNA objects
		DNA temp = GoodDNA[one];
		GoodDNA[one] = GoodDNA[two];
		GoodDNA[two] = temp;

}
/*-----------------------------------------------------------------*/
void BubbleSort( ){
//Sorts an array of by gc content from lowest gc ratio to highest
	int size=number_of_strings(GoodDNA);
	for(int j=0; j<size-1; j++){
	if(GoodDNA[j].gc > GoodDNA[j+1].gc){
		swap(j, j+1);
	}
	}
}
/*-----------------------------------------------------------------*/
void Write_GCcontent(DNA DNA[MAX_DNA_SIZE]){
//Create a new file called GCcontent.txt which contains the original (valid) DNA data, sorted by gc content.
	// and List the gc content of each DNA sequence as an additional header line.
	ofstream arrayData("GCcontent.txt "); // File Creation(on C drive)
			    for(int k=0;k<number_of_strings(DNA);k++)
			    {
			    	for(int z=0; z<DNA[k].headers.size(); z++){
			        arrayData<<DNA[k].headers[z]<<endl;}
			        arrayData<<"> GC content:"<< DNA[k].gc<<endl<< DNA[k].dnastring<<endl; //Outputs array to txtFile
			    }
}
/*-----------------------------------------------------------------*/
void Write_expandedDNA(DNA DNA[MAX_DNA_SIZE]){
	/*	Create a new file called expandedDNA.txt which contains the original (valid) DNA data, followed by:
			o	the transcription of the DNA into RNA
			o	the number of times UGG exists in the RNA sequence; the codon UGG maps on to the amino acid tryptophan - based on the codon function described above.
			o	the complement DNA string
	  */
	ofstream arrayData("expandedDNA.txt"); // File Creation(on C drive)
			    for(int k=0;k<number_of_strings(DNA);k++)
			    {
			    	for(int z=0; z<DNA[k].headers.size(); z++){
			        arrayData<<DNA[k].headers[z]<<endl;}
			        arrayData<<"> GC content: "<< DNA[k].gc<<endl<< DNA[k].dnastring<<endl; //Outputs array to txtFile
			        arrayData<<"> RNA: "<< transcribe(DNA[k].dnastring)<<endl;

			        string s=transcribe(DNA[k].dnastring);
			        vector<string> c=codons(s);
			        string ugg="ugg";
			        int Num_of_ugg=numCodon(c,ugg);
			        arrayData<<"> Number of UGG (tryptophan): " <<Num_of_ugg<<endl;

			        arrayData<<"> DNA complement: "<< complementStr(DNA[k].dnastring) <<endl;
			    }
}
/*-----------------------------------------------------------------*/
int main() {
	DNA temp_aray[MAX_DNA_SIZE];

	DNA badDNA[MAX_DNA_SIZE];

	createlist(temp_aray);

	int g_index=0;
	int b_index=0;
	// the following loop divides temp_aray into two other array,
	// one containing the object with a valid dna string GoodDNA( declared globally)
	// and the other containing the objects with the invalid dna strings badDNA
	for(int i=0; i<number_of_strings(temp_aray); i++){
		if(!isValidDNAstring(temp_aray[i].dnastring)){
			badDNA[b_index]=temp_aray[i];
			b_index++;
		} else {
			GoodDNA[g_index]=temp_aray[i];
			g_index++;
		}
	}
	WriteBadDNA(badDNA);// outputs badDNA
	Write_headerLinesFreq(GoodDNA);// outputs the frequency of each number of header lines
	
	for(int h=0; h<number_of_strings(GoodDNA);h++){
	BubbleSort(); // sorts GoodDNA
	}
	
	
	Write_GCcontent(GoodDNA);// outputs GoodDNA including its gc content as a header
	Write_expandedDNA(GoodDNA);// output an expanded version of GoodDNA

return 0;
}
