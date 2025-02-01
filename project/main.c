#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <locale.h>
#include <signal.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#define FRAME_DELAY 16666.66666666666666666666666666666666666
int score = 0 , live = 3 , emtiaz = 0;
int menu();
int menu2();
int sign_up();
int sign_in();
int ch_information();
int foget_pas();
int start_game1(char username[31]);
int render1(char screen[15][65]);
int end_game1(int lose , char username[31]);
int start_game2(char username[31]);
int history(char username[31]);
int render2(char screen[29][62]);
int end_game2(int lose ,char username[31]);
int foget_pas()
{
    char line[151] , username[31];
    printf("\033[33mPlease enter your user name:\033[0m ");
    printf("\033[32m");
    scanf("%s" , username);
    printf("\033[0m");
    FILE *file = fopen("informaition.txt" , "r");
    FILE *file2 = fopen("ch_information.txt" , "w");
    int flag = 1 , flag2 = 1;
    while(fgets(line , sizeof(line) , file))
    {
        if (line[0] == ' ')
            break;
        flag = 1; 
        int i;
        for (i = 0; i < strlen(username); ++i)
        {
            if (line[i] != username[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1 && username[i] == '\0' && line[i] == ' ')
        {
            char email[61];
            printf("\033[33mPlease enter your email:\033[0m ");
            printf("\033[32m");
            scanf("%s" , email); 
            printf("\033[32m");
            i++;
            while(line[i] != ' ')
            {
                i++;
            }
            i++;
            int j = 0 , flag1 = 1;
            for(j = 0 ; j < strlen(email) ; ++j)
            {
                if (line[i] != email[j])
                {
                    printf("hi");
                    flag1 = 0;
                    break;
                }
                i++;
            }
            if (flag1 == 1 && line[i] == '\n')
            {
                flag2 = 0;
                int m = 0;
                fprintf(file2 , "%s " , username);
                char password[21];
                printf("\033[33mPlease enter your new password:\033[0m ");
                printf("\033[32m");
                scanf("%s" , password);
                printf("\033[0m");
                if (strlen(password) < 8)
                {
                    system("clear");
                    printf("\033[33mYour password is too short.\033[0m\n");
                    return menu();
                }
                fprintf(file2 , "%s " , password);
                fprintf(file2 , "%s\n" , email);
            }
            else
            {
                system("clear");
                printf("\033[33mYour email is not correct.\033[0m\n");
                return menu();
            }
        }
        else
            fprintf(file2 , "%s" , line);
    }
    if (flag2 == 1)
    {
        system("clear");
        printf("\033[33mThis user name does not exist\033[0m\n");
        return menu();
    }
    fclose(file);
    fclose(file2);
    file = fopen("informaition.txt" , "w");
    file2 = fopen("ch_information.txt" , "r");
    char ch;
    while ((ch = fgetc(file2)) != EOF) 
    {
        fputc(ch, file);
    }
    fclose(file);
    fclose(file2);
    system("clear");
    printf("\033[33mYour password updated.\033[0m\n");
    return menu();
}
int ch_information(char username[31])
{
    char line[151] , new_username[31];
    int your_input;
    FILE *file1 = fopen("informaition.txt" , "r");
    FILE *file2 = fopen("ch_information.txt" , "w");
    while(fgets(line , sizeof(line) , file1))
    {
        if(line[0] == ' ')
            break;    
        int flag = 0 , i;
        for(i = 0 ; line[i] != ' ' ; ++i)
        {
            if (line[i] != username[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && i == strlen(username))
        {
            printf("\033[31mPlease choose one of this item:\033[0m\n");
            printf("\033[33m1. user name\n2. password\n3. email\n===============\nEnter your choice:\033[0m ");
            printf("\033[32m");
            while(scanf("%i" , &your_input))
            {
                printf("\033[0m");
                if (your_input == 1)
                {
                    int j = 0;
                    while(line[j] != ' ')
                    {
                        j++;
                    }
                    j++;
                    printf("\033[33mPlease enter your new user name:\033[0m ");
                    printf("\033[32m");
                    scanf("%s" , new_username);
                    printf("\033[0m");
                    char line3[151];
                    FILE *file3 = fopen("informaition.txt" , "r");
                    while(fgets(line3 , sizeof(line3) , file3))
                    {
                        if (line3[0] == ' ')
                            break;
                        int i = 0 , flag = 1;
                        while(line3[i] != ' ')
                        {
                            if (line3[i] != new_username[i])
                            {
                                flag = 0;
                                break;
                            }
                            i++;
                        }
                        if (flag == 1 && strlen(new_username) == i)
                        {
                            system("clear");
                            printf("\033[35mYour username already exists. Please choose another username\n\033[0m");
                            fclose(file3);  
                            return menu2(username);
                        }
                    }
                    fprintf(file2 , "%s " , new_username);
                    while(line[j] != '\0')
                    {
                        fprintf(file2 , "%c" , line[j]);
                        j++;
                    }
                    system("clear");
                    printf("\033[33mYour user name updated.\033[0m\n");
                    break;
                }
                else if (your_input == 2)
                {
                    int i = 0;
                    while(line[i] != ' ')
                    {
                        fprintf(file2 , "%c" , line[i]);
                        i++;
                    }
                    ++i;
                    while(line[i] != ' ')
                    {
                        ++i;
                    }
                    ++i;
                    fprintf(file2 , " ");
                    char new_password[21] , new_password2[21];
                    printf("\033[33mPlease enter your new password:\033[0m ");
                    printf("\033[32m");
                    scanf("%s" , new_password);
                    printf("\033[0m");
                    if (strlen(new_password) < 8)
                    {
                        system("clear");
                        printf("\033[33mYour password is too short.\033[0m\n");
                        return menu2(username);
                    }
                    printf("\033[33mPlease enter your new password again for maching:\033[0m ");
                    printf("\033[32m");
                    scanf("%s" , new_password2);
                    printf("\033[0m");
                    if (strlen(new_password2) < 8)
                    {
                        system("clear");
                        printf("\033[33mYour password is too short.\033[0m\n");
                        return menu2(username);
                    }
                    if (strlen(new_password2) != strlen(new_password))
                    {
                        system("clear");
                        printf("\033[33mYour password is not mach.\033[0m\n");
                        return menu2(username);
                    }
                    for (int i = 0; i < strlen(new_password2); ++i)
                    {
                        if (new_password2[i] != new_password[i])
                        {
                            system("clear");
                            printf("\033[33mYour password is not mach.\033[0m\n");
                            return menu2(username);
                        }
                    }
                    fprintf(file2 , "%s " , new_password);
                    while(line[i] != '\0')
                    {
                        fprintf(file2 , "%c" , line[i]);
                        i++;
                    }
                    system("clear");
                    printf("\033[33mYour user password updated.\033[0m\n");
                    break;
                }
                else if(your_input == 3)
                {
                    int i = 0 ;
                    while(line[i] != ' ')
                    {
                        fprintf(file2 , "%c" , line[i]);
                        i++;
                    }
                    ++i;
                    fprintf(file2 , " ");
                    while(line[i] != ' ')
                    {
                        fprintf(file2 , "%c" , line[i]);
                        i++;
                    }
                    fprintf(file2 , " ");
                    char new_email[61];
                    printf("\033[33mPlease enter your new email:\033[0m ");
                    printf("\033[32m");
                    scanf("%s" , new_email);
                    printf("\033[0m");
                    fprintf(file2 , "%s\n" , new_email);
                    system("clear");
                    printf("\033[33mYour user email updated.\033[0m\n");
                    break;
                }
                else
                {
                    printf("Invalid choice! Please try again.\n");
                    printf("\033[32m");
                }
            }
        }
        else
        {
            fprintf(file2 , "%s" , line);
        }
    }
    fclose(file2);
    fclose(file1);
    file1 = fopen("informaition.txt" , "w");
    file2 = fopen("ch_information.txt" , "r");
    char ch;
    while ((ch = fgetc(file2)) != EOF) 
    {
        fputc(ch, file1);
    }
    fclose(file1);
    fclose(file2);
    if(your_input == 1)
        return menu2(new_username);
    menu2(username);
}
int menu2(char username[31])
{
    printf("\033[31m\033[1m===================\033[0m\n");
    printf("\033[31m\033[1m      Welcome      \033[0m\n");
    printf("\033[31m\033[1m===================\033[0m\n");
    printf("\033[35mchoose one :\033[0m\n");
    printf("\033[33m1. change informaition\033[0m\n");
    printf("\033[33m2. history\033[0m\n");
    printf("\033[33m3. start\033[33m\n");
    printf("\033[36mEnter your choice:\033[0m ");
    int a;
    printf("\033[32m");
    scanf("%i" , &a);
    printf("\033[0m");
    if (a == 1)
    {
        system("clear");
        return ch_information(username);
    }
    else if (a == 2)
    {
        system("clear");
        return history(username);
    }
    else if (a == 3)
    {
        system("clear");
        return start_game1(username);
    }
    else
    {
        system("clear");
        printf("\033[33myour entery is not correct\033[0m\n");
        return menu2(username);
    }
}
int history(char username[31])
{
    FILE *file1 = fopen("informaition.txt" , "r");
    char line[151];
    while(fgets(line , sizeof(line) , file1))
    {
        if(line[0] == ' ')
            break;    
        int flag = 0 , i;
        for(i = 0 ; line[i] != ' ' && i < strlen(username); ++i)
        {
            if (line[i] != username[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && i == strlen(username))
        {
            while (line[i] == ' ') i++;
            while (line[i] != ' ' && line[i] != '\0') i++;
            while (line[i] == ' ') i++;
            while (line[i] != ' ' && line[i] != '\0') i++;
            while (line[i] == ' ') i++;
            int j = 1;
            if(line[i] == '\n'  || line[i] == '\0')
            {
                printf("\033[34mits your first time , first try game\033[0m\n");
                fclose(file1);
                return menu2(username);
            }
            while(line[i] != '\0' && line[i] != '\n')
            {
                printf("\033[35mgame%i\033[0m" , j);
                printf("\033[33m");
                if (line[i] == '0')  printf("    lose" );
                else printf("    win" );
                ++i;
                while (line[i] == ' ') i++;
                int score = 0 , score2 = 0;
                while (line[i] >= '0' && line[i] <= '9')
                {
                    score = score * 10 + (line[i] - '0');
                    ++i;
                }
                while (line[i] == ' ') i++;
                printf("    %d\n", score);
                while (line[i] >= '0' && line[i] <= '9')
                {
                    score2 = score2 * 10 + (line[i] - '0');
                    ++i;
                }
                printf("    %d\n", score2);
                ++j;
                while (line[i] == ' ') i++;
                printf("\033[0m");
            }
            if (line[i] == '\n' || line[i] == '\0')
            {
                fclose(file1);
                return menu2(username);
            }
        }
    }
    fclose(file1);
    return 0;
}
int sign_in()
{
    printf("\033[34m");
    printf(" W   W  H   H   OOO     AAAAA  RRRR   EEEEE   Y   Y  OOO  U   U\n");
    printf(" W   W  H   H  O   O   A     A R   R  E        Y Y  O   O U   U\n");
    printf(" W W W  HHHHH  O   O   AAAAAAA RRRRR  EEEE      Y   O   O U   U\n");
    printf(" WW WW  H   H  O   O   A     A R  R   E         Y   O   O U   U\n");
    printf(" W   W  H   H   OOO    A     A R   R  EEEEE     Y    OOO   UUU\n");
    printf("\033[0m");
    char username[31] , password[21] , line[151];
    printf("\033[33mEnter your user name :(for recovery your password enter one)\033[0m ");
    printf("\033[32m");
    scanf("%30s" , username);
    printf("\033[0m");
    if (strlen(username) == 1 && username[0] - '0' == 1)
    {
        system("clear");
        return foget_pas();
    }
    printf("\033[33mPlease enter your password :\033[0m ");
    struct termios oldt, newt;
    int i = 0;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON); 
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    while ((ch = getchar()) != '\n' && ch != EOF) 
    {
        if (ch == 127) 
        {  
            if (i > 0) 
            {
                i--;
                printf("\b \b");  
            }
        } 
        else 
        {
            password[i++] = ch;
            printf("\033[32m");
            putchar('*');  
            printf("\033[0m");
        }
        fflush(stdout);  
    }
    password[i] = '\0';
    putchar('\n');
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    FILE *file = fopen("informaition.txt" , "r");
    int username_found = 0;
    while(fgets(line, sizeof(line), file))
    {
        int i = 0 ;
        while(line[i] != ' ' && line[i] != '\0')
        {
            if (line[i] != username[i])
                break;
            i++;
        }
        if (line[i] == ' ' && username[i] == '\0')
        {
            username_found = 1;
            int flag2 = 0 , j = i + 1;
            while(line[j] != ' ' && line[j] != '\0')
            {
                if (line[j] != password[j - i - 1])
                {
                    flag2 = 1;
                    break;
                }
                j++;
            }
            if(flag2 == 0 && strlen(password) == j - i - 1)
            {
                system("clear");
                fclose(file);
                return menu2(username);
            }
            else
            {
                system("clear");
                printf("\033[33mYour password is not correct\033[0m\n");
                fclose(file);
                return menu();
            }
        }
    }
    fclose(file);
    if (!username_found)
    {
        system("clear");
        printf("\033[33mThis user name does not exist\033[0m\n");  
    }
    return menu();
}
int sign_up()
{
    FILE *file = fopen("informaition.txt" , "r");
    if (file == NULL)
        file = fopen("informaition.txt" , "w");
    char username[31] , password[21] , password2[21] , email[61] , line[151];
    printf("\033[33mPlease enter your user name :(less than 30 charackter)\033[0m ");
    printf("\033[32m");
    scanf("%30s" , username);
    printf("\033[0m");
    file = fopen("informaition.txt" , "r");
    while (fgets(line, sizeof(line), file))
    {
        if (line[0] == ' ')
            break;
        int i = 0 , flag = 0;
        while(line[i] != ' ')
        {
            if (line[i] != username[i])
            {
                flag = 1;
                break;
            }
            ++i;
        }
        if (flag == 0 && (line[i] == ' ' || line[i] == '\0') && i == strlen(username)) 
        {
            system("clear");
            printf("\033[35mYour username already exists. Please choose another username\n\033[0m");
            fclose(file);  
            return sign_up();  
        }
    }
    printf("\033[33mPlease enter your password :(less than 20 charackter and more than 8 charackter)\033[0m ");
    printf("\033[32m");
    scanf("%20s" , password);
    printf("\033[0m");
    if (strlen(password) < 8)
    {
        system("clear");
        printf("\033[35myour password is too short please try again\033[0m\n");
        return sign_up();
    }
    printf("\033[33mPlease enter your password again for maching\033[0m ");
    printf("\033[32m");
    scanf("%s" , password2); 
    printf("\033[0m");
    if (strlen(password) != strlen(password2))
    {
        system("clear");
        printf("\033[35myour password is not mach please try again\033[0m\n");
        return sign_up();
    }
    for (int j = 0; j < strlen(password); ++j)
    {
        if (password2[j] != password[j] )
        {
            system("clear");
            printf("\033[35myour password is not mach please try again\033[0m\n");
            return sign_up();
        }
    }
    printf("\033[33mPlease enter your email :\033[0m ");
    printf("\033[32m");
    scanf("%s" , email);
    printf("\033[0m");
    file = fopen("informaition.txt" , "a");
    fprintf(file,"%s " , username);
    fprintf(file,"%s " , password);
    fprintf(file,"%s\n" , email);
    fclose(file);
    system("clear");
    printf("\033[32myour sign up is completely\033[0m\n");
    return menu();
}   
int menu()
{
    system("./menu.sh");
    printf("\033[31m\033[1m==== Menu ====\033[0m\n");
    printf("\033[33m1. sign up\033[0m\n");
    printf("\033[33m2. sign in\033[0m\n");
    printf("\033[33m3. Exit\033[0m\n");
    printf("\033[33m===============\033[0m\n");
    printf("\033[36mEnter your choice:\033[0m ");
    int fin_menu_number;
    printf("\033[32m");
    scanf("%i" , &fin_menu_number);
    printf("\033[0m");
    if (fin_menu_number  == 1)
    {
        system("clear");
        return sign_up();
    }
    else if(fin_menu_number == 2)
    {
        system("clear");
        return sign_in();
    }
    else if (fin_menu_number == 3)
    {
        FILE *fp = popen("pgrep mpg123", "r");
        char pid[16];
        if (fgets(pid, sizeof(pid), fp) != NULL) 
        {
            pid[strcspn(pid, "\n")] = '\0';
            char command[64];
            snprintf(command, sizeof(command), "kill %s", pid);
            system(command);
        }
        pclose(fp);
        system("clear");
        return 0;
    }
    else
    {
        system("clear");
        printf("your entery is not correct\n");
        return menu();
    }
    return 0;
}
int main() 
{
    system("clear");
    printf("\033[34m");
    printf(" W   W  EEEEE  L       CCCC  OOO  M   M  EEEEE\n");
    printf(" W   W  E      L      C     O   O MM MM  E    \n");
    printf(" W W W  EEEE   L      C     O   O M M M  EEEE \n");
    printf(" WW WW  E      L      C     O   O M   M  E    \n");
    printf(" W   W  EEEEE  LLLLL   CCCC  OOO  M   M  EEEEE\n");
    printf("\033[0m");
    system("nohup mpg123 -q sound.mp3 > /dev/null 2>&1 &");
    menu();
    return 0;
}
int render1(char screen[16][65])
{
    for (int y = 0; y < 15; y++) 
    {
        for (int x = 0; x < 64; x++) 
        {
            if (screen[y][x] == '#') printf("🧱");
            else if(screen[y][x] == '=') printf("😎");
            else if (screen[y][x] == ';') printf("🟨");
            else if (screen[y][x] == '^') printf("🟧");
            else if (screen[y][x] == '*') printf("🪙");
            else if (y == 4 && x == 19)printf("🚩");
            else if ((y == 1 && x == 24) || (y == 2 && x == 24) || (y == 12 && x == 60) || (y == 11 && x == 60))
            {
                printf("\033[32m█\033[0m");
                printf(" ");
            }
            else if ((y == 3 && x == 22) || (y == 10 && x == 58))
            {
                printf(" ");
                printf("\033[32m█\033[0m");
            }
            else if((y == 12 && x == 59) || (y == 11 && x == 59) || (y == 10 && x == 60) || (y == 10 && x == 59) || (y == 1 && x == 23) || (y == 2 && x == 23) || (y == 3 && x == 23) || (y == 3 && x == 24))
            {
                printf("\033[32m█\033[0m");
                printf("\033[32m█\033[0m");
            }
            else if (screen[y][x] == 'w') printf("💀");
            else if (screen[y][x] == '(')
            {
                if ((y == 12 && x == 34)|| (y == 9 && x == 38) || (y == 4 && x == 44) || (y == 7 && x == 42) || (y == 5 && x == 46))
                {
                    printf("\033[37m█\033[0m");
                    printf(" ");
                }
                else if((y == 11 && x == 32) || (y == 12 && x == 36) || (y == 11 && x == 36) || (y == 10 && x == 36) || (y == 7 && x == 39) || (y == 12 && x == 40) || (y == 11 && x == 40) || (y == 10 && x == 40) || (y == 9 && x == 40) || (y == 8 && x == 40) || (y == 12 && x == 44) || (y == 11 && x == 44) || (y == 10 && x == 44) || (y == 9 && x == 44) || (y == 8 && x == 44) || (y == 7 && x == 44) || (y == 6 && x == 44))
                {
                    printf(" ");
                    printf("\033[37m█\033[0m");
                }
                else
                {
                    printf("\033[37m█\033[0m");
                    printf("\033[37m█\033[0m");
                }
            }
            else if (screen[y][x] == ')') printf("🦖");
            else if(screen[y][x] == '_') printf("🌱");
            else if (x == 1 && y == 14) 
            {
                printf("                                 \033[32myour score is :\033[0m \033[35m%i\033[0m           \033[32myour lives :\033[0m " , score);
                int i = 0; 
                while(i != live)
                {
                    printf("❤️ ");
                    i +=1;
                }
            }
            else if (y != 14)printf("%c%c" , screen[y][x] , screen[y][x]);

        }
        putchar('\n');  
    }
    fflush(stdout);
}
int start_game1(char username[31])
{
    FILE *fp = popen("pgrep mpg123", "r");
    char pid[16];
    if (fgets(pid, sizeof(pid), fp) != NULL) 
    {
        pid[strcspn(pid, "\n")] = '\0';
        char command[64];
        snprintf(command, sizeof(command), "kill %s", pid);
        system(command);
    }
    pclose(fp);
    system("nohup mpg123 -q mario.mp3 > /dev/null 2>&1 &");
    system("clear");
    system("./start1.sh");
    setlocale(LC_ALL, "en_US.UTF-8");
    struct termios oldt, newt , t;
    char key;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char empty = ' ';
    char wall_helper = '#';
    char star = '*';
    char simple_enemy = 'w';
    char white = '(';
    char enemy_bad = ')';
    char mario = '=';
    char yellow = ';';
    char giah = '_';
    char orange = '^';
    char screen[16][65];
    for (int y = 0; y < 15; y++) 
    {
        for (int x = 0; x < 64; x++) 
        {
            screen[y][x] = empty;  
        }
    }
    for (int i = 0; i < 14; ++i)
    {
        screen[i][0] = wall_helper;
        screen[i][63] = wall_helper;
    }
    for (int i = 0; i < 64; ++i)
    {
        screen[0][i] = wall_helper;
        screen[13][i] = wall_helper;
    }
    for (int i = 0; i < 3; ++i)
    {
        screen[8][i + 3] = wall_helper;
        screen[10][i + 11] = wall_helper;
        screen[5][i + 17] = wall_helper;
        screen[6][i + 22] = wall_helper; 
        screen[5][i + 27] = wall_helper;
    }
    for (int i = 0; i < 2; ++i)
    {
        screen[9][i + 6] = wall_helper;
        screen[8][i + 6] = star;
        screen[12][i + 17] = star;
        screen[4][i + 27] = star;
        screen[12][33 + i] = white;
        screen[11][32 + i] = white;
        screen[12][36 + i] = white;
        screen[11][36 + i] = white;
        screen[10][36 + i] = white;
        screen[9][36 + i] = white;
        screen[12][40 + i] = white;
        screen[11][40 + i] = white;
        screen[10][40 + i] = white;
        screen[9][40 + i] = white;
        screen[8][40 + i] = white;
        screen[7][41 + i] = white;
        screen[12][44 + i] = white;
        screen[11][44 + i] = white;
        screen[10][44 + i] = white;
        screen[9][44 + i] = white;
        screen[8][44 + i] = white;
        screen[7][44 + i] = white;
        screen[6][44 + i] = white;
        screen[5][44 + i] = white;
    }
    screen[9][38] = white;
    screen[7][40] = white;
    screen[5][46] = white;
    screen[9][9] = wall_helper;
    screen[12][25] = simple_enemy;
    screen[12][35] = enemy_bad;
    screen[12][39] = enemy_bad;
    screen[12][43] = enemy_bad;
    screen[12][46] = enemy_bad;
    screen[12][47] = enemy_bad;
    screen[12][48] = enemy_bad;
    screen[12][49] = wall_helper;
    screen[11][49] = wall_helper;
    screen[10][49] = wall_helper;
    screen[9][49] = wall_helper;
    screen[9][52] = wall_helper;
    screen[10][52] = wall_helper;
    screen[11][52] = wall_helper;
    screen[12][56] = simple_enemy;
    screen[12][57] = simple_enemy;
    screen[11][34] = white;
    screen[9][8] = yellow;
    screen[8][36] = giah;
    screen[4][44] = giah;
    screen[9][51] = orange;
    screen[9][50] = orange;
    printf("\033[?25l");  
    int mario_x = 2, mario_y = 12 ,is_jump = 0 , flag = 1 , rast = 0 , chap = 0 , bala =  0 , flag2 = 0 , x0 , y0 , ground = 13;
    int star1 = 1 , star2 = 1 , star3 = 1 , star4 = 1 , star5 = 1 , star6 = 1 , star_box = 1 , simple_enemyx = 25 , rast_enemy1 = 1 , simple_enemy1 = 1; 
    int giah1 = 0 , simple_enemy2 = 1 , simple_enemyx2 = 56 , rast_enemy2 = 1 ,rast_enemy3 = 1 , simple_enemyx3 = 57 , simple_enemy3 = 1;
    screen[mario_y][mario_x] = '=';
    render1(screen);
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    time_t last_enemy_move_time = time(NULL);
    time_t last_enemy_move_time1 = time(NULL);
    time_t last_enemy_move_time2 = time(NULL);
    time_t last_enemy_move_time3 = time(NULL);
    time_t start_time1 ;
    time_t current_time1;
    struct timespec start_time, end_time;
    while(1)
    {
        for (int i = 0; i < 14; ++i)
        {
            screen[i][0] = wall_helper;
            screen[i][63] = wall_helper;
        }
        for (int i = 0; i < 64; ++i)
        {
            screen[0][i] = wall_helper;
            screen[13][i] = wall_helper;
        }
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        system("clear");
        screen[mario_y][mario_x] = ' ';
        if (read(STDIN_FILENO, &key, 1) > 0)
        {
            if (is_jump)  continue;
            else if (key == 'w' && mario_y >= 1 && screen[mario_y - 1][mario_x] != '#' ) 
            {
                is_jump = 1;
                current_time1 = time(NULL);
            }
            else if (key == 'a' && mario_x >= 1 && screen[mario_y][mario_x - 1] != '#') 
            {
                start_time1 = time(NULL);
                rast = 0;
                chap = 1;
                mario_x--;
            }
            else if (key == 'd' && mario_x <= 63 && screen[mario_y][mario_x + 1] != '#') 
            {   
                start_time1 = time(NULL);
                chap = 0;
                rast = 1;
                mario_x++;
            }
        }
        if (current_time1 - start_time1 > 1)
        {
            chap = 0;
            rast = 0;
        }
        time_t current_time = time(NULL);
        if (current_time - last_enemy_move_time3 >= 2)
        {
            if (giah1 % 2 == 0)
            {
                screen[8][36] = giah;
                screen[4][44] = giah;
            }
            else
            {
                screen[8][36] = ' ';
                screen[4][44] = ' ';
            }
            giah1++;
            last_enemy_move_time3 = current_time;
        }
        if (current_time - last_enemy_move_time1 >= 1 && simple_enemy1 == 1)
        {
            if (screen[12][simple_enemyx-1] == empty && rast_enemy1 == 1)
            {
                screen[12][simple_enemyx] = ' ';
                simple_enemyx -= 1;
            }
            else
            {
                rast_enemy1 = 0;
                screen[12][simple_enemyx] = ' ';
                simple_enemyx += 1;
                if (screen[12][simple_enemyx+1] != empty)rast_enemy1 =1;
            }
            screen[12][simple_enemyx] = simple_enemy;
            last_enemy_move_time1 = current_time;
        }
        if (current_time - last_enemy_move_time2 >= 1 && simple_enemy3 == 1)
        {
            if (screen[12][simple_enemyx3-2] == empty && rast_enemy3 == 1)
            {
                screen[12][simple_enemyx3] = ' ';
                simple_enemyx3 -= 1;
            }
            else
            {
                rast_enemy3 = 0;
                screen[12][simple_enemyx3] = ' ';
                simple_enemyx3 += 1;
                if (simple_enemyx3 == 58)rast_enemy3 =1;
            }
            screen[12][simple_enemyx3] = simple_enemy;
            last_enemy_move_time2 = current_time;
        }
        if (current_time - last_enemy_move_time >= 1 && simple_enemy2 == 1)
        {
            if (screen[12][simple_enemyx2-1] == empty && rast_enemy2 == 1)
            {
                if (simple_enemy3 == 0)screen[12][simple_enemyx2] = ' ';
                simple_enemyx2 -= 1;
            }
            else
            {
                rast_enemy2 = 0;
                screen[12][simple_enemyx2] = ' ';
                simple_enemyx2 += 1;
                if (simple_enemyx2 == 57)rast_enemy2 =1;
            }
            screen[12][simple_enemyx2] = simple_enemy;
            last_enemy_move_time = current_time;
        }
        if (mario_y == 4 && mario_x == 19)
        {
            system("clear");
            printf("\033[J");
            printf("\033[?25h");
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            tcgetattr(STDIN_FILENO, &t);
            t.c_lflag |= ICANON; 
            t.c_lflag |= ECHO;    
            tcsetattr(STDIN_FILENO, TCSANOW, &t);
            fcntl(STDIN_FILENO, F_SETFL, 0);
            return end_game1(1 , username);
        }
        while(is_jump)
        {
            x0 = mario_x; y0 = mario_y;
            system("clear");
            screen[mario_y][mario_x] = ' ';
            if (!flag && rast)
            {
                mario_y += 1;
                mario_x += 1;
                if (mario_y >= ground) rast = 0;
            }
            if (!flag && chap)
            {
                mario_y += 1;
                mario_x -= 1;
                if (mario_y >= ground) chap = 0;
            }
            if (!flag && bala)
            {
                mario_y += 1;
                if (mario_y >= ground) bala = 0;
            }
            if (rast && flag)
            {
                mario_y -= 1;
                mario_x += 1;
                if (mario_y <= ground - 4) flag = 0;
            }
            else if (chap && flag)
            {
                mario_y -= 1;
                mario_x -= 1;
                if (mario_y <= ground - 4) flag = 0;
            }
            if (!flag && !chap && !rast && !bala)
            {
                is_jump = 0;
                flag = 1;
                chap = 0;
                rast = 0;
                bala = 0;
            }
            if (!chap && !rast && !bala)
            {
                mario_y -= 1;
                if (mario_y <= ground - 4)
                {
                    bala = 1;
                    flag = 0;
                }
            }
            if (screen[mario_y][mario_x] == ';')
            {
                is_jump = 0;
                flag = 1;
                ++mario_y;
                while(screen[mario_y+1][mario_x] != '#')
                {
                    system("clear");
                    screen[mario_y][mario_x] = ' ';
                    mario_y++;
                    screen[mario_y][mario_x] = '=';
                    render1(screen);
                    usleep(80000);
                }
                if (star_box == 1)
                {
                    star_box = 0;
                    srand(time(NULL));
                    int shans = rand() % 5 + 1;
                    score+= shans;
                }
            }
            if (screen[mario_y][mario_x] == white)
            {
                flag = 1;
                is_jump = 0;
                if (y0 + 1 == mario_y)
                {
                    ground = mario_y + 1;
                    mario_y--;        
                }
                else if(x0 + 1 == mario_x)
                {
                    mario_x--;
                    while(screen[mario_y+1][mario_x] != '#')
                    {
                        system("clear");
                        screen[mario_y][mario_x] = ' ';
                        mario_y++;
                        screen[mario_y][mario_x] = '=';
                        render1(screen);
                        usleep(80000);
                    }
                }
                else if (y0 - 1 == mario_y) mario_y++; 
            }
            if (screen[mario_y][mario_x] == '^')
            {
                flag = 1;
                is_jump = 0;
                mario_y++;
                while(screen[mario_y+1][mario_x] != '#')
                {
                    system("clear");
                    screen[mario_y][mario_x] = ' ';
                    mario_y++;
                    screen[mario_y][mario_x] = '=';
                    render1(screen);
                    usleep(80000);
                }
            }
            if (mario_y == 4 && mario_x == 19)
            {
                system("clear");
                printf("\033[J");
                printf("\033[?25h");
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                tcgetattr(STDIN_FILENO, &t);
                t.c_lflag |= ICANON; 
                t.c_lflag |= ECHO;    
                tcsetattr(STDIN_FILENO, TCSANOW, &t);
                fcntl(STDIN_FILENO, F_SETFL, 0);
                return end_game1(1 , username);
            }
            if ((mario_y == 12 && mario_x == 59) || (mario_y == 11 && mario_x == 59) || (mario_y == 10 && mario_x == 59) || (mario_y == 10 && mario_x == 58) || (mario_y == 10 && mario_x == 60) || (mario_y == 12 && mario_x == 60) || (mario_y == 11 && mario_x == 60))
            {
                flag = 1;
                is_jump = 0 ;
                screen[mario_y][mario_x] = ' ';
                mario_y = 4;
                mario_x = 23; 
            }
            if (screen[mario_y][mario_x] == '#' )
            {
                flag = 1;
                if((mario_x == 52 && mario_y == 11) || (mario_x == 52 && mario_y == 10) || (mario_x == 52 && mario_y == 9) || (mario_x == 49 && mario_y == 11) || (mario_x == 49 && mario_y == 12) || (mario_x == 49 && mario_y == 10) || (mario_x == 49 && mario_y == 9))
                {
                    is_jump = 0;
                    if(x0 == mario_x + 1)mario_x++;
                    else mario_x--;
                    mario_y++;
                    while(screen[mario_y+1][mario_x] != '#')
                    {
                        system("clear");
                        screen[mario_y][mario_x] = ' ';
                        mario_y++;
                        screen[mario_y][mario_x] = '=';
                        render1(screen);
                        usleep(80000);
                    }
                }
                else if (y0 == mario_y + 1)
                {
                    is_jump = 0;
                    mario_y++;
                    while(screen[mario_y+1][mario_x] != '#')
                    {
                        system("clear");
                        screen[mario_y][mario_x] = ' ';
                        mario_y++;
                        screen[mario_y][mario_x] = '=';
                        render1(screen);
                        usleep(80000);
                    }
                }
                else if(mario_x == 0)
                {
                    flag = 1;
                    is_jump = 0;
                    ++mario_x;
                    while(screen[mario_y+1][mario_x] != '#')
                    {
                        system("clear");
                        screen[mario_y][mario_x] = ' ';
                        mario_y++;
                        screen[mario_y][mario_x] = '=';
                        render1(screen);
                        usleep(80000);
                    }
                }
                else if(mario_x == 63)
                {
                    flag = 1;
                    is_jump = 0;
                    --mario_x;
                    while(screen[mario_y+1][mario_x] != '#')
                    {
                        system("clear");
                        screen[mario_y][mario_x] = ' ';
                        mario_y++;
                        screen[mario_y][mario_x] = '=';
                        render1(screen);
                        usleep(80000);
                    }
                }
                else if (y0 == mario_y - 1)
                {
                    flag = 1;
                    is_jump = 0;
                    mario_y--;  
                    ground = mario_y + 1;                  
                }
            }
            if (mario_x == 17 && mario_y == 12 && star1 == 1)
            {
                star1 = 0;
                score += 1;
            }
            else if (mario_x == 18 && mario_y == 12 && star2 == 1)
            {
                star2 = 0;
                score += 1;
            }
            screen[mario_y][mario_x] = '=';
            render1(screen);
            usleep(80000);
            if (screen[mario_y][mario_x] == giah)
            {
                live--;
                if (live == 0) 
                {
                    system("clear");
                    printf("\033[J");
                    printf("\033[?25h");
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    tcgetattr(STDIN_FILENO, &t);
                    t.c_lflag |= ICANON; 
                    t.c_lflag |= ECHO;    
                    tcsetattr(STDIN_FILENO, TCSANOW, &t);
                    fcntl(STDIN_FILENO, F_SETFL, 0);
                    return end_game1(0 , username);                
                }
                mario_x = 2;
                mario_y = 12;
            }
            if (mario_y == 12 && mario_x == simple_enemyx) 
            {
                if (y0 != mario_y)
                {
                    simple_enemy1 = 0;
                    screen[12][simple_enemyx] == ' ';
                    simple_enemyx = 0;
                    emtiaz += 100;
                }
                else
                {
                    live--;
                    if (live == 0) 
                    {
                        system("clear");
                        printf("\033[J");
                        printf("\033[?25h");
                        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                        tcgetattr(STDIN_FILENO, &t);
                        t.c_lflag |= ICANON; 
                        t.c_lflag |= ECHO;    
                        tcsetattr(STDIN_FILENO, TCSANOW, &t);
                        fcntl(STDIN_FILENO, F_SETFL, 0);
                        return end_game1(0, username);
                    }
                    mario_x = 2;
                    mario_y = 12;
                }
            }
            if (mario_y == 12 && mario_x == simple_enemyx3) 
            {
                if (y0 != mario_y)
                {
                    simple_enemy3 = 0;
                    screen[12][simple_enemyx3] == ' ';
                    simple_enemyx3 = 0;
                    emtiaz += 100;
                }
                else
                {
                    live--;
                    if (live == 0) 
                    {
                        system("clear");
                        printf("\033[J");
                        printf("\033[?25h");
                        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                        tcgetattr(STDIN_FILENO, &t);
                        t.c_lflag |= ICANON; 
                        t.c_lflag |= ECHO;    
                        tcsetattr(STDIN_FILENO, TCSANOW, &t);
                        fcntl(STDIN_FILENO, F_SETFL, 0);
                        return end_game1(0 , username);
                    }
                    mario_x = 2;
                    mario_y = 12;
                }
            }
            if (mario_y == 12 && mario_x == simple_enemyx2) 
            {
                if (y0 != mario_y)
                {
                    simple_enemy2 = 0;
                    screen[12][simple_enemyx2] == ' ';
                    simple_enemyx2 = 0;
                    emtiaz += 100;
                }
                else
                {
                    live--;
                    if (live == 0) 
                    {
                        system("clear");
                        printf("\033[J");
                        printf("\033[?25h");
                        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                        tcgetattr(STDIN_FILENO, &t);
                        t.c_lflag |= ICANON; 
                        t.c_lflag |= ECHO;    
                        tcsetattr(STDIN_FILENO, TCSANOW, &t);
                        fcntl(STDIN_FILENO, F_SETFL, 0);
                        return end_game1(0 , username);
                    }
                    mario_x = 2;
                    mario_y = 12;
                }
            }
        }
        while(screen[mario_y+1][mario_x] != '#' && screen[mario_y+1][mario_x] != ';' && screen[mario_y+1][mario_x] != white && screen[mario_y+1][mario_x] != '^')
        {
            if (mario_y == 4 && mario_x == 19)
            {
                system("clear");
                printf("\033[J");
                printf("\033[?25h");
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                tcgetattr(STDIN_FILENO, &t);
                t.c_lflag |= ICANON; 
                t.c_lflag |= ECHO;    
                tcsetattr(STDIN_FILENO, TCSANOW, &t);
                fcntl(STDIN_FILENO, F_SETFL, 0);
                return end_game1(1 , username);
            }
            if ((mario_y == 12 && mario_x == 59) || (mario_y == 11 && mario_x == 59) || (mario_y == 10 && mario_x == 59) || (mario_y == 10 && mario_x == 58) || (mario_y == 10 && mario_x == 60) || (mario_y == 12 && mario_x == 60) || (mario_y == 11 && mario_x == 60))
            {
                screen[mario_y][mario_x] = ' ';
                mario_y = 4;
                mario_x = 23; 
            }
            if (screen[mario_y+1][mario_x] == enemy_bad)
            {
                system("clear");
                screen[mario_y][mario_x] = ' ';
                live--;
                if (live == 0)
                {
                    system("clear");
                    printf("\033[J");
                    printf("\033[?25h");
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    tcgetattr(STDIN_FILENO, &t);
                    t.c_lflag |= ICANON; 
                    t.c_lflag |= ECHO;    
                    tcsetattr(STDIN_FILENO, TCSANOW, &t);
                    fcntl(STDIN_FILENO, F_SETFL, 0);
                    return end_game1(0 , username);
                }
                mario_x = 2;
                mario_y = 12;
                screen[12][2] = '=';
                render1(screen);
                usleep(85000);
                break;
            }
            if (mario_y == 11 && mario_x == simple_enemyx) 
            {
                screen[mario_y][mario_x] = ' ';
                simple_enemy1 = 0;
            }
            if (mario_y == 11 && mario_x == simple_enemyx2) 
            {
                screen[mario_y][mario_x] = ' ';
                simple_enemy2 = 0;
            }
            if (mario_y == 11 && mario_x == simple_enemyx3) 
            {
                screen[mario_y][mario_x] = ' ';
                simple_enemy3 = 0;
            }
            system("clear");
            screen[mario_y][mario_x] = ' ';
            mario_y++;
            screen[mario_y][mario_x] = '=';
            render1(screen);
            usleep(85000);
            ground = mario_y + 1;
        }
        if (mario_y == 11 && mario_x == 36)
        {
            screen[mario_y][mario_x] = white;
            mario_x--;
        }
        if (mario_y == 7 && mario_x == 44)
        {
            screen[mario_y][mario_x] = white;
            mario_x--;
        }
        if (mario_y == 9 && mario_x == 40)
        {
            screen[mario_y][mario_x] = white;
            mario_x--; 
        }
        ground = mario_y + 1;
        if (mario_x == 17 && mario_y == 12 && star1 == 1)
        {
            star1 = 0;
            score += 1;
        }
        else if (mario_x == 18 && mario_y == 12 && star2 == 1)
        {
            star2 = 0;
            score += 1;
        }
        else if(mario_x == 6 && mario_y == 8 && star3 == 1)
        {
            star3 = 0;
            score += 1;
        }
        else if(mario_x == 7 && mario_y == 8 && star4 == 1)
        {
            star4 = 0;
            score += 1;
        }
        if (screen[mario_y][mario_x] == white)
        {
            mario_x--;
        }
        if (mario_y == 12 && mario_x == simple_enemyx && simple_enemy1 == 1) 
        {
            live--;

            if (live == 0) 
            {
                system("clear");
                printf("\033[J");
                printf("\033[?25h");
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                tcgetattr(STDIN_FILENO, &t);
                t.c_lflag |= ICANON; 
                t.c_lflag |= ECHO;    
                tcsetattr(STDIN_FILENO, TCSANOW, &t);
                fcntl(STDIN_FILENO, F_SETFL, 0);
                return end_game1(0 , username);
            }
            mario_x = 2;
            mario_y = 12;
        }
        if (mario_y == 12 && mario_x == simple_enemyx2 && simple_enemy2 == 1) 
        {
            live--;
            if (live == 0) 
            {
                system("clear");
                printf("\033[J");
                printf("\033[?25h");
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                tcgetattr(STDIN_FILENO, &t);
                t.c_lflag |= ICANON; 
                t.c_lflag |= ECHO;    
                tcsetattr(STDIN_FILENO, TCSANOW, &t);
                fcntl(STDIN_FILENO, F_SETFL, 0);
                return end_game1(0 , username);
            }
            mario_x = 2;
            mario_y = 12;
        }
        if (mario_y == 12 && mario_x == simple_enemyx3 && simple_enemy3 == 1) 
        {
            live--;
            if (live == 0) 
            {
                system("clear");
                printf("\033[J");
                printf("\033[?25h");
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                tcgetattr(STDIN_FILENO, &t);
                t.c_lflag |= ICANON; 
                t.c_lflag |= ECHO;    
                tcsetattr(STDIN_FILENO, TCSANOW, &t);
                fcntl(STDIN_FILENO, F_SETFL, 0);
                return end_game1(0 , username);
            }
            mario_x = 2;
            mario_y = 12;
        }
        if (screen[mario_y][mario_x] == giah) 
        {
            screen[mario_y][mario_x] = ' ';
            live--;
            if (live == 0) 
            {
                system("clear");
                printf("\033[J");
                printf("\033[?25h");
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                tcgetattr(STDIN_FILENO, &t);
                t.c_lflag |= ICANON; 
                t.c_lflag |= ECHO;    
                tcsetattr(STDIN_FILENO, TCSANOW, &t);
                fcntl(STDIN_FILENO, F_SETFL, 0);
                return end_game1(0 , username);
            }
            mario_x = 2;
            mario_y = 12;
        }
        if ((mario_y == 12 && mario_x == 59) || (mario_y == 11 && mario_x == 59) || (mario_y == 10 && mario_x == 59) || (mario_y == 10 && mario_x == 58) || (mario_y == 10 && mario_x == 60) || (mario_y == 12 && mario_x == 60) || (mario_y == 11 && mario_x == 60))
        {
            screen[mario_y][mario_x] = ' ';
            mario_y = 4;
            mario_x = 23; 
        }
        system("clear");
        screen[mario_y][mario_x] = '=';
        render1(screen);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        long elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_nsec - start_time.tv_nsec) / 1000;
        if (elapsed_time < FRAME_DELAY) 
        {
            usleep(FRAME_DELAY - elapsed_time);
        }
    }
    return 0;
}
int end_game1(int lose , char username[31])
{
    FILE *fp = popen("pgrep mpg123", "r");
    char pid[16];
    if (fgets(pid, sizeof(pid), fp) != NULL) 
    {
        pid[strcspn(pid, "\n")] = '\0';
        char command[64];
        snprintf(command, sizeof(command), "kill %s", pid);
        system(command);
    }
    pclose(fp);
    char line[151];
    FILE *file1 = fopen("informaition.txt" , "r");
    FILE *file2 = fopen("ch_information.txt" , "w");
    while(fgets(line , sizeof(line) , file1))
    {
        if (line[0] == ' ') break;
        int flag = 1; 
        int i;
        for (i = 0; i < strlen(username); ++i)
        {
            if (line[i] != username[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1 && username[i] == '\0' && line[i] == ' ')
        {
            int j = 0;
            while(line[j] != '\0') {
                if (line[j] == '\n') 
                {
                    line[j] = '\0';
                    break;
                }
                ++j;
            }
            int k = 0;
            while(line[k] != '\0')
            {
                fprintf(file2, "%c", line[k]);
                ++k;
            }
            fprintf(file2, " ");
            if (lose == 0)fprintf(file2 , "0");
            else fprintf(file2 , "1");
            fprintf(file2, " ");
            fprintf(file2, "%i" , score);
            fprintf(file2, " ");
            emtiaz += live * 100;
            fprintf(file2, "%i" , emtiaz);
            fprintf(file2, "\n");
        }
        else fprintf(file2, "%s", line);
    }
    fclose(file1);
    fclose(file2);
    file1 = fopen("informaition.txt" , "w");
    file2 = fopen("ch_information.txt" , "r");
    char ch;
    while ((ch = fgetc(file2)) != EOF) 
    {
        fputc(ch, file1);
    }
    fclose(file1);
    fclose(file2);
    emtiaz = 0;
    return start_game2(username);
}
int render2(char screen[29][62])
{
    for (int y = 0; y < 28; y++) 
    {
        for (int x = 0; x < 61; x++) 
        {
            if ((y == 10 && x == 3) || (y == 8 && x == 5) || (y == 8 && x == 6) || (y == 8 && x == 7) || (y == 6 && x == 9) || (y == 8 && x == 11))printf("🧱");
            else if (y == 6 && x == 11) printf("🟧");
            else if ((y == 6 && x == 10) || (y == 6 && x == 12) || (y == 6 && x == 13)) printf("🧱");
            else if ((y == 7 && x == 24) || (y == 7 && x == 23) || (y == 7 && x == 25) || (y == 7 && x == 26)|| (y == 7 && x == 27))printf("🧱");
            else if ((y == 7 && x == 29) || (y == 6 && x == 28) || (y == 6 && x == 27)) printf("🧱");
            else if ((y == 8 && x == 47) || (y == 6 && x == 38)) printf("🟨");
            else if (y == 5 && x == 56) printf("🚩");
            else if (screen[y][x] == 's') printf("🛡️ ");
            else if (screen[y][x] == '^')printf("🟧");
            else if (screen[y][x] == '#') printf("🧱");
            else if(screen[y][x] == '=') printf("😎");
            else if (screen[y][x] == 'w')printf("💀");
            else if(screen[y][x] == '*')printf("🪙");
            else if(screen[y][x] == ')') printf("🦖");
            else if(screen[y][x] == 'g') printf("\033[32m██\033[0m");
            else if((y == 11 && x == 28) || (y == 12 && x == 27) || (y == 11 && x == 27) || (y == 6 && x == 25) || (y == 5 && x == 25) || (y == 4 && x == 25) || (y == 4 && x == 24) || (y == 2 && x == 59) || (y == 3 && x == 59))
            {
                printf("\033[32m█\033[0m");
                printf("\033[32m█\033[0m");
            }
            else if ((y == 11 && x == 26) || (y == 6 && x == 24) || (y == 5 && x == 24) || (y == 3 && x == 58) || (y == 2 && x == 58) || (y == 1 && x == 58) || (y == 4 && x == 58))
            {
                printf(" ");
                printf("\033[32m█\033[0m");
            }
            else if ((y == 12 && x == 28) || (y == 4 && x == 26))
            {
                printf("\033[32m█\033[0m");
                printf(" ");
            }
            else if (y == 27 && x == 0)
            {
                printf("                                 \033[32myour score is :\033[0m \033[35m%i\033[0m           \033[32myour lives :\033[0m " , score);
                int i = 0; 
                while(i != live)
                {
                    printf("❤️ ");
                    i +=1;
                }
            }
            else if (screen[y][x] == 'a')printf("🍄");
            else printf("%c%c" , screen[y][x] , screen[y][x]);
        }
        printf("\n");
    }
}
int start_game2(char username[31])
{
    system("nohup mpg123 -q mario2.mp3 > /dev/null 2>&1 &");
    system("clear");
    system("./start2.sh");
    setlocale(LC_ALL, "en_US.UTF-8");
    struct termios oldt, newt , t;
    char key , key2 , key3;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char empty = ' ';
    char wall_helper = '#';
    char star = '*';
    char simple_enemy = 'w';
    char white = '(';
    char enemy_bad = ')';
    char mario = '=';
    char yellow = ';';
    char giah = '_';
    char orange = '^';
    char green = 'g';
    char shild = 's';
    char gharch_ch = 'a';
    char screen[29][62];
    live = 3;
    score = 0;
    for (int y = 0; y < 28; y++) 
    {
        for (int x = 0; x < 61; x++) 
        {
            screen[y][x] = empty;  
        }
    }
    for (int i = 0; i < 14; ++i)
    {
        screen[i][0] = wall_helper;
        screen[i][60] = wall_helper;
    }
    for (int i = 1; i < 60; ++i)
    {
        screen[0][i] = wall_helper;
        screen[13][i] = wall_helper;
    }
    for (int i = 0; i < 61; ++i)
    {
        screen[14][i] = wall_helper;
    }
    screen[13][27] = empty;
    screen[14][27] = empty;
    screen[8][5] = wall_helper ;
    screen[8][6] = wall_helper ;
    screen[8][7] = wall_helper ;
    screen[8][11] = wall_helper ;
    screen[7][22] = wall_helper;
    screen[7][23] = wall_helper;
    screen[7][24] = wall_helper;
    screen[7][25] = wall_helper;
    screen[7][26] = wall_helper;
    screen[6][9] = wall_helper ;
    screen[6][10] = wall_helper ;
    screen[6][12] = wall_helper ;
    screen[6][13] = wall_helper ;
    screen[10][3] = wall_helper ;
    screen[11][29] = wall_helper ;
    screen[11][30] = wall_helper ;
    screen[10][31] = wall_helper ;
    screen[11][31] = wall_helper ;
    screen[8][31] = wall_helper ;
    screen[9][32] = wall_helper ;
    screen[7][31] = wall_helper ;
    screen[7][30] = wall_helper ;
    screen[7][29] = wall_helper ;
    screen[6][28] = wall_helper ;
    screen[6][29] = wall_helper ;
    screen[6][27] = wall_helper ;
    screen[5][27] = wall_helper ;
    screen[9][30] = star ;
    screen[12][2] = mario;
    screen[9][3] = star;
    screen[12][52] = star;
    screen[12][18] = star;
    screen[12][15] = simple_enemy;
    screen[12][42] = simple_enemy;
    screen[10][47] = simple_enemy;
    screen[13][47] = empty;
    screen[14][47] = empty;
    screen[12][48] = wall_helper ;
    screen[11][48] = wall_helper ;
    screen[11][47] = wall_helper ;
    screen[11][46] = wall_helper ;
    screen[11][45] = wall_helper ;
    screen[11][44] = wall_helper ;
    screen[11][43] = wall_helper ;
    screen[11][42] = wall_helper ;
    screen[11][41] = wall_helper ;
    screen[11][40] = wall_helper ;
    screen[11][39] = wall_helper ;
    screen[11][38] = wall_helper ;
    screen[11][37] = wall_helper ;
    screen[11][36] = wall_helper ;
    screen[10][36] = wall_helper ;
    screen[8][33] = wall_helper ;
    screen[8][34] = wall_helper ;
    screen[8][35] = wall_helper ;
    screen[8][36] = wall_helper ;
    screen[8][37] = wall_helper ;
    screen[8][38] = wall_helper ;
    screen[8][39] = wall_helper ;
    screen[10][48] = wall_helper ;
    screen[10][49] = wall_helper ;
    screen[11][49] = wall_helper ;
    screen[8][49] = wall_helper ;
    screen[8][48] = wall_helper ;
    screen[8][46] = wall_helper ;
    screen[8][45] = wall_helper ;
    screen[8][44] = wall_helper ;
    screen[9][44] = wall_helper ;
    screen[8][43] = wall_helper ;
    screen[8][42] = wall_helper ;
    screen[8][41] = wall_helper ;
    screen[8][40] = wall_helper ;
    screen[8][47] = wall_helper ;
    screen[8][50] = wall_helper ;
    screen[8][51] = wall_helper ;
    screen[8][52] = wall_helper ;
    screen[9][52] = wall_helper ;
    screen[10][52] = wall_helper ;
    screen[11][52] = wall_helper ;
    screen[10][59] = wall_helper ;
    screen[10][58] = wall_helper ;
    screen[9][53] = wall_helper ;
    screen[10][53] = wall_helper ;
    screen[11][53] = wall_helper ;
    screen[11][54] = wall_helper ;
    screen[11][55] = wall_helper ;
    screen[10][54] = wall_helper ;
    screen[10][57] = shild ;
    screen[7][41] = enemy_bad;
    screen[6][39] = wall_helper ;
    screen[6][37] = wall_helper ;
    screen[4][36] = wall_helper ;
    screen[4][35] = wall_helper ;
    screen[6][59] = wall_helper ;
    screen[6][58] = wall_helper ;
    screen[6][57] = wall_helper ;
    screen[6][56] = wall_helper ;
    screen[6][55] = wall_helper ;
    screen[6][54] = wall_helper ;
    screen[5][54] = wall_helper ;
    screen[4][54] = wall_helper ;
    screen[3][54] = wall_helper ;
    screen[2][54] = wall_helper ;
    screen[1][54] = wall_helper ;
    screen[8][32] = wall_helper ;
    screen[6][38] = yellow;
    screen[4][37] = orange;
    screen[6][11] = wall_helper;
    printf("\033[?25l");
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    render2(screen);
    int is_jump = 0 , mario_y = 12 , mario_x = 2, ground = 12 , max = 5 , flag = 1 , rast = 0 , chap = 0;
    int star1 = 1 , star3 = 1 , star2 = 1 ,star4 = 1 , star5 = 1 , star6 = 1 , star7 = 1 , simple_enemy1 = 1 , simple_enemyx1 = 15 , rast_enemy1 = 1 , simple_enemyx2 = 34 , rast_enemy2 = 1 , simple_enemy2 = 1 , namar = 0 , simple_enemyx3 = 42 , simple_enemy3 = 1 , rast_enemy3 = 1 , simple_enemyx4 = 47 , rast_enemy4 = 1 , simple_enemy4 = 1;
    int ava_shild = 1 , shild_dar = 0 , gharch = 0 , star_box2 = 1;
    int bro_rast = 0 , bro_chap = 0  , star_box = 1 , count_gharch = 0 , mario_gharch = 0 , sit = 0;
    time_t last_enemy_move_time1 = time(NULL);
    time_t last_enemy_move_time2 = time(NULL);
    time_t last_enemy_move_time3 = time(NULL);
    time_t last_enemy_move_time4 = time(NULL);
    time_t last_enemy_move_time5 = time(NULL);
    time_t last_enemy_move_time6;
    struct timespec start_time, end_time;
    while(1)
    {
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        system("clear");
        if (mario_gharch == 1 && sit == 0)screen[mario_y-1][mario_x] = empty;
        screen[mario_y][mario_x] = empty;
        if (read(STDIN_FILENO, &key, 1) > 0)
        {
            if (is_jump)  continue;
            else if (key == 'w' && screen[mario_y - 1][mario_x] != '#' ) 
            {
                is_jump = 1;
            }
            else if (key == 'a'&& screen[mario_y][mario_x-1] != '#') 
            {
                if (mario_gharch == 1 && screen[mario_y-1][mario_x-1] == '#' && sit == 0)
                {
                    screen[mario_y-1][mario_x]=empty;
                    mario_gharch = 0;
                    count_gharch = 0; 
                    mario_x++;
                }
                mario_x--;
            }
            else if (key == 'd' && screen[mario_y][mario_x+1] != '#') 
            {   
                if (mario_gharch == 1 && screen[mario_y-1][mario_x+1] == '#' && sit == 0)
                {
                    screen[mario_y-1][mario_x]=empty;
                    mario_gharch = 0;
                    count_gharch = 0;
                    star_box2 = 1;
                    mario_x--;
                }
                mario_x++;
            }
            else if (key == 's' && mario_gharch == 1)
            {
                sit = 1;
                last_enemy_move_time6 = time(NULL);
                screen[mario_y-1][mario_x] = empty;
            }
        }
        time_t current_time = time(NULL);
        if (sit == 1 && current_time - last_enemy_move_time6 >= 2 && screen[mario_y-1][mario_x] == empty) 
        {
            sit = 0;
            if (screen[mario_y-1][mario_x] == empty)
            {
                screen[mario_y-1][mario_x] = mario;
            }
        }
        if (current_time - last_enemy_move_time5 >= 1 && gharch == 1)
        {
            if (count_gharch == 0)
                screen[5][38] = gharch_ch;
            else if (count_gharch == 1)
            {
                screen[5][38] = empty;
                screen[5][37] = gharch_ch;
            }
            else if (count_gharch == 2)
            {
                screen[5][37] = empty;
                screen[5][36] = gharch_ch;
            }
            else if (count_gharch == 3)
            {
                screen[5][36] = empty;
                screen[6][36] = gharch_ch;
            }
            else if (count_gharch == 4)
            {
                screen[6][36] = empty;
                screen[7][36] = gharch_ch;
            }
            ++count_gharch;
            last_enemy_move_time5 = current_time;
        }
        if (screen[mario_y][mario_x] == gharch_ch && gharch == 1)
        {
            gharch = 0;
            mario_gharch = 1; 
            screen[mario_y-1][mario_x] = mario; 
        }
        if (current_time - last_enemy_move_time1 >= 1 && simple_enemy1 == 1)
        {
            if (screen[12][simple_enemyx1-1] == empty && rast_enemy1 == 1)
            {
                screen[12][simple_enemyx1] = ' ';
                simple_enemyx1 -= 1;
            }
            else
            {
                rast_enemy1 = 0;
                screen[12][simple_enemyx1] = ' ';
                simple_enemyx1 += 1;
                if (screen[12][simple_enemyx1+1] != empty || simple_enemyx1+1 == 27)rast_enemy1 =1;
            }
            screen[12][simple_enemyx1] = simple_enemy;
            last_enemy_move_time1 = current_time;
        }
        if (current_time - last_enemy_move_time2 >= 1 && simple_enemy2 == 1 && namar == 1)
        {
            if (screen[25][simple_enemyx2-1] == empty && rast_enemy2 == 1)
            {
                screen[25][simple_enemyx2] = ' ';
                simple_enemyx2 -= 1;
            }
            else
            {
                rast_enemy2 = 0;
                screen[25][simple_enemyx2] = ' ';
                simple_enemyx2 += 1;
                if (screen[25][simple_enemyx2+1] != empty)rast_enemy2 =1;
            }
            screen[25][simple_enemyx2] = simple_enemy;
            last_enemy_move_time2 = current_time;
        }
        if (current_time - last_enemy_move_time3 >= 1 && simple_enemy3 == 1 )
        {
            if (simple_enemyx3-1 != 28 && rast_enemy3 == 1)
            {
                screen[12][simple_enemyx3] = ' ';
                simple_enemyx3 -= 1;
            }
            else
            {
                rast_enemy3 = 0;
                screen[12][simple_enemyx3] = ' ';
                simple_enemyx3 += 1;
                if (simple_enemyx3+1 == 47)rast_enemy3 =1;
            }
            screen[12][simple_enemyx3] = simple_enemy;
            last_enemy_move_time3 = current_time;
        }
        if (current_time - last_enemy_move_time4 >= 1 && simple_enemy4 == 1)
        {
            if (screen[10][simple_enemyx4-1] == empty && rast_enemy4 == 1)
            {
                screen[10][simple_enemyx4] = ' ';
                simple_enemyx4 -= 1;
            }
            else
            {
                rast_enemy4 = 0;
                screen[10][simple_enemyx4] = ' ';
                simple_enemyx4 += 1;
                if (screen[10][simple_enemyx4+1] != empty )rast_enemy4 =1;
            }
            screen[10][simple_enemyx4] = simple_enemy;
            last_enemy_move_time4 = current_time;
        }
        while(is_jump)
        {
            if (star_box == 1 && mario_x == 47 && mario_y == 9)
            {
                star_box = 0;
                srand(time(NULL));
                int shans = rand() % 5 + 1;
                score+= shans;
            }
            if (star_box2 == 1 && mario_x == 38 && mario_y == 7)
            {
                gharch = 1;
                is_jump = 0;
                flag = 1;
                break;
            }
            if (screen[mario_y-1][mario_x] == '#')
            {
                flag = 0;
            }
            system("clear");
            if (mario_gharch == 1)screen[mario_y-1][mario_x] = empty;
            screen[mario_y][mario_x] = empty;
            int x = mario_x;
            int y = mario_y;
            if (mario_y >= ground - max && flag == 1)
            {
                --mario_y;
                if (mario_y == ground - max)
                    flag = 0;
            }
            else if(flag == 0)
            {
                mario_y++;
            }
            if (mario_y == ground)
            {
                flag = 1;
                is_jump = 0;
            }
            if (read(STDIN_FILENO, &key2, 1) > 0)
            {
                if (key2 == 'a' && screen[mario_y][mario_x-1] != '#' ) 
                {
                    chap = 1;
                    mario_x--;
                    if (mario_gharch == 1 && screen[mario_y-1][mario_x-1] == '#')
                    {
                        chap = 0;
                        mario_x++;
                    }
                }
                else if (key2 == 'd' && screen[mario_y][mario_x+1] != '#') 
                {   
                    rast = 1;
                    mario_x++;
                    if (mario_gharch == 1 && screen[mario_y-1][mario_x+1] == '#')
                    {
                        rast = 0;
                        mario_x--;
                    }
                }
                if (screen[mario_y][mario_x] == '#' && rast == 1)
                {
                    if (screen[mario_y-1][mario_x-1] == '#')
                    {
                       mario_x--;
                       mario_y++; 
                    }
                    else mario_x--;
                }
                if (screen[mario_y][mario_x] == '#' && chap == 1)
                {
                    mario_x++;
                }
            }
            if (mario_y == 3 && mario_x == 37 && mario_gharch == 1)
            {
                screen[mario_y+1][mario_x] = empty;
                srand(time(NULL));
                int shans = rand() % 10 + 1;
                if (shans <= 2) score+= shans;
            }
            if (screen[mario_y][mario_x] == green)
            {
                flag = 1;
                is_jump = 0;
                screen[mario_y][mario_x] = 'g';
                mario_y = 14;
                mario_x = 47;
                screen[mario_y][mario_x] = '=';
                render2(screen);
                usleep(120000);
                screen[mario_y][mario_x] = empty;
                mario_y = 13;
                screen[mario_y][mario_x] = '=';
                render2(screen);
                usleep(120000);
                screen[mario_y][mario_x] = empty;
                mario_y = 12;
                screen[mario_y][mario_x] = '=';
                render2(screen);
                usleep(120000);
                screen[mario_y][mario_x] = empty;
                mario_x = 46;
                for (int y = 15; y < 27; y++) 
                {
                    for (int x = 26; x < 49; x++) 
                    {
                        screen[y][x] = empty;  
                    }
                }
                namar = 0;
            }
            if ((mario_y == 12 && mario_x == 27) || (mario_y == 12 && mario_x == 28) || (mario_y == 11 && mario_x == 27) || (mario_y == 11 && mario_x == 28))
            {
                flag = 1;
                is_jump = 0;
                for (int i = 0; i < 13; ++i)
                {
                    screen[i + 14][26] = wall_helper;
                    screen[i + 14][48] = wall_helper;

                }
                for (int i = 27; i < 48; ++i)
                {
                    screen[26][i] = wall_helper;
                }
                screen[25][35] = wall_helper ;
                screen[24][36] = wall_helper ;
                screen[24][37] = wall_helper ;
                screen[23][37] = enemy_bad ;
                screen[22][39] = enemy_bad ;
                screen[23][38] = wall_helper;
                screen[23][39] = wall_helper;
                screen[23][40] = wall_helper;
                screen[22][40] = wall_helper;
                screen[22][41] = wall_helper;
                screen[26][42] = empty;
                screen[22][45] = wall_helper;
                screen[22][46] = wall_helper;
                screen[21][46] = wall_helper;
                if (star3 == 1) screen[24][35] = star;
                if (star4 == 1) screen[21][45] = star;
                if (star5 == 1) screen[20][46] = star;
                if (star6 == 1) screen[25][45] = star;
                screen[25][46] = green;
                screen[25][47] = green;
                screen[24][47] = green;
                screen[23][47] = green;
                screen[22][47] = green;
                screen[21][47] = green;
                screen[20][47] = green;
                screen[19][47] = green;
                screen[18][47] = green;
                screen[17][47] = green;
                screen[16][47] = green;
                screen[15][47] = green;
                screen[mario_y][mario_x] = empty; 
                mario_y = 13;
                mario_x = 27;
                namar = 1;
            }
            if (mario_y == 12 && mario_x == simple_enemyx1)
            {
                if (shild_dar == 1)
                    shild_dar = 0;
                simple_enemy1 = 0;
                screen[12][simple_enemyx1] = ' ';
                simple_enemyx1 = 0;
                emtiaz += 100;
            }
            if (mario_y == 25 && mario_x == simple_enemyx2)
            {
                if (shild_dar == 1)
                    shild_dar = 0;
                simple_enemy2 = 0;
                screen[25][simple_enemyx2] = ' ';
                simple_enemyx2 = 0;
                emtiaz += 100;
            }
            if (mario_y == 12 && mario_x == simple_enemyx3)
            {
                if (shild_dar == 1)
                    shild_dar = 0;
                simple_enemy3 = 0;
                screen[12][simple_enemyx3] = ' ';
                simple_enemyx3 = 0;
            }
            if (mario_y == 10 && mario_x == simple_enemyx4)
            {
                if (shild_dar == 1)
                    shild_dar = 0;
                simple_enemy4 = 0;
                screen[10][simple_enemyx4] = ' ';
                simple_enemyx4 = 0;
                emtiaz += 100;
            }
            if (mario_gharch == 1 && screen[mario_y-2][mario_x] == '#')
            {
                flag = 0;
            }
            if (screen[mario_y+1][mario_x] == '#')
            {
                is_jump = 0;
                flag = 1;
                ground = mario_y ;
            }
            if (screen[mario_y][mario_x] == '#')
            {
                if (chap == 0 && rast == 0)
                {
                    flag = 0;
                    mario_y++;
                }
                else if(rast == 1)
                {
                    flag = 0;
                    mario_x--;
                }
                else if (chap == 1)
                {
                    flag = 0;
                    mario_x++;
                }
            }
            if (screen[mario_y][mario_x] == shild && ava_shild == 1)
            {
                ava_shild = 0;
                shild_dar = 1;
            }
            if (screen[mario_y][mario_x] == gharch_ch && gharch == 1)
            {
                gharch = 0;
                mario_gharch = 1;
                screen[mario_y-1][mario_x] = mario;
            }
            if (mario_y == 9 && mario_x == 3 && star1 == 1)
            {
                star1 = 0;
                score++;
            }
            if (mario_y == 12 && mario_x == 18 && star2 == 1)
            {
                star2 = 0;
                score++;
            }
            if (mario_y == 24 && mario_x == 35 && star3 == 1)
            {
                star3 = 0;
                score++;
            }
            if (mario_y == 21 && mario_x == 45 && star4 == 1)
            {
                star4 = 0;
                score++;
            }
            if (mario_y == 20 && mario_x == 46 && star5 == 1)
            {
                star5 = 0;
                score++;
            }
            if (mario_y == 25 && mario_x == 45 && star6 == 1)
            {
                star6 = 0;
                score++;
            }
            if (mario_y == 12 && mario_x == 52 && star7 == 1)
            {
                star7 = 0;
                score++;
            }
            if ((mario_y == 6 && mario_x == 25) || (mario_y == 6 && mario_x == 24) || (mario_y == 5 && mario_x == 25) || (mario_y == 5 && mario_x == 24) || (mario_y == 4 && mario_x == 25) || (mario_y == 4 && mario_x == 24) || (mario_y == 4 && mario_x == 26))
            {
                screen[mario_y][mario_x] = empty;
                mario_y = 2;
                mario_x = 57;
            }
            if (screen[mario_y][mario_x] == ')')
            {
                if (shild_dar == 1)
                {
                    shild_dar = 0;
                    screen[mario_y][mario_x] = mario;
                }
                else
                {
                    --live;
                    if (live == 0)
                    {
                        printf("\033[J");
                        printf("\033[?25h");
                        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                        tcgetattr(STDIN_FILENO, &t);
                        t.c_lflag |= ICANON; 
                        t.c_lflag |= ECHO;    
                        tcsetattr(STDIN_FILENO, TCSANOW, &t);
                        fcntl(STDIN_FILENO, F_SETFL, 0);
                        return end_game2(0 , username);
                    }
                    screen[mario_y][mario_x] = ')';
                    mario_y = 12;
                    mario_x = 2;
                }
            }
            if (mario_y == 9 && mario_x == 47) bro_rast++;
            if (bro_rast == 2)
            {
                bro_rast = 0;
                is_jump = 0;
                flag = 1;
                mario_x = 48;
            }
            if (mario_y == 9 && mario_x == 37) bro_chap++;
            if (bro_chap == 2)
            {
                bro_chap = 0;
                is_jump = 0;
                flag = 1;
                mario_x = 36;
            }
            if (mario_gharch == 1)screen[mario_y-1][mario_x] = mario;
            screen[mario_y][mario_x] = mario;
            render2(screen);
            if ((mario_y == 9 && mario_x == 37) || (mario_y == 9 && mario_x == 38) || (mario_y == 9 && mario_x == 39) || (mario_y == 9 && mario_x == 40) || (mario_y == 9 && mario_x == 41) || (mario_y == 9 && mario_x == 42) || (mario_y == 9 && mario_x == 43) || (mario_y == 9 && mario_x == 44) || (mario_y == 9 && mario_x == 45) || (mario_y == 9 && mario_x == 46) || (mario_y == 9 && mario_x == 47))usleep(400000);
            else usleep(120000);
        }
        if (screen[mario_y][mario_x] == gharch_ch && gharch == 1)
        {
            gharch = 0;
            mario_gharch = 1;
        }
        if (screen[mario_y][mario_x] == green)
        {
            screen[mario_y][mario_x] = 'g';
            mario_y = 14;
            mario_x = 47;
            screen[mario_y][mario_x] = '=';
            render2(screen);
            usleep(120000);
            screen[mario_y][mario_x] = empty;
            mario_y = 13;
            screen[mario_y][mario_x] = '=';
            render2(screen);
            usleep(120000);
            screen[mario_y][mario_x] = empty;
            mario_y = 12;
            screen[mario_y][mario_x] = '=';
            render2(screen);
            usleep(120000);
            screen[mario_y][mario_x] = empty;
            mario_x = 46;
            for (int y = 15; y < 27; y++) 
            {
                for (int x = 26; x < 49; x++) 
                {
                    screen[y][x] = empty;  
                }
            }
            namar = 0;
        }
        if ((mario_y == 12 && mario_x == 27) || (mario_y == 12 && mario_x == 28) || (mario_y == 11 && mario_x == 27) || (mario_y == 11 && mario_x == 28))
        {
            for (int i = 0; i < 13; ++i)
            {
                screen[i + 14][26] = wall_helper;
                screen[i + 14][48] = wall_helper;

            }
            for (int i = 27; i < 48; ++i)
            {
                screen[26][i] = wall_helper;
            }
            screen[25][35] = wall_helper ;
            screen[24][36] = wall_helper ;
            screen[24][37] = wall_helper ;
            screen[23][37] = enemy_bad ;
            screen[22][39] = enemy_bad ;
            screen[23][38] = wall_helper;
            screen[23][39] = wall_helper;
            screen[23][40] = wall_helper;
            screen[22][40] = wall_helper;
            screen[22][41] = wall_helper;
            screen[26][42] = empty;
            screen[22][45] = wall_helper;
            screen[22][46] = wall_helper;
            screen[21][46] = wall_helper;
            if (star3 == 1) screen[24][35] = star;
            if (star4 == 1) screen[21][45] = star;
            if (star5 == 1) screen[20][46] = star;
            if (star6 == 1) screen[25][45] = star;
            screen[25][46] = green;
            screen[25][47] = green;
            screen[24][47] = green;
            screen[23][47] = green;
            screen[22][47] = green;
            screen[21][47] = green;
            screen[20][47] = green;
            screen[19][47] = green;
            screen[18][47] = green;
            screen[17][47] = green;
            screen[16][47] = green;
            screen[15][47] = green;
            screen[mario_y][mario_x] = empty; 
            mario_y = 13;
            mario_x = 27;
            namar = 1;
        }
        while(screen[mario_y+1][mario_x]!= '#' && screen[mario_y+1][mario_x]!= orange && screen[mario_y+1][mario_x] != yellow )
        {
            if (screen[mario_y+1][mario_x] == green)
            {
                screen[mario_y][mario_x] = empty;
                mario_y = 14;
                mario_x = 47;
                screen[mario_y][mario_x] = '=';
                render2(screen);
                usleep(120000);
                screen[mario_y][mario_x] = empty;
                mario_y = 13;
                screen[mario_y][mario_x] = '=';
                render2(screen);
                usleep(120000);
                screen[mario_y][mario_x] = empty;
                mario_y = 12;
                screen[mario_y][mario_x] = '=';
                render2(screen);
                usleep(120000);
                screen[mario_y][mario_x] = empty;
                mario_x = 46;
                for (int y = 15; y < 27; y++) 
                {
                    for (int x = 26; x < 49; x++) 
                    {
                        screen[y][x] = empty;  
                    }
                }
                namar = 0;
                break;
            }
            if (screen[mario_y][mario_x] == shild && ava_shild == 1)
            {
                ava_shild = 0;
                shild_dar = 1;
            }
            if (screen[mario_y+1][mario_x] == gharch_ch && gharch == 1)
            {
                gharch = 0;
                mario_gharch = 1; 
                screen[mario_y-1][mario_x] = mario;           
            }
            system("clear");
            if (mario_gharch == 1)screen[mario_y-1][mario_x] = empty;
            screen[mario_y][mario_x] = empty;
            ++mario_y;
            if (mario_y == 26)
            {
                --live;
                if (live == 0)
                {
                    printf("\033[J");
                    printf("\033[?25h");
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    tcgetattr(STDIN_FILENO, &t);
                    t.c_lflag |= ICANON; 
                    t.c_lflag |= ECHO;    
                    tcsetattr(STDIN_FILENO, TCSANOW, &t);
                    fcntl(STDIN_FILENO, F_SETFL, 0);
                    return end_game2(0 , username);
                }
                screen[mario_y][mario_x] = ' ';
                mario_y = 12;
                mario_x = 2;
            }
            if (namar == 1)screen[25][simple_enemyx2] = simple_enemy;
            if (read(STDIN_FILENO, &key3, 1) > 0)
            {
                if (key3 == 'a') 
                {
                    chap = 1;
                    mario_x--;
                }
                else if (key3 == 'd') 
                {   
                    rast = 1;
                    mario_x++;
                }
            }
            if ((mario_y == 6 && mario_x == 25) || (mario_y == 6 && mario_x == 24) || (mario_y == 5 && mario_x == 25) || (mario_y == 5 && mario_x == 24) || (mario_y == 4 && mario_x == 25) || (mario_y == 4 && mario_x == 24) || (mario_y == 4 && mario_x == 26))
            {
                screen[mario_y][mario_x] = empty;
                mario_y = 2;
                mario_x = 57;
            }
            if (mario_y == 12 && mario_x == simple_enemyx1)
            {
                if (shild_dar == 1)
                    shild_dar = 0;
                simple_enemy1 = 0;
                screen[12][simple_enemyx1] = ' ';
                simple_enemyx1 = 0;
                emtiaz += 100;
            }
            if (mario_y == 25 && mario_x == simple_enemyx2)
            {
                if (shild_dar == 1)
                    shild_dar = 0;
                simple_enemy2 = 0;
                screen[25][simple_enemyx2] = ' ';
                simple_enemyx2 = 0;
                emtiaz += 100;
            }
            if (mario_y == 12 && mario_x == simple_enemyx3)
            {
                if (shild_dar == 1)
                    shild_dar = 0;
                simple_enemy3 = 0;
                screen[12][simple_enemyx3] = ' ';
                simple_enemyx3 = 0;
                emtiaz += 100;
            }
            if (mario_y == 10 && mario_x == simple_enemyx4)
            {
                if (shild_dar == 1)
                    shild_dar = 0;
                simple_enemy4 = 0;
                screen[10][simple_enemyx4] = ' ';
                simple_enemyx4 = 0;
                emtiaz += 100;
            }
            if (mario_y == 12 && mario_x == 18 && star2 == 1)
            {
                star2 = 0;
                score++;
            }
            if (screen[mario_y][mario_x] == ')')
            {
                if (shild_dar == 1)
                {
                    shild_dar = 0 ;
                    screen[mario_y][mario_x] = mario;
                }
                else
                {
                    --live;
                    if (live == 0)
                    {
                        printf("\033[J");
                        printf("\033[?25h");
                        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                        tcgetattr(STDIN_FILENO, &t);
                        t.c_lflag |= ICANON; 
                        t.c_lflag |= ECHO;    
                        tcsetattr(STDIN_FILENO, TCSANOW, &t);
                        fcntl(STDIN_FILENO, F_SETFL, 0);
                        return end_game2(0 , username);
                    }
                    screen[mario_y][mario_x] = ')';
                    mario_y = 12;
                    mario_x = 2;
                }
            }
            if (mario_y == 5 && mario_x == 56)
            {
                printf("\033[J");
                printf("\033[?25h");
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                tcgetattr(STDIN_FILENO, &t);
                t.c_lflag |= ICANON; 
                t.c_lflag |= ECHO;    
                tcsetattr(STDIN_FILENO, TCSANOW, &t);
                fcntl(STDIN_FILENO, F_SETFL, 0);
                return end_game2(1 , username);
            }
            if (mario_gharch == 1)screen[mario_y-1][mario_x] = mario;
            screen[mario_y][mario_x] = mario;
            render2(screen);
            usleep(120000);
        }

        if (mario_y == 12 && mario_x == simple_enemyx1)
        {
            if (shild_dar == 1)
            {
                shild_dar = 0;
                screen[mario_y][mario_x] = mario;
                simple_enemy1 = 0;
                screen[12][simple_enemyx1] = mario;
                simple_enemyx1 = 0;
            }
            else
            {
                if (mario_x == 2) simple_enemyx1 = 1;
                --live;
                if (live == 0)
                {
                    printf("\033[J");
                    printf("\033[?25h");
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    tcgetattr(STDIN_FILENO, &t);
                    t.c_lflag |= ICANON; 
                    t.c_lflag |= ECHO;    
                    tcsetattr(STDIN_FILENO, TCSANOW, &t);
                    fcntl(STDIN_FILENO, F_SETFL, 0);
                    return end_game2(0 , username);
                }
                screen[mario_y][mario_x] = ' ';
                mario_y = 12;
                mario_x = 2;
            }
        }
        if (mario_y == 25 && mario_x == simple_enemyx2)
        {
            if (shild_dar == 1)
            {
                shild_dar = 0;
                screen[mario_y][mario_x] = mario;
                simple_enemy2 = 0;
                screen[25][simple_enemyx2] = mario;
                simple_enemyx2 = 0;
            }
            else
            {
                --live;
                if (live == 0)
                {
                    printf("\033[J");
                    printf("\033[?25h");
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    tcgetattr(STDIN_FILENO, &t);
                    t.c_lflag |= ICANON; 
                    t.c_lflag |= ECHO;    
                    tcsetattr(STDIN_FILENO, TCSANOW, &t);
                    fcntl(STDIN_FILENO, F_SETFL, 0);
                    return end_game2(0 , username);
                }
                screen[mario_y][mario_x] = ' ';
                mario_y = 12;
                mario_x = 2;
            }

        }
        if (screen[mario_y][mario_x] == gharch_ch && gharch == 1)
        {
            gharch = 0;
            mario_gharch = 1; 
            screen[mario_y-1][mario_x] = mario; 
            render2(screen);          
        }
        if (mario_y == 12 && mario_x == simple_enemyx3)
        {
            if (shild_dar == 1)
            {
                shild_dar = 0;
                screen[mario_y][mario_x] = mario;
                simple_enemy3 = 0;
                screen[12][simple_enemyx3] = ' ';
                simple_enemyx3 = 0;
            }
            else
            {
                --live;
                if (live == 0)
                {
                    printf("\033[J");
                    printf("\033[?25h");
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    tcgetattr(STDIN_FILENO, &t);
                    t.c_lflag |= ICANON; 
                    t.c_lflag |= ECHO;    
                    tcsetattr(STDIN_FILENO, TCSANOW, &t);
                    fcntl(STDIN_FILENO, F_SETFL, 0);
                    return end_game2(0 , username);
                }
                screen[mario_y][mario_x] = ' ';
                mario_y = 12;
                mario_x = 2;
            }
        }
        if (mario_y == 10 && mario_x == simple_enemyx4)
        {
            if (shild_dar == 1)
            {
                shild_dar = 0;
                screen[mario_y][mario_x] = mario;
                simple_enemy4 = 0;
                screen[10][simple_enemyx4] = ' ';
                simple_enemyx4 = 0;
            }
            else
            {
                --live;
                if (live == 0)
                {
                    printf("\033[J");
                    printf("\033[?25h");
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    tcgetattr(STDIN_FILENO, &t);
                    t.c_lflag |= ICANON; 
                    t.c_lflag |= ECHO;    
                    tcsetattr(STDIN_FILENO, TCSANOW, &t);
                    fcntl(STDIN_FILENO, F_SETFL, 0);
                    return end_game2(0 , username);
                }
                screen[mario_y][mario_x] = ' ';
                mario_y = 12;
                mario_x = 2;
            }

        }
        if (mario_y == 12 && mario_x == 18 && star2 == 1)
        {
            star2 = 0;
            score++;
        }
        if (mario_y == 24 && mario_x == 35 && star3 == 1)
        {
            star3 = 0;
            score++;
        }
        if (mario_y == 21 && mario_x == 45 && star4 == 1)
        {
            star4 = 0;
            score++;
        }
        if (mario_y == 20 && mario_x == 46 && star5 == 1)
        {
            star5 = 0;
            score++;
        }
        if (mario_y == 25 && mario_x == 45 && star6 == 1)
        {
            star6 = 0;
            score++;
        }
        if (mario_y == 12 && mario_x == 52 && star7 == 1)
        {
            star7 = 0;
            score++;
        }
        if (screen[mario_y][mario_x] == ')')
        {
            if (shild_dar == 1)
            {
                shild_dar = 0;
                screen[mario_y][mario_x] = mario;
            }
            else
            {
                --live;
                if (live == 0)
                {
                    printf("\033[J");
                    printf("\033[?25h");
                    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                    tcgetattr(STDIN_FILENO, &t);
                    t.c_lflag |= ICANON; 
                    t.c_lflag |= ECHO;    
                    tcsetattr(STDIN_FILENO, TCSANOW, &t);
                    fcntl(STDIN_FILENO, F_SETFL, 0);
                    return end_game2(0 , username);
                }
                screen[mario_y][mario_x] = ')';
                mario_y = 12;
                mario_x = 2;
            }
        }
        if (mario_y == 5 && mario_x == 56)
        {
            printf("\033[J");
            printf("\033[?25h");
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            tcgetattr(STDIN_FILENO, &t);
            t.c_lflag |= ICANON; 
            t.c_lflag |= ECHO;    
            tcsetattr(STDIN_FILENO, TCSANOW, &t);
            fcntl(STDIN_FILENO, F_SETFL, 0);
            return end_game2(1 , username);        }
        if ((mario_y == 6 && mario_x == 25) || (mario_y == 6 && mario_x == 24))
        {
            screen[mario_y][mario_x] = empty;
            mario_y = 2;
            mario_x = 57;
        }
        ground = mario_y;
        if(mario_gharch == 1 && sit == 0)screen[mario_y-1][mario_x] = mario;
        screen[mario_y][mario_x] = mario;
        screen[25][0] = empty;
        render2(screen);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        long elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_nsec - start_time.tv_nsec) / 1000;
        if (elapsed_time < FRAME_DELAY) 
        {
            usleep(FRAME_DELAY - elapsed_time);
        }
    }
    printf("\033[J");
    printf("\033[?25h");
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON; 
    t.c_lflag |= ECHO;    
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    fcntl(STDIN_FILENO, F_SETFL, 0);
}
int end_game2(int lose ,char username[31])
{
    FILE *fp = popen("pgrep mpg123", "r");
    char pid[16];
    if (fgets(pid, sizeof(pid), fp) != NULL) 
    {
        pid[strcspn(pid, "\n")] = '\0';
        char command[64];
        snprintf(command, sizeof(command), "kill %s", pid);
        system(command);
    }
    pclose(fp);
    char line[151];
    FILE *file1 = fopen("informaition.txt" , "r");
    FILE *file2 = fopen("ch_information.txt" , "w");
    while(fgets(line , sizeof(line) , file1))
    {
        if (line[0] == ' ') break;
        int flag = 1; 
        int i;
        for (i = 0; i < strlen(username); ++i)
        {
            if (line[i] != username[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1 && username[i] == '\0' && line[i] == ' ')
        {
            int j = 0;
            while(line[j] != '\0') 
            {
                if (line[j] == '\n') 
                {
                    line[j] = '\0';
                    break;
                }
                ++j;
            }
            int k = 0;
            while(line[k] != '\0')
            {
                fprintf(file2, "%c", line[k]);
                ++k;
            }
            fprintf(file2, " ");
            if (lose == 0)fprintf(file2 , "0");
            else fprintf(file2 , "1");
            fprintf(file2, " ");
            fprintf(file2, "%i" , score);
            fprintf(file2, " ");
            emtiaz += live * 100;
            fprintf(file2, "%i" , emtiaz);
            fprintf(file2, "\n");
        }
        else fprintf(file2, "%s", line);
    }
    fclose(file1);
    fclose(file2);
    file1 = fopen("informaition.txt" , "w");
    file2 = fopen("ch_information.txt" , "r");
    char ch;
    while ((ch = fgetc(file2)) != EOF) 
    {
        fputc(ch, file1);
    }
    fclose(file1);
    fclose(file2);
    system("./menu.sh");
    system("nohup mpg123 -q sound.mp3 > /dev/null 2>&1 &");
    score = 0;
    emtiaz = 0;
    return menu2(username);
}