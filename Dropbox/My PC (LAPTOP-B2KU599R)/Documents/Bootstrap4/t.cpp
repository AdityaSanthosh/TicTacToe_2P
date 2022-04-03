#include <iostream>
#include <set>

using namespace std;

char player = 'X';
bool MatchOver = false;
int n=0;
set<int> vec;
char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
void Draw()
{    
    system("cls");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << matrix[i][j]<<' ';
        }
        cout << '\n';   
    }
    cout<<'\n';
}
void Input()
{
    int a;
    cout<<"It's  "<<player<<" 's turn. Enter the number of the field"<<'\n';
    cout<<'\n';
    cin>>a;
    if(vec.find(a)==vec.end())
    {
        vec.insert(a);
    }
    else {
        cout<<"Sorry,the field is already occupied"<<'\n';
        cout<<"Please enter another field"<<'\n';
        Input();
    }
    if(a>9 || a<0)
    {
        cout<<"Invalid field."<<"  Please enter valid field number"<<'\n';
        cout<<'\n';
        cin>>a;
    }
    if(a==1)
    {
        matrix[0][0]=player;   
    }
    if(a==2)
    {
        matrix[0][1]=player;
    }
    if(a==3)
    {
        matrix[0][2]=player;
    }
    if(a==4)
    {
        matrix[1][0]=player;
    }
    if(a==5)
    {
        matrix[1][1]=player;
    }
    if(a==6)
    {
        matrix[1][2]=player;
    }
    if(a==7)
    {
        matrix[2][0]=player;
    }
    if(a==8)
    {
        matrix[2][1]=player;
    }
    if(a==9)
    {
        matrix[2][2]=player;
    }
}
void TogglePlayer()
{
    if(player=='X')
        player='O';
    else
        player='X';
}
void CheckWin()
{
    // checks if any row elements are equal 
    for(int i=0;i<3;i++)
    {
        if(matrix[i][0]==player && matrix[i][1]==player && matrix[i][2]==player)
        {
            MatchOver=true;
            break;
        }
    }
    // checks if any column elements are equal
    for(int j=0;j<3;j++)
    {
        if(matrix[0][j]==player && matrix[1][j]==player && matrix[2][j]==player)
        {
            MatchOver=true;
            break;
        }
    }
    // checks if left diagonal elements are equal
    if(matrix[0][0]==player && matrix[1][1]==player && matrix[2][2]==player)
    {
        MatchOver=true;
    }
    // checks if right diagonal elements are equal
    if(matrix[0][2]==player && matrix[1][1]==player && matrix[2][0]==player)
    {
        MatchOver=true;
    }
}
int main()
{
    Draw();
    while (1)
    {
        if(n==9)
        {
            cout<<"It's a draw"<<'\n';
            break;
        }
        Input();
        cout<<'\n';
        Draw();
        CheckWin();
        if(MatchOver)
        {
            cout<<"The Player "<<player<<" Won"<<'\n';
            break;
        }
        n++;
        TogglePlayer();
    }
    cout<<'\n';
    system("pause");
    return 0;
}