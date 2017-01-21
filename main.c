#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
int level = 0;
double high_score = 0;
double my_time = 0;
int speed;
double level_high_score = 0;
int word_counter = 0;
int level_word_counter = 0;
double level_enter_time = 0;

struct player
{
    char player_name[40];
    double high_score;
    int level;
    int word_counter;
    double Play_time;
    int begin_level;
    struct player *next;
};


struct wordlist
{
    char word[40];
    struct wordlist * next;
};





//
//struct player * create_player_list(void){
//struct player *player_list=(struct player *) malloc (sizeof(struct player));
//struct player * tmp = (struct player *) malloc (sizeof(struct player));
//struct player * current;
//current =player_list;
//player_list->next = NULL;
//FILE *fp;
//fp=fopen("Players.bin","rb");
//int k=fread(player_list,sizeof(struct player),1,fp);
//if(k<=0)
//return NULL;
//while(k>0){
//k = fread(tmp,sizeof(struct player),1,fp);
//if(k<=0)
//break;
//add_end_player(player_list,tmp);
//current=current->next;
//}
//current=current->next;
//current->next=NULL;
//return player_list;
//}
//
//
//
//void add_end_player(struct player *my_player,struct player *new_d){
//struct player *current;
//for(current = my_player; current->next!=NULL; current=current->next);
//new_d->next=NULL;
//current->next=new_d;
//}
//
//void show_Top_10(struct player *my_player){
//struct player *current1;
//struct player *current2;
//struct player *racer=(struct player *)malloc(sizeof(struct player));
//int i;
//int count;
//double max=0;
//current1=my_player;
//if(current1==NULL)
//printf("NO players played yet!\n");
//for(i=0; i<10; i++){
//max=0;
//count=1;
//current1=my_player;
//current2=my_player;
//if(current1==NULL)
//break;
//while(current2!=NULL){
//if((current2->high_score)>max){
//max=current2->high_score;
//}
//current2=current2->next;
//}
//while(current1->high_score!=max){
//count++;
//current1=current1->next;
//}
//racer=current1;
//  printf("%d.%s     Highscore:%.2lf     Level:%d     WPM:%.2lf     Levelscore:%d\n",i+1,racer->player_name,racer->high_score,racer->level,((racer->word_counter * 1.0 * 60)/(racer->Play_time)),((racer->level)-(racer->begin_level))*10);
//if(count==1){
//delete_front_player(&my_player);
//}
//else if(count==player_number(my_player)){
//delete_end_player(my_player);
//}
//else{
//delete_next_player(my_player,count-2);
//}
//}
//current1=my_player;
//while(current1!=NULL){
//delete_front_player(&my_player);
//}
//return;
//}
//
//
//
//void show(struct player *me){
//struct player *current;
//for(current = me; current!=NULL ; current=current->next){
//    printf("%s\n",current->player_name);
//}
//return;
//}
//
//
//int player_number(struct player *my_player){
//struct player *current=my_player;
//int counter=0;
//while(current!=NULL){
//counter++;
//current=current->next;
//}
//return counter;
//}
//
//
//
//
//
//
//void delete_front_player(struct player **my_list)
//{
//    struct player *save;
//    save = *my_list;
//    *my_list = (*my_list)->next;
//}
//
//void delete_next_player(struct player *my_list,int next_go)
//{
//    struct player *current;
//    current=my_list;
//    while(next_go)
//    {
//        current=current->next;
//        next_go--;
//    }
//    struct player *tmp=current->next;
//    current->next=tmp->next;
//}
//
//
//void delete_end_player(struct wordlist *my_list)
//{
//    struct player * current = my_list;
//    struct player *tmp=current->next;
//    while(tmp->next !=NULL)
//    {
//        current = current->next;
//        tmp=current->next;
//    }
//    free(tmp);
//    free(current->next);
//    current->next = NULL;
//}








int find_max_level (void)
{
    int k = 1;
    char levels[50];
    strcpy(levels, "level-");
    FILE *fp;
    char l[50];
    sprintf(l, "%d", k);
    strcat(l, ".txt");
    strcat(levels, l);
    fp=fopen(levels, "r");
    while(fp != NULL)
    {
        k++;
        strcpy(levels, "level-");
        levels[7] = '\0';
        sprintf(l, "%d", k);
        strcat(l, ".txt");
        strcat(levels, l);
        fp=fopen(levels, "r");
    }
    return (k-1);
}




