// Default constructor (1 pt)
// Parameterized constructor (1 pt)
// Public member functions
// InsertAfter() (1 pt)
// SetNext() - Mutator (1 pt)
// GetID() - Accessor
// GetSongName() - Accessor
// GetArtistName() - Accessor
// GetSongLength() - Accessor
// GetNext() - Accessor
// PrintPlaylistNode()
// Private data members
// string uniqueID - Initialized to "none" in default constructor
// string songName - Initialized to "none" in default constructor
// string artistName - Initialized to "none" in default constructor
// int songLength - Initialized to 0 in default constructor
// PlaylistNode* nextNodePtr - Initialized to 0 in default constructor
#include <string>
#include <iostream>
#ifndef PLAYLIST_H
#define PLAYLIST_H

class PlaylistNode
{
public:
    PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(0){};
    PlaylistNode(std::string ID, std::string songname, std::string artistname, int songlength, PlaylistNode *nextNodePtr = 0) : uniqueID(ID), songName(songname), artistName(artistname), songLength(songlength), nextNodePtr(nextNodePtr){};
    // ~PlaylistNode()
    // {
    //     delete this;
    // };
    // PlaylistNode(PlaylistNode *node)
    // {
    //     this->uniqueID = node->GetID();
    //     this->songName = node->GetSongName();
    //     this->artistName = node->GetArtistName();
    //     this->songLength = node->GetSongLength();
    //     this->nextNodePtr = 0;
    // };
    void InsertAfter(PlaylistNode *node);
    void SetNext(PlaylistNode *node)
    {
        // this->nextNodePtr = new PlaylistNode(node->GetID(), node->GetSongName(), node->GetArtistName(), node->GetSongLength(), node->Get);
        this->nextNodePtr = node;
    }
    const std::string GetID() const;
    const std::string GetSongName() const;
    const std::string GetArtistName() const;
    const int GetSongLength() const;
    PlaylistNode *GetNext() const;
    void PrintPlaylistNode() const;

private:
    std::string uniqueID;
    std::string songName;
    std::string artistName;
    int songLength;
    PlaylistNode *nextNodePtr;
};

struct Playlist
{
    PlaylistNode *head;
    PlaylistNode *tail;
};

#endif
