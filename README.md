# Bioinformatics--Qubi-Model

This was a class assignment with the following instruction 


CSCI 135/136  Qubi Model: Bioinformatics assignment

A Bit of Biology 

(copied from: http://onlamp.com/pub/a/python/2002/10/17/biopython.html by Patrick O'Brien 10/17/2002)

One of the goals of molecular biology is to understand the processes that take place within the cells of living organisms. One such process is the creation of proteins, some of the most basic raw materials of all living things. Almost every process within a living creature makes use of, or is influenced by, these large, complex molecular structures. There are thousands of different proteins and we have barely begun to understand them in any detail. One thing we do know is that the creation of proteins is determined by the information encoded within the genetic material in each cell, called DNA.

DNA is a linear structure made up of a sequence of molecules called nucleotides or bases. Four nucleotides appear in DNA: adenine, cytosine, guanine, and thymine. These nucleotides are usually represented by their initials,   A,   C,   G   and   T. DNA is actually composed of two strands of these nucleotides wound around each other in the famous double helix shape.
The sequence of a single strand of DNA can be represented as a sequence of alphabetical characters identifying each base in the sequence, such as ACCTTGGCACCT. Due to their chemical attractions, the nucleotides always appear in pairs, also called base pairs, such that adenine (A) always pairs up with thymine (T), and cytosine (C) always pairs up with guanine (G). Because of this base-pairing characteristic, we can easily determine the complementary, or opposite, strand of any single-stranded DNA sequence.

A simplified view of how DNA determines the creation of a protein goes something like this. A section of DNA called a gene contains the encoded information about the protein to create. Through the process of transcription, the two DNA strands along a gene separate, and the gene is copied. This single-stranded copy is called RNA, or, more precisely, messenger RNA. It is identical to the original gene sequence, except that the nucleotide uracil (U) appears in place of thymine (T).

Once formed, the messenger RNA moves to a structure in the cell known as a ribosome. The ribosome moves along the messenger RNA, reading its sequence three nucleotides at a time. Each group of three nucleotides, called a codon, determines which of 20 amino acids gets assembled by the ribosome into a protein. Like DNA and RNA, proteins are linear structures that can be represented by a text string. Where DNA and RNA use a four-character alphabet, proteins require a 20-character alphabet to represent each amino acid in a protein sequence.

CSCI 135 Assignment Two

Some important notes: 

1) You may not use any functions in the C++ standard string library except for those we covered in class (indexing, size, {push,pop}_back). You may not use C strings.
2) The term data member is the same as field, slot, or attribute for structs.

Download the file dna.txt from blackboard. This is a file of DNA sequences. 

Each line of the file is either a header line that is used as a label, or a DNA sequence.  All header lines begin with the character '>'.  There can be multiple header lines for each DNA sequence – you cannot assume there is a maximum number of header lines. 

For example, consider:

> 77120247 Human rotavirus G3 segment 8, complete sequence
ggcttttaatgcttttcagtggttgatgctcaagatggagtctactcagcagatggctag
> 77119805 Human rotavirus G3 segment 11, 
>  This is a complete sequence
ggcttttaaagcgctacagtgatgtctctcagtattgacgtgacgagtcttccttctatt

“DNA data”: These 5 lines contain two sequences. The first sequence has one header line beginning with  > 77120247  followed by the actual sequence. The second sequence has two header lines which is then followed by the sequence. When I use the term “DNA data” I mean the collection of header lines together with the actual DNA sequence. So the example above has two sets of DNA data:

> 77120247 Human rotavirus G3 segment 8, complete sequence
ggcttttaatgcttttcagtggttgatgctcaagatggagtctactcagcagatggctag

and

> 77119805 Human rotavirus G3 segment 11, 
>  This is a complete sequence
ggcttttaaagcgctacagtgatgtctctcagtattgacgtgacgagtcttccttctatt

NOTE: Most of the DNA sequences are longer than a usual line in most text editors. So, if you open the file in a text editor, your editor will probably wrap lines so that the DNA sequences appear to be on multiple lines – they are not, they are on a single very long line.

