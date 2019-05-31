#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int start(vector <string>& kamus)
{
    ifstream file("kamus.txt");
    string line;
    if(file.is_open())
        {
            while(line != "!")
                {
                    getline(file, line);
                    kamus.push_back(line);
                }
            file.close();
        }
    else
        {
            cout<<"\nError, tidak bisa membuka text file atau text file tidak ada."<<endl;
            cout<<"Tolong memulai kembali program."<<endl;
            return 0;
        }
}

void finish(vector <string> kamus)
{
    ofstream file("kamus.txt");

    if(file.is_open())
        {
            for(int i = 0; i < kamus.size(); i++)
                {
                    file<<kamus[i]<<endl;
                }
            cout<<"Semua perubahan yang dibuat akan disimpan."<<endl;
            file.close();
        }
    else
        {
            cout<<"\nError, tidak bisa membuka text file atau text file tidak ada."<<endl;
            cout<<"Semua perubahan tidak dapat disimpan"<<endl<<"Tolong restart program."<<endl;
        }
}

void sortWord(vector <string>& kamus)
{
    vector <string> sortedList, sorted;
    for(int i = 0; i < kamus.size(); i++)
        {
            if(i == 0 || i%2 == 0)
                {
                    if(kamus[i] != "!")
                        {
                            sortedList.push_back(kamus[i]);
                        }
                }
        }

    sort(sortedList.begin(), sortedList.end());

    for(int i = 0; i < sortedList.size(); i++)
        {
            for(int y = 0; y < kamus.size(); y++)
                {
                    if(y == 0 || y%2 == 0)
                        {
                            if(sortedList[i] == kamus[y] && kamus[y] != "!")
                                {
                                    sorted.push_back(kamus[y]);
                                    sorted.push_back(kamus[y+1]);
                                    break;
                                }
                        }
                }
        }

    for(int i = 0; i < sorted.size(); i++)
        {
            kamus[i] = sorted[i];
        }
}

void search(vector <string>& kamus)
{
    string input;
    cout<<"\nTolong ketik kata yang ingin dicari : ";
    cin>>input;
    cout<<endl;

    for(int i = 0; i < kamus.size(); i++)
        {
            if(kamus[i] == input)
                {
                    cout<<kamus[i]<<endl;
                    cout<<kamus[i+1]<<endl;
                    break;
                }
            else if(kamus[i] == "!")
                {
                    cout<<"Kata tersebut tidak ada di dalam text file."<<endl;
                    return;
                }
        }
}

void insert(vector <string>& kamus)
{
    string input, word; bool available, found = 0;

    cout<<"\nTolong ketik kata yang ingin dimasukkan : ";
    do
        {
             available = 1;
             cin>>input;
             cout<<endl;
             if(input.length() > 36)
                {
                    cout<<"Kata tidak boleh melebihi dari 36 huruf."<<endl;
                    cout<<"\nTolong ketik kata yang ingin dimasukkan : ";
                    available = 0;
                }

            if(available)
                {
                    for(int i = 0; i < kamus.size(); i++)
                        {
                            if(i == 0 || i&2 == 0)
                                {
                                    if(kamus[i] == input)
                                        {
                                            cout<<"Kata tersebut sudah ada di dalam text file."<<endl;
                                            found = 1;
                                            break;
                                        }
                                    else if(kamus[i] == "!")
                                        {
                                            found = 0;
                                        }
                                }
                        }
                }
        }while(input.length() > 36 || found);

    word = input;
    cin.ignore(32767,'\n');
    cin.clear();
    string toRemove = "!";
    kamus.erase(remove(kamus.begin(), kamus.end(), toRemove), kamus.end());
    kamus.push_back(input);

    cout<<"Tolong ketik definisi dari kata tersebut : ";
    do
        {
            getline(cin, input);
            if(input.length() > 100)
                {
                    cout<<"Definisi tidak boleh melebihi dari 100 huruf."<<endl;
                    cout<<"Tolong ketik definisi dari kata tersebut : ";
                }
        }while(input.length() > 100);
    kamus.push_back(input);
    kamus.push_back(toRemove);
    cout<<"Kata "<<word<<" telah ditambahkan."<<endl;

    sortWord(kamus);
}