void add_end (struct wordlist * my_list, char s[40])
{
    struct wordlist * current;
    struct wordlist * new_word = (struct wordlist *) malloc (sizeof(struct wordlist));
    strcpy(new_word->word, s);
    for(current = my_list; current->next != NULL; current = current->next);
    current->next = new_word;
    new_word->next = NULL;
}

void delete_front (struct wordlist **my_list)
{
    *my_list = (*my_list)->next;
}

void delete_next (struct wordlist *my_list, int next_go)
{
    struct wordlist * current;
    current = my_list;
    while(next_go)
    {
        current = current->next;
        next_go--;
    }
    struct wordlist * tmp = current->next;
    current->next = tmp->next;
}


void delete_end (struct wordlist *my_list)
{
    struct wordlist * current = my_list;
    struct wordlist *tmp = current->next;
    while(tmp->next != NULL)
    {
        current = current->next;
        tmp = current->next;
    }
    free(tmp);
    free(current->next);
    current->next = NULL;
}


void print_list (struct wordlist *my_list)
{
    struct wordlist * current;
    for (current = my_list; current->next != NULL; current = current->next)
    {
        printf("%s\n", current->word);
    }
    printf("%s\n", current->word);
    return;
}

void add_front (struct wordlist **plist, char front_word[40])
{
    struct wordlist * new_word = (struct wordlist *)malloc(sizeof(struct wordlist));
    strcpy(new_word->word, front_word);
    new_word->next = *plist;
    *plist = new_word;
}

struct wordlist * create_level_link_list (int chosen_level, struct player *racer)
{
    char ch;
    FILE *fp;
    char levels[50];
    strcpy(levels , "level-");
    char ld[50];
    sprintf(ld , "%d", chosen_level);
    strcat(ld , ".txt");
    strcat(levels , ld);
    fp=fopen(levels , "r");
    if(fp == NULL)
    {
        printf("You reached end of our level!\nThank you for playing this game!\n");
        printf("Do you wish to save your level and score?(Y/N)");
        if(ch == 'Y')
        {
            save_player(racer);
            exit(0);
        }
        if(ch == 'N')
        {
            exit(0);
        }
    }
    speed = (find_max_level() - chosen_level + 1)*150;
    char save_word[40];
    struct wordlist * level_link_list = (struct wordlist *) malloc (sizeof(struct wordlist));
    level_link_list->next = NULL;
    int k;
    k = fscanf(fp, "%s", &save_word);
    strcpy(level_link_list->word, save_word);
    while(k>0)
    {
        k = fscanf(fp, "%s", &save_word);
        if(k<=0)
            break;
        add_end(level_link_list, save_word);

    }
    fclose(fp);
    return level_link_list;
}

int word_number (struct wordlist * my_list)
{
    struct wordlist * current;
    int counter = 1;
    for(current = my_list; current->next != NULL; current = current->next)
    {
        counter++;
    }
    return counter;
}

void welcome (void)
{
    HANDLE welcome_console;
    welcome_console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(welcome_console, 121);
    printf("Hi dear player!Welcome to our little type racing.\n");
    printf("Firt you must enter your name.\nSo if you quit game you can continue from your current level!\n");
    printf("After that you will choose the level you want to play!\nthere is no need to play from level 1! ;D\n");
    printf("Remember this that if you finish all of our levels your level will be saved as %d! ;D\n", (find_max_level() + 1));
    printf("There is other options in our game:\nyou can see Top 10 players at main menu!\nor see what players played our game before!\n");
    printf("My name is Soroush Barmaki!Creator of this little game!\nIf you have any idea to improve this game call me!\n");
    printf("My Email address : SR.BARMAKI@aut.ac.ir\n");
    printf("Let the fun begin!Press any key to enter game!\n");
    char c;
    c=getch();
    system("cls");
    return;
}


