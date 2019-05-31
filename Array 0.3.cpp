#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int start(string kamus[], int size[])
{
    ifstream file("kamus.txt");
    string line;
    int counter = -1;

    if(file.is_open())
        {
            while(line != "!")
                {
                    size[0]++;
                    counter++;
                    getline(file, line);
                    kamus[counter] = line;
                }
            size[0]++;
            counter++;
            cout<<counter<<" "<<size[0];
            file.close();
        }
    else
        {
            cout<<"\nError, tidak bisa membuka text file atau text file tidak ada."<<endl;
            cout<<"Tolong restart program."<<endl;
            return 0;
        }
}

void finish(string kamus[], int size[])
{
    ofstream file("kamus.txt");

    if(file.is_open())
        {
            for(int i = 0; i < size[0]; i++)
                {
                    file<<kamus[i]<<endl;
                    if(kamus[i] == "!")
                        {
                            break;
                        }
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

void sortWord(string kamus[], int size[])
{
    int number = 0, counter = 0;
    string sorted[2001], sortedList[2001];

    for(int i = 0; i < size[0]; i++)
        {
            if(i == 0 || i%2 == 0)
                {
                    if(kamus[i] != "!")
                        {
                            sorted[counter] = kamus[i];
                            counter++;
                        }
                }
            else if(kamus[i] == "!")
                {
                    break;
                }
        }

    number = counter;
    sort(sorted, sorted+counter);
    counter = 0;

    for(int i = 0; i < number; i++)
        {
            for(int y = 0; y < size[0]; y++)
                {
                    if(y == 0 || y%2 == 0)
                        {
                            if(sorted[i] == kamus[y])
                                {
                                    sortedList[counter] = kamus[y];
                                    sortedList[counter+1] = kamus[y+1];
                                    counter += 2;
                                    break;
                                }
                        }
                }
        }

    for(int i = 0; i < counter; i++)
        {
            kamus[i] = sortedList[i];
        }
}

void search(string kamus[], int size[])
{
    string input;
    cout<<"\nTolong ketik kata yang ingin dicari : ";
    cin>>input;
    cout<<endl;

    for(int i = 0; i < size[0]; i++)
        {
            if(i == 0 || i%2 == 0)
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
                        }
                }
        }
}

void insert(string kamus[], int size[])
{
    string input, word;
    bool found = 0, available;

    do
        {
            cout<<"\nTolong ketik kata yang ingin dimasukkan : ";
             available = 1;
             cin>>input;
             cout<<endl;
             word = input;
             cin.ignore(32767,'\n');
             cin.clear();
             if(input.length() > 36)
                {
                    cout<<"Kata tidak boleh melebihi dari 36 huruf."<<endl;
                    cout<<"\nTolong ketik kata yang ingin dimasukkan : ";
                    available = 0;
                }

            if(available)
                {
                    for(int i = 0; i < size[0]; i++)
                        {
                            if(input == kamus[i])
                                {
                                    cout<<"Kata tersebut sudah ada di dalam text file."<<endl;
                                    found = 1;
                                    break;
                                }
                            else if(kamus[i] == "!")
                                {
                                    kamus[i] = input;
                                    cout<<"Tolong ketik definisi dari kata tersebut : ";
                                    do
                                        {
                                            getline(cin, input);
                                            if(input.length() > 100)
                                               {
                                                   cout<<"Kata tidak boleh melebihi dari 36 huruf."<<endl;
                                                   cout<<"Tolong ketik definisi dari kata tersebut : ";
                                               }
                                        }while(input.length() > 100);
                                    kamus[i+1] = input;
                                    kamus[i+2] = "!";
                                    cout<<"Kata "<<word<<" telah ditambahkan."<<endl;
                                    size[0] = size[0] + 2;
                                    sortWord(kamus, size);
                                    return;
                                }
                        }
                }
        }while(input.length() > 36 || found);
}

void deleteWord(string kamus[], int size[])
{
    string input, temp1, temp2;
    int word = 0;

    for(int i = 0; i < size[0]; i++)
        {
            if(i == 0 || i%2 == 0)
                {
                    if(kamus[i] != "!")
                        {
                            word++;
                        }
                    else if(kamus[0] == "!")
                        {
                            break;
                        }
                }
        }

    if(word > 0)
        {
            cout<<"\nAda sebanyak "<<word<<" kata yang bisa dihapus."<<endl;
            cout<<"Tolong ketik kata yang ingin dihapuskan : ";
            cin>>input;

            for(int i = 0; i < size[0]; i++)
                {
                    if(i == 0 || i%2 == 0)
                        {
                            if(kamus[i] == input)
                                {
                                    if(kamus[i+2] == "!")
                                        {
                                            kamus[i] = "!";
                                            kamus[i+1] = "empty";
                                            kamus[i+2] = "empty";
                                            cout<<"Kata "<<input<<" telah dihapuskan."<<endl;
                                            size[0] = size[0] - 2;
                                            break;
                                        }
                                    else
                                        {
                                            for(int y = 0; y < size[0]; y++)
                                                {
                                                    if(kamus[y+2] == "!")
                                                        {
                                                            temp1 = kamus[y];
                                                            temp2 = kamus[y+1];
                                                            kamus[y] = "!";
                                                            kamus[y+1] = "empty";
                                                            kamus[y+2] = "empty";
                                                            kamus[i] = temp1;
                                                            kamus[i+1] = temp2;
                                                            cout<<"Kata "<<input<<" telah dihapuskan."<<endl;
                                                            size[0] = size[0] - 2;
                                                            sortWord(kamus, size);
                                                            break;
                                                        }
                                                }
                                            break;
                                        }
                                }
                            else if(kamus[i] == "!")
                                {
                                    cout<<"\nKata tersebut tidak ada didalam text file."<<endl;
                                    return;
                                }
                        }
                }
        }
    else
        {
            cout<<"\nText file tidak mengandung kata apapun.";
        }
}

void countWord(string kamus[], int size[])
{
    int wordCount = 0, letterCount = 0;

    for(int i = 0; i < size[0]; i++)
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
        }
}