void deleteWord(vector <string>& kamus)
{
    string input;
    int word = 0;

    for(int i = 0; i < kamus.size(); i++)
        {
            if(i == 0 || i%2 == 0)
                {
                    if(kamus[i] != "!")
                        {
                            word++;
                        }
                }
        }

    if(word > 0)
        {
            cout<<"\nAda sebanyak "<<word<<" kata yang bisa dihapus."<<endl;
            cout<<"Tolong ketik kata yang ingin dihapuskan : ";
            cin>>input;

            for(int i = 0; i < kamus.size(); i++)
                {
                    if(i == 0 || i%2 == 0)
                        {
                            if(kamus[i] == input)
                                {
                                    string toRemoveDef = kamus[i+1];
                                    kamus.erase(remove(kamus.begin(), kamus.end(), input), kamus.end());
                                    kamus.erase(remove(kamus.begin(), kamus.end(), toRemoveDef), kamus.end());
                                    cout<<"Kata "<<input<<" telah dihapuskan."<<endl;
                                    break;
                                }
                        }
                    else if(kamus[i] == "!")
                        {
                            cout<<"Kata tersebut tidak ada didalam text file."<<endl;
                            return;
                        }
                }
            sortWord(kamus);
        }
    else
        {
            cout<<"\nText file tidak mengandung kata apapun.";
            return;
        }
}

void countWord(vector <string> kamus)
{
    int wordCount = 0, letterCount = 0;

    for(int i = 0; i < kamus.size(); i++)
        {
            if(i == 0 || i%2 == 0)
                {
                    if(kamus[i] != "!")
                        {
                            letterCount = letterCount + kamus[i].length();
                            wordCount++;
                        }
                }
        }

    if(wordCount > 0 && letterCount > 0)
        {
            cout<<"\nAda sebanyak "<<wordCount<<" kata"<<endl;
            cout<<"Dengan total "<<letterCount<<" huruf."<<endl;
        }
    else
        {
            cout<<"\nText file tidak mengandung kata apapun.";
            return;
        }
}

void print(vector <string>& kamus)
{
    cout<<"\nDaftar kata : ";

    if(kamus[0] == "!")
        {
            cout<<"\nText file tidak mengandung kata apapun.";
            return;
        }

    for(int i = 0; i < kamus.size()-1; i++)
        {
            if(i == 0 || i%2 == 0)
                {
                    cout<<kamus[i];
                    if(kamus[i+2] != "!")
                        {
                            cout<<" ,";
                        }
                }
        }
    cout<<endl;
}

int main()
{
    vector <string> kamus;
    string command;
    bool status = 1;
    status = start(kamus);
    if(status == 0)
        {
            return 0;
        }
    cout<<"Perintah : 0.selesai|1.cari|2.masuk|3.hapus|4.hitung|5.print"<<endl;
    cout<<"0 = selesai dan menyimpan, 1 = mencari definisi kata, 2 = menambahkan kata ke daftar"<<endl;
    cout<<"3 = menghapus kata dari daftar, 4 = menghitung jumlah kata dan huruf, 5 = men display daftar kata."<<endl;
    cout<<"Warning : Keluar dari program tanpa eksekusi perintah 0 tidak akan menyimpan perubahan apapun!"<<endl;
    while (1)
        {
            cout<<"\nKetik sebuah perintah : ";
            cin>>command;
            if(command == "0")
                {
                    finish(kamus);
                    return 0;
                }
            else if(command == "1")
                {
                    search(kamus);
                }
            else if(command == "2")
                {
                    insert(kamus);
                }
            else if(command == "3")
                {
                    deleteWord(kamus);
                }
            else if(command == "4")
                {
                    countWord(kamus);
                }
            else if(command == "5")
                {
                    print(kamus);
                }
            else
                {
                    cout<<"Error, perintah tidak dikenali"<<endl;
                }
        }
}