int selection (void)
{
    int select_me;
    scanf("%d", &select_me);
    system("cls");
    while(select_me > 4 || select_me < 1)
    {
        printf("%d\n", select_me);
        printf("Worng choice\n");
        scanf("%d", &select_me);
        system("cls");
    }
    return select_me;
}







void show_players (void)
{
    struct player * racer = (struct player *) malloc (sizeof(struct player));
    FILE *fp;
    fp=fopen("Players.bin", "rb");
    int i = 1;
    int k = fread(racer, sizeof(struct player), 1, fp);
    if(k == 0 || k < 0)
    {
        printf("NO players played yet!\n");
        return;
    }
    printf("%d.%s     Highscore:%.2lf     Level:%d     WPM:%.2lf     Levelscore:%d\n",i,racer->player_name,racer->high_score,racer->level,((racer->word_counter * 1.0 * 60)/(racer->Play_time)),((racer->level)-(racer->begin_level))*10);
    while(k > 0)
    {
        i++;
        k = fread(racer, sizeof(struct player), 1, fp);
        if(k == 0 || k < 0)
            break;
        printf("%d.%s     Highscore:%.2lf     Level:%d     WPM:%.2lf     Levelscore:%d\n",i,racer->player_name,racer->high_score,racer->level,((racer->word_counter * 1.0 * 60)/(racer->Play_time)),((racer->level)-(racer->begin_level))*10);
    }
    free(racer);
    fclose(fp);
    return;
}




//void show_Top_10 (void)
//{
//    struct player racer;
//    FILE *fp;
//    fp=fopen("Top10.bin", "rb");
//    int i = 1;
//    int k = fread(&racer, sizeof(struct player), 1, fp);
//    if(k == 0 || k < 0)
//    {
//        printf("No players played yet!\n");
//        return;
//    }
//    printf("%d.%s     %.2lf     %d     %.2lf     Levelscore:%d\n",i,racer.player_name,racer.high_score,racer.level,((racer.word_counter * 1.0 * 60)/(racer.Play_time)),((racer.level)-(racer.begin_level))*10);
//    while(k > 0)
//    {
//        i++;
//        k = fread(&racer, sizeof(struct player), 1, fp);
//        if(k == 0 || k < 0)
//            break;
//        printf("%d.%s     %.2lf     %d     %.2lf     Levelscore:%d\n",i,racer.player_name,racer.high_score,racer.level,((racer.word_counter * 1.0 * 60)/(racer.Play_time)),((racer.level)-(racer.begin_level))*10);
//    }
//    fclose(fp);
//    return;
//}





void set_previous_data (char name[40])
{
    FILE *fp;
    struct player tmp;
    fp=fopen("Players.bin", "rb");
    while(!feof(fp))
    {
        fread(&tmp, sizeof(struct player), 1, fp);
        if(strcmp(tmp.player_name,name) == 0)
        {
            level = tmp.level;
            high_score = tmp.high_score;
            my_time = tmp.Play_time;
            word_counter = tmp.word_counter;
            return;
        }
    }
}

void delete_previous_data (char name[40])
{
    FILE *fp;
    struct player *tmp = (struct player *)malloc(sizeof(struct player));
    fp = fopen("Players.bin","r+b");
    while(!feof(fp))
    {
        fread(tmp, sizeof(struct player), 1, fp);
        if(strcmp(tmp->player_name,name) == 0)
        {
            tmp->high_score = 0;
            tmp->level = 0;
            tmp->Play_time = 0;
            tmp->word_counter = 0;
            tmp->begin_level = 0;
            fseek(fp, -1*sizeof(struct player), SEEK_CUR);
            fwrite(tmp, sizeof(struct player), 1, fp);
            free(tmp);
            fclose(fp);
            return;
        }
    }
}




void save_player (struct player *racer)
{
    racer->high_score = high_score;
    racer->level = level;
    racer->Play_time = my_time;
    racer->word_counter = word_counter;
    FILE *fpout;
    fpout=fopen("Players.bin", "r+b");
    struct player * tmp = (struct player *) malloc (sizeof(struct player));
    while(!feof(fpout))
    {
        fread(tmp, sizeof(struct player), 1, fpout);
        if(strcmp(tmp->player_name,racer->player_name) == 0)
        {
            fseek(fpout, (-1)*sizeof(struct player), SEEK_CUR);
            fwrite(racer, 1*sizeof(struct player), 1, fpout);
            fclose(fpout);
            return;
        }
    }
    fwrite(racer, sizeof(struct player), 1, fpout);
    fclose(fpout);
    return;
}




