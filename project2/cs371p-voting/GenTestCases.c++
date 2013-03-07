#include <iostream>
#include<vector>
#include <algorithm>

int main() {
	/*Candidate List to use*/
	std::vector< std::string > candidates = {
    "Felton Aubin",
    "Bruce Hodak",
    "Yoshiko Marone",
    "Lonnie Nock" ,
    "Kandy Domenick",
    "Cindi Shafer",
    "Alex Vanvliet",
    "Marquis Kunkle",
    "Joetta Pinero",
    "Darrel Philipps",
    "Aurora Bond",
    "Tyron Kernan",
    "Sheri Salvas", 
    "Quyen Armistead",
    "Cathrine Kucera",
    "Ola Mabe",
    "Maritza Toy",
    "Jada Krall",
    "Kari Greear",
    "Georgann Holahan" };
    
    /* Generate Random Number of Test Cases [1, 5]*/	
	srand(unsigned(time(NULL)));
	int numCases = 1 + rand()%4;
	
	std::cout << numCases << std::endl << std::endl;
	
	/*Loop through number of test cases*/
	//for(int i = 0; i < numCases; i++) {
	
		/* Generate Random Number of Candidates [1 ,20]*/	
		//srand(unsigned(time(NULL)));
		int numCandidates = 1 + rand()%19;
	    //int numCandidates = 1;
	    
	    /*Print out Num Candidates and then blank line*/	
	    std::cout <<  numCandidates;
		std::cout <<  std::endl;
		
		/*Generate Random Number of Ballots[1, 1000]*/
		//srand(unsigned(time(NULL)));
		int numBallots = 1 + rand()%150;		
	    //int numBallots = 1;
	
		/*Print out candidates*/
		for(int i = 0; i < numCandidates; i++) {
			std::cout << candidates[i] << std::endl;
		}	
	    
	    std::vector< int >votes;
	    
	    for (int i = 0; i < numCandidates; i++) {
	    	votes.push_back(i + 1);
	    }
	    
		srand(unsigned(time(NULL)));
		for(int j = 0; j < numBallots; j++) {
			std::random_shuffle(votes.begin(), votes.end());
			for(int i = 0; i < (int)votes.size(); i++) {
				std::cout << votes[i] << " ";
			}
			
		std::cout << std::endl;		
		}
		//if( i != numCases - 1)
			//std::cout << std::endl;
	//}
}
