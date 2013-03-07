// --------
// includes
// --------

#include <cassert> // assert
#include <iostream> // endl, istream, ostream
#include <vector> // vector
#include <algorithm> // max_element
#include <sstream> //istringstream

// Data struct ballot with vector of candidate numbers
struct ballot {
    std::vector<int> data;
    int index;
};

// Data struct candidate with name and vector of ballots
struct candidate {
    std::string name;
    std::vector< ballot > ballots;
    bool isEliminated;
};

// ------------
// globals
// ------------
const int MAX_LENGTH_NAME = 80;

// ------------
// voting_eval
// ------------

/**
 * Evaluates the ballots
 * @param candidates a reference to a candidate vector
 * @param numberOfBallots an int reference to the total number of ballots
 * @return true if that succeeds, false otherwise
 */
bool voting_eval (std::vector< candidate >& candidates, int& numberOfBallots, std::ostream& w) {
    
    int min = numberOfBallots;
    int max = 0;
    int maxIndex = 0;
    std::vector<int> minIndices;
    
    // Establish min and max num of ballots
    for(int i = 0; i < (int)candidates.size(); ++i){
        if(!candidates[i].isEliminated){
            min = std::min(min, (int)candidates[i].ballots.size());
            max = std::max(max, (int)candidates[i].ballots.size());
            if(max == (int)candidates[i].ballots.size())
                maxIndex = i;
        }
    }
    
    assert(min > 0);
    assert(max <= numberOfBallots);
    
    //if there is a tie, then print winners
    if(min == max){
        for(int i = 0; i < (int)candidates.size(); ++i){
            if(!candidates[i].isEliminated){
                w << candidates[i].name << std::endl;
            }
        }
        return true;
    }
      
    //if there's a single winner print name
    if(max > numberOfBallots/2){
        w << candidates[maxIndex].name << std::endl;
        return true;
    }
    
    // Add to min vector
    for(int i = 0; i < (int)candidates.size(); ++i){
        if(!candidates[i].isEliminated && (int)candidates[i].ballots.size() == min){
            minIndices.push_back(i);
            candidates[i].isEliminated = true;
        }
    }  
    
    // Cycle through min vector and check next highest vote, add to  candidate array ballot if
    //     still elligible
    for(int i = 0; i < (int)minIndices.size(); i++) {
    	for(int j = 0; j < (int)candidates[minIndices[i]].ballots.size(); j++) {
    		int index = candidates[minIndices[i]].ballots[j].index;  	
    		while(candidates[ candidates[minIndices[i]].ballots[j].data[index] - 1].isEliminated) {
    			index += 1;
    		}
    		candidates[ candidates[minIndices[i]].ballots[j].data[index] - 1].ballots.push_back(candidates[minIndices[i]].ballots[j]);
    	}
    }
    return voting_eval(candidates, numberOfBallots, w);
    
}


// ------------
// voting_read
// ------------

/**
 * reads in all the test cases
 * @param r a std::istream
 * @param candidates a reference to a candidate vector
 * @param numberOfBallots an int reference to the total number of ballots
 */
void voting_read (std::istream& r, std::vector< candidate >& candidates, int& numberOfBallots) {
        
    int numberOfCandidates, k;
    std::string line;
    char conLine[MAX_LENGTH_NAME];
    r >> numberOfCandidates;
    assert (numberOfCandidates > 0);
    r.getline(conLine, MAX_LENGTH_NAME);
    
    // Read in Candidates
    for(int j = 0; j < numberOfCandidates; j++){
        candidate thisCandidate;
        
        r.getline(conLine, MAX_LENGTH_NAME);
    	std::string name(conLine);     
        thisCandidate.name = name;
        thisCandidate.isEliminated = false;
        candidates.push_back(thisCandidate);
    }
	
	// While not the end of file or blank line, read in the ballots 
	//     and put them in the correct candidate ballot pile
    while(r.good()){
    	r.getline(conLine, MAX_LENGTH_NAME);
    	std::string line(conLine);
    	
    	if(line == ""){
    		break;
    	}
    	std::istringstream iss (line,std::istringstream::in);
    	ballot voterBallot;
    	voterBallot.index = 0;
    	
    	for(int i = 0; i < numberOfCandidates; ++i){
    		iss >> k;
    		voterBallot.data.push_back(k);
    	}
    	candidates[voterBallot.data[0] - 1].ballots.push_back(voterBallot);
    	++numberOfBallots;
    }
    assert (numberOfBallots > 0);
    //check for candidates with no ballots
    for(int i = 0; i < (int)candidates.size(); i++) {
    	if(candidates[i].ballots.size() == 0)
    		candidates[i].isEliminated = true;
    }
}
    
// -------------
// voting_solve
// -------------

/**
 * read and eval/print test cases
 * @param r a std::istream
 * @param w a std::ostream
 */    
void voting_solve (std::istream& r, std::ostream& w) {
    int numberOfTestCases;
    
    r >> numberOfTestCases;
    assert (numberOfTestCases > 0);
    for(int i = 0; i < numberOfTestCases; ++i){       
	    	
	 	int numberOfBallots = 0;
        std::vector< candidate > candidates;
        voting_read(r, candidates, numberOfBallots);        
		voting_eval(candidates, numberOfBallots, w);   
       	if(i != numberOfTestCases - 1)
       		w << std::endl;
	}
} 
      
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    voting_solve(cin, cout);
    return 0;} 
