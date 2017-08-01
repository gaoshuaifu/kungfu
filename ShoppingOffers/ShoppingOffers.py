class Solution(object):
    def shoppingOffers(self, price, special, needs):
        # Retail cost: by each item with original price
        cost = sum([p * n for p, n in zip(price, needs)])

        # Go through each offer
        for offer in special:
            # The needs after apply the offer
            new_needs = [(n - m) for n, m in zip(needs, offer)]

            # If the offer is valid, calculate price with the offer
            if all([n >= 0 for n in new_needs]):
                special_cost = offer[-1] + self.shoppingOffers(price, special, new_needs)
                cost = min(cost, special_cost)

        return cost