void print(string kamus[], int size[])
{
    cout<<"\nDaftar kata : ";

    if(kamus[0] == "!")
        {
            cout<<"\nText file tidak mengandung kata apapun.";
            return;
        }

    for(int i = 0; i < size[0]; i++)
        {
            if(i == 0 || i%2 == 0)
                {
                    if(kamus[i] != "!")
                        {
                            cout<<kamus[i];
                            if(kamus[i+2] != "!")
                                {
                                    cout<<" ,";
                                }
                        }
                }
        }
    cout<<endl;
}

int main()
{
    int size[1] = {-1};
    string kamus[2001] = {"empty"}, command;
    int status =  start(kamus, size);
    switch(status)
    {
        case 0 : return 0;
    }
    cout<<"Perintah : 0.selesai|1.cari|2.masuk|3.hapus|4.hitung|5.print"<<endl;
    cout<<"0 = selesai dan menyimpan, 1 = mencari definisi kata, 2 = menambahkan kata ke daftar"<<endl;
    cout<<"3 = menghapus kata dari daftar, 4 = menghitung jumlah kata dan huruf, 5 = men display daftar kata."<<endl;
    cout<<"Warning : Keluar dari program tanpa eksekusi perintah 0 tidak akan menyimpan perubahan apapun!"<<endl;
    while(1)
        {
            cout<<"\nKetik sebuah perintah : ";
            cin>>command;
            if(command == "0")
                {
                    finish(kamus, size);
                    return 0;
                }
            else if(command == "1")
                {
                    search(kamus, size);
                }
            else if(command == "2")
                {
                    insert(kamus, size);
                }
            else if(command == "3")
                {
                    deleteWord(kamus, size);
                }
            else if(command == "4")
                {
                    countWord(kamus, size);
                }
            else if(command == "5")
                {
                    print(kamus, size);
                }
            else
                {
                    cout<<"Error, perintah tidak dikenali"<<endl;
                }
        }
}
