#include<bits/stdc++.h>
#include<stdlib.h>
#include <windows.h>
#include <dos.h>

using namespace std;
void delay(int seconds)
{
    time_t start, current;

    time(&start);

    do
    {
        time(&current);
    }
    while ((current - start) < seconds);
}

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

        ///Use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        ///Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void ClearConsoleToColors(int ForgC, int BackC)
 {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                     //This is used to reset the carat/cursor to the top left.
    COORD coord = {0, 0};
                  //A return value... indicating how many chars were written
                    //   not used but we need to capture this since it will be
                      //   written anyway (passing NULL causes an access violation).
    DWORD count;

                               //This is a structure containing all of the console info
                      // it is used here to find the size of the console.
    CONSOLE_SCREEN_BUFFER_INFO csbi;
                 //Here we will set the current color
    SetConsoleTextAttribute(hStdOut, wColor);

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
                          //This fills the buffer with a given character (in this case 32=space).
        FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                          //This will set our cursor position for the next print statement.
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}

int main()
{
  //  ClearConsoleToColors(0 , 4);
   // SetColor(10);
   // ClearConsoleToColors(0 , 15);
    SetColor(10);
    cout << "I also wanna sayy : ";
    cout << endl << endl << endl;cout << endl << endl << endl;
   // delay(30);
    cout << "                       :G:G:G     :O:O:O     :O:O:O   :D:D:D        :B:B:B     :Y    :Y   :E:E:E:E                       " << endl;delay(1);
    cout << "                      :G         :O    :O   :O    :O  :D    :D      :B    :B    :Y  :Y    :E                             " << endl;delay(1);
    cout << "                      :G  :G:G   :O    :O   :O    :O  :D    :D      :B:B:B        :Y      :E:E:E:E                       " << endl;delay(1);
    cout << "                      :G    :G   :O    :O   :O    :O  :D    :D      :B    :B      :Y      :E                             " << endl;delay(1);
    cout << "             __________:G:G:G     :O:O:O     :O:O:O   :D:D:D        :B:B:B        :Y      :E:E:E:E      __________       " << endl;delay(1);
    cout << endl << endl;




    ClearConsoleToColors(0 , 15);
    SetColor(9);
    cout << endl << endl;

    cout << "                           *   *   *        <3        <3       <3      <3<3<3<3        *   *   *                    " << endl;delay(1);
    cout << "                             * * *          <3 <3  <3 <3     <3  <3       <3             * * *                      " << endl;delay(1);
    cout << "                           * * * * *        <3   <3   <3    <3<3<3<3      <3           * * * * *                    " << endl;delay(1);
    cout << "                             * * *          <3        <3    <3    <3      <3             * * *                      " << endl;delay(1);
    cout << "                           *   *   *        <3        <3    <3    <3   <3<3<3<3        *   *   *                    " << endl;delay(1);
    cout << endl << endl;

    cout << endl << endl;
    cout << "                                          :$:$:$   :$     :$   :$:$:$:$    :$:$:$:$                                 " << endl;delay(1);
    cout << "                  ~~~~~~~~~~~~~~~~~     :$         :$     :$      :$       :$             ~~~~~~~~~~~~~~~~~         "  << endl;delay(1);
    cout << "                  -----------------     :$         :$     :$      :$       :$:$:$:$       -----------------         " << endl;delay(1);
    cout << "                  =================     :$         :$     :$      :$       :$             =================         " << endl;delay(1);
    cout << "                                          :$:$:$    :$:$:$:       :$       :$:$:$:$                                 " << endl;delay(1);delay(1);delay(1);

    ClearConsoleToColors(0 , 4);
    SetColor(13);
    cout << endl << endl;cout << endl << endl << endl;cout << endl << endl << endl;cout << endl;
    cout << "                             :S:S:S     :E:E:E:E    :E:E:E:E       :Y    :Y   :O:O:O    :U     :U                   "   << endl;delay(1);
    cout << "                            :S          :E          :E              :Y  :Y   :O    :O   :U     :U                   "    << endl;delay(1);
    cout << "                             :S:S:S     :E:E:E:E    :E:E:E:E          :Y     :O    :O   :U     :U                   "     << endl;delay(1);
    cout << "                                  :S    :E          :E                :Y     :O    :O   :U     :U                   "   << endl;delay(1);
    cout << "             __________      :S:S:S     :E:E:E:E    :E:E:E:E          :Y      :O:O:O     :U:U:U:       _________   " << endl;delay(1);

        ClearConsoleToColors(0 , 5);
    SetColor(14);
    cout << endl << endl;cout << endl << endl << endl;cout << endl << endl << endl;cout << endl << endl;
    cout << "                                         :S:S:S      :O:O:O     :O:O:O     :N    :N                                "   << endl;delay(1);
    cout << "                                        :S          :O    :O   :O    :O    :N:N  :N                                "    << endl;delay(1);
    cout << "                                         :S:S:S     :O    :O   :O    :O    :N :N :N                                "     << endl;delay(1);
    cout << "                                              :S    :O    :O   :O    :O    :N  :N:N                                "   << endl;delay(1);
    cout << "             _._._._._._._._._._._       :S:S:S      :O:O:O     :O:O:O     :N    :N        _._._._._._._._._._._   " << endl;delay(1);


    ClearConsoleToColors(0 , 15);
    SetColor(9);

    cout << endl << endl;
    cout << "                                          ^^                                  ^^" << endl;
    cout << "                                        ^^  ^^                              ^^  ^^" << endl;
    cout << "                                      ^^      ^^                          ^^      ^^" << endl;
    cout << "                                    ^^          ^^                      ^^          ^^" << endl;
    cout << "                                  ^^              ^^                  ^^              ^^" << endl;
    cout << "                                ^^                  ^^              ^^                  ^^" << endl;


    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "                                                      ______________                      " << endl;
    cout << endl << endl << endl;

    string VLM;
    cout << "See you again in VOI =)))) I'll try hard to meet you heheee =)))))";
    cin >> VLM;
}


/*
        '-^-.......''.......-^-'
     '$.$.$.$......''.....$.$.$.$.'
   '$.$.$.$.$.$....''....$.$.$.$.$.$'
 '$.$.$.$.$.$.$.$._''_.$.$.$.$.$.$.$.$'
'$.$.$.$.$.$.$.$.$...$.$.$.$.$.$.$.$.$.'
'$.$.$.$.$.$.$.$.$.~~$.$.$.$.$.$.$.$.$.'
 '$.$.$.$.$.$.$.$.$==$.$.$.$.$.$.$.$.$'
  '$.$.$.$.$.$.$.$.$.$.$.$.$.$.$.$.$.'
    '$.$.$.$.$.$.$.$.$.$.$.$.$.$.$.'
       '$.$.$.$.$.$.$.$.$.$.$.$.'
         '$.$.$.$.$.$.$.$.$.$.'

           '$.$.$.$.$.$.$.$.'
             '$.$.$.$.$.$.'
               '$.$.$.$.'
                 '$.$.'
                   "".....................

*/

////-------------------------------\\\\