int find_name (char name[40])
{
    FILE *fp;
    struct player * racer = (struct player *)malloc(sizeof(struct player));
    fp = fopen("Players.bin", "rb");
    int k = fread(racer, sizeof(struct player), 1, fp);
    if(k == 0 || k < 0)
    {
        printf("Not find player by this name!\n");
        return 0;
    }
    if(strcmp(name,racer->player_name) == 0)
    {
        fclose(fp);
        return 1;
    }
    while(k > 0)
    {
        k = fread(racer, sizeof(struct player), 1, fp);
        if(k <= 0)
            break;
        if(strcmp(name,racer->player_name) == 0)
        {
            fclose(fp);
            return 1;
        }
    }
    printf("Not find player by this name!\n");
    fclose(fp);
    return 0;
}








void show_menu (void)
{
    system("cls");
    COORD word;
    HANDLE position = GetStdHandle(STD_OUTPUT_HANDLE);
    word.X = 50;
    word.Y = 0;
    SetConsoleCursorPosition(position,word);
    printf("WELCOME!Keep calm and Type ;D\n");
    word.Y++;
    SetConsoleCursorPosition(position,word);
    printf("=================================\n");
    word.Y++;
    SetConsoleCursorPosition(position,word);
    printf("=================================\n");
    word.Y += 2;
    SetConsoleCursorPosition(position,word);
    printf("1.Entering the game");
    word.Y += 2;
    SetConsoleCursorPosition(position,word);
    printf("2.show the players");
    word.Y += 2;
    SetConsoleCursorPosition(position,word);
    printf("3.show Top 10");
    word.Y += 2;
    SetConsoleCursorPosition(position,word);
    printf("4.Exit");
    return ;
}






void Enter_game (void)
{
    system("cls");
    printf("Enter your name Please :\n");
    struct player * typer = (struct player *) malloc (sizeof(struct player));
    typer->next = NULL;
    scanf(" %s", typer->player_name);
    int what_do = find_name(typer->player_name);
    if(what_do == 1)
    {
        printf("You had a previous saved level!Do you wish to continue previous game?(Y/N)\n");
        char ch;
        ch = getch();
        while(ch != 'N' && ch != 'Y')
            ch = getch();
        if(ch == 'Y')
        {
            set_previous_data(typer->player_name);
            if(level == 0)
            {
                printf("You removed before informations!Please Enter again and enter a level to play! ;D\n");
                exit(0);
            }
            while(level < find_max_level())
            {
                level_high_score = 0;
                level_enter_time = 0;
                level_word_counter = 0;
                struct wordlist *my_level = create_level_link_list(level, typer);
                int level_word_number = word_number(my_level);
                level_words_progress(my_level, level_word_number, typer);
                level++;
                printf("Do you wish to continue?(Y/N)\n");
                char end;
                end = getch();
                while(end != 'N' && end != 'Y')
                    end = getch();
                if(end == 'N')
                {
                    printf("Do you want to save current level and score?(Y/N)\n");
                    end = getch();
                    if(end == 'N')
                    {
                        exit(0);
                    }
                    if(end == 'Y')
                    {
                        save_player(typer);
                        exit(0);
                    }
                }
            }
            printf("Do you want to save current level and score?(Y/N)\n");
            char saving;
            saving = getch();
            while(saving != 'N' && saving != 'Y')
                saving = getch();
            if(saving == 'Y')
            {
                save_player(typer);
                exit(0);
            }
            if(saving == 'N')
            {
                exit(0);
            }
        }
        if(ch == 'N')
        {
            delete_previous_data(typer->player_name);
            what_do = 0;
        }
    }
    if(what_do == 0)
    {
        printf("Enter Level you wanna to play Please :\n");
        scanf("%d", &level);
        while(level > find_max_level() || level < 1)
        {
            printf("invalid level!Please enter a level between 1 and %d :\n", find_max_level());
            scanf("%d", &level);
        }
        typer->begin_level = level;
        while(level < find_max_level())
        {
            level_high_score = 0;
            level_word_counter = 0;
            level_enter_time = 0;
            struct wordlist * my_level = create_level_link_list(level, typer);
            int level_word_number = word_number(my_level);
            level_words_progress(my_level, level_word_number, typer);
            level++;
            printf("Do you wish to continue?(Y/N)\n");
            char end;
            end = getch();
            while(end != 'N' && end != 'Y')
                end = getch();
            if(end == 'N')
            {
                printf("Do you want to save current level and score?(Y/N)\n");
                end = getch();
                if(end == 'N')
                {
                    exit(0);
                }
                if(end == 'Y')
                {
                    save_player(typer);
                    exit(0);
                }
            }
        }
        printf("Do you want to save current level and score?(Y/N)\n");
        char saving;
        saving = getch();
        while(saving != 'N' && saving != 'Y')
            saving = getch();
        if(saving == 'Y')
        {
            save_player(typer);
            exit(0);
        }
        if(saving == 'N')
        {
            exit(0);
        }
    }
}


