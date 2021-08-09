#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

string dataBase[500];
int order[35];
int randNum[35];

class Dictionary {
public:
	void getdataBase() 
	{
		// capture database file into dataBase[] array.
		int i;
		fstream file;

		file.open("vocab_one.dat", ios::in);
		while(!file.eof())
		{
			file >> dataBase[i];
			i++;
		}
		file.close();
	}

	int search(string s_string) 
	{
		//search element number in dataBase[]
		int i;

		for (i = 0; i < 500; i++) 
		{
			if ((s_string) == dataBase[i])
				break;
		}
		return i;
	}

	void searchChapter(int n)
	{
		//search chapter by name and define head and scope value.
		string temp[] = {"ps1", "ps2", "ps3", "ps4", "ps5", "ps6", "ps7"};
		string c_name = temp[n-1];

		head = search(c_name) + 1;                      // the first word element number.
	    cout << head << endl;
			scope = search(c_name + "_end") - head;         // number of word in chapter.
	    cout << scope;
	}

	void order_vertical() 
	{
		//generate print sequence of vertical display.
		int c1, c2, c3;
		int display_column = 3;
		int i;

		switch (scope % display_column) {
			case 0:
				c1 = c2 = c3 = scope / display_column;
				break;

			case 1:
				c1 = c2 = scope / display_column + 1;
				c3 = scope / display_column - 1;
				break;

			case 2:
				c1 = c2 = scope / display_column + 1;
				c3 = scope / display_column;
				break;
		}

		for (i = 0; i < c1; i++)
			order[0 + i*display_column] = i + 1;

		for (i = 0; i < c2; i++)
			order[1 + i*display_column] = i + c1 + 1;

		for (i = 0; i < c3; i++)
			order[2 + i*display_column] = i + c1 + c2 +1;
			
		if (scope % 3 == 1) {
		    order [scope - 1] = c2 + c1;
		    order [scope - 2] = c1;
		}
	}

	void order_random() 
	{
		//generate print sequence of random display.
		int i,j;
        int temp;
        bool check;

        // reset randNum[] to 0
        for (i = 0; i < scope; i++) {
        	randNum[i] = 0;
        }
        
        for (i = 0; i < scope; i++) {
            do {
                temp = rand() % scope + 1;
                check = false;
                
                for (j = 0; j < scope; j++) {
                    if (randNum[j] == temp)
                        check = true;
                }
            } while (check == true);
        
            randNum[i] = temp;
        }
    
        for (i = 0; i < scope; i++) {
            cout << order[i] << " ";
        }
	}

	// using in searchChapter() only
	void displayList() {
		int i;
		string withNum;				// string of word including item number at the begining
		int display_column = 3;		// number of column that the list display

		switch (scope % 3) {
			case 1:
				for (i = 0; i < scope; i++) {
					withNum = to_string(order[i]) + "." + dataBase[head + order[i] - 1];
					cout << left << setw(35) << withNum;
					
					if (i >= scope - 4) {
						if (i == scope-1 || i == scope-3)
							cout << endl;

					} else {
						if ((i+1) % 3 == 0) {
							cout << endl;
						}
					}
				}
				break;

			case 2:
			case 0:
				for (i = 0; i < scope; i++) {
					withNum = to_string(order[i]) + "." + dataBase[head + order[i] - 1];

					cout << left << setw(35) << withNum;
					if ((i+1) % 3 == 0) {
						cout << endl;
					}
				}
				break;
		}
		
		cout << endl;
	}
    
    void displayListRandom() {
		int i;
		string withNum;				// string of word including item number at the begining
		int display_column = 3;		// number of column that the list display


		switch (scope % 3) {
			case 1:
				for (i = 0; i < scope; i++) {
					withNum = to_string(order[i]) + "." + dataBase[head + randNum[i] - 1];
					cout << left << setw(35) << withNum;
					
					if (i >= scope - 4) {
						if (i == scope-1 || i == scope-3)
							cout << endl;
					} 
					else {
						if ((i+1) % 3 == 0) {
							cout << endl;
						}
					}
				}
				break;

			case 2:
			case 0:
				for (i = 0; i < scope; i++) {
					withNum = to_string(order[i]) + "." + dataBase[head + randNum[i] - 1];

					cout << left << setw(35) << withNum;
					if ((i+1) % 3 == 0) {
						cout << endl;
					}
				}
				break;
		}
		
		cout << endl;
	}

	void instruction() {
    	cout << "Ch1 - My grandmother\n\n";
		cout << "Passage 1 - Norwegian parents accident.\n";
		cout << "Passage 2 - Five children story.\n";
		cout << "Passage 3 - Point number 1 and 2.\n";
	    cout << "Passage 4 - Point number 3 and 4.\n";
	    cout << "Passage 5 - Back to England.\n";
	    cout << "Passage 6 - Tree house issue.\n";
	    cout << "Passage 7 - Summer hoilday.\n";
		cout << "?";
		cin >> page;
	}

	void insertWord() {
		string insert[5];
		int i;

		cout << "Enter your five word: \n";
		cout << "? ";
		for (i = 0; i < 5; i++) {
			cin >> insert[i];
		}
		cout << "well done. you inputed five words.\n";
	}

	int getPage() {
		return page;
	}

	void pageElon() {
		int e_page;

		searchChapter(page);
		order_vertical();
		cout << "\n=== vocabulary list: ===\n" << endl;
		displayList();

		do{
			cout << "\n1.random 2.normal 3.back ?" ;
			cin >> e_page;
			switch (e_page) {
				case 1:
          order_random();
					cout << "\n=== vocabulary list: ===\n" << endl;
					displayListRandom();
					break;

				case 2:
					//order_vertical();
					cout << "\n=== vocabulary list: ===\n" << endl;
					displayList();
					break;
			}

		} while (e_page != 3);

		cout << "back to main menu.\n" << endl;
	}

private:
	int page;
	int scope;
	int head;
};

int main() {
	
	Dictionary myDictionary;
	myDictionary.getdataBase();

	cout << "\n==== Welcome to Vocab One program. ====" << endl;

	while (1) {
		myDictionary.instruction();
		myDictionary.pageElon();
	}
}