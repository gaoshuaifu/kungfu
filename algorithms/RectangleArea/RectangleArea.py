class Solution(object):
    def rectArea(self, x1, y1, x2, y2):
        return (x2 - x1) * (y2 - y1) if x1 < x2 and y1 < y2 else 0

    def computeArea(self, A, B, C, D, E, F, G, H):
        area1 = self.rectArea(A, B, C, D)
        area2 = self.rectArea(E, F, G, H)
        overlap = self.rectArea(max(A, E), max(B, F), min(C, G), min(D, H))
        return area1 + area2 - overlap
