
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "winterGames.h"

using namespace std;




winterGames::winterGames(int dimension, int max_amount): dim(dimension), maxAmount(max_amount) {
    this->athleteCount = 0;
    athletes = new string[max_amount];
    scores = new double*[max_amount];
    for (int i = 0; i < max_amount;i++){
        scores[i] = new double[dimension];
        }

    }
//   freeing memory of all dynamically allocated arrays.
winterGames::~winterGames() {
        delete[] athletes;
        for(int i = 0; i < this->athleteCount; i++){
            delete[] scores[i];
        }
        delete[] scores;
    }




// the menu of the program
void winterGames::start() {
    int index, userChoice = 7;

    while (userChoice != 0) {
        cin >> userChoice;
        switch (userChoice) {
            case 0:
                return;
            case 1:
                this->addResult();
                break;
            case 2:
                this->prntAthlete();
                break;
            case 3:
                index = this->findName();
                this->athleteAvg(index);
                break;
            case 4:
                this->athleteScores();
                break;
            case 5:
                this->avgResuls();
                break;
            case 6:
                this->Covariance();
                break;
            default:
                cout << "ERROR: invalid command; type 0 for exit" << endl;
                break;

        }
    }
}


void winterGames::addResult() {
    string new_A, numbers;
    double temp = 0;//will hold next number to be added
    int count = 0;//will count the index of the number just added
    int indexAthlete;//will hold the index of the player to be added/switched if already exist
    cin >> new_A;
    if(new_A.length() > 18 || new_A.length() < 1){
        cerr << "ERROR: invalid input" << endl;
        return;
}
    cin.ignore();
    getline(cin, numbers); // getting score results
    if(checkLegalnumbers(this->getDimension(), numbers)){//checking if legal score number input
        std::replace(numbers.begin(),  numbers.end(),',',' ');
        istringstream ss(numbers);
        indexAthlete = (findIndex(this->athletes, new_A, this->athleteCount));//checking if new athlete to get index
        if(indexAthlete >= 0){ //athlete already exist
            while(ss >> temp){
                scores[indexAthlete][count] = temp;//updating scores in correct index
                count++;}
        }
        else{//new athlete
            if(athleteCount >= this->maxAmount){
                cout << "ERROR: MAX_ATHLETES exceeded" << endl;
                return;
            }
            athletes[this->athleteCount] = new_A; //adding new athlete
            while(ss >> temp){
                scores[this->athleteCount][count] = temp;//adding scores in correct index
                count++;}
            this->athleteCount++; // updating amount of athletes entered so far
        }
        }

    else{cerr << "ERROR: invalid input" << endl;
        return;
    }



}
// get name from user and returns its index.
int winterGames:: findName(){
    int index;
    string name;
    cin >> name;
    index = findIndex(athletes, name, athleteCount);
    if( index < 0){
        cerr << "ERROR: "<< "<" <<name <<"> " << "does not exist" << endl;


    }
    return index;

}


void winterGames::prntAthlete() {
    int index = findName();
    cout << athletes[index] <<"=[";
    for (int i = 0;i<dim;i++){
        cout << scores[index][i];
        if (i == (dim-1)){
            break;
        }
        else{
            cout <<",";
        }
    }
    cout <<"]"<<endl;

}
void prntFloat(double num){
    stringstream ss;
    ss << fixed << setprecision(2) <<num;
    string str = ss.str();

    // Remove trailing zeroes
    str = str.substr(0, str.find_last_not_of('0') + 1);
    // If the decimal point is now the last character, remove that as well
    if (str.find('.') == str.size() - 1) {
        str = str.substr(0, str.size() - 1);
    }
    cout << str;
}

//calculates the avg of an athlete and prints it.
void winterGames::athleteAvg(int const index) {
    double avg, sum = 0;
    for (int i = 0; i<getDimension();i++){
        sum += scores[index][i];
    }
    avg = sum/getDimension();

    cout << athletes[index] <<", ";
    prntFloat(avg);
    cout << endl;




}

void winterGames::athleteScores() {
    if(getAthleteCount() == 0){
        cerr << "ERROR: no records in the system" <<endl;
        return;

    }
    for(int i = 0;i < getAthleteCount();i++){ // looping over each athlete and calling the function for printing the avg.
        athleteAvg(i);
    }

}



//loops over each referee (each column) calculates the avg and prints it
void winterGames::avgResuls() {
    double sum;
    double vec[getDimension()]; // holds all the avg
    for (int i = 0;i < getDimension();i++){
        for (int j = 0; j < getAthleteCount(); j++){
            sum += scores[j][i];
        }
        vec[i] = sum/getAthleteCount();
        sum = 0;
    }
    cout << "mean=[";
    for (int i = 0; i< getDimension();i++){
        prntFloat(vec[i]);
        if (i == (getDimension()-1)){
            break;
        }
        else{
            cout <<",";
        }
    }
    cout <<"]" <<endl;
}


void winterGames::Covariance() {
    if (getAthleteCount() == 0){
        cerr << "ERROR: no records in the system"<<endl;
        return;
    }
    double covecMatrix[getDimension()][getDimension()]; // will hold the covariance matrix
    double covev[getDimension()]; // will hold the referees average.
    double sum = 0;
    int flag = getAthleteCount()>1?1:0; // for the equation (M-1 or not)

    for (int i = 0;i< getDimension();i++){ //getting the average of referees.
        for (int j = 0; j <  getAthleteCount();j++){
            sum+=scores[j][i];
        }
        covev[i] = sum/getAthleteCount();
        sum = 0;
        
    }
        //the equation
        for (int M = 0; M < getAthleteCount() ; M++) {
            for (int i = 0; i < getDimension() ; i++) {
                for(int j = 0; j < getDimension();j++) {
                    covecMatrix[i][j] += ((scores[M][i] - covev[i]) * (scores[M][j] - covev[j]));
            }
            }


    }
        // printing the matrix
    cout<<"cov=["<<endl;
    for(int i = 0;i<getDimension();i++){
        for(int j = 0;j<getDimension();j++){
            prntFloat(covecMatrix[i][j]/(getAthleteCount()-flag));
            if(j == (getDimension()-1)){
                cout << endl;}
            else {
                cout << ",";

            }
        }
    }
    cout << "]" <<endl;
    }


//global funcs

int findIndex(string* athlete, const string& new_N , int athlete_count){
    for(int i = 0 ; i < athlete_count; i++){
        if(athlete[i] == new_N){
            return i;
        }
    }
    return -1;

}

bool isNumber(char const *str){
    for(unsigned int i = 0; i < strlen(str);i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}



bool checkLegalnumbers(int const dimension, const string& str) {
    int numCount = 1;
    bool hasDot = false;
    for( unsigned int i = 0 ;i < str.size() ;i++){

        if(str[i] == ','){
            numCount++;
            if(numCount>dimension){
                return false;
            }
            else {
                hasDot = false;
            }

        }
        else if(str[i] == '.' && hasDot){
            return false;
        }
        else if(str[i] == '.' && !hasDot){
            hasDot = true;
            if(i<1 || i == str.size()){
                return false;
            }
            if(!isdigit(str[i-1]) || !isdigit(str[i+1])){
                return false;
            }
        }
        else if(!isdigit(str[i])){
            return false;
        }
    }
    if(numCount>dimension){
        return false;
    }
    return true;
}