void level_words_progress (struct wordlist * my_level, int level_number, struct player * racer)
{
    struct wordlist * current;
    char my_word[40];
    while(level_number)
    {
        current = my_level;
        int random_choose = (rand() % level_number) + 1;
        int s_rand = random_choose;
        system("cls");
        if(random_choose == 1)
        {
            strcpy(my_word, current->word);
            word_doing(my_word, racer);
            delete_front(&my_level);
        }
        else if(random_choose == level_number)
        {
            for(; current->next != NULL; current = current->next);
            strcpy(my_word, current->word);
            word_doing(my_word, racer);
            delete_end(my_level);
        }
        else if(random_choose > 1 && random_choose < level_number)
        {
            for(; random_choose > 1; current = current->next, random_choose--);
            strcpy(my_word, current->word);
            word_doing(my_word, racer);
            delete_next(my_level, s_rand-2);
        }
        level_number--;
    }
    system("cls");
    printf("Your score is : %lf\n", high_score);
    racer->high_score = high_score;
    return;
}


void maximize (void)
{
    HWND hWnd;
    SetConsoleTitle("test");
    hWnd = FindWindow(NULL, "test");
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSBSize = GetLargestConsoleWindowSize(hOut);
    SMALL_RECT DisplayArea = {0, 0, 0, 0};
    SetConsoleScreenBufferSize(hOut, NewSBSize);
    DisplayArea.Right = NewSBSize.X - 1;
    DisplayArea.Bottom = NewSBSize.Y - 1;
    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
    ShowWindow(hWnd, SW_MAXIMIZE);
}


