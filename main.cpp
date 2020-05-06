#include <iostream>
#include "hash_Map_2.hpp"

using namespace std;

int main(){
  hash_map<char, string> Movies;
  Movies.insert('D',"Lo que el viento de llevo ");

	//Movies.display();

	cout << endl;

	Movies.insert('S',"Avengers");
	Movies.insert('C',"Matrix");
	Movies.insert('T',"saw");
	Movies.insert('I',"Frozen");

	//Movies.display();

	cout << endl;

	Movies.find('D');
  Movies.find('T');

	cout << endl;

	//Movies.display();

  return 0;
}
