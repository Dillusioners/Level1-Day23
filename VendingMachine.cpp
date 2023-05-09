# include <iostream>
# include <limits>
# include <vector>

// fixes std::cin if bad input is provided
void fix_cin(){
	if(std::cin.fail()){
		// clearing std::cin from bad to good
		std::cin.clear();
		// removing all of the bad input from std::cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	}	
}

// VendingMachine class as the backbone of the program
class VendingMachine{
	private:
		// stores all the avaliable items in the machine
		std::vector<std::string> items;
		
	public:
		// constructor for the class
		VendingMachine();
		// shows the menu panel
		void showPanel();
		// prints all the avaliable items
		void viewItems();
		// purchase an item
		void purchase();		
};

VendingMachine::VendingMachine(){
	// initializing all items
	items = {"Coca Cola", "Limca", "Pepsi", "Pringles",
	"Dr. Pepper", "Doritoes", "Diet Coke"};
}

void VendingMachine::showPanel(){
	// variable declaration and welcome statement
	int choice;
	bool run = true;
	std::cout << "DILLUSIONERS VENDING MACHINE.";
	
	// looping until user exits
	while(run){
		// printing menu and taking input
		std::cout << "\n\nThe following are your options:\n1. View Items\n2. Purchase\n3. Exit\n>> ";
		std::cin >> choice;
		fix_cin();
		
		// switch-case on user choice
		switch(choice){
			case 3: { // exit
				run = false;
				break;
			}	
			case 1: { // view items
				viewItems();
				break;
			}	
			case 2: { // purchase
				purchase();
				break;
			}
			default: { // value not on the menu
				std::cout << "The above choice is invalid.";			
			}
						
		}	
	}	
}

void VendingMachine::viewItems(){
	std::cout << "\n\n";
	int itr = 1;
	
	// iterating through the vector and printing out all the items
	for(auto i = items.begin(); i != items.end(); i++, itr++){
		std::cout << itr << ". " << *i << std::endl;	
	}	
}

void VendingMachine::purchase(){
	int code;
	
	// asking for item code	
	std::cout << "\n\nEnter Item code: ";
	std::cin >> code;
	fix_cin();
	
	// checks if item code is invalid
	if(code < 1 || code > (int)items.size()){
		std::cout << "Invalid Code Item provided.\n";
		std::cout << "If you donot know what is item code, refer to option 1 in menu.";
		return;	
	}
	
	// success message	
	std::cout << "Successfully purchased " << items[code - 1] << " at the cost of $0.5";
}

// execution starts from here
int main(int argc, char** argv){
	// declaring object and showing the panel
	VendingMachine vend;
	vend.showPanel();	
	return 0;
}
