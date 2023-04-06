#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
private:
    string Name;
    int SubscribersCount;
    list<string> PublishedVideoTitles;
protected:
    string OwnerName;
    int contentQuality;
public:
    YouTubeChannel(string name, string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        contentQuality = 0;
    }
    void GetInfo() {
        cout << "Name: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "SubscribersCount: " << SubscribersCount << endl;
        cout << "Videos: " << endl;
        for (string videoTitle : PublishedVideoTitles) {
            cout << videoTitle << endl;
        }
    }
    void Subscribe() {
        SubscribersCount++;
    }
    void Unsubscribe() {
        if (SubscribersCount > 0)
            SubscribersCount--;
    }
    void PublishVideo(string title) {
        PublishedVideoTitles.push_back(title);
    }
    // create void RateContent that prints a content is good if the quality is above 5, bad otherwise.
     void RateContent() {
        if (contentQuality > 5)
            cout << "Good!" << endl;
        else cout << "Not good!" << endl;
    }

};

class CookingYouTubeChannel :public YouTubeChannel {
public:
    CookingYouTubeChannel(string name, string ownerName) :YouTubeChannel(name, ownerName) {

    }
    void Practice() {
        cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
        contentQuality++;
    }
};

class SingersYouTubeChannel :public YouTubeChannel {
public:
    SingersYouTubeChannel(string name, string ownerName) :YouTubeChannel(name, ownerName) {

    }
    void Practice() {
        cout << OwnerName << " is taking singing lessons, learning new music, experimenting with tunes..." << endl;
        contentQuality++;
    }
};

int main()
{
    CookingYouTubeChannel cook("Ali's Kitchen", "Ali");
    SingersYouTubeChannel sing("Rana's Studio", "Rana");

    // call the functions practice on both objects. Why are they different?
    
    for (int i = 0; i <= 5; i++) cook.Practice(); sing.Practice();

    cook.RateContent();  sing.RateContent();

    //I used the fact that these are two different objects from two different classes that we can access through the dot operator

    // call the function RateContent on both objects. You can only use 4 lines of code. Explain these lines in a few comments.

    return 0;
}
