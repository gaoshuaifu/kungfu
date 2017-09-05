class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """

        from collections import defaultdict
        self.user2tweet = defaultdict(list)
        self.tweet2time = dict()
        self.follower2followee = defaultdict(set)

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """

        import time
        self.user2tweet[userId].append(tweetId)
        self.tweet2time[tweetId] = time.time()

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """

        tweets = []

        # The tweets posted by the user herself
        tweets += self.user2tweet[userId]

        for followee in self.follower2followee[userId]:
            tweets += self.user2tweet[followee]
        return sorted(tweets, key=lambda tweet: self.tweet2time[tweet], reverse=True)[:10]

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """

        if followerId == followeeId:
            return
        self.follower2followee[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """

        if followerId == followeeId:
            return
        self.follower2followee[followerId].discard(followeeId)
