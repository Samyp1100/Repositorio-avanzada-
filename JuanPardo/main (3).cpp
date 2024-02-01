#include <iostream>

#define DISTRICTS 5
#define CANDIDATES 4
using namespace std;

char get_candidate_letter(int number);
int votes[DISTRICTS][CANDIDATES] = {
    {194, 48, 206, 45},
    {180, 20, 320, 16},
    {221, 90, 140, 20},
    {432, 50, 821, 14},
    {820, 61, 946, 18}
};
int main()
{
    cout<<"a. Impresión de los votos"<<endl;
    cout<<"Distrito  A   B   C   D"<<endl;
    for (int i = 0; i < DISTRICTS; i++) {
        cout<<"   "<<i+1<<"      ";
        for (int j = 0; j < CANDIDATES; j++) {
            cout<<votes[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"Cálculo de votos y ganador"<<endl<<endl;
    int results[CANDIDATES]={0,0,0,0}; 
    float total_votes=0;
    for (int i = 0; i < DISTRICTS; i++) {
        for (int j = 0; j < CANDIDATES; j++) {
            results[j] += votes[i][j];
            total_votes += votes[i][j];
        }
    }
    float percentages[CANDIDATES] = {0.0, 0.0, 0.0, 0.0};
    for (int i = 0; i < CANDIDATES; i++) {
        percentages[i] += results[i]/total_votes;
        cout<<"Votos de "<<get_candidate_letter(i)<<": "<<results[i]<<" ("<<percentages[i]*100<<"%)"<<endl;
    }
    for (int i = 0; i < CANDIDATES; i++) {
        if(percentages[i]>0.5){
            cout<<endl<<"El ganador es el candidato "<<get_candidate_letter(i)<<endl;
            return 0;
        }
    }
    // el primer elemento es el candidato y el segundo sus votos
    int winners[2][2]={
        {0,0},
        {0,0}
    };
    for (int i = 0; i < CANDIDATES; i++) {
        if(results[i]>winners[0][1]){
            winners[0][0]=i;
            winners[0][1]=results[i];
            continue;
        }
        if(results[i]>winners[1][1]){
            winners[1][0]=i;
            winners[1][1]=results[i];
        }
    }
    cout<<"Los ganadores son "<<get_candidate_letter(winners[0][0]) <<" y "<<get_candidate_letter(winners[1][0])
        <<" y pasan a segunda vuelta" <<endl;
    return 0;
    
    
}

char get_candidate_letter(int number){
    switch(number){
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        case 3:
            return 'D';
    }
    return ' ';
}