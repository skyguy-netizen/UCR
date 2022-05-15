#include <iostream>
#include "Playlist.h"

using namespace std;

void PrintMenu(string playlistname)
{
    cout << playlistname << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl
         << "d - Remove song" << endl
         << "c - Change position of song" << endl
         << "s - Output songs by specific artist" << endl
         << "t - Output total time of playlist (in seconds)" << endl
         << "o - Output full playlist" << endl
         << "q - Quit" << endl
         << endl
         << "Choose an option:" << endl;
}

int main()
{
    string name;
    cout << "Enter playlist's title:";
    // cin.ignore(1);
    getline(cin, name);
    cout << endl
         << endl;
    PrintMenu(name);
    char option;
    cin >> option;
    PlaylistNode *mainHead = nullptr;
    PlaylistNode *mainTail = nullptr;
    while (option != 'q')
    {
        if (option == 'a')
        {
            string Id;
            string name;
            string artistName;
            int songlength;
            cout << endl;
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> Id;
            cout << "Enter song's name:" << endl;
            cin.ignore(1);
            getline(cin, name);
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> songlength;
            cout << endl;
            PlaylistNode *temp = new PlaylistNode(Id, name, artistName, songlength, 0);
            if (mainHead == nullptr)
            {
                mainHead = temp;
                mainTail = temp;
            }
            else
            {
                mainTail->InsertAfter(temp);
                mainTail = temp;
            }
        }
        else if (option == 'd')
        {
            cout << endl
                 << endl
                 << "REMOVE SONG" << endl;
            string id;
            cout << "Enter song's unique ID:" << endl;
            cin >> id;
            PlaylistNode *temp = mainHead;
            if (mainHead->GetID() == id)
            {
                PlaylistNode *temp = mainHead;
                if (mainTail->GetID() == id)
                {
                    mainHead = nullptr;
                    mainTail = nullptr;
                }
                else
                {
                    mainHead = mainHead->GetNext();
                }
                cout << "\"" << temp->GetSongName() << "\" removed." << endl;
                delete temp;
            }
            else if (mainTail->GetID() == id)
            {
                PlaylistNode *temp = mainTail;
                PlaylistNode *fakeHead = mainHead;
                while (fakeHead->GetNext() != NULL)
                {
                    fakeHead = fakeHead->GetNext();
                }
                mainTail = fakeHead;
                cout << "\"" << temp->GetSongName() << "\" removed." << endl;
                delete temp;
            }
            else
            {
                while (temp->GetNext()->GetID() != id)
                {
                    temp = temp->GetNext();
                }
                PlaylistNode *todelete = temp->GetNext();
                temp->SetNext(todelete->GetNext());
                cout << "\"" << todelete->GetSongName() << "\" removed." << endl;
                // cout << "Test" << endl;
                delete todelete;
            }
            cout << endl;
        }
        else if (option == 'c')
        {
            int initPosition;
            int finalPosition;
            cout << endl
                 << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> initPosition;
            // initPosition -= 1; //change to index style
            cout << "Enter new position for song:" << endl;
            cin >> finalPosition;
            PlaylistNode *beforeToChange = mainHead;
            int nodes = 0;
            PlaylistNode *nodeCalc = mainHead;
            PlaylistNode *changing = nullptr;
            while (nodeCalc != nullptr)
            {
                nodeCalc = nodeCalc->GetNext();
                nodes++;
            }
            if (initPosition == 1)
            {
                changing = new PlaylistNode(mainHead->GetID(), mainHead->GetSongName(), mainHead->GetArtistName(), mainHead->GetSongLength());
                PlaylistNode *temp = mainHead;
                mainHead = mainHead->GetNext();
                // finalPosition--;
                delete temp;
            }
            else
            {
                for (int i = 1; i < initPosition - 1; i++)
                {
                    beforeToChange = beforeToChange->GetNext();
                }
                changing = new PlaylistNode(beforeToChange->GetNext()->GetID(), beforeToChange->GetNext()->GetSongName(), beforeToChange->GetNext()->GetArtistName(), beforeToChange->GetNext()->GetSongLength());
                PlaylistNode *temp = beforeToChange->GetNext();
                beforeToChange->SetNext(temp->GetNext());
                delete temp;
            }

            if (finalPosition <= 1)
            {
                changing->SetNext(mainHead);
                mainHead = changing;
            }
            else if (finalPosition >= nodes)
            {
                mainTail->InsertAfter(changing);
                mainTail = changing;
            }
            else
            {
                PlaylistNode *temp = mainHead;
                for (int i = 1; i < finalPosition - 1; i++)
                {
                    temp = temp->GetNext();
                }
                temp->InsertAfter(changing);
            }
            cout << "\"" << changing->GetSongName() << "\" moved to position " << finalPosition << endl
                 << endl;
            //  << "NODES: " << nodes << endl
            //  << endl;
        }
        else if (option == 's')
        {
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl
                 << endl;
            string artistName;
            cin.ignore(1);
            getline(cin, artistName);
            PlaylistNode *temp = mainHead;
            int i = 1;
            while (temp != nullptr)
            {
                if (temp->GetArtistName() == artistName)
                {
                    cout << i << "." << endl;
                    temp->PrintPlaylistNode();
                    cout << endl;
                }
                temp = temp->GetNext();
                i++;
            }
        }
        else if (option == 't')
        {
            cout << endl;
            PlaylistNode *temp = mainHead;
            int i = 0;
            while (temp != nullptr)
            {
                i += temp->GetSongLength();
                temp = temp->GetNext();
            }
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << i << " seconds" << endl
                 << endl;
        }
        else if (option == 'o')
        {
            cout << name << " - OUTPUT FULL PLAYLIST" << endl;
            if (mainHead == nullptr)
            {
                cout << "Playlist is empty" << endl
                     << endl;
            }
            else
            {
                PlaylistNode *curr = mainHead;
                int i = 1;
                while (curr != nullptr)
                {
                    cout << i << "." << endl;
                    curr->PrintPlaylistNode();
                    curr = curr->GetNext();
                    i++;
                    cout << endl;
                }
            }
        }
        else
        {
            cout << "Unknown option " << endl;
        }
        PrintMenu(name);
        cin >> option;
    }
    if (option == 'q')
    {
        PlaylistNode *curr = mainHead;
        while (curr != nullptr)
        {
            PlaylistNode *temp = curr->GetNext();
            delete curr;
            curr = temp;
        }
    }
    return 0;
}
