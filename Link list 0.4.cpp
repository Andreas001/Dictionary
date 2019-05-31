#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct node{
string kata;
string arti;
node *next=nullptr;
};

node *head=nullptr;

void print()
{
    node *curr;

    for (curr=head;curr!=nullptr;curr=curr->next)
    {
        cout << curr-> kata << ": " << curr->arti << endl;
    }
}

void searching(string kata)
{
    node *curr;
    curr = head;
    while (curr!= nullptr)
    {
        if (curr->kata == kata)
        {
            cout << curr->kata <<": " << curr->arti << endl;
            return;
        }
        curr=curr->next;
    }
    cout << "kata tidak ditemukan" << endl;
}

void delword(string kata)
{
    node *curr;
    node *temp;
    curr=head;
    int a=0,b=0;
    for(curr=head;curr!=nullptr;curr=curr->next)
    {
        a++;
    }
    for(curr=head;curr!=nullptr;curr=curr->next)
    {
        if(curr->kata != kata)
            b++;
    }
    if (a==b)
    {
        cout << "kata tidak ditemukan!" << endl;
        return;
    }

    while(curr!=nullptr)
    {
        if (head->kata == kata)
        {
            temp = head;
            head = head->next;
            delete temp;
            return;
        }

        if(curr->next->kata==kata)
        {
            temp = curr->next;
            curr->next = temp->next;
            delete temp;
            return;
        }
        curr=curr->next;
    }
}

void ins()
{
    node *curr;
    curr = head;
    ofstream textfile ("kamus.txt");
    if (textfile.is_open())
    {
        while(curr!=nullptr)
        {
            if(curr!=head)
            {
                textfile<<endl;
            }
            textfile << curr->kata << endl;
            textfile << curr->arti << endl;
            curr=curr->next;
        }
        textfile << "!";
    }
    else
        cout << "tidak dapat membuka file tujuan!";
}

void addnod(string kata, string arti)
{
    node *add,*last,*naw;
    add = new node;
    add->kata = kata;
    add->arti = arti;

    if(head==NULL)
    {
        add->next = head;
        head = add;
    }
    else
    {
        naw = head;
        last = head;
        while (naw && naw->kata < kata)
        {
            last = naw;
            naw = naw->next;
        }
        if (naw == head)
        {
            add->next = head;
            head = add;
        }
        else
        {
            last->next = add;
            add->next = naw;
        }
    }

}

