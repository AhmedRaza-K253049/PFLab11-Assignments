#include <stdio.h>
#include <string.h>
struct player{
    char name[30];
    int age;
    char position[30];
};
struct team{
    char name[20];
    char sport[20];
    struct player players[11];
    int playercount;
};
void addPlayer(struct team teams[], char teamname[], int count){
    char playername[30], playerposition[30];
    int playerage, index = -1, p;
    for(int i = 0; i < count; i++){
        if(strcmp(teams[i].name, teamname) == 0){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("Team Not Found !\n");
        return;
    }
    printf("Enter Player Name: ");
    fgets(playername, 30, stdin);
    playername[strcspn(playername, "\n")] = '\0';

    printf("Enter Player Position: ");
    fgets(playerposition, 30, stdin);
    playerposition[strcspn(playerposition, "\n")] = '\0';

    printf("Enter Player Age: ");
    scanf("%d", &playerage);
    getchar();

    if(teams[index].playercount < 11){
        p = teams[index].playercount;
        teams[index].playercount += 1;
        strcpy(teams[index].players[p].name, playername);
        strcpy(teams[index].players[p].position,playerposition);
        teams[index].players[p].age = playerage;
    }
}
void searchPosition(struct team teams[], int count){
    char searchPosition[20];
    printf("Enter position to search for: ");
    scanf("%s", searchPosition);
    getchar();
    for(int i = 0; i < count; i++){
        for(int j = 0; j < teams[i].playercount; j++){
            if(strcmp(teams[i].players[j].position, searchPosition) == 0){
                printf("Name: %s\nAge: %d\nSport: %s\nTeam: %s",teams[i].players[j].name, teams[i].players[j].age, teams[i].sport, teams[i].name);
            }
        }
    }
}
void displayTeam(struct team teams[], int count){
    for(int i = 0; i < count; i++){
        printf("\nTeam Name: %s\nTeam Sport: %s\nPlayers in Team: %d",teams[i].name,teams[i].sport,teams[i].playercount);
    }
}
int main(){
    struct team teams[10];
    char teamName[20], postion[20];
    int choice, repeat = 0, count = 0;
    do{
        printf("Do you want to add a player to a team or search a players by position or display team details ? Enter 1, 2, 3 for each respectively\n");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                printf("Enter team name you want to add player to: ");
                fgets(teamName, 20, stdin);
                teamName[strcspn(teamName, "\n")] = '\0';
                addPlayer(teams, teamName, count);
                break;
            case 2:
                searchPosition(teams, count);
                break;
            case 3:
                displayTeam(teams, count);
                break;
        }
        printf("Do you want to continue or exit the program ? Enter 1 or 0 for each respectively\n");
        scanf("%d", &choice);
    }while(choice);
}