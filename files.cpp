#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void MoveFromF1toF2()
{
    string line = "";
    int spaces  = 0;
    int i       = 1;
    
    ifstream in("file1.txt");
    ofstream out("file2.txt", ios::app);
    
    cout << "№ 1\n";
    
    if (in.is_open())
    {
        while (getline(in, line))
        {   
            spaces = count(line.begin(), line.end(), ' ');
            cout << i << ": '" << line << "' — " << spaces << " пробелов";
            if (spaces == 0)
            {
                cout << " => записывается\n";
                out << line << "\n";
            }
            else{
                cout << " => не записывается\n";
            }
            i++;
        }
    }
    
    in.close();  
    out.close();
}


void CheckOfConsonant()
{
    
    char vowels[12] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    string line     = "";
    int vow         = 0;
    int cons        = 0;
    int k           = 1;
    int max         = 0;
    int number      = 0;
    
    ifstream in("file2.txt");
    
    cout << "\n\n№ 2\n";
    
    if (in.is_open())
    {
        while (getline(in, line))
        {   
            for (int j = 0; j < 12; j++)
            {
                vow += count(line.begin(), line.end(), vowels[j]);
            }
            cons = line.size() - vow;
            cout << k << ": '" << line << "' — " << cons << " согласных\n";
            
            if (max <= cons)
            {
                max = cons;
                number = k;
            }
            
            k++;
            vow = 0;
        }
        cout << "\nСлово №" << number << " содержит больше всего гласных";
    }
    
    in.close();  
}


int main()
{
    MoveFromF1toF2();
    CheckOfConsonant();
    return 0;
}
