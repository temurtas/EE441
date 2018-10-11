#include <iostream>
#include "character.cpp" // class declaration of characters of game
#include <algorithm>     // included to use random_shuffle function
#include "stdlib.h"      // included to use abs function
#define Emax 200
#define Emin 100
using namespace std;
char fight (character* player, character* opponent,int number)
{   int A=player->getexp()*(1+(opponent->getlayer()-player->getlayer()/number));
    int B=(Emax-Emin)-abs(player->getexp()-opponent->getexp());
    int C= opponent->getexp();
    cout<<"Lose, Draw and Win intervals are: [0,"<<(A-1)<<"]-["<<(A)<<","<<(A+B-1)<<"]-["<<(A+B)<<","<<(A+B+C-1)<<"]"<<endl;
    int s=rand()%(A+B+C);
    cout<<"Random number is "<<s<<endl;
    if(0 <= s && s < A)
    {
      //lose case
      player->setexp(player->getexp()-(player->getexp()/opponent->getexp())*((player->getexp()-Emin)/2));
      opponent->setexp(opponent->getexp()+(player->getexp()/opponent->getexp())*((Emax-opponent->getexp())/3));
      if(player->getlayer() < opponent->getlayer())//organize layers
      {
          player->setlayer(opponent->getlayer()-1);//organize layers
      }
      else
      {
          opponent->setlayer(player->getlayer()+1);//organize layers
      }
      cout<<"Player lost against his opponent."<<endl;
      return 'l';
    }
    else if(A <= s && s < (A+B))
    {
      //draw case

      cout<<"It is draw."<<endl;
      cout<<"What you want to do="<<endl;
      cout<<"1.Fight back"<<endl;
      cout<<"2. Escape"<<endl;
      int dec;
      cin>>dec;
      if(dec==1)
      {
          player->setexp(player->getexp()-(player->getexp()/opponent->getexp())*((player->getexp()-Emin))/4);
          return fight(player,opponent,number);
      }
      else if (dec==2)
      {
          cout<<"Chicken-Hearted."<<endl;
          return 'd';
      }

    }
    else
    {
        //win case
        player->setexp(player->getexp()+(opponent->getexp()/player->getexp())*((Emax-player->getexp())/2));
        opponent->setexp(opponent->getexp()-(opponent->getexp()/player->getexp())*((opponent->getexp()-Emin)/3));
        if(player->getlayer() < opponent->getlayer())//organize layers
        {
            player->setlayer(opponent->getlayer()+1);//organize layers
        }
        else
        {
            opponent->setlayer(player->getlayer()-1);//organize layers
        }
        cout<<"Player won against his opponent."<<endl;
        return 'w';
    }
}

