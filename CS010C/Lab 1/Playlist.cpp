#include "Playlist.h"

using namespace std;

void PlaylistNode::InsertAfter(PlaylistNode *node)
{
    // PlaylistNode *temp = nextNodePtr;
    // nextNodePtr = node;
    // node->SetNext(temp);
    node->SetNext(this->GetNext());
    this->SetNext(node);
}
const std::string PlaylistNode::GetID() const
{
    return uniqueID;
}
const std::string PlaylistNode::GetSongName() const
{
    return songName;
}
const std::string PlaylistNode::GetArtistName() const
{
    return artistName;
}
const int PlaylistNode::GetSongLength() const
{
    return songLength;
}
PlaylistNode *PlaylistNode::GetNext() const
{
    return nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode() const
{
    cout << "Unique ID: " << uniqueID << endl
         << "Song Name: " << songName << endl
         << "Artist Name: " << artistName << endl
         << "Song Length (in seconds): " << songLength << endl;
}