Part 1) Write and test the following functions in a program using cin and cout. You can look at the dna.txt file, but don’t have your program read the file for this part of the assignment:
	
isValidDNAchar: returns true  if a char argument is one of 'a','c','g' or 't', otherwise the function returns false.

isValidDNAstring: returns true  if a string is only made up of valid DNA characters. If any other character exists in the string false is returned. You will want to call isValidDNAchar from within this function.

transcribe : Takes a DNA string argument, and returns its RNA equivalent.

gc :  The GC content of a single DNA sequence is the ratio of the total number of c’s and g’s to the length of the strand. For example, the sequence ATCGTTTGGA is of length 10 and has a total of 4 c’s and g’s, so its GC content is 0.4. This function should return a double between 0 and 1 that is the GC content of a DNA sequence.

complementChar: returns the complement of the base character.  If the argument is the base character 'a', then the character 't' is returned; If the argument is the base character 'c', then 'g' is returned, etc. Precondition: the base character argument is a valid DNA character.

complementStr: returns the complementary DNA string of a valid DNA string. Precondition: the argument is a valid DNA string. You will want to call complementChar from within this function.

codons: returns a vector of codons contained in an RNA string where each codon is a string of three nucleotides. If the length of the RNA sequence is not divisible by 3, then the last string in the vector will be either 1 or 2 characters long.

numCodon: takes a vector of codons (created by the function above), and a three character string as arguments and returns the number of times the string exists in the vector.
 
Part 2) Now write another program, you may use your code from part 1. Your program is going to read dna.txt and fill up an array of struct objects of a user defined type called DNA. Each DNA object is going to have the following data members:

•	A vector of strings that holds the header lines
•	The actual DNA string
•	The gc content of the DNA string which should be a double

Your program should :

•	Declare a MAX_DNA_SIZE constant of 1,000, and then declare an array of DNA struct objects.

•	For each DNA datum in the file (header lines and the actual DNA string) your program should check if a string is a valid DNA string. If it is not a valid string, the DNA data of the invalid DNA should be output to file called badDNA.txt, otherwise if the DNA string is valid, your program should add the DNA data to the array.

•	Calculate and fill the “gc content” data member of each DNA object in the array.

•	Create an output file called headerLinesFreq.txt that contains the frequency of the number of header lines. The file should have two columns, the columns separated (delimited) with tabs. The first column should be the number of header lines starting at 1, and the second column should be the number of DNA data that have that many header lines. It should look something like this (I am making these numbers up):

1	456 
2	320
3	119
4	50
5	23
…
This can read as 456 of the DNA data entries in the input file have only a 1 line header. 320 of them have 2 line headers. 119 entries have 3 lines. 

This part of your program should work with any DNA data file, no matter how many header lines is the maximum. 

•	Sort the array by gc content from lowest gc ratio to highest (nondecreasing).

•	Create a new file called GCcontent.txt which contains the original (valid) DNA data, sorted by gc content. List the gc content of each DNA sequence as an additional header line. This should be the last header line, immediately preceding the sequence.

Example:
> 77119805 Human rotavirus G3 segment 11, 
>  This is a complete sequence
> GC content: .45
ggcttttaaagcgctacagtgatgtctctcagtattgacgtgacgagtcttccttctatt

•	Create a new file called expandedDNA.txt which contains the original (valid) DNA data, followed by:
o	the transcription of the DNA into RNA 
o	the number of times UGG exists in the RNA sequence; the codon UGG maps on to the amino acid tryptophan - based on the codon function described above.  
o	the complement DNA string

each with their own header line.

So assuming the following DNA data is in the input file (dna.txt), and is a correct DNA sequence:

> gg_nat_gene ggrobacterium rhizogen
> this is not a complete sequence
atcgtttgga     

Your output file expandedDNA.txt would have the following lines:

> gg_nat_gene ggrobacterium rhizogen
> this is not a complete sequence
atcgtttgga     
> RNA:
aucguuugga
> Number of UGG (tryptophan): 1
> DNA complement:
tagcaaacct


All of this should be done in a single cpp file. You should submit that file to your 136 instructor's Blackboard page. Your 136 instructor may give further instructions on exactly how he wants you to submit your project.