int main()
{
    int itung,menu;
    itung = 0;
    ifstream textfile;
    textfile.open("kamus.txt");
    string arti;
    string kata;
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
    string tempo;
    while (textfile.eof()!=true)
    {
        textfile >> kata;
        if (kata==" " || kata == "!")
            break;
        kata[0]=toupper(kata[0]);
        textfile >> ws;
        getline(textfile,arti);
        addnod(kata,arti);
        itung++;
    }

    for (node *curr=head;curr!=nullptr;curr=curr->next)
    {
        tempo=curr->kata;
        if (tempo[0]=='A')
        {
            a++;
        }
        if (tempo[0]=='B')
        {
            b++;
        }
        if (tempo[0]=='C')
        {
            c++;
        }
        if (tempo[0]=='D')
        {
            d++;
        }
        if (tempo[0]=='E')
        {
            e++;
        }
        if (tempo[0]=='F')
        {
            f++;
        }
        if (tempo[0]=='G')
        {
            g++;
        }
        if (tempo[0]=='H')
        {
            h++;
        }
        if (tempo[0]=='I')
        {
            i++;
        }
        if (tempo[0]=='J')
        {
            j++;
        }
        if (tempo[0]=='K')
        {
            k++;
        }
        if (tempo[0]=='L')
        {
            l++;
        }
        if (tempo[0]=='M')
        {
            m++;
        }
        if (tempo[0]=='N')
        {
            n++;
        }
        if (tempo[0]=='O')
        {
            o++;
        }
        if (tempo[0]=='P')
        {
            p++;
        }
        if (tempo[0]=='Q')
        {
            q++;
        }
        if (tempo[0]=='R')
        {
            r++;
        }
        if (tempo[0]=='S')
        {
            s++;
        }
        if (tempo[0]=='T')
        {
            t++;
        }
        if (tempo[0]=='U')
        {
            u++;
        }
        if (tempo[0]=='V')
        {
            v++;
        }
        if (tempo[0]=='W')
        {
            w++;
        }
        if (tempo[0]=='X')
        {
            x++;
        }
        if (tempo[0]=='Y')
        {
            y++;
        }
        if (tempo[0]=='Z')
        {
            z++;
        }
    }

    while(true)
    {
        cout << " 0.Save & Exit\n 1.Insert\n 2.Print\n 3.Search\n 4.Delete\n 5.Words counting\n ";
        cout << "Input: ";
        cin >> menu;

        if(menu==0)
        {
            ins(); return 0;
        }
        else if(menu==1)
        {
            int alpha=0;

            while(true)
            {
            int leng=0;
            cout << "Masukkan kata: ";
            cin >> kata;

            kata[0]=toupper(kata[0]);
            if(kata.length()>36)
            {
                cout << "huruf harus kurang dari 36!" << endl;
                leng=1;
            }
            for (node *curr=head;curr!=nullptr;curr=curr->next)
            {
                if (curr->kata == kata)
                    alpha = 1;
            }
            if (alpha==1)
            {
                cout << "kata telah terdaftar di kamus!" << endl;
                break;
            }

            if (leng==0 && alpha == 0)
            {
                cout << "Masukkan arti: ";
                cin.ignore();
                getline(cin,arti);
                addnod(kata,arti);
                cout << endl;
                ++itung;
                break;
            }
            }
        }
        else if(menu==2)
        {
            print();
        }
        else if (menu==3)
        {
                int leng=0;
                cout << "Masukkan kata: ";
                cin >> kata;
                kata[0]=toupper(kata[0]);
                searching(kata);
        }
        else if (menu==4)
        {
            cout << "Masukkan kata yang akan di delete: ";
            cin >> kata;
            kata[0]=toupper(kata[0]);
            delword(kata);
            //print();
            --itung;
        }
        else if (menu==5)
        {
            cout << "jumlah kata dengan index huruf A: " << a << endl;
            cout << "jumlah kata dengan index huruf B: " << b << endl;
            cout << "jumlah kata dengan index huruf C: " << c << endl;
            cout << "jumlah kata dengan index huruf D: " << d << endl;
            cout << "jumlah kata dengan index huruf E: " << e << endl;
            cout << "jumlah kata dengan index huruf F: " << f << endl;
            cout << "jumlah kata dengan index huruf G: " << g << endl;
            cout << "jumlah kata dengan index huruf H: " << h << endl;
            cout << "jumlah kata dengan index huruf I: " << i << endl;
            cout << "jumlah kata dengan index huruf J: " << j << endl;
            cout << "jumlah kata dengan index huruf K: " << k << endl;
            cout << "jumlah kata dengan index huruf L: " << l << endl;
            cout << "jumlah kata dengan index huruf M: " << m << endl;
            cout << "jumlah kata dengan index huruf N: " << n << endl;
            cout << "jumlah kata dengan index huruf O: " << o << endl;
            cout << "jumlah kata dengan index huruf P: " << p << endl;
            cout << "jumlah kata dengan index huruf Q: " << q << endl;
            cout << "jumlah kata dengan index huruf R: " << r << endl;
            cout << "jumlah kata dengan index huruf S: " << s << endl;
            cout << "jumlah kata dengan index huruf T: " << t << endl;
            cout << "jumlah kata dengan index huruf U: " << u << endl;
            cout << "jumlah kata dengan index huruf V: " << v << endl;
            cout << "jumlah kata dengan index huruf W: " << w << endl;
            cout << "jumlah kata dengan index huruf X: " << x << endl;
            cout << "jumlah kata dengan index huruf Y: " << y << endl;
            cout << "jumlah kata dengan index huruf Z: " << z << endl << endl;
            cout << "TOTAL kata dalam kamus: " << itung << endl << endl;
        }
        else
            cout << "Masukkan angka 0-5!" << endl;
    }
}
