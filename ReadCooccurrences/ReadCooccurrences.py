import sys
from collections import defaultdict

def addCooccurrencesPerUser(pageViews, scores):
    """
    pageViews = [(page1, views1), ..., (pageN, viewsN)]
    """

    if len(pageViews) <= 1:
        return

    scores[(-1, -1)] += 1
    for c1 in pageViews:
        scores[(c1[0], -1)] += c1[1]
        for c2 in pageViews:
            scores[(c1[0], c2[0])] += c1[1] * c2[1]

def computeCooccurrences(userPageViews):
    """
    userPageViews = {user1: pageViews1, ..., userM: pageViewsM},
    pageViews1 = [(page1, views1), ..., (pageN, viewsN)]
    """

    scores = defaultdict(int)
    for user, pageViews in userPageViews.items():
        addCooccurrencesPerUser(pageViews, scores)
    return scores

if __name__ == '__main__':
    userPageViews = {
        11: [(1, 0), (2, 2), (3, 5)],
        22: [(1, 1), (2, 3), (3, 4)],
    }
    scores = computeCooccurrences(userPageViews)
    print(scores)
