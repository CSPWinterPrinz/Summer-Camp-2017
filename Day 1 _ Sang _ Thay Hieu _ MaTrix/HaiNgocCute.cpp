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
    ClearConsoleToColors(0 , 4);
    SetColor(10);
    cout << endl << endl << endl;cout << endl << endl << endl;
    delay(5);
    cout << "                    :H    :H       :A       :P:P     :P:P     :Y    :Y" << endl;delay(1);
    cout << "                    :H    :H     :A  :A     :P  :P   :P  :P    :Y  :Y" << endl;delay(1);
    cout << "                    :H:H:H:H    :A:A:A:A    :P:P     :P:P        :Y" << endl;delay(1);
    cout << "                    :H    :H    :A    :A    :P       :P          :Y" << endl;delay(1);
    cout << "          __________:H    :H    :A    :A    :P       :P          :Y__________" << endl;delay(1);
    cout << endl << endl;

    ClearConsoleToColors(0 , 5);
    SetColor(14);
    cout << endl << endl;cout << endl << endl << endl;cout << endl << endl << endl;cout << endl << endl;
    cout << ":B:B:B     :I:I:I:I    :R:R:   :T:T:T:T:T   :H    :H   :D:D:D         :A     :Y    :Y    "<< endl;delay(1);
    cout << ":B    :B      :I       :R  :R      :T       :H    :H   :D    :D     :A  :A    :Y  :Y         " << endl;delay(1);
    cout << ":B:B:B:       :I       :R:R:       :T       :H:H:H:H   :D     :D   :A:A:A:A     :Y           " << endl;delay(1);
    cout << ":B    :B      :I       :R :R       :T       :H    :H   :D    :D    :A    :A     :Y           " << endl;delay(1);
    cout << ":B:B:B     :I:I:I:I    :R  :R      :T       :H    :H   :D:D:D      :A    :A     :Y      " << endl;delay(1);
    cout << endl << endl;

    ClearConsoleToColors(0 , 4);
    SetColor(13);
    cout << endl << endl;cout << endl << endl << endl;cout << endl << endl << endl;cout << endl;
    cout << "           :F:F:F:F      :O:O:O     :R:R:        :Y    :Y      :A          :A             "   << endl;delay(1);
    cout << "           :F           :O    :O    :R  :R        :Y  :Y     :A  :A      :A  :A          "    << endl;delay(1);
    cout << "           :F:F:F       :O    :O    :R:R:           :Y      :A:A:A:A    :A:A:A:A           "     << endl;delay(1);
    cout << "           :F           :O    :O    :R :R           :Y      :A    :A    :A    :A         "   << endl;delay(1);
    cout << " __________:F            :O:O:O     :R  :R          :Y      :A    :A    :A    :A   _________   " << endl;delay(1);


    ClearConsoleToColors(0 , 15);
    SetColor(12);

    ClearConsoleToColors(0 , 15);
    SetColor(9);
    cout << endl << endl;
    cout << "                                :?:?                " << endl;        delay(1);
    cout << "                                 :?                 "  << endl << endl;delay(1);
    cout << " *   *   *        <3    <3       <3      <3<3<3<3   " << endl;delay(1);
    cout << "   * * *          <3    <3     <3  <3       <3      " << endl;delay(1);
    cout << " * * * * *        <3<3<3<3    <3<3<3<3      <3      " << endl;delay(1);
    cout << "   * * *          <3    <3    <3    <3      <3      " << endl;delay(1);
    cout << " *   *   *        <3    <3    <3    <3   <3<3<3<3   " << endl;delay(1);
    cout << endl << endl;

    cout << "                       <3    <3  <3<3<3<3   <3<3<3     <3<3<3          *   *   *" << endl;delay(1);
    cout << "                       <3<3  <3  <3        <3    <3  <3                  * * *  " << endl;delay(1);
    cout << "                       <3 <3 <3  <3  <3    <3    <3  <3                * * * * *" << endl;delay(1);
    cout << "                       <3  <3<3  <3    <3  <3    <3  <3                  * * *  " << endl;delay(1);
    cout << "                       <3    <3  <3<3<3<3   <3<3<3    <3<3<3           *   *   *" << endl;delay(1);
    cout << "                                              ::" << endl;delay(1);
    cout << "                                              .." << endl;delay(1);
    cout << endl << endl;

    cout << endl << endl;
    cout << "         :$:$:$   :$     :$   :$:$:$:$    :$:$:$:$                             " << endl;delay(1);
    cout << "       :$         :$     :$      :$       :$             ~~~~~~~~~~~~~~~~~                      "  << endl;delay(1);
    cout << "       :$         :$     :$      :$       :$:$:$:$       -----------------                        " << endl;delay(1);
    cout << "       :$         :$     :$      :$       :$             =================                " << endl;delay(1);
    cout << "         :$:$:$    :$:$:$:       :$       :$:$:$:$                        " << endl;delay(1);delay(1);delay(1);

    ClearConsoleToColors(0 , 15);
    SetColor(9);

        cout << endl << endl;
    cout << "             ^^                                  ^^" << endl;
    cout << "           ^^  ^^                              ^^  ^^" << endl;
    cout << "         ^^      ^^                          ^^      ^^" << endl;
    cout << "       ^^          ^^                      ^^          ^^" << endl;
    cout << "     ^^              ^^                  ^^              ^^" << endl;
    cout << "   ^^                  ^^              ^^                  ^^" << endl;





    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "                         ______________                      " << endl;
    cout << endl << endl << endl;

    ClearConsoleToColors(0 , 0);
    SetColor(10);
    cout << endl << endl;
    cout << "                         '-^-.......''.......-^-'" << endl;
    cout << "                      '$.$.$.$......''.....$.$.$.$.'" << endl;
    cout << "                    '$.$.$.$.$.$....''....$.$.$.$.$.$'" << endl;
    cout << "                  '$.$.$.$.$.$.$.$._''_.$.$.$.$.$.$.$.$'" << endl;
    cout << "                 '$.$.$HAINGOC$.$.$...$.$.$.HAINGOC$.$.$'" << endl;
    cout << "                 '$.$.$.=)))$.$.$.$.~~$.$.$.$=)))$.$.$.$'" << endl;
    cout << "                  '$.$.$.$.$.$.$.$.$==$.$.$.$.$.$.$.$.$'" << endl;
    cout << "                   '$.$.$$.$.$.$.$.$.$.$.$.$.$.$.$.$.$'" << endl;
    cout << "                     '$.$.$.$.$.$.$.$.$.$.$.$.$.$.$.'" << endl;
    cout << "                        '$.$.$.$.I.$.$.Y.$.$.$.$.'" << endl;
    cout << "                          '$.$.$.$.$L$.$.$.$.$.'" << endl;
    cout << "                            '$.$.$.$.$.$.$.$.'" << endl;
    cout << "                              '$.$.$.$.$.$.'" << endl;
    cout << "                                '$.$.$.$.'" << endl;
    cout << "                                  '2412'" << endl;
    cout << "                                    17" << endl;


   // ClearConsoleToColors(0 , 14);
   // SetColor(12);

    int BHN;
    cout << "THANK YOU =)))" << endl;
    cout << "I WISH YOU A HAPPY FUNNY SURPRISED BIRTHDAY =)))" << endl;
    cout << "SEE YOU SOON ~~" << endl;
    cin >> BHN;
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
                   ""

*/

////-------------------------------\\\\