void word_doing (char my_word[40], struct player * typer)
{
    double entering_time = 0;
    HANDLE my_console;
    my_console = GetStdHandle(STD_OUTPUT_HANDLE);
    int len = strlen(my_word);
    int spaces = (20 - (len)/2);
    int wrong_enter = 0;
    int k = 0;
    int continue_s = (40 - (21 + (len/2)));
    if(len % 2 == 0)
    {
        continue_s += 1;
    }
    int colors = k;
    int i,j,l;
    char c;
    clock_t start = clock();
    clock_t tmp;
    clock_t finish;
    for(i = 0; i < 48; )
    {
        system("cls");
        system("color 70");
        j = i;
        SetConsoleTextAttribute(my_console,17);
        for(l = 0; l < 42; l++)
        {
            printf(" ");
        }
        printf("\n");
        while(j)
        {
            SetConsoleTextAttribute(my_console,17);
            printf(" ");
            SetConsoleTextAttribute(my_console,57);
            for(l = 0; l < 40; l++)
            {
                printf(" ");
            }
            SetConsoleTextAttribute(my_console,17);
            printf(" ");
            printf("\n");
            j--;
        }
        SetConsoleTextAttribute(my_console,17);
        printf(" ");
        SetConsoleTextAttribute(my_console,57);
        while(spaces)
        {
            printf(" ");
            spaces--;
        }
        spaces = 20 - (len)/2;
        SetConsoleTextAttribute(my_console,58);
        for(j = 0; j < k; j++)
        {
            printf("%c", my_word[j]);
        }
        SetConsoleTextAttribute(my_console,60);
        for(j = k; j < strlen(my_word); j++)
        {
            printf("%c", my_word[j]);
        }
        SetConsoleTextAttribute(my_console,57);
        while(continue_s)
        {
            printf(" ");
            continue_s--;
        }
        SetConsoleTextAttribute(my_console,17);
        printf(" ");
        printf("\n");
        continue_s=40 - (21 + (len)/2);
        if(len % 2 == 0)
        {
            continue_s += 1;
        }
        for(l = i; l < 47; l++)
        {
            SetConsoleTextAttribute(my_console,17);
            printf(" ");
            SetConsoleTextAttribute(my_console,57);
            for(j = 0; j < 40; j++)
            {
                printf(" ");
            }
            SetConsoleTextAttribute(my_console,17);
            printf(" ");
            printf("\n");
        }
        for(l = 0; l < 42; l++)
            printf(" ");
        if(kbhit())
        {
            c = getch();
            if(c == my_word[k])
            {
                my_word[k] -= 32;
                k++;
                continue;
            }
            else
            {
                wrong_enter++;
            }
            if(c == 'P')
            {
                tmp = clock();
                entering_time += ((tmp-start) *1.0 / CLOCKS_PER_SEC);
                my_time += entering_time;
                level_enter_time += entering_time;
                while(c != 'R' && c != 'Q')
                {
                    SetConsoleTextAttribute(my_console,112);
                    printf("\npress R key to continue typing or press Q key to exit game!\n");
                    c = getch();
                }
                if(c == 'R')
                    start = clock();
            }
            if(c=='Q')
            {
                SetConsoleTextAttribute(my_console,112);
                system("cls");
                finish = clock();
                entering_time += ((finish-start) *1.0 / CLOCKS_PER_SEC);
                my_time += entering_time;
                level_enter_time += entering_time;
                high_score -= level_high_score;
                word_counter -= level_word_counter;
                my_time -= level_enter_time;
                printf("Do you want to save current level and score?(Y/N)");
                c = getch();
                if(c == 'N')
                {
                    exit(0);
                }
                if(c == 'Y')
                {
                    save_player(typer);
                    exit(0);
                }
            }
        }
        if(k == strlen(my_word))
        {
            SetConsoleTextAttribute(my_console,112);
            finish = clock();
            entering_time += ((finish-start) * 1.0 / CLOCKS_PER_SEC);
            high_score+=((strlen(my_word) * 3 - wrong_enter) / entering_time);
            my_time += entering_time;
            level_enter_time += entering_time;
            word_counter++;
            level_word_counter++;
            return ;
        }
        i++;
        Sleep(speed);
    }
//    SetConsoleTextAttribute(my_console,112);
//    finish=clock();
//    entering_time+=((finish-start)*1.0/CLOCKS_PER_SEC);
//    my_time+=entering_time;
//    level_enter_time=entering_time;
    printf("You Lose!Don't worry come back and have a better record! ;D\n");
    printf("Do you want to save information before reaching this level?(Y/N)\n");
    char ch;
    ch = getch();
    while(ch != 'N' && ch != 'Y')
        ch = getch();
    if(ch == 'Y')
    {
        high_score -= level_high_score;
        word_counter -= level_word_counter;
        my_time -= level_enter_time;
        save_player(typer);
        exit(0);
    }
    if(ch == 'N')
    {
        exit(0);
    }
}








int main ()
{
    time_t t = time(NULL);
    srand(t);
    system("color 70");
    char returning;
    maximize();
    welcome();
    show_menu();
//    struct player * player_link_list = create_player_list();
    int choice_of_menu = selection();
    while(1)
    {
        switch (choice_of_menu)
        {
        case 1:
            Enter_game();
            break;
        case 2:
            show_players();
            printf("\nPress any key to return to main menu!\n");
            returning = getch();
            break;
        case 3:
//            show_Top_10(player_link_list);
            printf("\nPress any key to return to main menu!\n");
            returning = getch();
            break;
        case 4:
            printf("Thank you for Playing! ;D\n");
            return 0;
            break;
        }
        show_menu();
        choice_of_menu = selection();
    }
    return 0;

}