int main()
{

    int number_of_players;
    int* sequence_of_players;
    character* player_list;
    cout<<"Please Enter number of players:"<<endl;
    cin>>number_of_players;
    player_list=new character[number_of_players]; // holds the list of character
    sequence_of_players= new int [number_of_players]; // holds sequence of players
    for(int i=0;i<number_of_players;i++) sequence_of_players[i]=i;// initialize sequence
    cout<<"Please enter the number for winning condition which a player has to be on top layer:"<<endl;
    int tur_sayisi, counter=0;
    cin>>tur_sayisi;
    int max_layer_player=-1, prevwinner=-1;
    while(counter <= tur_sayisi)
    {
        //mix sequence of players
        random_shuffle(sequence_of_players,(sequence_of_players+number_of_players));
        //print sequence for this turn
        cout<<"Sequence in this round will be: ";
        for(int i=0;i<number_of_players;i++) cout<<*(sequence_of_players+i)<<",";
        cout<<endl;
        //start to this round
        for(int i=0;i<number_of_players;i++)
        {   int player=sequence_of_players[i];
            int decision;
            //ask user what he wants
            cout<<"Player_"<<player<<" What do you want to do:"<<endl;
            cout<<"1. Rest"<<endl;
            cout<<"2. Fight"<<endl;
            cout<<"3. Look player Status"<<endl;
            cin>>decision;
            do
            {
              if (decision == 1 || decision == 2)
            {
                switch(decision)
                {
                case 1: //rest case
                    if(player_list[player].getrest()==0)
                    {
                        //rest islemi yap resti set et
                        player_list[player].setexp(player_list[player].getexp()+(Emax-player_list[player].getexp())/2);
                        player_list[player].setrest(1);
                        break;
                    }
                    else
                    {
                        //rest yapamayacagini söyle fighta geçir
                        cout<<"Rest is not permitted."<<endl;
                    }
                case 2: //fight case
                    if(player_list[player].getparent()==-1)
                    {
                        //hür yasadim hür yasarim case
                        int opponent;
                        do
                        {
                            cout<<"Available players are: ";
                            for(int j=0;j<number_of_players;j++)
                            {
                                if(player_list[j].getparent()==-1 && j != player)
                                {
                                    cout<<j<<",";
                                }
                            }
                            cout<<endl;
                            cin>>opponent; //request opponent
                        }
                        while (player_list[opponent].getparent() != -1);// opponent da root degilse user root girene kadar dönude kalacak
                        char who_win=fight((player_list+player),(player_list+opponent),number_of_players);

                            if(who_win=='w')
                            {
                                player_list[opponent].setparent(player);//organize parent
                            }
                            else if(who_win=='l')
                            {
                                player_list[player].setparent(opponent);//organize parent
                            }
                        for(int j=0;j<number_of_players;j++)
                        {
                            for(int k=0;k<number_of_players;k++)
                            {
                                if(player_list[k].getparent()!=-1)
                                {
                                    player_list[k].setlayer(player_list[player_list[k].getparent()].getlayer()-1);
                                }
                            }
                        }
                    }
                    else
                    {
                        //basimm bagli sitayla
                        //sadece ustundeki adamla kapisabilecegini soyle
                        int bas;
                        do
                        {
                          cout<<"you can only fight with player_"<<player_list[player].getparent()<<endl;
                          cout<<"Please enter that number:"<<endl;
                          cin>>bas;
                        }
                        while(player_list[player].getparent() != bas);
                        char who_win=fight(player_list+player,player_list+bas,number_of_players);
                        if(who_win=='w')
                        {
                            player_list[player].setparent(player_list[bas].getparent());
                            player_list[bas].setparent(player);
                            //listi traverse et headi opponent olanları player ile player olanları opponent ile değiştir
                            for(int c=0; c<number_of_players; c++)
                            {
                                if(player_list[c].getparent()== player)
                                {
                                    player_list[c].setparent(bas);
                                }
                                else if(player_list[c].getparent()==bas)
                                {
                                    player_list[c].setparent(player);
                                }
                            }
                        }


                    }
                    player_list[player].setrest(0);
                    break;
                }
                if(player_list[player].getlayer() > max_layer_player) max_layer_player=player;
                else if(player_list[player].getlayer() == max_layer_player) max_layer_player=-1;
            }
            else if(decision==3)
            {
              int status;
              cout<<"Please Enter a player number:"<<endl;
              cin>>status;
              cout<<"Player_"<<status<<" has "<<player_list[status].getexp()<<" experience points"<<endl;
            }
            else
            {
                //þansýný kaybettin bro
                //-1 exp penalty olacagini soyle
                cout<<"You made a wrong decision and lost your turn. There will be -1 experience point penalty."<<endl;
                player_list[player].setexp(player_list[player].getexp()-1);
            }
            }
            while (decision==3);

       }
        //winner conditiona göre güncelle
        if(max_layer_player != -1)
        {
            if(prevwinner==max_layer_player)
                counter++;
            else
                counter=0;
            prevwinner=max_layer_player;
        }
        else
        {
            counter=0;
            prevwinner=-1;
        }
    }
    cout<<"Game Finished. Winner is Player_"<<prevwinner<<". Congratulations!"<<endl;
    delete []player_list;
    delete []sequence_of_players;
    return 0;
}
