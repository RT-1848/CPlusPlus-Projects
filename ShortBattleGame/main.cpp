#include <iostream>
#include <random>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: string;

int loudSoundPunch(string mon);
int bandaids(string mon);
int specialBeamAttack(string mon);
void runAway(string mon);
void outputHealth(string mon, string AImon, int userhp, int AIhp);

int main(){
	srand((unsigned)time(NULL));

	int damage;
	
	string AI = "BadguyAI";
	
	string mon;
	string AImon = "BattlemonX";

	int choice;
	int AIchoice;
	
  cout << AI <<" has requested a battle!!!" << endl << "..." << endl;
	cout << "BadguyAI sent out " << AImon << endl << "..." << endl;
	cout << "Who do you send out? "; getline(cin, mon);
	cout << "You sent out " << mon << "!" << endl << "\n\n";
	int AIhp = (rand() % 51) + 100;
	int userhp = (rand() % 51) + 100;
	
	
	cout << AImon << ": " << AIhp << "hp" << endl;
	cout << mon << ": " << userhp << "hp" << endl;

	while (AIhp > 0 && userhp > 0){

	cout << "Select Ability (1-4)" << endl;
	cout << "1. LOUDSOUNDPUNCH     " << " 3. BANDAIDS" << endl;
	cout << "2. SPECIALBEAMATTACK   " << "4. RUNAWAY" << endl;
	
	cout << "Choice: "; cin >> choice;
	while (choice > 4 || choice < 1){
		cout << "Invalid move. Try Again" << endl;
		cout << "Choice: "; cin >> choice;
	}

	
	if (choice == 1){
		damage = loudSoundPunch(mon);
		AIhp -= damage;
		outputHealth(mon, AImon, userhp, AIhp);
	}
	else if (choice == 2){
		damage = specialBeamAttack(mon);
		AIhp -= damage;
		outputHealth(mon, AImon, userhp, AIhp);
	}
	else if (choice == 3){
		damage = bandaids(mon);
		userhp += damage;
		outputHealth(mon, AImon, userhp, AIhp);
	}
	else if (choice == 4){
		runAway(mon);
		outputHealth(mon, AImon, userhp, AIhp);
	}

		
	AIchoice = (rand() % 4) + 1;
	
	if (AIchoice == 1){
		damage = loudSoundPunch(AImon);
		userhp -= damage;
		outputHealth(mon, AImon, userhp, AIhp);
	}
	else if (AIchoice == 2){
		damage = specialBeamAttack(AImon);
		userhp -= damage;
		outputHealth(mon, AImon, userhp, AIhp);
	}
	else if (AIchoice == 3){
		damage = bandaids(AImon);
		AIhp += damage;
		outputHealth(mon, AImon, userhp, AIhp);
	}
	else if (AIchoice == 4){
		runAway(AImon);
		outputHealth(mon, AImon, userhp, AIhp);
	}

	}
	if (AIhp <= 0){
		cout << mon << " won the battle!";
	}
	else if (userhp <= 0){
		cout << AImon << " won the battle!";
	}
}



int loudSoundPunch(string mon){
	cout << mon << " performed LOUDSOUNDPUNCH!";
	return ((rand() % 10) + 1);
}

int bandaids(string mon){
	cout << mon << " performed BANDAIDS!";
	return ((rand() % 7) + 4);
}

int specialBeamAttack(string mon){
	cout << mon << " performed SPECIALBEAMATTACK!";
	return 2 * (rand() % 9);
}

void runAway(string mon){
	cout << mon << " tried to run away..." << endl;
	cout << "too bad you can't in our awesome game!";
}

void outputHealth(string mon, string AImon, int userhp, int AIhp){
	cout << "\n\n\n" << AImon << ": " << AIhp << "hp" << endl;
	cout << mon << ": " << userhp << "hp" << endl;
}
