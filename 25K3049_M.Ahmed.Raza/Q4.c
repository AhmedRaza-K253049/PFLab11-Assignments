#include <stdio.h>
#include <string.h>

struct movie{
    char title[50];
    char genre[50];
    char director[50];
    int releaseYear;
    float rating;
};
void addMovie(struct movie movies[], int *count){
    if(*count >= 50){
        printf("Cannot add any more movies");
        return;
    }
    printf("Enter Movie title: ");
    fgets(movies[*count].title, 50, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = '\0';

    printf("Enter Genre of the movie: ");
    fgets(movies[*count].genre, 50, stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = '\0';

    printf("Enter Director of the movie: ");
    fgets(movies[*count].director, 50, stdin);
    movies[*count].director[strcspn(movies[*count].director, "\n")] = '\0';

    printf("Enter Year of Release of the movie: ");
    scanf("%d", &movies[*count].releaseYear);

    printf("Enter Rating of the movie: ");
    scanf("%f", &movies[*count].rating);

    (*count)++;
    printf("Movie has been added !\n");
}
void searchGenre(struct movie movies[],char search[], int count){
    for(int i = 0; i < count; i++){
        if(strcmp(movies[i].genre, search) == 0){
            printf("\nTitle: %s\nGenre: %s\nDirector of Movie: %s\nYear of Release: %d\nRating: %.1f", movies[i].title,movies[i].genre,movies[i].director,movies[i].releaseYear,movies[i].rating);
        }
    }
}
void display(struct movie movies[], int count){
    for(int i = 0; i < count; i++){
            printf("\nTitle: %s\nGenre: %s\nDirector of Movie: %s\nYear of Release: %d\nRating: %.1f", movies[i].title,movies[i].genre,movies[i].director,movies[i].releaseYear,movies[i].rating);
            printf("\n");
    }
}
int main(){
    struct movie movies[50];
    char search[50];
    int choice, repeat = 0, count = 0;
    do{
        printf("Do you want to add a movie or search for movies by genre or display all movies stored. Enter 1, 2 and 3 for each respectively\n");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                printf("Enter genre for movies to search for: ");
                fgets(search, 50, stdin);
                search[strcspn(search, "\n")] = '\0';
                searchGenre(movies, search, count);
                break;
            case 3:
                display(movies, count);
                break;
            default:
            printf("Input should be 1 / 2 / 3");
        }
        printf("Do you want to Continue or End the application ? Enter 1 and 0 for each respectively\n");
        scanf("%d", &repeat);
    }while(repeat);
}