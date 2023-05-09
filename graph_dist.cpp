# include <iostream>


// execution starts from here
int main(int argc, char** argv){
	// variables declared here
	std::pair<int, int> p1, p2;
	float distance;
	
	// asking the user for the point coordinates
	std::cout << "Enter the coordinates for the first point(x, y):\n";
	std::cin >> p1.first >> p1.second;
	std::cout << "Enter the coordinates for the second point:\n";
	std::cin >> p2.first >> p2.second;
	
	// calculating the distance
	distance = sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
	
	// printing the distance
	std::cout << "The distance is " << distance;	
	return 0;
}
