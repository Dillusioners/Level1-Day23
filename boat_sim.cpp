// imported for input and output streams
# include <iostream>

/*
  * Author: LeeTuah
  * Program: Boat Riding Simulator
  * Date: 09/05/23
  * For SuperB league event
  */

int main(int argc, char const* argv[]){
	// variable declaration
	int people, input, total_weight = 0;
	
	// welcome text and people count taken
	std::cout << "Hello travellers! It seems you need to use my boat.\nHow many of you are here?: ";
	std::cin >> people;
	
	// if-else-if construct checks if people count is a positive integer
	// lesser than 7
	if(people < 0){
		std::cout << "I might be unschooled, but I am pretty sure people cannot be negative.\n";
		return 0;	
	}
	else if(people == 0){
		std::cout << "If none of you want to go along, then I just go by myself....\n";
		return 0;
	}
	else if(people > 6){
		std::cout << "Sorry lads! My boat is too small for this much of you.\n";
		return 0;	
	}
	
	// iterating through to get the inputs of all the individuals
	for(int i = 0; i < people; i++){
		// asking for input in output stream
		std::cout << "Enter the input for lad no. " << i + 1 << " (in kg): ";
		std::cin >> input;
		
		// checking if input is zero or negative
		if(input <= 0){
			std::cout << "I think this input doesnot work out.\n";
			i--;
			continue;	
		}
		
		total_weight += input;
	}
	
	// checking if the total input is too much for the boat to take
	if(total_weight > 500){
		std::cout << "Sorry fellas! My boat cannot take this much input.\n";
		return 0;	
	}
	
	std::cout << "Alright lads! I am ready to set sail when you are.\n";
	
	return 0;	
}
