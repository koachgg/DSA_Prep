// class Twitter {
// public:
//     Twitter() {
        
//     }
    
//     void postTweet(int userId, int tweetId) {
        
//     }
    
//     vector<int> getNewsFeed(int userId) {
        
//     }
    
//     void follow(int followerId, int followeeId) {
        
//     }
    
//     void unfollow(int followerId, int followeeId) {
        
//     }
// };

// /**
//  * Your Twitter object will be instantiated and called as such:
//  * Twitter* obj = new Twitter();
//  * obj->postTweet(userId,tweetId);
//  * vector<int> param_2 = obj->getNewsFeed(userId);
//  * obj->follow(followerId,followeeId);
//  * obj->unfollow(followerId,followeeId);
// //  

class Twitter {
public:
    unordered_set<int> user[501];   // Array of unordered sets to store followees for each user
    vector<pair<int,int>> tweet;    // Vector of pairs to store tweets where each pair is {tweetId, userId}

    Twitter() {}  // Constructor

    // Method to post a tweet
    void postTweet(int userId, int tweetId) {
        tweet.push_back({tweetId, userId});  // Add the tweet to the tweet vector
    }

    // Method to retrieve the 10 most recent tweets from user's feed
    vector<int> getNewsFeed(int userId) {
        int t = tweet.size();  // Total number of tweets
        vector<int> ans;       // Vector to store the 10 most recent tweet IDs

        // Traverse tweets in reverse order to get most recent first
        for(int i = t - 1; i >= 0 && ans.size() < 10; i--) {
            // Check if tweet is from the user or from a user they follow
            if(tweet[i].second == userId || user[userId].find(tweet[i].second) != user[userId].end()) {
                ans.push_back(tweet[i].first);  // Add tweetId to answer vector
            }
        }
        return ans;  // Return the 10 most recent tweet IDs
    }

    // Method to let a user follow another user
    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);  // Insert followeeId into followerId's set
    }

    // Method to let a user unfollow another user
    void unfollow(int followerId, int followeeId) {
        // Check if followeeId exists in followerId's set
        if(user[followerId].find(followeeId) != user[followerId].end()) {
            user[followerId].erase(followeeId);  // If yes, remove followeeId from followerId's set
        }
    }
};
